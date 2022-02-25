#include <iostream>

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char current_marker;
char current_player;
void drawBoard()
{
	std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

void placeMarker(int slot)
{
	int row;
	int col;
	if (slot % 3 == 0)
	{
		row = (slot / 3) - 1;
		col = 2;
	}
	else 
	{
		row = slot / 3;
		col = slot % 3 - 1;
	}
	if (board[row][col] != 'X' && board[row][col] != 'O')
	{
		board[row][col] = current_marker;
		if (current_marker == 'X')
		{
			current_marker = 'O';
		}
		else
		{
			current_marker = 'X';
		}
	}

}
bool winner()
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
	}
}

int main() {
	int place_in;
	char place_ch;
	drawBoard();
	std::cout << std::endl << std::endl;
	current_marker = 'X';
	bool flag = true;
	int index;

	while (flag)
	{
		std::cout << "which number you want to place in ?" << std::endl;
		do
		{
			scanf_s(" %c", &place_ch,1);
		} while (!isdigit(place_ch));
		place_in = ((int)place_ch - 48);
		current_player = current_marker;
		placeMarker(place_in);
		std::system("CLS");
		drawBoard();
		if (winner() == true)
		{
			flag = false;
			std::cout << "\n";
			std::cout << R"( 
     _______________
    |@@@@|     |####|
    |@@@@|     |####|
    |@@@@|     |####|
    \@@@@|     |####/
     \@@@|     |###/
      `@@|_____|##'
           (O)
        .-'''''-.
      .'  * * *  `.
     :  *       *  :
    : ~)";
			std::cout <<"\t    " << current_player << "     ";
			std::cout<< R"(~ :
    : ~   W I N   ~ :
     :  *       *  :
      `.  * * *  .'
        `-.....-'                                           | |
)";
		}	
	}

	return 0;
}