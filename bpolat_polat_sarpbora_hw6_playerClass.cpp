#include "bpolat_polat_sarpbora_hw6_boardClassHeader.h"
#include "bpolat_polat_sarpbora_hw6_playerClassHeader.h"
#include<iostream>
#include<string>

using namespace std;

template <class itemType> //constructor. Inýtally score=0 and take actual board to playerboard
Player<itemType>::Player(Board<itemType> &playerboard): board(playerboard), score(0)
{}

template <class itemType>
const itemType& Player<itemType>::openCard(int row, int col)
{
	board.getBoard()[row][col].status = true; //open card. put true value to status
	return board.getBoard()[row][col].value; //return the value of opened card

}

template <class itemType>
bool Player<itemType>::validMove(int row, int col) //checks whether the row and column values are valid or not, and returns the validation result in an appropriate type
{
	return row >= 0 && row < board.getRow() && col >= 0 && col < board.getColumn() && !board.getStatus(row,col);
}

template <class itemType>
void Player<itemType>::increaseNumberOfSuccess() //increase scor of the specific player after success.
{
	score++;
}
template <class itemType>
int Player<itemType>::getNumberOfSuccess()//return players score
{
	return score;
}




