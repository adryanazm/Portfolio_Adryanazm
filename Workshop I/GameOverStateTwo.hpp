#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Sonar
{
	class GameOverStateTwo : public State
	{
	public:
		GameOverStateTwo(GameDataRef data, int score);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _gameOverTitle;
		sf::Sprite _gameOverContainer;

		sf::Sprite _menubutton;
		sf::Sprite _replaybutton;

		sf::Text _scoreText;
		sf::Text _highScoreText;

		int _score;
		int _highScore;

	};
}