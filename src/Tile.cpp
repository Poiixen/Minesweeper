#include <iostream>
#include "Tile.h"

Tile::Tile() : HasMine(false), isRevealed(false), isFlagged(false), adjacentMines(0) {
    tileSprite.setTexture(Textures::Get("tile_hidden"));
    flagSprite.setTexture(Textures::Get("flag"));
    mineSprite.setTexture(Textures::Get("mine"));
}

bool Tile::IsRevealed() const {
    return isRevealed;
}

bool Tile::Uncover() {
    if (isFlagged) {
        return false;
    }
    isRevealed = true;
    tileSprite.setTexture(Textures::Get("tile_revealed"));

    if (HasMine) {
        return true;
    }
    if (adjacentMines == 0) {
        for (int i = 0; i < 8; i++) {
            if (neighborTiles[i] != nullptr && !neighborTiles[i]->isRevealed && !neighborTiles[i]->HasMine && !neighborTiles[i]->isFlagged) {
                neighborTiles[i]->Uncover();
            }
        }
    }
    return false;
}

void Tile::RevealMine() {
    tileSprite.setTexture(Textures::Get("tile_revealed"));
}

void Tile::SetNeighborTiles(Tile**& tiles, int i, int j, int iMax, int jMax) {
    adjacentMines = 0;

    const int directions[][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

    for (int k = 0; k < 8; ++k) {
        int ni = i + directions[k][0];
        int nj = j + directions[k][1];

        if (ni >= 0 && ni < iMax && nj >= 0 && nj < jMax) {
            neighborTiles[k] = &tiles[ni][nj];

            if (neighborTiles[k]->HasMine) {
                ++adjacentMines;
            }
        }
    }

    // for debugging
    std::cout << "Tile (" << i << ", " << j << ") has " << adjacentMines << " adjacent mines.\n";

    if (adjacentMines > 0 && adjacentMines <= 8) {
        numberSprite.setTexture(Textures::Get("number_" + std::to_string(adjacentMines)));
    }
}




void Tile::Render(sf::RenderWindow& window, bool showMines) {
    window.draw(tileSprite);
    if (isFlagged) {
        window.draw(flagSprite);
    }
    if (HasMine && showMines) {
        window.draw(mineSprite);
    }
    else if (isRevealed && adjacentMines > 0) {
        window.draw(numberSprite);
    }
}

void Tile::SetPosition(float x, float y) {
    numberSprite.setPosition(x, y);
    mineSprite.setPosition(x, y);
    tileSprite.setPosition(x, y);
    flagSprite.setPosition(x, y);
}

void Tile::Flag(MineCounter& mineCounter) {
    if (!isRevealed) {
        if (isFlagged) {
            isFlagged = false;
            mineCounter.Add();
        }
        else {
            isFlagged = true;
            mineCounter.Subtract();
        }
    }
}
