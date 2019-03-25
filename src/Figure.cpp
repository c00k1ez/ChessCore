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



}