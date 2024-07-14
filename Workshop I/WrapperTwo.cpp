#include "WrapperTwo.hpp"
#include "DEFINITIONS.hpp"

namespace Sonar
{
	WrapperTwo::WrapperTwo(GameDataRef data) : _data(data)

	{
		_randomY = this->_data->window.getSize().y;
		_wrapperSpawnYOffset = 0;
	}

	void WrapperTwo::SpawnBottomWrapper()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Wrapper"));

		sprite.setPosition(this->_data->window.getSize().x, this->_data->window.getSize().y - sprite.getLocalBounds().height - _wrapperSpawnYOffset);

		wrapperSprites.push_back(sprite);
	}


	void WrapperTwo::SpawnTopWrapper()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Wrapper"));

		sprite.setPosition(this->_data->window.getSize().x, -_wrapperSpawnYOffset);

		wrapperSprites.push_back(sprite);
	}

	void WrapperTwo::SpawnInvisibleWrapper()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Wrapper"));

		sprite.setPosition(this->_data->window.getSize().x, -_wrapperSpawnYOffset);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		wrapperSprites.push_back(sprite);
	}

	void WrapperTwo::MoveWrapper(float dt)
	{
		for (unsigned short int i = 0; i < wrapperSprites.size(); i++)
		{
			if (wrapperSprites.at(i).getPosition().x < 0 - wrapperSprites.at(i).getLocalBounds().width)
			{
				wrapperSprites.erase(wrapperSprites.begin() + i);
			}
			else
			{
				sf::Vector2f position = wrapperSprites.at(i).getPosition();
				float movement = WRAPPER_MOVEMENT_SPEED_TWO * dt;

				wrapperSprites.at(i).move(-movement, 0);
			}
		}
	}

	void WrapperTwo::DrawWrapper()
	{
		for (unsigned short int i = 0; i < wrapperSprites.size(); i++)
		{
			this->_data->window.draw(wrapperSprites.at(i));
		}


	}
	void WrapperTwo::RandomiseWrapperOffset()
	{
		_wrapperSpawnYOffset = rand() % (_randomY + 1);
	}

	const std::vector<sf::Sprite> &WrapperTwo::GetSprites() const
	{
		return wrapperSprites;
	}
}