#include "Board.hpp"
#include <map>
#include <vector>
#include <iostream>

namespace  ChessCore
{
	
	Board::Board(std::map<FigureType, MySprite> t_sprites)
	{	

		std::vector<PlayerType> player {Player_1, Player_2, None_player};
		std::vector< std::vector<Figure> >_backLine(2);
		std::vector< std::vector<Figure> > _pawns(2);

		for(int player_num = 0; player_num < 2; ++player_num)
		{

			std::vector<FigureType> figs {ROOK, KNIGHT, BISHOP, KING, QUEEN, BISHOP, KNIGHT, ROOK};
			for (int i = 0; i < figs.size(); ++i)
			{
				FigureCoordinates crd;
				if(player[player_num] == Player_1)
					crd.x = 0;
				else crd.x = 7;
				crd.y = i;
				Figure _fig(crd, t_sprites[figs[i]], figs[i], player[player_num]);

				_backLine[player_num].push_back(_fig);
			}


			for(int i = 0; i < 8; ++i)
			{
				FigureCoordinates crd;
				if(player[player_num] == Player_1)
					crd.x = 1;
				else crd.x = 6;
				crd.y = i;
				Figure _fig(crd, t_sprites[PAWN], PAWN, player[player_num]);
				_pawns[player_num].push_back(_fig);
			}

		}

		m_board.push_back(_backLine[0]);
		m_board.push_back(_pawns[0]);

		std::vector<Figure> _empty;

		for(int i = 2; i < 6; ++i)
		{
			_empty.clear();
			for(int j = 0; j < 8; ++j)
			{
				FigureCoordinates crd;
				crd.x = i; crd.y = j;
				Figure _fig(crd, t_sprites[EMPTY], EMPTY, player[2]);
				_empty.push_back(_fig);
			}
			m_board.push_back(_empty);
		}

		m_board.push_back(_pawns[1]);
		m_board.push_back(_backLine[1]);

	}

	void Board::_print_board_()
	{
		for(int i = 0; i < 8; ++i)
		{

			for(int j = 0; j < 8; ++j)
			{
				FigureCoordinates crd = m_board[i][j].getCoords();
				std::cout << "(" << crd.x << " " << crd.y << ")\t"; 
			}
			std::cout << std::endl;
		}
	}

	Board::~Board()
	{

	}

}