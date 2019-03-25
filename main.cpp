#include <iostream>
#include <map>
#include "src/Board.hpp"

using namespace std;
using namespace ChessCore;

int main(int argc, char const *argv[])
{	
	MySprite _s;
	std::vector<FigureType> v {PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING, EMPTY};
	std::map<FigureType, MySprite> map;
	for(int i = 0; i < v.size(); ++i)
	{
		map.insert({v[i], _s});
	}

	Board brd(map);
	brd._print_board_();
	return 0;
}