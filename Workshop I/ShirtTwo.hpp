
#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Sonar
{
	class ShirtTwo
	{
	public:
		ShirtTwo(GameDataRef data);

		void SpawnBottomShirt();
		void SpawnTopShirt();
		void SpawnInvisibleShirt();
		void MoveShirt(float dt);
		void DrawShirt();
		void RandomiseShirtOffset();

		const std::vector<sf::Sprite> &GetSprites() const;

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> shirtSprites;
		std::vector<sf::Sprite> shirtToDelete;

		int _randomY;
		int _shirtSpawnYOffset;
	};
}