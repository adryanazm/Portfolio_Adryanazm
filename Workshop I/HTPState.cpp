#include <sstream>
#include "DEFINITIONS.hpp"
#include "HTPState.hpp"
#include "MainMenuState.hpp"


#include <iostream>

namespace Sonar
{
	HTPState::HTPState(GameDataRef data) : _data(data)
	{

	}

	void HTPState::Init()
	{
		this->_data->assets.LoadTexture("Background", GAME_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("HTP Background", HTP_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("BTM Button", BTM_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Background"));
		_HTPbackground.setTexture(this->_data->assets.GetTexture("HTP Background"));
		_BTMButton.setTexture(this->_data->assets.GetTexture("BTM Button"));

		_HTPbackground.setPosition(280, 20);
		_BTMButton.setPosition(470, 540);

	}

	void HTPState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_BTMButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}

		}
	}

	void HTPState::Update(float dt)
	{

	}

	void HTPState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Transparent);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_HTPbackground);
		this->_data->window.draw(this->_BTMButton);

		this->_data->window.display();
	}
}