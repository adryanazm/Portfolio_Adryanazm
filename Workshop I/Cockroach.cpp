#include "Cockroach.hpp"

namespace Sonar
{
	Cockroach::Cockroach(GameDataRef data) : _data(data)
	{
		_cockroachSprite.setTexture(this->_data->assets.GetTexture("Cockroach Frame 1"));
	}

	Cockroach::~Cockroach()
	{
	}

	void Cockroach::Draw()
	{
		_data->window.draw(_cockroach);
	}
}