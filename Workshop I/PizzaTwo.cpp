#include "PizzaTwo.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Sonar
{
	PizzaTwo::PizzaTwo(GameDataRef data) : _data(data)
	{
		_randomY = this->_data->window.getSize().y;
		_pizzaSpawnYOffSet;
	}

	void PizzaTwo::SpawnPizza()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Pizza"));

		sprite.setPosition(this->_data->window.getSize().x, this->_data->window.getSize().y - sprite.getLocalBounds().height - _pizzaSpawnYOffSet);

		pizzaSprites.push_back(sprite);
	}

	void PizzaTwo::SpawnInvisiblePizza()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Pizza"));

		sprite.setPosition(this->_data->window.getSize().x, _pizzaSpawnYOffSet);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		pizzaSprites.push_back(sprite);
	}

	void PizzaTwo::SpawnScoringPizza()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Scoring Pizza"));

		sprite.setPosition(this->_data->window.getSize().x, 0);

		scoringPizza.push_back(sprite);
	}

	void PizzaTwo::MovePizza(float dt)
	{
		for (int i = 0; i < pizzaSprites.size(); i++)
		{
			if (pizzaSprites.at(i).getPosition().x < 0 - pizzaSprites.at(i).getLocalBounds().width)
			{
				pizzaSprites.erase(pizzaSprites.begin() + i);
			}
			else
			{
				sf::Vector2f position = pizzaSprites.at(i).getPosition();
				float movement = PIZZA_MOVEMENT_SPEED_TWO * dt;

				pizzaSprites.at(i).move(-movement, 0);
			}
		}

		for (int i = 0; i < scoringPizza.size(); i++)
		{
			if (scoringPizza.at(i).getPosition().x < 0 - scoringPizza.at(i).getLocalBounds().width)
			{
				scoringPizza.erase(scoringPizza.begin() + i);
			}

		}
	}
	void PizzaTwo::PizzaCollision()
	{
		for (unsigned short int i = 0; i < pizzaSprites.size(); i++)
		{
			pizzaSprites.erase(pizzaSprites.begin() + i);
		}
	}
	void PizzaTwo::DrawPizza()
	{
		for (unsigned short int i = 0; i < pizzaSprites.size(); i++)
		{
			this->_data->window.draw(pizzaSprites.at(i));
		}

	}

	void PizzaTwo::RandomisePizzaOffSet()
	{
		_pizzaSpawnYOffSet = rand() % (_randomY + 1);

	}
	const std::vector<sf::Sprite> &PizzaTwo::GetSprites() const
	{
		return pizzaSprites;
	}

	std::vector<sf::Sprite> &PizzaTwo::GetScoringSprites()
	{
		return scoringPizza;
	}
}