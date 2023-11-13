#pragma once
#include <iostream>

bool Game_finished(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 'S') {
                return false;
            }
        }
    }
    return true;
}

void Game_result(bool playerWin) {
    system("cls");
    if (playerWin) {
        cout << " YOU WIN! ! !" << endl;
    }
    else {
        cout << "YOU LOST =(" << endl;
    }
}
