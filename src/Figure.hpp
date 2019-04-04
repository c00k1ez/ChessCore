#include "BaseTypes.hpp"

namespace  ChessCore
{
	
	class Figure
	{
		
	public:
		Figure(const FigureCoordinates &t_coords,
			   const MySprite &t_sprite,
			   const FigureType &t_type,
			   const PlayerType &t_player);

		FigureCoordinates getCoords() const;

		void setCoords(const FigureCoordinates &t_coords);

		void setFieldCoords(const FigureCoordinates &t_field_coords);

		FigureCoordinates getFieldCoords() const;

		FigureType getType() const;

		PlayerType getPlayer() const;
		
		MySprite m_sprite;

		void setType(FigureType t);

		void setPlayer(PlayerType p); 

		~Figure();

	private:
		FigureCoordinates m_coords;
		FigureType m_type;
		PlayerType m_player;
		FigureCoordinates m_field_coords;
		
	};

}