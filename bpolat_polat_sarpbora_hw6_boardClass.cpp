#include "bpolat_polat_sarpbora_hw6_boardClassHeader.h"
#include <iostream>
#include <string>

using namespace std;

template <class itemType> //constructor of board class
Board<itemType>::Board(int r,int c): myCol(c), myRow(r)
{
	myBoard = new matrixStruct<itemType> *[r];

	for (int i = 0; i <r ; i++) //creating matrix that dynammicly created array.
	{
		myBoard[i]=new matrixStruct<itemType>[c];		
	}
}
template <class itemType> //detructor
Board<itemType>::~Board()
{
	for (int k = 0; k< myRow; k++)
	{
		delete [] myBoard[k]; //delete each row of myboard
		myBoard[k]=NULL;
	}
	delete [] myBoard;
	myBoard=NULL;
}

template <class itemType>
void Board<itemType>::readBoardFromFile(ifstream &input) //getting ifstream object (it has already openned in main), each line take realted value and equate status to false.
{
	string lines;
	int Row=0;
	while (getline(input, lines))
	{	
		itemType type;
		istringstream ist(lines);

		for (int i = 0; ist >> type; i++)
		{
			myBoard[Row][i].value = type;
			myBoard[Row][i].status = false;
		}
		Row++;
	}
}

template <class itemType>
void Board<itemType>::closeCard(int row, int col) //changing cards status
{
	myBoard[row][col].status=false;
}

template <class itemType>
int Board<itemType>::getRow() //getting row value from antoher cpp file
{
	return myRow;
}

template <class itemType>
int Board<itemType>::getColumn() //getting column value from antoher cpp file
{
	return myCol;
}

template <class itemType>
void Board<itemType>::displayBoard() //displays the board values
{    
	for(int i=0; i<myRow; i++)
    {
		for(int j=0; j<myCol; j++)
        {
			if (myBoard[i][j].status)
			{
				cout<<myBoard[i][j].value<<" "; //if card is open show value
			}
			else
			{
				cout<<"X "; //if it is not open, show 'X'
			}
        }
        cout << endl;  
	}
}

template <class itemType>
matrixStruct<itemType>** Board<itemType>::getBoard() //reaching board from another file
{
	return myBoard;
}

template <class itemType>
bool Board<itemType>::getStatus(int r, int c) //geting correlated coordinates status wether it is false or not
{
	return myBoard[r][c].status;
}





