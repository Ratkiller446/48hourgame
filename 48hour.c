#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define GRID_SIZE 8
#define TOTAL_DOTS (GRID_SIZE * GRID_SIZE)
#define TOTAL_TIME (48 * 3600) // 48 hours in seconds
#define INTERVAL (TOTAL_TIME / TOTAL_DOTS) // Time per dot in seconds

void init_grid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = ' ';
        }
    }
}

void print_grid(char grid[GRID_SIZE][GRID_SIZE]) {
    system("clear"); // Use "cls" for Windows
    printf("\n  Grid Game: Fill the 8x8 grid with dots\n\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("  ");
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n  Dots remaining: %d\n", TOTAL_DOTS - count_dots(grid));
}

int count_dots(char grid[GRID_SIZE][GRID_SIZE]) {
    int count = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == '.') count++;
        }
    }
    return count;
}

void place_dot(char grid[GRID_SIZE][GRID_SIZE]) {
    int empty_cells = TOTAL_DOTS - count_dots(grid);
    if (empty_cells == 0) return;

    int rand_index = rand() % empty_cells;
    int current = 0;

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == ' ') {
                if (current == rand_index) {
                    grid[i][j] = '.';
                    return;
                }
                current++;
            }
        }
    }
}

void print_countdown(int seconds_left) {
    int hours = seconds_left / 3600;
    int minutes = (seconds_left % 3600) / 60;
    int seconds = seconds_left % 60;
    printf("  Next dot in: %02d:%02d:%02d\r", hours, minutes, seconds);
    fflush(stdout);
}

int main() {
    srand(time(NULL));
    char grid[GRID_SIZE][GRID_SIZE];
    init_grid(grid);

    printf("Starting Grid Game. It will take approximately 48 hours to complete.\n");
    printf("A new dot will appear every %d seconds.\n", INTERVAL);
    printf("Press Ctrl+C to exit early.\n");

    while (count_dots(grid) < TOTAL_DOTS) {
        print_grid(grid);
        place_dot(grid);
        for (int t = INTERVAL; t > 0; t--) {
            print_countdown(t);
            sleep(1);
        }
        printf("\n"); // Move to next line after countdown
    }

    print_grid(grid);
    printf("\nCongratulations! The grid is fully filled with dots.\n");
    printf("Game completed in approximately 48 hours.\n");

    return 0;
}