#include "cards.h"

#include <iostream>
using namespace std;






#include <QApplication>
#include <QPushButton>

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>

using namespace std;

class SnakeGame {
private:
    int width, height;
    int x, y, fruitX, fruitY, score;
    vector<pair<int, int>> snake;
    char direction;

    void Draw() {
        system("cls");
        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0)
                    cout << "#";
                else if (j == width - 1)
                    cout << "#";
                else if (i == y && j == x)
                    cout << "O"; // head of the snake
                else if (i == fruitY && j == fruitX)
                    cout << "F"; // fruit
                else {
                    bool snakePart = false;
                    for (auto s : snake) {
                        if (s.first == j && s.second == i) {
                            snakePart = true;
                            break;
                        }
                    }
                    if (snakePart)
                        cout << "o"; // body of the snake
                    else
                        cout << " ";
                }
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        cout << "Score: " << score << endl;
    }

    void Input() {
        if (_kbhit()) {
            direction = _getch();
        }
    }

    void Logic() {
        int prevX = snake.empty() ? x : snake.front().first;
        int prevY = snake.empty() ? y : snake.front().second;
        int prev2X, prev2Y;
        if (!snake.empty()) {
            prev2X = snake[0].first;
            prev2Y = snake[0].second;
            snake[0] = {x, y};
        }

        // Snake movement logic
        switch (direction) {
        case 'a': x--; break;
        case 'd': x++; break;
        case 'w': y--; break;
        case 's': y++; break;
        }

        // Check for boundary collisions
        if (x < 1 || x > width - 2 || y < 0 || y >= height) {
            gameOver();
        }

        // Check for self-collision
        for (auto s : snake) {
            if (s.first == x && s.second == y) {
                gameOver();
            }
        }

        // Check for fruit collision
        if (x == fruitX && y == fruitY) {
            score++;
            fruitX = rand() % (width - 2) + 1;
            fruitY = rand() % height;
            snake.push_back({prevX, prevY});
        }

        // Move the snake
        if (!snake.empty()) {
            for (int i = snake.size() - 1; i > 0; i--) {
                snake[i] = snake[i - 1];
            }
            snake[0] = {prevX, prevY};
        }
    }

    void gameOver() {
        system("cls");
        cout << "Game Over!" << endl;
        cout << "Final Score: " << score << endl;
        exit(0);
    }

public:
    SnakeGame(int w, int h) : width(w), height(h), score(0) {
        x = w / 2;
        y = h / 2;
        fruitX = rand() % (w - 2) + 1;
        fruitY = rand() % h;
        direction = 'd'; // start moving right
        snake.push_back({x, y});
    }

    void Run() {
        while (true) {
            Draw();
            Input();
            Logic();
            Sleep(100); // Game speed
        }
    }
};

int main() {
    SnakeGame game(30, 15);
    game.Run();
    return 0;
}
