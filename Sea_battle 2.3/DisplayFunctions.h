#pragma once
#include <iostream>
#include <iomanip>

using namespace std;


void InitializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '0';
        }
    }
}

void ShowPlayerAndBotGrids(char playerGrid[GRID_SIZE][GRID_SIZE], char botGrid[GRID_SIZE][GRID_SIZE]) {
    system("cls");
    cout << "   A B C D E F G H I J\t\t\t   A B C D E F G H I J" << endl;
    for (int i = 0; i < GRID_SIZE; i++) {
        cout << setw(2) << i + 1 << " ";
        for (int j = 0; j < GRID_SIZE; j++) {
            cout << playerGrid[i][j] << " ";
        }
        cout << "\t\t\t";
        cout << setw(2) << i + 1 << " ";
        for (int j = 0; j < GRID_SIZE; j++) {
            if (botGrid[i][j] == 'S') {
                cout << '0' << " ";
            }
            else {
                cout << botGrid[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
void ShowPlayerGrid(char grid[GRID_SIZE][GRID_SIZE]) {

    cout << "   A B C D E F G H I J" << endl;
    for (int i = 0; i < GRID_SIZE; i++) {
        cout << setw(2) << i + 1 << " ";
        for (int j = 0; j < GRID_SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
