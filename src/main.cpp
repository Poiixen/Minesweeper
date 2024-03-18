#include <iostream>
#include "Board.h"

using namespace sf;


bool ClickedOn(RenderWindow& window, Sprite& sprite) {
    return sprite.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
}

int main() {
    ifstream config("boards/config.cfg");
    string columns, rows, mines;

    getline(config, columns);
    getline(config, rows);
    getline(config, mines);

    RenderWindow window(VideoMode(stoi(columns) * 32, stoi(rows) * 32 + 88), "Minesweeper");
    Board board(stoi(rows), stoi(columns), stoi(mines));
    bool gameOver = false;
    bool gameWon = false;
    bool debugMode = false;

    Sprite debugButton(Textures::Get("debug"));
    Sprite resetButton(Textures::Get("face_happy"));
    

    string testBoardNames[3] = { "testboard1", "testboard2", "testboard3" };
    Sprite testButtons[3];

    for (int i = 0; i < 3; ++i) {
        testButtons[i].setTexture(Textures::Get("test_" + to_string(i + 1)));
        testButtons[i].setPosition((((stof(columns) - 2.0f) / 2.0f)) * 32.0f + 192.0f + i * 64.0f, stof(rows) * 32.0f);
    }

    resetButton.setPosition((((stof(columns) - 19.0f) / 2.0f)) * 32.0f, stof(rows) * 32.0f);
    debugButton.setPosition((((stof(columns) - 23.0f) / 2.0f)) * 32.0f + 128.0f, stof(rows) * 32.0f);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                for (int i = 0; i < 3; ++i) {
                    if (ClickedOn(window, testButtons[i])) {
                        board.Clear();
                        board.GenerateTiles(testBoardNames[i]);
                        gameOver = false;
                        gameWon = false;
                        resetButton.setTexture(Textures::Get("face_happy"));
                    }
                }

                if (ClickedOn(window, resetButton)) {
                    board.Clear();
                    board.GenerateTiles("");
                    gameOver = false;
                    gameWon = false;
                    resetButton.setTexture(Textures::Get("face_happy"));
                }

                if (ClickedOn(window, debugButton) && !gameWon) {
                    debugMode = !debugMode;
                }

                if (Mouse::getPosition(window).y < stoi(rows) * 32 && Mouse::getPosition(window).x < stoi(columns) * 32 && !gameWon && !gameOver) {
                    int row = Mouse::getPosition(window).y / 32;
                    int col = Mouse::getPosition(window).x / 32;

                    if (board.Reveal(row, col)) {
                        gameOver = true;
                        board.RevealMines();
                        resetButton.setTexture(Textures::Get("face_lose"));
                    }

                    if (board.Won()) {
                        gameWon = true;
                        debugMode = false;
                        resetButton.setTexture(Textures::Get("face_win"));
                    }
                }
            }

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right) {
                if (Mouse::getPosition(window).y < stoi(rows) * 32 && Mouse::getPosition(window).x < stoi(columns) * 32 && !gameWon && !gameOver) {
                    int row = Mouse::getPosition(window).y / 32;
                    int col = Mouse::getPosition(window).x / 32;
                    board.Flag(row, col);
                }
            }
        }

        window.clear();
        board.Draw(window, (gameOver || debugMode));
        window.draw(resetButton);
        window.draw(debugButton);

        for (const auto& button : testButtons) {
            window.draw(button);
        }

        window.display();
    }

    Textures::Clear();
    return 0;
}
