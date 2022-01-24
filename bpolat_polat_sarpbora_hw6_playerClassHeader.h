#ifndef BPOLAT_POLAT_SARPBORA_HW6_PLAYERCLASSHEADER
#define BPOLAT_POLAT_SARPBORA_HW6_PLAYERCLASSHEADER

#include "bpolat_polat_sarpbora_hw6_boardClassHeader.h"
#include <iostream>

using namespace std;
template <class itemType>
class Player
{
	public:
		Player(Board<itemType> &playerboard); //constructor
		const itemType &openCard(int row, int col); //it opens card and The function returns the value of the card
		void increaseNumberOfSuccess(); //function which keeps the number of successful matches (i.e. the current score) of the player, by one.
		bool validMove(int,int); //The function checks whether the row and column values are valid or not, and returns the validation result in an appropriate type
		int getNumberOfSuccess(); //function which keeps the number of successful matches (i.e. the current score) of the player.
		

	private:
		Board<itemType> & board; //board object from board.cpp. & means the actual board not coppy
		int score; //private mem

		
};

#include "bpolat_polat_sarpbora_hw6_PlayerClass.cpp"
#endif