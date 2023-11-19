#pragma once
#include <iostream>



bool IsPlacementValid(char grid[GRID_SIZE][GRID_SIZE], int x, int y, int size, bool vertical);
bool IsValidCell(int x, int y);
bool AreNeighborsClear(char grid[GRID_SIZE][GRID_SIZE], int x, int y, int size, bool vertical);



bool AreNeighborsClear(char grid[GRID_SIZE][GRID_SIZE], int x, int y, int size, bool vertical) {
    int startX, startY, endX, endY;
    if (x > 0) {
        startX = x - 1;
    }
    else {
        startX = 0;
    }

    if (y > 0) {
        startY = y - 1;
    }
    else {
        startY = 0;
    }

    if (vertical && x + size < GRID_SIZE) {
        endX = x + size;
    }
    else {
        endX = GRID_SIZE - 1;
    }

    if (y + size < GRID_SIZE) {
        endY = y + size;
    }
    else {
        endY = GRID_SIZE - 1;
    }

    for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
            if (grid[i][j] != '0') {
                return false;
            }
        }
    }

    return true;
}

bool IsValidCell(int x, int y) {
    return x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE;
}
bool IsPlacementValid(char grid[GRID_SIZE][GRID_SIZE], int x, int y, int size, bool vertical) {
    if (!IsValidCell(x, y)) {
        return false;
    }

    if (vertical) {
        if (x + size > GRID_SIZE) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            if (grid[x + i][y] != '0' || !AreNeighborsClear(grid, x + i, y, size, vertical)) {
                return false;
            }
        }
    }
    else {
        if (y + size > GRID_SIZE) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            if (grid[x][y + i] != '0' || !AreNeighborsClear(grid, x, y + i, size, vertical)) {
                return false;
            }
        }
    }

    return true;
}
