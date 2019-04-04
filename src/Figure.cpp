#include "Figure.hpp"

namespace ChessCore
{

	Figure::Figure(const FigureCoordinates &t_coords,
			   	   const MySprite &t_sprite,
			   	   const FigureType &t_type,
			       const PlayerType &t_player)
		: m_coords(t_coords), m_sprite(t_sprite), m_type(t_type), m_player(t_player)
		{

		}

	Figure::~Figure()
	{
		
	}

	FigureCoordinates Figure::getCoords() const
	{
		return m_coords;
	}


	void Figure::setCoords(const FigureCoordinates &t_coords) 
	{
		m_coords = t_coords;
	}

	void Figure::setFieldCoords(const FigureCoordinates &t_field_coords)
	{
		m_field_coords = t_field_coords;
	}

	FigureCoordinates Figure::getFieldCoords() const
	{
		return m_field_coords;
	}

	FigureType Figure::getType() const
	{
		return m_type;
	}

	PlayerType Figure::getPlayer() const
	{
		return m_player;
	}

	void Figure::setType(FigureType t)
	{
		m_type = t;
	}

	void Figure::setPlayer(PlayerType p)
	{
		m_player = p;
	}

}