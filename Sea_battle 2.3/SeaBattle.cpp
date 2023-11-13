#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <cstdio>
#include <Windows.h>
#include "DisplayFunctions.h"
#include "PlacementFunctions.h"
#include "PlacementLogich.h"
#include "PlayerAndBotTurnFunctions.h"
#include "IntroduceFunction.h"
#include "GameFinishAndResultFunctions.h"

using namespace std;


bool playerHit = false;
const int GRID_SIZE = 10;
const int num_ship = 10;

void InitializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void ShowPlayerAndBotGrids(char playerGrid[GRID_SIZE][GRID_SIZE], char botGrid[GRID_SIZE][GRID_SIZE]);
void ShowPlayerGrid(char grid[GRID_SIZE][GRID_SIZE]);
void Welcome();
void Color_menu(int color);
void Game_result(bool playerWin);
void PlaceShips(char grid[GRID_SIZE][GRID_SIZE]);
void PlayerTurn(char playerGrid[GRID_SIZE][GRID_SIZE], char botGrid[GRID_SIZE][GRID_SIZE]);
void BotTurn(char botGrid[GRID_SIZE][GRID_SIZE], char playerGrid[GRID_SIZE][GRID_SIZE]);
void ManualPlacement(char grid[GRID_SIZE][GRID_SIZE], char grid2[GRID_SIZE][GRID_SIZE]);
bool IsPlacementValid(char grid[GRID_SIZE][GRID_SIZE], int x, int y, int size, bool vertical);
bool IsValidCell(int x, int y);
bool AreNeighborsClear(char grid[GRID_SIZE][GRID_SIZE], int x, int y, int size, bool vertical);
bool Game_finished(char grid[GRID_SIZE][GRID_SIZE]);



int main() {
    char grid1[GRID_SIZE][GRID_SIZE], grid2[GRID_SIZE][GRID_SIZE];
    int operation;
    Welcome();
    cin >> operation;
    system("cls");

    if (operation == 1) {
        InitializeGrid(grid1);
        InitializeGrid(grid2);

        playerHit = false;

        cout << "Choose ship placement method:" << endl;
        cout << "1 - Random Placement" << endl;
        cout << "2 - Manual Placement" << endl;
        int placementMethod;
        cin >> placementMethod;

        if (placementMethod == 1) {
            PlaceShips(grid1);
            PlaceShips(grid2);
        }
        else if (placementMethod == 2) {
            ManualPlacement(grid1, grid2);
            PlaceShips(grid2);
        }

        ShowPlayerAndBotGrids(grid1, grid2);

        while (true) {
            PlayerTurn(grid1, grid2);

            if (Game_finished(grid2)) {
                Game_result(true);
                break;
            }

            BotTurn(grid2, grid1);

            if (Game_finished(grid1)) {
                Game_result(false);
                break;
            }
        }
    }

    return 0;
}



