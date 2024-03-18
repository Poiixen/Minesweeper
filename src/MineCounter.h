#pragma once
#include "Textures.h"

class MineCounter {
    public:
        bool Negative;
        MineCounter(int rows, int mines);
        void AssignCountValue(const std::string& rhs);
        void Add();
        void Subtract();
        void Draw(sf::RenderWindow& window);
        void UpdateTextures();
        void SetRectangles(char countDigit, sf::Sprite& sprite);
        
    private:
        sf::Sprite sprites[3];
        std::string count;
        const sf::Vector2i digits[11] = { sf::Vector2i(0, 0), sf::Vector2i(21, 0), sf::Vector2i(42, 0), sf::Vector2i(63, 0), sf::Vector2i(84, 0), sf::Vector2i(105, 0), sf::Vector2i(126, 0), sf::Vector2i(147, 0),
            sf::Vector2i(168, 0), sf::Vector2i(189, 0), sf::Vector2i(210, 0) };
        const sf::Vector2i size;
        sf::Sprite hyphen;
};
