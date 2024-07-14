#include "Shirt.hpp"
#include "DEFINITIONS.hpp"

namespace Sonar
{
	Shirt::Shirt(GameDataRef data) : _data(data)

	{
		_randomY = this->_data->window.getSize().y;
		_shirtSpawnYOffset = 0;
	}

	void Shirt::SpawnBottomShirt()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Shirt"));

		sprite.setPosition(this->_data->window.getSize().x, this->_data->window.getSize().y - sprite.getLocalBounds().height - _shirtSpawnYOffset);

		shirtSprites.push_back(sprite);
	}


	void Shirt::SpawnTopShirt()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Shirt"));

		sprite.setPosition(this->_data->window.getSize().x, -_shirtSpawnYOffset);

		shirtSprites.push_back(sprite);
	}

	void Shirt::SpawnInvisibleShirt()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Shirt"));

		sprite.setPosition(this->_data->window.getSize().x, -_shirtSpawnYOffset);
		sprite.setColor(sf::Color(0, 0, 0, 0));

	shirtSprites.push_back(sprite);
	}

	void Shirt::MoveShirt(float dt)
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
				float movement = SHIRT_MOVEMENT_SPEED * dt;

				shirtSprites.at(i).move(-movement, 0);
			}
		}
	}

	void Shirt::DrawShirt()
	{
		for (unsigned short int i = 0; i < shirtSprites.size(); i++)
		{
			this->_data->window.draw(shirtSprites.at(i));
		}
		
		
	}
	void Shirt::RandomiseShirtOffset()
	{
		_shirtSpawnYOffset = rand() % (_randomY + 1);
	}

	const std::vector<sf::Sprite> &Shirt::GetSprites() const
	{
		return shirtSprites;
	}
}