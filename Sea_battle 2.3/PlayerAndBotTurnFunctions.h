#pragma once
#include <iostream>
#include <conio.h>

using namespace std;





void ShowPlayerAndBotGrids(char playerGrid[GRID_SIZE][GRID_SIZE], char botGrid[GRID_SIZE][GRID_SIZE]);
void PlayerTurn(char playerGrid[GRID_SIZE][GRID_SIZE], char botGrid[GRID_SIZE][GRID_SIZE]);
void BotTurn(char botGrid[GRID_SIZE][GRID_SIZE], char playerGrid[GRID_SIZE][GRID_SIZE]);

void PlayerTurn(char grid[GRID_SIZE][GRID_SIZE], char botGrid[GRID_SIZE][GRID_SIZE]) {
    ShowPlayerAndBotGrids(grid, botGrid);
    cout << "Enter shot coordinates: ";
    char coord_x;
    int coord_y;
    cin >> coord_x >> coord_y;


    int x = coord_y - 1;
    int y = coord_x - 'A';

    if (IsValidCell(x, y)) {
        if (botGrid[x][y] == 'S') {
            botGrid[x][y] = 'X';
            cout << "Shot hit!" << endl;
            playerHit = true;

        }
        else if (botGrid[x][y] == '0') {
            botGrid[x][y] = 'M';
            cout << "Missed Shot!" << endl;
            playerHit = false;
        }
        else {
            cout << "You have already shot there, try again." << endl;
        }
    }
    else {
        cout << "Wrong coordinates, try again." << endl;
    }
    cout << "Press any key to continue...";
    _getch();
    ShowPlayerAndBotGrids(grid, botGrid);

}

void BotTurn(char grid2[GRID_SIZE][GRID_SIZE], char grid[GRID_SIZE][GRID_SIZE]) {
    if (!playerHit) {
        int x, y;

        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (grid[x][y] == 'X' || grid[x][y] == 'M');

        if (grid[x][y] == 'S') {
            grid[x][y] = 'X';
            cout << "Enemy hit your ship!" << endl;
            playerHit = true;
        }
        else {
            grid[x][y] = 'M';
            cout << "Enemy missed!" << endl;
        }
    }
    else {

        if (rand() % 2 == 0) {

            playerHit = false;
        }
    }
    cout << "Press any key to continue...";
    _getch();
    ShowPlayerAndBotGrids(grid, grid2);

}
