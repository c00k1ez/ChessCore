#include "Behavior.hpp"
#include <cmath>

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
	    FigureCoordinates f_crd_a = a.getFieldCoords();
	    FigureCoordinates f_crd_b = b.getFieldCoords();
	    a.setFieldCoords(f_crd_b);
	    b.setFieldCoords(f_crd_a);

	    FigureCoordinates crd_a = a.getCoords();
	    FigureCoordinates crd_b = b.getCoords();
	    a.setCoords(crd_b);
	    b.setCoords(crd_a);

	}

	bool Behavior::check(Figure &a, Figure &b)
	{

		int direction = (a.getPlayer() == Player_1) ? 1 : -1;
		int flag = false;
		FigureType fig = a.getType();
		FigureCoordinates crd_a = a.getCoords();
		FigureCoordinates crd_b = b.getCoords();

		switch(fig)
		{
			case PAWN:
				if((crd_b.x - crd_a.x) == direction &&
				   (crd_b.y - crd_a.y) == 0)
				flag = true;
				break;

			
		}

		return flag;

	}

	bool Behavior::canEat(Figure &a, Figure &b)
	{
		int direction = (a.getPlayer() == Player_1) ? 1 : -1;
		int flag = false;
		FigureType fig = a.getType();
		FigureCoordinates crd_a = a.getCoords();
		FigureCoordinates crd_b = b.getCoords();

		switch(fig)
		{
			case PAWN:
				if((crd_b.x - crd_a.x) == direction &&
				   std::abs(crd_b.y - crd_a.y) == 1 &&
				   b.getType() != KING)
				flag = true;
				break;
		}

		return flag;
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
