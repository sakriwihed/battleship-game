# Battleship Game (C++) 🚢

A two-player Battleship game for the console, written in **C++17**.
I built it in four stages during a C++ programming course at **TU Braunschweig** (2025). Each assignment added new features to the same game.

## How it works

- Each player has their own 5 × 5 sea with three ships (sizes 1, 2 and 3)
- The players take turns firing missiles at the other player's sea
- The missile type changes every round:
  - **Missile**: hits exactly the target field
  - **Tumbling missile**: lands on a random field next to the target
  - **Double missile**: one precise hit plus a tumbling second missile
- The game ends when all ships of one player are sunk
- At the end, statistics are shown for each player (ship parts not hit, missiles that landed in the water, most missiles on one field)

The game's text is in German.

## What I practised

- **Object-oriented design**: classes, inheritance and polymorphism (`Missile` → `TumblingMissile`, `DoubleMissile`)
- **Templates**: a generic 2D grid (`Grid2D<T>`) and `sendMissile<T>()`
- **Smart pointers** (`std::shared_ptr`) and the STL (`vector`, lambdas, `filter`)
- **Exceptions**: invalid ship placement (outside the sea, overlapping ships)
- **Operator overloading**: printing the sea with `operator<<`
- **Project structure**: the code is split into two libraries (`libSea`, `libGameObjects`) and the app, built with **CMake**

## Project structure

```
src/
├── app/               # game loop, player setup, tests
├── libGameObjects/    # ships, missiles, player sea, statistics
└── libSea/            # coordinates and the generic 2D grid
previous-versions/     # the three earlier stages of the game
```

## Development stages

The game was built over four assignments. The main code (`src/`) is the final version. The earlier stages are in [`previous-versions/`](previous-versions):

| Version | What was added |
|---|---|
| [v1](previous-versions/v1-ships-and-missiles) | Ships, player sea, basic missiles |
| [v2](previous-versions/v2-tumbling-missile) | Tumbling missile (inheritance), exceptions for invalid ship placement |
| [v3](previous-versions/v3-double-missile-and-grid) | Double missile (polymorphism), generic `Grid2D<T>` template |
| v4 (main code) | Player statistics with lambdas and grid filters |

## Build & run

```bash
cmake -S . -B build
cmake --build build
./build/src/app/Battleship
```

Each older version can be built the same way from inside its folder, for example:

```bash
cd previous-versions/v2-tumbling-missile
cmake -S . -B build
cmake --build build
./build/app/Battleship
```

## Note

This was a university assignment series. The course provided the project skeleton, and I implemented the tasks on each assignment sheet.
