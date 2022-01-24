#ifndef BPOLAT_POLAT_SARPBORA_HW6_BOARDCLASSHEADER
#define BPOLAT_POLAT_SARPBORA_HW6_BOARDCLASSHEADER

#include<string>
#include <sstream>
#include <fstream>
#include <istream>
using namespace std;

template <class itemType>
struct matrixStruct //sturct form for holding value and status of each matrix position.
{
	itemType value; // its item type because it may be char or string or int.
	bool status;

	matrixStruct(): value(), status(false)
	{}
	
};
template <class itemType>
class Board
{
	public:
		Board(int row,int col); //constructor
		~Board(); //destructor
		void readBoardFromFile(ifstream &input); //The readBoardFromFile function takes an input file stream as a parameter (hint: use reference parameter) and fills the board matrix by reading the input file.
		void displayBoard(); //It only displays the current state of the board.
		void closeCard(int, int); //This function should change the status of the card to closed.
		int getRow(); //This function returns the number of rows of the board.
		int getColumn(); //This function returns the number of columns of the board.
		matrixStruct<itemType>** getBoard(); //this is to reach board from another cpp that is player.cpp. Since another cpp file can not reach any private member of this class.
		bool getStatus(int, int); //this is to give the status of board from player cpp. Ýt allows us to reach status from another file.


	private:
		int myRow; //private row value of board	
		int myCol; //private column value of board
		matrixStruct<itemType> **myBoard; //private member of board. 

		
};
#include "bpolat_polat_sarpbora_hw6_boardClass.cpp"
#endif
