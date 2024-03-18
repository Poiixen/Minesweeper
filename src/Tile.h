#pragma once
#include "MineCounter.h"

class Tile {
    public:
        bool HasMine;
        Tile();
        bool IsRevealed() const;
        void SetNeighborTiles(Tile**& tiles, int i, int j, int iMax, int jMax);
        void SetPosition(float x, float y);
        void Render(sf::RenderWindow& window, bool showMines);
        void Flag(MineCounter& mineCounter);
        bool Uncover();
        void RevealMine();

    private:
        sf::Sprite flagSprite;
        sf::Sprite numberSprite;
        sf::Sprite mineSprite;
        sf::Sprite tileSprite;
        bool isFlagged;
        bool isRevealed;
        short adjacentMines;
        Tile* neighborTiles[8] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
};
