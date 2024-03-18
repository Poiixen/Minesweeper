#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

using namespace std;

class Textures {
	public:
		static sf::Texture& Get(string name);
		static void Clear();

	private:
		static unordered_map<string, sf::Texture> textures;
		static void LoadTexture(string name);
};

//reference from Proffesor Fox. "A class to Manage sf::Texture Objects"