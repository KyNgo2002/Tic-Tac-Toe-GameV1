#include <iostream>
#include <iomanip>
#include<windows.h>
using namespace std;


char board[3][3] = {
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
};
void printBoard() {
	cout << setw(21) << right << "Board" << endl << endl;;
	cout << "      1           2           3      " << endl;
	cout << "1" << setw(6) << right << board[0][0] << "     |" << setw(6) << right << board[0][1] << "     |" << setw(6) << right << board[0][2] << endl;
	cout << "2" << setw(6) << right << board[1][0] << "     |" << setw(6) << right << board[1][1] << "     |" << setw(6) << right << board[1][2] << endl;
	cout << "3" << setw(6) << right << board[2][0] << "     |" << setw(6) << right << board[2][1] << "     |" << setw(6) << right << board[2][2] << endl << endl;
}
bool checkSpot(int row, int col) {
	row--;
	col--;
	if (row < 0 || row > 2) {
		return false;
	}
	if (col < 0 || col > 2) {
		return false;
	}
	if (board[row][col] == ' ') {
		return true;
	}
	return false;
}
bool checkWin() {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[0][1] == board[0][2] && board[i][0] != ' ') {
			return true;
		}
	}
	for (int j = 0; j < 3; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
			return true;
		}

	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
		return true;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
		return true;
	}
	return false;
}
void startGame() {
	printBoard();
	bool winner = false;
	int rowNumber;
	int colNumber;
	while (!winner) {
		//Player one turn

		cout << "Enter a row number and a column number seperated by a space for Player 1" << endl;
		std::cin >> rowNumber;
		std::cin >> colNumber;
		while (!checkSpot(rowNumber, colNumber)) {
			cout << "Invalid Spot!" << endl;
			cout << "Enter a row number and a column number seperated by a space for Player 1" << endl;
			std::cin >> rowNumber;
			std::cin >> colNumber;
		}
		board[--rowNumber][--colNumber] = 'X';
		system("CLS");
		printBoard();
		winner = checkWin();
		if (winner == true) {
			Sleep(1000);
			cout << endl << endl << "Player 1 is the winner!" << endl;
			exit(0);
		}


		//Player 2 turn
		cout << "Enter a row number and a column number seperated by a space for Player 2" << endl;
		std::cin >> rowNumber;
		std::cin >> colNumber;
		while (!checkSpot(rowNumber, colNumber)) {
			cout << endl << "Invalid Spot!" << endl << endl;
			cout << "Enter a row number and a column number seperated by a space for Player 2" << endl;
			std::cin >> rowNumber;
			std::cin >> colNumber;
		}
		board[--rowNumber][--colNumber] = 'O';
		system("CLS");
		printBoard();
		winner = checkWin();
		if (winner == true) {
			Sleep(1000);
			cout << endl << endl << "Player 2 is the winner!" << endl;
			exit(0);
		}
	}

}
int main() {
	cout << "Welcome to my first cpp project: Tic Tac Toe!" << endl << endl << endl;
	Sleep(3000);
	cout << "Player 1 is 'X' and Player 2 is 'O'" << endl << endl;
	Sleep(3000);
	cout << "Game is now starting!" << endl << endl;
	Sleep(2000);
	system("CLS");

	startGame();

	return 0;
}