#include "Game2048.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Game2048::initialize() {
    srand(time(0));
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = 0;
    spawnTile();
    spawnTile();
}


void Game2048::display() {
    system("cls"); // ใช้ "clear" บน Linux/Mac
    cout << "2048 GAME (Use Arrow Keys: W/A/S/D)\n";
    cout << "+------------------------+\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "|";
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                cout << setw(6) << ".";
            else
                cout << setw(6) << board[i][j];
        }
        cout << " |\n";
    }
    cout << "+------------------------+\n";
}

bool Game2048::move(char direction) {
    bool moved = false;

    for (int i = 0; i < SIZE; i++) {
        vector<int> line;
        for (int j = 0; j < SIZE; j++) {
            int val;
            switch (direction) {
                case 'w': val = board[j][i]; break;
                case 's': val = board[SIZE - 1 - j][i]; break;
                case 'a': val = board[i][j]; break;
                case 'd': val = board[i][SIZE - 1 - j]; break;
            }
            if (val != 0) line.push_back(val);
        }

        for (size_t j = 0; j + 1 < line.size(); j++) {
            if (line[j] == line[j + 1]) {
                line[j] *= 2;
                line.erase(line.begin() + j + 1);
                moved = true;
            }
        }

        while (line.size() < SIZE) line.push_back(0);

        for (int j = 0; j < SIZE; j++) {
            int& target = (direction == 'w') ? board[j][i]
                            : (direction == 's') ? board[SIZE - 1 - j][i]
                            : (direction == 'a') ? board[i][j]
                                                 : board[i][SIZE - 1 - j];
            if (target != line[j]) {
                target = line[j];
                moved = true;
            }
        }
    }

    if (moved) spawnTile();
    return moved;
}

bool Game2048::isGameOver() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == 0)
                return false;

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE - 1; j++)
            if (board[i][j] == board[i][j + 1] || board[j][i] == board[j + 1][i])
                return false;

    return true;
}

void Game2048::spawnTile() {
    vector<pair<int, int>> empty;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == 0)
                empty.emplace_back(i, j);

    if (!empty.empty()) {
        auto [x, y] = empty[rand() % empty.size()];
        board[x][y] = (rand() % 10 < 9) ? 2 : 4;
    }
}