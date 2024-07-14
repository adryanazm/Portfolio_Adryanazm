#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

#include <vector>

namespace Sonar
{
	class Roach
	{
	public:
		Roach(GameDataRef data);
		~Roach();

		void Draw();

		void Animate(float dt);

		void Update(float dt);

		void Tap();

		const sf::Sprite &GetSprite() const;

	private:
		GameDataRef _data;

		sf::Sprite _roachSprite;
		std::vector<sf::Texture> _animationFrames;

		unsigned int _animationIterator;

		sf::Clock _clock;

		sf::Clock _movementClock;

		int _roachState;

		float _rotation;

	};
}
