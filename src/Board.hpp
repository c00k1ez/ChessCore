#include "Figure.hpp"
#include <vector>
#include <map>

namespace ChessCore
{
	
	class Board
	{

	public:
		Board(std::map<FigureType, MySprite> t_sprites);
		~Board();

		void _print_board_();

	private:
		std::vector< std::vector<Figure> > m_board;
		
	};

}