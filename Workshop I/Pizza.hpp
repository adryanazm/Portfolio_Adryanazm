#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Sonar
{
	class Pizza
	{
	public:
		Pizza(GameDataRef data);

		void SpawnPizza();
		void SpawnInvisiblePizza();
		void SpawnScoringPizza();
		void MovePizza(float dt);
		void PizzaCollision();
		void DrawPizza();
		void RandomisePizzaOffSet();

		const std::vector<sf::Sprite> &GetSprites() const;
		std::vector<sf::Sprite> &GetScoringSprites();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> pizzaSprites;
		std::vector<sf::Sprite> scoringPizza;

		int _randomY;
		int _pizzaSpawnYOffSet;

	};
}