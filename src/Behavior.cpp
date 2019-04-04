#include "Behavior.hpp"

namespace ChessCore
{

	Behavior::Behavior()
	{

	}

	Behavior::~Behavior()
	{



	}

	void Behavior::mySwap(Figure &a, Figure &b)
	{
		std::swap(a, b);
		sf::Vector2f _pos1 = a.m_sprite.m_sprite.getPosition();
	    sf::Vector2f _pos2 = b.m_sprite.m_sprite.getPosition();
	    a.m_sprite.m_sprite.setPosition(_pos2);
	    b.m_sprite.m_sprite.setPosition(_pos1);
	}

	bool Behavior::check(Figure &a, Figure &b)
	{

		return true;

	}

	bool Behavior::canEat(Figure &a, Figure &b)
	{
		return true;
	}

	void Behavior::deleteFigure(Figure &a, MySprite sprite)
	{
		sf::Vector2f _pos1 = a.m_sprite.m_sprite.getPosition();
		a.m_sprite = sprite;
		a.m_sprite.m_sprite.setPosition(_pos1);
		a.setType(EMPTY);
		a.setPlayer(None_player);
	}

}
