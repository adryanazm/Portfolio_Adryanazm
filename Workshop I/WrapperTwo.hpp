
#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Sonar
{
	class WrapperTwo
	{
	public:
		WrapperTwo(GameDataRef data);

		void SpawnBottomWrapper();
		void SpawnTopWrapper();
		void SpawnInvisibleWrapper();
		void MoveWrapper(float dt);
		void DrawWrapper();
		void RandomiseWrapperOffset();

		const std::vector<sf::Sprite> &GetSprites() const;

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> wrapperSprites;
		std::vector<sf::Sprite> wrapperToDelete;

		int _randomY;
		int _wrapperSpawnYOffset;
	};
}