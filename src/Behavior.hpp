#ifndef BEHAVIOR_HPP
#define BEHAVIOR_HPP

#include "Board.hpp"

namespace ChessCore
{

	class Behavior
	{
	public:
		Behavior();
		~Behavior();

		static void mySwap(Figure &a, Figure &b);

		static bool check(Figure &a, Figure &b);

		static bool canEat(Figure &a, Figure &b);

		static void deleteFigure(Figure &b, MySprite sprite);
		
	};

}

#endif