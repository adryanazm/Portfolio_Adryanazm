#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Shirt.hpp"
#include "Wrapper.hpp"
#include "Pizza.hpp"
#include "Roach.hpp"
#include "Mouse.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "HUD.hpp"

namespace Sonar
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);


	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _backbutton;

		Shirt *shirt;
		Pizza *pizza;
		Roach *roach;
		Mouse *mouse;
		Collision collision;
		Flash *flash;
		HUD *hud;

		sf::Clock clock;

		int _gameState;

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
