#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include "carG.h"

#define COLLISION_CHECK (carPosX == playerPos && frameRow == 21) || (carPosX == playerPos && frameRow == 22) || (carPosX == playerPos && frameRow == 23) || \
                         (carPosX + 1 == playerPos && frameRow == 21) || (carPosX + 1 == playerPos && frameRow == 22) || (carPosX + 1 == playerPos && frameRow == 23) || \
                         (carPosX + 2 == playerPos && frameRow == 21) || (carPosX + 2 == playerPos && frameRow == 22) || (carPosX + 2 == playerPos && frameRow == 23) || \
                         (carPosX + 3 == playerPos && frameRow == 21) || (carPosX + 3 == playerPos && frameRow == 22) || (carPosX + 3 == playerPos && frameRow == 23) || \
                         (carPosX + 4 == playerPos && frameRow == 21) || (carPosX + 4 == playerPos && frameRow == 22) || (carPosX + 4 == playerPos && frameRow == 23)

using namespace std;

COORD consoleCoord = {0, 0};

void CarG::setCursorPosition(int x, int y) {
    consoleCoord.X = x;
    consoleCoord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), consoleCoord);
}

CarG::CarG() {
    srand(time(0));
    cashSymbol = '$';
    playerPos = 27;
    score = 0;
    enemySpeed = 150;
}

void CarG::drawFrame() {
    for (int j = 1; j <= 3; j += 2)
        for (int i = 0; i <= 24; i++) {
            setCursorPosition(16 * j, i);
            cout << char(178);
        }
}

void CarG::drawCar(int shift) {
    playerPos += shift;
    setCursorPosition(playerPos, 22);
    cout << "@   @";
    setCursorPosition(playerPos, 23);
    cout << "| X |";
    setCursorPosition(playerPos, 24);
    cout << "@   @";
}

void CarG::clearCar() {
    setCursorPosition(playerPos, 22);
    cout << "     ";
    setCursorPosition(playerPos, 23);
    cout << "     ";
    setCursorPosition(playerPos, 24);
    cout << "     ";
}

void CarG::drawEnemyCar(int row, int enemyPos) {
    setCursorPosition(enemyPos, row);
    cout << char(219) << "  " << char(219);
    setCursorPosition(enemyPos, row + 1);
    cout << char(219) << char(219) << char(219) << char(219);
    setCursorPosition(enemyPos, row + 2);
    cout << char(219) << "  " << char(219);
}

void CarG::clearEnemyCar(int row, int enemyPos) {
    for (int i = 0; i < 3; i++) {
        setCursorPosition(enemyPos, row + i);
        cout << "    ";
    }
}

void CarG::handleMovement(char inputKey) {
    switch (inputKey) {
        case 'A':
        case 'a':
            moveLeft();
            break;
        case 'D':
        case 'd':
            moveRight();
            break;
    }
}

void CarG::moveLeft() {
    if (playerPos > 17) {
        clearCar();
        drawCar(-2);
    }
}

void CarG::moveRight() {
    if (playerPos < 42) {
        clearCar();
        drawCar(2);
    }
}

char CarG::gameLoop() {
    while (true) {
        int carPosX = rand() % 30 + 17;
        int enemyPosX = rand() % 28 + 17;

        if (carPosX == enemyPosX)
            carPosX = rand() % 31 + 17;

        for (int frameRow = 0; frameRow <= 23; frameRow++) {
            setCursorPosition(carPosX, frameRow);
            cout << ' ';
            setCursorPosition(carPosX, frameRow + 1);
            cout << cashSymbol;

            if (frameRow == 23) {
                setCursorPosition(carPosX, 24);
                cout << ' ';
            }

            drawEnemyCar(frameRow, enemyPosX);
            Sleep(enemySpeed);

            for (int offsetX = -3; offsetX <= 4; offsetX++)
                for (int offsetY = 0; offsetY <= 3; offsetY++)
                    if ((enemyPosX == playerPos + offsetX && frameRow + 2 == 21 + offsetY) ||
                        (enemyPosX == playerPos + offsetX && frameRow + 2 == 22 + offsetY) ||
                        (enemyPosX == playerPos + offsetX && frameRow + 2 == 23 + offsetY)) {
                        inputKey = displayGameOver();
                        return inputKey;
                    }

            clearEnemyCar(frameRow, enemyPosX);

            if (COLLISION_CHECK) {
                drawCar(0);
                score += 5;
                break;
            }

            score++;
            displayScore();

            if (_kbhit()) {
                inputKey = _getch();
                if (inputKey == 'a' || inputKey == 'A' || inputKey == 'D' || inputKey == 'd') {
                    handleMovement(inputKey);
                } else if (inputKey == 'Q' || inputKey == 'q') {
                    return inputKey;
                }
            }

            if (score % 100 == 0) {
                if (enemySpeed > 25)
                    enemySpeed -= 25;
                else if (enemySpeed > 15 && enemySpeed < 25)
                    enemySpeed -= 3;
            }
        }
    }
}

void CarG::displayScore() {
    setCursorPosition(50, 15);
    cout << "Score = " << score;
}

char CarG::displayGameOver() {
    setCursorPosition(26, 12);
    cout << "GAME OVER";
    setCursorPosition(23, 13);
    cout << "Your Score is: " << score;
    setCursorPosition(19, 15);
    cout << "Play Again? (Y/N): ";
    inputKey = _getche();

    if (inputKey == 'y' || inputKey == 'Y') {
        score = 0;
        enemySpeed = 175;
        return inputKey;
    } else if (inputKey == 'n' || inputKey == 'N') {
        return 'q';
    } else {
        return displayGameOver();
    }
}

void CarG::playMusic() {
    PlaySound(TEXT("123.wav"), NULL, SND_SYNC);
    PlaySound(TEXT("all.wav"), NULL, SND_SYNC);
}
