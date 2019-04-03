#include "SpritesLoader.hpp"
#include <iostream>


namespace ChessCore
{
	
	SpritesLoader::SpritesLoader(const std::string &board_file, 
					  const std::string &chess_file)
	{

		sf::Image img; 
		if(!img.loadFromFile(board_file))
		{
			std::cout << "ERROR LOAD FILE !\n"; 
		}

		img.createMaskFromColor(sf::Color(41, 33, 59));
		b_txt.loadFromImage(img);
		b_txt.setSmooth(true);
		
		m_board.setTexture(b_txt);
		m_board.setTextureRect(sf::IntRect(0, 0, 800, 800));
		sf::Image c_img; c_img.loadFromFile(chess_file);
		c_txt.loadFromImage(c_img);
		c_txt.setSmooth(true);
		std::vector<FigureType> v {ROOK, KNIGHT, BISHOP, QUEEN, KING, PAWN, EMPTY};
		std::vector<PlayerType> player {Player_1, Player_2, None_player};

		/*
		Sprites for first 6 (first 5 + pawns) figures for first and second player. 
		*/
		for(int i = 0; i < 6; ++i)
		{
			std::map<PlayerType, MySprite> m;
			sf::Sprite s1, s2;
			s1.setTexture(c_txt); s2.setTexture(c_txt);
			if(i != 5)
			{
				s1.setTextureRect(sf::IntRect(i * 100, 0, 100, 100));
				s2.setTextureRect(sf::IntRect(i * 100, 300, 100, 100));
			} else
			{
				s1.setTextureRect(sf::IntRect(0, 100, 100, 100));
				s2.setTextureRect(sf::IntRect(0, 200, 100, 100));
			}
			MySprite _s1(s1), _s2(s2);
			m.insert({player[0], _s1});
			m.insert({player[1], _s2});
			m_sprites.insert(std::make_pair(v[i], m));
		}
		sf::Sprite empty_s;
		MySprite tmp(empty_s);
		std::map<PlayerType, MySprite> temp_map = {{player[2], tmp}};
		m_sprites.insert(std::make_pair(v[6], temp_map));

	}
	
	SpritesLoader::~SpritesLoader()
	{



	}

}