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

		~Figure();

	private:
		FigureCoordinates m_coords;
		MySprite m_sprite;
		FigureType m_type;
		PlayerType m_player;
		
	};

}