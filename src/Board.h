#pragma once
#include <fstream>
#include "Tile.h"

class Board {
    public:
        Board(int rows, int columns, int mines);
        void GenerateTiles(string board);
        void Clear();
        void Draw(sf::RenderWindow& window, bool showMines);
        void RevealMines();
        void Flag(int i, int j);
        bool Reveal(int i, int j);
        bool Won();
        ~Board();

    private:
        int numMines;
        int numColumns;
        int numRows;
        int GetNumMines();
        MineCounter mineCounter;
        Tile** tiles;
};


