#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void PlaceShips(char grid[GRID_SIZE][GRID_SIZE]) {
    int shipSizes[num_ship] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };

    for (int ship = 0; ship < num_ship; ship++) {
        int size = shipSizes[ship];
        bool placed = false;

        while (!placed) {
            int x = rand() % GRID_SIZE;
            int y = rand() % GRID_SIZE;
            bool vertical = rand() % 2 == 0;

            if (IsPlacementValid(grid, x, y, size, vertical)) {
                for (int i = 0; i < size; i++) {
                    if (vertical) {
                        grid[x + i][y] = 'S';
                    }
                    else {
                        grid[x][y + i] = 'S';
                    }
                }
                placed = true;
            }
        }
    }
}
void ManualPlacement(char grid[GRID_SIZE][GRID_SIZE], char grid2[GRID_SIZE][GRID_SIZE]) {
    int shipSizes[num_ship] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };

    for (int ship = 0; ship < num_ship; ship++) {
        int size = shipSizes[ship];
        bool placed = false;

        while (!placed) {
            system("cls");
            ShowPlayerGrid(grid);

            cout << "Place a ship of size " << size << endl;
            cout << "Enter the starting coordinates (example, A2): ";
            char xCoord;
            int yCoord;
            cin >> xCoord >> yCoord;

            int x = yCoord - 1;
            int y = xCoord - 'A';

            cout << "Enter orientation (0 for horizontal, 1 for vertical): ";
            bool vertical;
            cin >> vertical;

            if (IsValidCell(x, y) && IsPlacementValid(grid, x, y, size, vertical)) {
                for (int i = 0; i < size; i++) {
                    if (vertical) {
                        grid[x + i][y] = 'S';
                    }
                    else {
                        grid[x][y + i] = 'S';
                    }
                }
                placed = true;
            }
            else {
                cout << "Invalid placement. Please try again." << endl;
            }
        }
    }
}
