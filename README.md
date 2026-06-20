# Plankton

A short animated scene built with `graphics.h` (via **SDL_bgi**, the SDL2-based reimplementation of Borland's classic BGI graphics library) and C++. Plankton walks across a SpongeBob-style background while Mr. Krabs accuses him of stealing the Krabby Patty.

## Requirements

- A C++ compiler (`g++`)
- [SDL_bgi](https://github.com/sdlbgi/sdl_bgi) installed (provides `graphics.h`, `libSDL_bgi.so`)
- SDL2 (`libsdl2-dev`)

## Build & Run

```bash
g++ -x c++ plankton.c -o plankton -lSDL_bgi -lSDL2 -lm && ./plankton
```

## How it works

`drawScene()` redraws the whole frame every loop iteration (background, signage, the Krabby Patty, Plankton's body/arms/legs), and `main()` shifts Plankton's x-position (`plankton`) leftward each frame to animate him walking across the screen, looping back around once he goes off-screen.

## ⚠️ SDL_bgi `COLOR()` gotchas

This project uses several custom RGB colors (sky, road, buns, sign, etc.) instead of the built-in 16-color BGI palette (`BLACK`, `RED`, `GREEN`, ...). Getting custom colors working correctly with SDL_bgi took some real debugging, so the lessons are recorded here.

### 1. `COLOR(r, g, b)` always returns `-1` — that's by design, not a bug

Looking at the SDL_bgi source (`src/SDL_bgi.c`):

```c
int COLOR (int r, int g, int b)
{
  bgi_use_tmp_color = SDL_TRUE;
  bgi_argb_palette[ARGB_TMP_COL] = 0xff000000 | r << 16 | g << 8 | b;
  return -1;
}
```

`COLOR()` doesn't hand back a usable color value. It stashes your RGB triplet into a **single shared temporary slot** (`ARGB_TMP_COL`) and returns the sentinel `-1`. Functions like `setcolor()`, `setfillstyle()`, and `setbkcolor()` check for `-1` and, when they see it, copy whatever is currently sitting in that temp slot into their own dedicated slot.

**Implication:** you cannot do this —

```cpp
int sky = COLOR(116, 185, 237);   // ❌ stores -1 into `sky`, RGB value is gone
...
setfillstyle(SOLID_FILL, sky);    // every call like this resolves to whatever
                                   // was LAST stashed into the shared temp slot —
                                   // not necessarily sky's color!
```

If you call `COLOR()` multiple times before consuming the result, only the **last** call's RGB value survives in the shared slot — every earlier one is overwritten. Storing `COLOR()`'s return value in a variable and using it later is the #1 way to get this library to render everything as one collapsed color.

**The fix used in this project:** define colors as macros, so `COLOR()` is called fresh, immediately before the function that consumes it:

```cpp
#define sky   COLOR(116, 185, 237)
#define road  COLOR(68,  84,  110)
#define buns  COLOR(250, 213, 92)
// ...
```

This way, `setfillstyle(SOLID_FILL, sky)` expands to `setfillstyle(SOLID_FILL, COLOR(116, 185, 237))` — the stash-and-consume happens atomically, right where it's used, with no risk of another `COLOR()` call sneaking in between.

### 2. Macro placement matters — `#define` only affects code *below* it

`#define` is a textual substitution done top-to-bottom by the preprocessor. If your color macros are defined *inside* `main()`, but `drawScene()` is written *above* `main()` in the file, then `drawScene()` was already compiled before the preprocessor ever saw your `#define`s — so none of the substitutions apply there.

**Fix:** put all `#define` color macros near the top of the file, right after your `#include`s, before any function that uses them.

Also make sure you don't have a leftover `int sky, road, ...;` global variable declaration sitting around — if both the macro *and* a same-named global variable exist, you'll get confusing/inconsistent behavior depending on which one the compiler picks up at each call site.

### 3. `setbkcolor()` silently clears the whole viewport

From the SDL_bgi source:

```c
void setbkcolor (int col)
{
  ...
  // this was undocumented!
  clearviewport ();
}
```

Calling `setbkcolor()` **wipes everything currently drawn** back to the background color, every time it's called — not just future draws. In this project, a `setbkcolor(WHITE)` call inside the "text" block (meant only to set a background color for `outtextxy`) was silently erasing the sky background that had already been drawn earlier in the same `drawScene()` call.

**Fix:** avoid calling `setbkcolor()` mid-scene unless you specifically intend to clear everything drawn so far. If you only need text to render with a particular background, look for a more targeted approach, or call `setbkcolor()` once before any drawing happens rather than partway through.

### Quick debugging tip

If colors look wrong (everything collapsing to one shade, or randomly going black/white), add temporary `printf` statements right where a color is *consumed* (inside `setcolor`/`setfillstyle` calls) rather than where it's defined — and check the call order in `drawScene()` from top to bottom for anything that calls `setbkcolor()`, or any `COLOR()` call whose result gets stored instead of used immediately.

## Project structure

- `plankton.c` — single-file source containing `drawScene()` (renders one frame) and `main()` (the animation loop).
