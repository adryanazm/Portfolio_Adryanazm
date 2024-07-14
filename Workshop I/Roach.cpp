#include "Roach.hpp"

namespace Sonar
{
	Roach::Roach(GameDataRef data) : _data(data)
	{
		_animationIterator = 0;

		_animationFrames.push_back(this->_data->assets.GetTexture("Roach Frame 1"));
		_animationFrames.push_back(this->_data->assets.GetTexture("Roach Frame 2"));
		_animationFrames.push_back(this->_data->assets.GetTexture("Roach Frame 3"));
		_animationFrames.push_back(this->_data->assets.GetTexture("Roach Frame 4"));

		_roachSprite.setTexture(_animationFrames.at(_animationIterator));

		_roachSprite.setPosition((_data->window.getSize().x / 4) - (_roachSprite.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_roachSprite.getGlobalBounds().height / 2));

		_roachState = ROACH_STATE_STILL;

		sf::Vector2f origin = sf::Vector2f(_roachSprite.getGlobalBounds().width / 2, _roachSprite.getGlobalBounds().height / 2);

		_roachSprite.setOrigin(origin);

		_rotation = 0;
	}

	Roach::~Roach()
	{
	}

	void Roach::Draw()
	{
		_data->window.draw(_roachSprite);
	}

	void Roach::Animate(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > ROACH_ANIMATION_DURATION / _animationFrames.size())
		{
			if (_animationIterator < _animationFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}

			_roachSprite.setTexture(_animationFrames.at(_animationIterator));

			_clock.restart();
		}
	}

	void Roach::Update(float dt)
	{
		if (ROACH_STATE_FALLING == _roachState)
		{
			_roachSprite.move(1, GRAVITY * dt);
			_rotation += ROTATION_SPEED * dt;

			if (_rotation > 25.0f)
			{
				_rotation = 25.0f;
			}

			_roachSprite.setRotation(_rotation);
		}
		else if (ROACH_STATE_WALKING == _roachState)
		{
			_roachSprite.move(0, -WALKING_SPEED * dt);
			_rotation -= ROTATION_SPEED * dt;

			if (_rotation < -25.0f)
			{
				_rotation = -25.0f;
			}

			_roachSprite.setRotation(_rotation);
		}

		if (_movementClock.getElapsedTime().asSeconds() > WALKING_DURATION)
		{
			_movementClock.restart();
			_roachState = ROACH_STATE_FALLING;
		}
	}

	void Roach::Tap()
	{
		_movementClock.restart();
		_roachState = ROACH_STATE_WALKING;
	} 

	const sf::Sprite &Roach::GetSprite() const
	{
		return _roachSprite;
	}
}