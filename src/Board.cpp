#include <cstdlib>
#include <iostream>
#include "Board.h"


Board::Board(int rows, int columns, int mines) : mineCounter(rows, mines), numRows(rows), numColumns(columns), numMines(mines) {
    GenerateTiles("");
}


void Board::GenerateTiles(string board) {
    tiles = new Tile * [numRows];
    for (int i = 0; i < numRows; i++) {
        tiles[i] = new Tile[numColumns];
    }

    if (board == "") {
        srand(static_cast<unsigned>(time(0)));
        while (numMines > GetNumMines()) {
            int randomI = rand() % numRows;
            int randomJ = rand() % numColumns;
            tiles[randomI][randomJ].HasMine = true;
        }
    }
    else {
        ifstream boardFile("boards/" + board + ".brd");
        string row;
        for (int i = 0; getline(boardFile, row); i++) {
            for (unsigned int j = 0; j < row.length(); j++) {
                tiles[i][j].HasMine = row[j] == '1';
            }
        }
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            tiles[i][j].SetNeighborTiles(tiles, i, j, numRows - 1, numColumns - 1);
            tiles[i][j].SetPosition(j * 32.0f, i * 32.0f);
        }
    }

    mineCounter.AssignCountValue(to_string(GetNumMines()));
    mineCounter.Negative = false;
    mineCounter.UpdateTextures();
}

void Board::Clear() {
    for (int i = 0; i < numRows; ++i) delete[] tiles[i];
    delete[] tiles;
}

void Board::Draw(sf::RenderWindow& window, bool showMines) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            tiles[i][j].Render(window, showMines);
        }
    }
    mineCounter.Draw(window);
}

void Board::RevealMines() {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            if (tiles[i][j].HasMine) {
                tiles[i][j].RevealMine();
            }
        }
    }
}

int Board::GetNumMines() {
    int mines = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            mines += tiles[i][j].HasMine ? 1 : 0;
        }
    }
    return mines;
}

void Board::Flag(int i, int j) { tiles[i][j].Flag(mineCounter); }

bool Board::Reveal(int i, int j) { return tiles[i][j].Uncover(); }

bool Board::Won() {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            if (!tiles[i][j].HasMine && !tiles[i][j].IsRevealed()) {
                return false;
            }
        }
    }

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            if (tiles[i][j].HasMine) {
                tiles[i][j].Flag(mineCounter);
            }
        }
    }

    return true;
}

Board::~Board() {
    Clear();
}