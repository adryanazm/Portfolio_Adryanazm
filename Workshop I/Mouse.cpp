#include "Mouse.hpp"

namespace Sonar
{
	Mouse::Mouse(GameDataRef data) : _data(data)
	{
		_animationIterator = 0;

		_animationFrames.push_back(this->_data->assets.GetTexture("Mouse Frame 1"));
		_animationFrames.push_back(this->_data->assets.GetTexture("Mouse Frame 2"));
		_animationFrames.push_back(this->_data->assets.GetTexture("Mouse Frame 3"));
		_animationFrames.push_back(this->_data->assets.GetTexture("Mouse Frame 4"));

		_mouseSprite.setTexture(_animationFrames.at(_animationIterator));

		_mouseSprite.setPosition(sf::Vector2f(-40, 200));

		_mouseState = MOUSE_STATE_STILL;

		sf::Vector2f origin = sf::Vector2f(_mouseSprite.getGlobalBounds().width / 2, _mouseSprite.getGlobalBounds().height / 2);

		_mouseSprite.setOrigin(origin);
	}

	Mouse::~Mouse()
	{
	}

	void Mouse::Draw()
	{
		_data->window.draw(_mouseSprite);
	}

	void Mouse::Animate(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > MOUSE_ANIMATION_DURATION / _animationFrames.size())
		{
			if (_animationIterator < _animationFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}

			_mouseSprite.setTexture(_animationFrames.at(_animationIterator));

			_clock.restart();
		}
	}

	void Mouse::Update(float dt)
	{
		 if (MOUSE_STATE_WALKING == _mouseState)
		{
			_mouseSprite.move(rand () % + 3, -WALKING_SPEED * dt);
		}
		 else if (MOUSE_STATE_FALLING == _mouseState)
		 {
			 _mouseSprite.move(rand() % + 1, GRAVITY * dt);
		 }

		 if (_movementClock.getElapsedTime().asSeconds() > WALKING_DURATION)
		 {
			 _movementClock.restart();
			 _mouseState = MOUSE_STATE_FALLING;
		 }
	}

	void Mouse::Tap()
	{
		_movementClock.restart();
		_mouseState = MOUSE_STATE_WALKING;
	}

	const sf::Sprite &Mouse::GetSprite() const
	{
		return _mouseSprite;
	}
}
