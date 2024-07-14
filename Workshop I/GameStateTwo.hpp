#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "ShirtTwo.hpp"
#include "WrapperTwo.hpp"
#include "PizzaTwo.hpp"
#include "Roach.hpp"
#include "Mouse.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "HUD.hpp"

namespace Sonar
{
	class GameStateTwo : public State
	{
	public:
		GameStateTwo(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);


	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _backbutton;

		ShirtTwo *shirt;
		WrapperTwo *wrapper;
		PizzaTwo *pizza;
		Roach *roach;
		Mouse *mouse;
		Collision collision;
		Flash *flash;
		HUD *hud;

		sf::Clock clock;

		int _gameStatetwo;

		sf::RectangleShape _gameOverFlash;
		bool _flashOn;

		int _score;

		sf::SoundBuffer _hitSoundBuffer;
		sf::SoundBuffer _eatSoundBuffer;

		sf::Sound _hitSound;
		sf::Sound _eatSound;

		sf::Music _BGMGame;
	};
}