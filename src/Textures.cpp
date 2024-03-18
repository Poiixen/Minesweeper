#include "Textures.h"

unordered_map<string, sf::Texture> Textures::textures;

sf::Texture& Textures::Get(string name) {
	if (textures.find(name) == textures.end())
		LoadTexture(name);
	return textures[name];
}

void Textures::LoadTexture(string name) {
	string path = "images/" + name + ".png";
	textures[name].loadFromFile(path);
}

void Textures::Clear() {
	textures.clear();
}
//reference from Proffesor Fox. "A class to Manage sf::Texture Objects"