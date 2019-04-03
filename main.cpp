#include <iostream>
#include <map>
#include "src/Board.hpp"
#include "src/SpritesLoader.hpp"


using namespace std;
using namespace ChessCore;
using namespace sf;


const int board_size = 800;
const int x_0 = 30, y_0 = 30;

int main(int argc, char const *argv[])
{	

	SpritesLoader sl("assets/board.png", "assets/figures.png");
	map<FigureType, map<PlayerType, MySprite> > sprites = sl.m_sprites;

	Sprite s = sl.m_board;

	RenderWindow window(VideoMode(board_size, board_size), "Game");

	Board brd(sprites);

	bool isPressed = false;

	int x_start, y_start, x_end, y_end;

	while (window.isOpen())
	{


		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);

		sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && 
            	s.getGlobalBounds().contains(pos.x, pos.y) && 
            	((pos.x - 20) >=0 && (pos.y - 20) >= 0))
            {
            	//cout << (int(pos.x - 20) / 100) << " " << (int(pos.y - 20) / 100) << endl;
            	if(!isPressed)
            	{
            		isPressed = true;
            		x_start = (int(pos.x - 20) / 100);
            		y_start = (int(pos.y - 20) / 100);
            		cout << "X_start = " << x_start << " y_start = " << y_start << endl;
            	} else
            	{
            		isPressed = false;
            		x_end = (int(pos.x - 20) / 100);
            		y_end = (int(pos.y - 20) / 100);
            		cout << "X_end = " << x_start << " y_end = " << y_end << endl;
            		swap(brd.m_board[y_start][x_start], brd.m_board[y_end][x_end]);
            		Vector2f _pos1 = brd.m_board[y_start][x_start].m_sprite.m_sprite.getPosition();
            		Vector2f _pos2 = brd.m_board[y_end][x_end].m_sprite.m_sprite.getPosition();
            		brd.m_board[y_start][x_start].m_sprite.m_sprite.setPosition(_pos2);
            		brd.m_board[y_end][x_end].m_sprite.m_sprite.setPosition(_pos1);
            	}
            }

        }
           

		window.clear();
		window.draw(s);

		for(int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				window.draw(brd.m_board[i][j].m_sprite.m_sprite);
			}
		}
		window.display();

	}

	return 0;
}