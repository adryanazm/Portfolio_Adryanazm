#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "GameOverStateTwo.hpp"
#include "GameStateTwo.hpp"

#include <iostream>
#include <fstream>

namespace Sonar
{
	GameOverStateTwo::GameOverStateTwo(GameDataRef data, int score) : _data(data), _score(score)
	{

	}

	void GameOverStateTwo::Init()
	{
		std::ifstream readFile;
		readFile.open("Resources/HighscoreTwo.txt");


		if (readFile.is_open())
		{
			while (!readFile.eof())
			{
				readFile >> _highScore;
			}
		}

		std::cout << _highScore << std::endl;

		readFile.close();

		std::ofstream writeFile("Resources/HighscoreTwo.txt");

		if (writeFile.is_open())
		{
			if (_score > _highScore)
			{
				_highScore = _score;
			}

			writeFile << _highScore;
		}

		writeFile.close();

		this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);
		this->_data->assets.LoadTexture("Menu Button", MENU_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Replay Button", REPLAY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
		_gameOverTitle.setTexture(this->_data->assets.GetTexture("Game Over Title"));
		_gameOverContainer.setTexture(this->_data->assets.GetTexture("Game Over Body"));
		_menubutton.setTexture(this->_data->assets.GetTexture("Menu Button"));
		_replaybutton.setTexture(this->_data->assets.GetTexture("Replay Button"));


		_gameOverContainer.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height / 2)));
		_gameOverTitle.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y - (_gameOverTitle.getGlobalBounds().height * 1.2)));

		_scoreText.setFont(this->_data->assets.GetFont("Roach Font"));
		_scoreText.setString(std::to_string(_score));
		_scoreText.setCharacterSize(56);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
		_scoreText.setPosition(sf::Vector2f(560, 390));

		_highScoreText.setFont(this->_data->assets.GetFont("Roach Font"));
		_highScoreText.setString(std::to_string(_highScore));
		_highScoreText.setCharacterSize(56);
		_highScoreText.setFillColor(sf::Color::White);
		_highScoreText.setOrigin(sf::Vector2f(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2));
		_highScoreText.setPosition(sf::Vector2f(710, 390));

		_menubutton.setPosition(490, 450);
		_replaybutton.setPosition(490, 500);
	}

	void GameOverStateTwo::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_menubutton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
			if (this->_data->input.IsSpriteClicked(this->_replaybutton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new GameStateTwo(_data)), true);
			}

		}
	}

	void GameOverStateTwo::Update(float dt)
	{

	}

	void GameOverStateTwo::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		_data->window.draw(_gameOverTitle);
		_data->window.draw(_gameOverContainer);

		_data->window.draw(_scoreText);
		_data->window.draw(_highScoreText);

		_data->window.draw(_menubutton);
		_data->window.draw(_replaybutton);

		this->_data->window.display();
	}
}