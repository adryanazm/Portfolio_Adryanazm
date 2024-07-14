#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameStateTwo.hpp"
#include "MainMenuState.hpp"
#include "GameOverStateTwo.hpp"
#include <vector>

#include <iostream>

namespace Sonar
{
	GameStateTwo::GameStateTwo(GameDataRef data) : _data(data)
	{

	}

	void GameStateTwo::Init()
	{
		if (!_BGMGame.openFromFile(BGM_SOUND_FILEPATH))
		{
			std::cout << "error, could not located music file" << std::endl;
		}

		_BGMGame.play();
		_BGMGame.setLoop(true);

		if (!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH))
		{
			std::cout << "Error Loading Hit Sound Effect" << std::endl;
		}
		_hitSound.setBuffer(_hitSoundBuffer);

		if (!_eatSoundBuffer.loadFromFile(EAT_SOUND_FILEPATH))
		{
			std::cout << "Error Loading Eat Sound Effect" << std::endl;
		}
		_eatSound.setBuffer(_eatSoundBuffer);

		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Back Button", BACK_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Shirt", SHIRT_FILEPATH);
		this->_data->assets.LoadTexture("Wrapper", WRAPPER_FILEPATH);
		this->_data->assets.LoadTexture("Pizza", PIZZA_FILEPATH);
		this->_data->assets.LoadTexture("Roach Frame 1", ROACH_FRAME_1_FILEPATH);
		this->_data->assets.LoadTexture("Roach Frame 2", ROACH_FRAME_2_FILEPATH);
		this->_data->assets.LoadTexture("Roach Frame 3", ROACH_FRAME_3_FILEPATH);
		this->_data->assets.LoadTexture("Roach Frame 4", ROACH_FRAME_4_FILEPATH);
		this->_data->assets.LoadTexture("Mouse Frame 1", MOUSE_FRAME_1_FILEPATH);
		this->_data->assets.LoadTexture("Mouse Frame 2", MOUSE_FRAME_2_FILEPATH);
		this->_data->assets.LoadTexture("Mouse Frame 3", MOUSE_FRAME_3_FILEPATH);
		this->_data->assets.LoadTexture("Mouse Frame 4", MOUSE_FRAME_4_FILEPATH);
		this->_data->assets.LoadTexture("Scoring Pizza", SCORING_PIZZA_FILEPATH);
		this->_data->assets.LoadFont("Roach Font", ROACH_FONT_FILEPATH);

		shirt = new ShirtTwo(_data);
		wrapper = new WrapperTwo(_data);
		pizza = new PizzaTwo(_data);
		roach = new Roach(_data);
		mouse = new Mouse(_data);
		flash = new Flash(_data);
		hud = new HUD(_data);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
	

		_score = 0;
		hud->UpdateScore(_score);

		_gameStatetwo = GameStates::eReady;
	}

	void GameStateTwo::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_background, sf::Mouse::Left, this->_data->window))
			{
				if (GameStates::eGameOver != _gameStatetwo)
				{
					_gameStatetwo = GameStates::ePlaying;
					roach->Tap();
					mouse->Tap();
				}
			}

		}
	}

	void GameStateTwo::Update(float dt)
	{
		if (GameStates::eGameOver != _gameStatetwo)
		{
			roach->Animate(dt);;
			mouse->Animate(dt);;
		}

		if (GameStates::ePlaying == _gameStatetwo)
		{
			shirt->MoveShirt(dt);
			wrapper->MoveWrapper(dt);
			pizza->MovePizza(dt);


			if (clock.getElapsedTime().asSeconds() > SHIRT_SPAWN_FREQUENCY_TWO)
				if (clock.getElapsedTime().asSeconds() > WRAPPER_SPAWN_FREQUENCY_TWO)
				if (clock.getElapsedTime().asSeconds() > PIZZA_SPAWN_FREQUENCY_TWO)
				{
					shirt->RandomiseShirtOffset();
					wrapper->RandomiseWrapperOffset();

					shirt->SpawnTopShirt();
					shirt->SpawnBottomShirt();
					wrapper->SpawnTopWrapper();
					wrapper->SpawnBottomWrapper();

					pizza->RandomisePizzaOffSet();


					pizza->SpawnPizza();

					clock.restart();

				}

			roach->Update(dt);
			mouse->Update(dt);


			std::vector<sf::Sprite> shirtSprites = shirt->GetSprites();

			for (int i = 0; i < shirtSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(roach->GetSprite(), 0.625f, shirtSprites.at(i), 1.0f))
				{
					_gameStatetwo = GameStates::eGameOver;

					_hitSound.play();
				}
			}
			std::vector<sf::Sprite> wrapperSprites = wrapper->GetSprites();

			for (int i = 0; i < shirtSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(roach->GetSprite(), 0.625f, wrapperSprites.at(i), 1.0f))
				{
					_gameStatetwo = GameStates::eGameOver;

					_hitSound.play();
				}
			}
			sf::Sprite _mouseSprite = mouse->GetSprite();
			if ((collision.CheckSpriteCollision(roach->GetSprite(), 0.625f, _mouseSprite, 1.0f)))
			{
				_gameStatetwo = GameStates::eGameOver;
			}

			if (GameStates::ePlaying == _gameStatetwo)
			{
				std::vector<sf::Sprite> pizzaSprites = pizza->GetSprites();

				for (int i = 0; i < pizzaSprites.size(); i++)
				{
					if (collision.CheckSpriteCollision(roach->GetSprite(), 0.625f, pizzaSprites.at(i), 1.0f))
					{
						pizza->PizzaCollision(); //delete coin from external function
						_eatSound.play();
						_score = _score + 1;

						hud->UpdateScore(_score);
					}
				}
			}
		}

		if (GameStates::eGameOver == _gameStatetwo)
		{
			flash->Show(dt);

			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
			{
				this->_data->machine.AddState(StateRef(new GameOverStateTwo(_data, _score)), true);

				_BGMGame.stop();
			}
		}
	}

	void GameStateTwo::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_backbutton);

		shirt->DrawShirt();
		wrapper->DrawWrapper();
		roach->Draw();
		mouse->Draw();
		pizza->DrawPizza();

		flash->Draw();

		hud->Draw();

		this->_data->window.display();
	}
}