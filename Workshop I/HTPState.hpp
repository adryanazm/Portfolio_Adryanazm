#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Sonar
{
	class HTPState : public State
	{
	public:
		HTPState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _HTPbackground;
		sf::Sprite _BTMButton;
		

	};
}