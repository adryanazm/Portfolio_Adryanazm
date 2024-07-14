#include "Wrapper.hpp"
#include "DEFINITIONS.hpp"

namespace Sonar
{
	Wrapper::Wrapper(GameDataRef data) : _data(data)

	{
		_randomY = this->_data->window.getSize().y;
		_wrapperSpawnYOffset = 0;
	}

	void Wrapper::SpawnBottomWrapper()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Wrapper"));

		sprite.setPosition(this->_data->window.getSize().x, this->_data->window.getSize().y - sprite.getLocalBounds().height - _wrapperSpawnYOffset);

		wrapperSprites.push_back(sprite);
	}


	void Wrapper::SpawnTopWrapper()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Wrapper"));

		sprite.setPosition(this->_data->window.getSize().x, -_wrapperSpawnYOffset);

		wrapperSprites.push_back(sprite);
	}

	void Wrapper::SpawnInvisibleWrapper()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Wrapper"));

		sprite.setPosition(this->_data->window.getSize().x, -_wrapperSpawnYOffset);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		wrapperSprites.push_back(sprite);
	}

	void Wrapper::MoveWrapper(float dt)
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
				float movement = WRAPPER_MOVEMENT_SPEED * dt;

				wrapperSprites.at(i).move(-movement, 0);
			}
		}
	}

	void Wrapper::DrawWrapper()
	{
		for (unsigned short int i = 0; i < wrapperSprites.size(); i++)
		{
			this->_data->window.draw(wrapperSprites.at(i));
		}


	}
	void Wrapper::RandomiseWrapperOffset()
	{
		_wrapperSpawnYOffset = rand() % (_randomY + 1);
	}

	const std::vector<sf::Sprite> &Wrapper::GetSprites() const
	{
		return wrapperSprites;
	}
}