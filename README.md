# Car Game 🚗

A console-based Car Game implemented in C++ that utilizes **multithreading** to enhance gameplay by playing background music and handling other tasks simultaneously.

## Project Structure
This project includes the following files:
- **main.cpp**: Contains the main game logic, including movement, scoring, and collision detection.
- **CarG.h**: The header file defining the `CarG` class and its methods, including multithreaded functionality.
- **CarG.exe**: The compiled executable for running the game.

## Features
- **Player-Controlled Car**: Navigate left and right on the road to avoid obstacles.
- **Enemy Cars and Cash Collection**: Dodge enemy cars and collect cash symbols (`$`) for points.
- **Dynamic Difficulty**: As points increase, the game speed accelerates, adding to the challenge.
- **Multithreading for Background Music**: A separate thread plays background music while the game runs smoothly.
- **Simple Controls**:
  - **`A`** or **`a`** - Move Left
  - **`D`** or **`d`** - Move Right
  - **`Q`** or **`q`** - Quit the game

## Multithreading Feature
The game uses multithreading to play background music continuously during gameplay. The `music` function is run in a separate thread to ensure that sound playback does not interfere with the main game loop.

In **CarG.h**, the `music` function is defined to play sound files:
```cpp
void music() {
    PlaySound(TEXT("123.wav"), NULL, SND_SYNC);
    PlaySound(TEXT("all.wav"), NULL, SND_SYNC);
}

