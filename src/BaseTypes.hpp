#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace ChessCore 
{

	typedef struct 
	{
		
		int x; // x == row
		int y; // y == column

	} FigureCoordinates;

	class MySprite 
	{
	public:
		MySprite();
		~MySprite();
		
	};

	enum FigureType
	{
		PAWN,
		ROOK,
		KNIGHT,
		BISHOP,
		QUEEN,
		KING,
		EMPTY
	};

	enum PlayerType
	{
		Player_1,
		Player_2,
		None_player
	};

	template <class T> 
	void swap (T &t_a, T &t_b)
	{
		T tmp = t_a;
		t_a = t_b;
		t_b = t_a;
	}

}

#endif