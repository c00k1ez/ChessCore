#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <SFML/Graphics.hpp>


namespace ChessCore 
{

	typedef struct 
	{
		
		int x; // x == row
		int y; // y == column

	} FigureCoordinates;

	typedef struct 
	{
		
		int x;
		int y;

	} FieldCoordinates;

	class MySprite 
	{
	public:
		MySprite(sf::Sprite t_sprite);
		MySprite();
		~MySprite();
		sf::Sprite m_sprite;
		
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

}

#endif