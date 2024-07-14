#include "ShirttWO.hpp"
#include "DEFINITIONS.hpp"

namespace Sonar
{
	ShirtTwo::ShirtTwo(GameDataRef data) : _data(data)

	{
		_randomY = this->_data->window.getSize().y;
		_shirtSpawnYOffset = 0;
	}

	void ShirtTwo::SpawnBottomShirt()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Shirt"));

		sprite.setPosition(this->_data->window.getSize().x, this->_data->window.getSize().y - sprite.getLocalBounds().height - _shirtSpawnYOffset);

		shirtSprites.push_back(sprite);
	}


	void ShirtTwo::SpawnTopShirt()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Shirt"));

		sprite.setPosition(this->_data->window.getSize().x, -_shirtSpawnYOffset);

		shirtSprites.push_back(sprite);
	}

	void ShirtTwo::SpawnInvisibleShirt()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Shirt"));

		sprite.setPosition(this->_data->window.getSize().x, -_shirtSpawnYOffset);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		shirtSprites.push_back(sprite);
	}

	void ShirtTwo::MoveShirt(float dt)
	{
		for (unsigned short int i = 0; i < shirtSprites.size(); i++)
		{
			if (shirtSprites.at(i).getPosition().x < 0 - shirtSprites.at(i).getLocalBounds().width)
			{
				shirtSprites.erase(shirtSprites.begin() + i);
			}
			else
			{
				sf::Vector2f position = shirtSprites.at(i).getPosition();
				float movement = SHIRT_MOVEMENT_SPEED_TWO * dt;

				shirtSprites.at(i).move(-movement, 0);
			}
		}
	}

	void ShirtTwo::DrawShirt()
	{
		for (unsigned short int i = 0; i < shirtSprites.size(); i++)
		{
			this->_data->window.draw(shirtSprites.at(i));
		}


	}
	void ShirtTwo::RandomiseShirtOffset()
	{
		_shirtSpawnYOffset = rand() % (_randomY + 1);
	}

	const std::vector<sf::Sprite> &ShirtTwo::GetSprites() const
	{
		return shirtSprites;
	}
}