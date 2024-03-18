#include "MineCounter.h"

MineCounter::MineCounter(int rows, int mines) : size(21, 32), hyphen(Textures::Get("digits")) {
    count = "000";
    Negative = false;

    for (int i = 0; i < 3; ++i) {
        sprites[i].setTexture(Textures::Get("digits"));
        sprites[i].setPosition((i + 1) * 21.0f, rows * 32.0f);
    }

    hyphen.setTextureRect(sf::IntRect(digits[10], size));
    hyphen.setPosition(0.0f, rows * 32.0f);
    AssignCountValue(std::to_string(mines));
    UpdateTextures();
}

void MineCounter::AssignCountValue(const std::string& rhs) {
    count = rhs.length() < 3 ? std::string(3 - rhs.length(), '0') + rhs : rhs;
}

void MineCounter::Add() {
    int countInt = stoi(count);
    countInt = Negative ? countInt - 1 : countInt + 1;
    Negative = countInt == 0 && !Negative;
    AssignCountValue(std::to_string(std::abs(countInt)));
    UpdateTextures();
}

void MineCounter::Subtract() {
    int countInt = stoi(count);
    countInt = Negative ? countInt + 1 : countInt - 1;
    Negative = countInt < 0;
    AssignCountValue(std::to_string(std::abs(countInt)));
    UpdateTextures();
}

void MineCounter::Draw(sf::RenderWindow& window) {
    if (Negative) {
        window.draw(hyphen);
    }

    for (const auto& sprite : sprites) {
        window.draw(sprite);
    }
}

void MineCounter::UpdateTextures() {
    for (int i = 0; i < 3; ++i) {
        SetRectangles(count[i], sprites[i]);
    }
}

void MineCounter::SetRectangles(char countDigit, sf::Sprite& sprite) {
    int digitIndex = countDigit - '0';
    sprite.setTextureRect(sf::IntRect(digits[digitIndex], size));
}


