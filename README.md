# Grid Game

## Overview
Grid Game is a simple C program that simulates an 8x8 grid gradually filling with dots over a period of 48 hours. The game is designed to be a passive, time-based experience where a new dot appears approximately every 45 minutes (2700 seconds) until the entire grid is filled. The program uses a random placement algorithm to add dots to empty cells and updates the display after each addition.

## Features
- Displays an 8x8 grid that fills with dots (`.`) over time.
- Updates the grid every 2700 seconds (45 minutes) for a total playtime of ~48 hours.
- Shows the number of remaining empty cells.
- Simple terminal-based interface with automatic screen clearing for each update.
- Press `Ctrl+C` to exit the game early.

## Requirements
- C compiler (e.g., `gcc`)
- POSIX-compliant system (e.g., Linux, macOS) for the `sleep` function and `clear` command.
- For Windows, modify `system("clear")` to `system("cls")` in the source code.

## Installation
1. Save the source code as `grid_game.c`.
2. Compile the program:
   ```bash
   gcc grid_game.c -o grid_game
   ```
3. Run the executable:
   ```bash
   ./grid_game
   ```

## How to Play
- Run the program to start the game.
- The 8x8 grid will initialize empty (spaces represent empty cells).
- A new dot (`.`) will appear in a random empty cell every 2700 seconds.
- The grid updates automatically, showing the current state and the number of dots remaining.
- The game ends when all 64 cells are filled with dots, which takes approximately 48 hours.
- To exit early, press `Ctrl+C`.

## Notes
- The game is designed to run continuously for 48 hours. For testing, you can modify the `INTERVAL` constant in `grid_game.c` to a smaller value (e.g., `INTERVAL = 5` for 5 seconds per dot).
- On Windows, replace `system("clear")` with `system("cls")` in the `print_grid` function to clear the terminal.
- The random dot placement uses the C standard library's `rand()` function, seeded with the current time.

## File Structure
- `grid_game.c`: The main C source code for the game.

## Example Output
```
  Grid Game: Fill the 8x8 grid with dots

    . . . . . . . .
    . . . . . . . .
    . . . . . . . .
    . . . . . . . .
    . . . . . . . .
    . . . . . . . .
    . . . . . . . .
    . . . . . . . .

  Dots remaining: 63
```

## License
This project is unlicensed and provided as-is for personal use.
