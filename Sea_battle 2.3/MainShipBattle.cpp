#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 10;
const int num_ship = 10;

void InitializeGrid(char grid[SIZE][SIZE]);
void ShowGrid(char grid[SIZE][SIZE], char grid2[SIZE][SIZE]);
void Welcome();
void PlaceShips(char grid[SIZE][SIZE]);
bool IsPlacementValid(char grid[SIZE][SIZE], int x, int y, int size, bool vertical);
bool IsValidCell(int x, int y);
bool AreNeighborsClear(char grid[SIZE][SIZE], int x, int y, int size, bool vertical);

int main() {
    char grid1[SIZE][SIZE], grid2[SIZE][SIZE];
    int operation;

    Welcome();
    cin >> operation;
    system("cls");

    if (operation == 1) {
        InitializeGrid(grid1);
        InitializeGrid(grid2);

        PlaceShips(grid1);
        PlaceShips(grid2);

        ShowGrid(grid1, grid2);
    }

    return 0;
}

void PlaceShips(char grid[SIZE][SIZE]) {
    int shipSizes[num_ship] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };

    for (int ship = 0; ship < num_ship; ship++) {
        int size = shipSizes[ship];
        bool placed = false;

        while (!placed) {
            int x = rand() % SIZE;
            int y = rand() % SIZE;
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

bool IsPlacementValid(char grid[SIZE][SIZE], int x, int y, int size, bool vertical) {
    if (!IsValidCell(x, y)) {
        return false;
    }

    if (vertical) {
        if (x + size > SIZE) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            if (grid[x + i][y] != '0' || !AreNeighborsClear(grid, x + i, y, size, vertical)) {
                return false;
            }
        }
    }
    else {
        if (y + size > SIZE) {
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

bool IsValidCell(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

bool AreNeighborsClear(char grid[SIZE][SIZE], int x, int y, int size, bool vertical) {
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

    if (vertical && x + size < SIZE) {
        endX = x + size;
    }
    else {
        endX = SIZE - 1;
    }

    if (y + size < SIZE) {
        endY = y + size;
    }
    else {
        endY = SIZE - 1;
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

void InitializeGrid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = '0';
        }
    }
}

void ShowGrid(char grid[SIZE][SIZE], char grid2[SIZE][SIZE]) {
    cout << "   A B C D E F G H I J\t\t\t   A B C D E F G H I J" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << setw(2) << i + 1 << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\t\t\t";
        cout << setw(2) << i + 1 << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << grid2[i][j] << " ";
        }
        cout << "\n";
    }
}

void Welcome() {
    cout << "\t" << " _____               ______         _    _    _       \n";
    cout << "\t" << "/  ___|              | ___ \\       | |  | |  | |      \n";
    cout << "\t" << "\\ `--.   ___   __ _  | |_/ /  __ _ | |_ | |_ | |  ___ \n";
    cout << "\t" << " `--. \\ / _ \\ / _` | | ___ \\ / _` || __|| __|| | / _ \\\n";
    cout << "\t" << "/\\__/ /|  __/| (_| | | |_/ /| (_| || |_ | |_ | ||  __/\n";
    cout << "\t" << "\\____/  \\___| \\__,_| \\____/  \\__,_| \\__| \\__||_| \\___|\n";
    cout << "\t" << "                                                      \n";
    cout << "\t" << "                                                      \n";
    cout << "\t\t\t     1 - Play\n\t\t\t     2 - Exit\n\n" << endl;
}
