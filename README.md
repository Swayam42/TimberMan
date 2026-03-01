# TimberMan — Learning Game

> A C++ + SFML game built step-by-step for learning purposes.
> Based on the classic "Timber!" game concept.

---

## What is TimberMan?

TimberMan is a simple game where:

- A player stands next to a tree
- You chop branches while avoiding being hit by them
- A timer counts down — chop faster to keep time alive
- A bee flies across the screen as an obstacle/distraction

**Current Progress (what this code covers):**

- Window creation
- Background, tree, player, axe sprites layered correctly
- Score display (HUD)
- "Press Enter to Start" screen
- Countdown timer bar
- Randomly moving bee
- Randomly generated branch system on the tree

---

## Folder Structure

```
TimberMan/
├── Timber.cpp          ← Final combined file (the full game so far)
├── graphics/           ← All .png image assets
│   ├── background.png
│   ├── tree.png
│   ├── player.png
│   ├── axe.png
│   ├── branch.png
│   └── bee.png
├── font/
│   └── KOMIKAP_.ttf    ← Font for score text
└── Steps/              ← Step-by-step learning files
    ├── Step1_BlackWindow.cpp
    ├── Step2_SpriteLayers.cpp
    ├── Step3_HUD.cpp
    ├── Step4_EnterToStart_Timer.cpp
    ├── Step5_BeeMovement.cpp
    └── Step6_BranchSystem.cpp
```

---

## The Step-by-Step Learning Path

Each file in `Steps/` is a **complete, runnable program**.
Start from Step 1 and read the comments carefully.

| Step | File                           | What You Learn                                  |
| ---- | ------------------------------ | ----------------------------------------------- |
| 1    | `Step1_BlackWindow.cpp`        | Creating a window, the game loop skeleton       |
| 2    | `Step2_SpriteLayers.cpp`       | Loading textures, drawing sprites in layers     |
| 3    | `Step3_HUD.cpp`                | Font, Text, drawing score + timer bar           |
| 4    | `Step4_EnterToStart_Timer.cpp` | Events, pausing, Clock, counting down time      |
| 5    | `Step5_BeeMovement.cpp`        | Moving a sprite, random speed/height, reset     |
| 6    | `Step6_BranchSystem.cpp`       | Arrays, enums, the branch shift + random system |

---

## Key Concepts by Chapter

### The Game Loop (every step uses this)

```
while window is open:
  1. poll events (keyboard, window close)
  2. if not paused: update positions, timer
  3. clear screen
  4. draw layers in order
  5. display
```

### Screen Coordinates

```
(0,0) is TOP-LEFT

       0    400   800   960  1200  1920
    0  ┌─────────────────────────────────┐
       │ background fills everything    │
  500  │         tree at x=810          │
       │  player at x=580               │
 1080  └─────────────────────────────────┘
```

### Sprite Positions Used in This Game

| Object          | X    | Y      | Notes                     |
| --------------- | ---- | ------ | ------------------------- |
| Background      | 0    | 0      | Fills the screen          |
| Tree            | 810  | 0      | Center-ish, top to bottom |
| Player          | 580  | 720    | Left side of tree         |
| Axe             | 700  | 830    | Near player's hands       |
| Branch (right)  | 1330 | varies | Right side of tree        |
| Branch (left)   | 610  | varies | Left side of tree         |
| Branch (hidden) | 3000 | varies | Off screen (NONE)         |
| Timer Bar       | 760  | 980    | Bottom center             |
| Score Text      | 20   | 20     | Top left                  |

---

## How the Branch System Works

```
Branches array: [0][1][2][3][4][5]
                 ^
                 TOP of tree (newest)

When updateBranches() is called:
  [5] ← [4]   (shift everything down one slot)
  [4] ← [3]
  [3] ← [2]
  [2] ← [1]
  [1] ← [0]
  [0] ← rand() = new random LEFT / RIGHT / NONE

The oldest branch (index 5) falls off the tree.
```

Think of it like a conveyor belt going downward.

---

## How the Bee Works

```
State 1: beeActive = false
  → Pick random speed (200–399)
  → Pick random height (500–999)
  → Set bee to far right (x=2000)
  → beeActive = true

State 2: beeActive = true
  → Move bee LEFT by (beeSpeed × deltaTime) each frame
  → When x < -100 (off left edge):
    → beeActive = false → repeat
```

---

## Building This Project

### Using VS Code Tasks (Recommended)

1. Open the `.cpp` step file you want to compile
2. Press `Ctrl+Shift+B` → Select "Build C Program" (or "Compile and Run C Program")

### Manual Command Line

```bash
cd "6th-SEM/Game Programming with C++/Games/TimberMan"
g++ Steps/Step1_BlackWindow.cpp -o Step1.exe -IC:/SFML/include -LC:/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
Step1.exe
```

> Make sure SFML `.dll` files are in the same folder as the `.exe`!

---

