#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "GameStateTwo.hpp"
#include "HTPState.hpp"

#include <iostream>

namespace Sonar
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("Level One Button", LEVELONE_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Level Two Button", LEVELTWO_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("HTP Button", HTP_BUTTON_FILEPATH);
	

		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_leveloneButton.setTexture(this->_data->assets.GetTexture("Level One Button"));
		_leveltwoButton.setTexture(this->_data->assets.GetTexture("Level Two Button"));
		_HTPButton.setTexture(this->_data->assets.GetTexture("HTP Button"));
	

		_title.setPosition(280, 100);
		_leveloneButton.setPosition(520, 400);
		_leveltwoButton.setPosition(520, 460);
		_HTPButton.setPosition(520, 520);
		
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_leveloneButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
			if (this->_data->input.IsSpriteClicked(this->_leveltwoButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new GameStateTwo(_data)), true);
			}
			if (this->_data->input.IsSpriteClicked(this->_HTPButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new HTPState(_data)), true);
			}
	
		}
	}

	void MainMenuState::Update(float dt)
	{

	}

	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_leveloneButton);
		this->_data->window.draw(this->_leveltwoButton);
		this->_data->window.draw(this->_HTPButton);

		this->_data->window.display();
	}
}