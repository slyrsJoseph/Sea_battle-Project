#pragma once
#include <iostream>


void Welcome() {
    Color_menu(12);
    cout << "\t" << " _____               ______         _    _    _       \n";
    cout << "\t" << "/  ___|              | ___ \\       | |  | |  | |      \n";
    cout << "\t" << "\\ `--.   ___   __ _  | |_/ /  __ _ | |_ | |_ | |  ___ \n";
    cout << "\t" << " `--. \\ / _ \\ / _` | | ___ \\ / _` || __|| __|| | / _ \\\n";
    cout << "\t" << "/\\__/ /|  __/| (_| | | |_/ /| (_| || |_ | |_ | ||  __/\n";
    cout << "\t" << "\\____/  \\___| \\__,_| \\____/  \\__,_| \\__| \\__||_| \\___|\n";
    Color_menu(15);
    cout << "\t\t\t     ";
    Color_menu(10);
    cout << "1 - Play";
    Color_menu(15);
    cout << " ";
    Color_menu(14);
    cout << "2 - Exit";
    Color_menu(15);
    cout << "\n\n";

}

void Color_menu(int color) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
