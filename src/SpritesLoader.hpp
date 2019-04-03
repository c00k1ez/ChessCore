#ifndef SPRITESLOADER_HPP
#define SPRITESLOADER_HPP

#include "BaseTypes.hpp"
#include <string>
#include <map>


namespace  ChessCore
{
	
	class SpritesLoader
	{
	public:

		SpritesLoader(const std::string &board_file, 
					  const std::string &chess_file);


		std::map<FigureType, std::map<PlayerType, MySprite> > getSprites();

		~SpritesLoader();
		sf::Sprite m_board;
		std::map<FigureType, std::map<PlayerType, MySprite> > m_sprites;

	private:
		
		sf::Texture b_txt;
		sf::Texture c_txt; 


	};

}

#endif