
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int q[8], c = 0;
int counter = 0;
void Print(int q[], int c);
void BT(int c);
void NextRow(int c);

void NextColumn(int c) {
	c++;
	if (c == 8) Print(q, c);
	q[c] = -1;
	NextRow(c);
}

void NextRow(int c) {
	q[c]++;
	if (q[c] == 8) BT(c);

	for (int i = 0; i < c; i++)
		if (q[c] == q[i] || c - i == abs(q[c] - q[i])) {
			NextRow(c);
		}

	// queen implicitly placed

	NextColumn(c);
}

void BT(int c) {
	c--;
	if (c == -1) {
		cout << "Total Number of Solutions: " << counter << "\n\n\n";
		exit(0);
	}

	NextRow(c);

}

void Print(int q[], int c) {
	

	counter++;
	cout << "Solution: " << counter << "\n\n";


	int i, j, k, l;
	typedef char box[5][7];
	box bb, wb, bq, wq, *board[8][8];
	//fill in bb=black box and wb=whitebox
	for (i = 0; i<5; i++)
		for (j = 0; j<7; j++)
		{
			wb[i][j] = ' ';
			wq[i][j] = ' ';
			bb[i][j] = char(219);
			bq[i][j] = char(219);
		}

	// make crown shape
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 7; j++) {
			if (j % 2 == 1 && i == 1) {
				wq[i][j] = char(219);
				bq[i][j] = ' ';
			}
			else if (i == 2 || i == 3) {
				if (j > 0 && j < 6) {
					wq[i][j] = char(219);
					bq[i][j] = ' ';
				}
			}
		}
	}

	//fill board with pointers to bb and wb in alternate positions
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0)
				board[i][j] = &wb;
			else
				board[i][j] = &bb;
		}
	}

	for (i = 0; i < 8; i++) {
		board[q[i]][i] = ((q[i] + i) % 2 == 0 ? &wq : &bq);
	}

	// print the board via the pointers in array board
	// first print upper border
	cout << " ";
	for (i = 0; i<7 * 8; i++)
		cout << '_';
	cout << endl;
	// now print the board
	for (i = 0; i<8; i++)
		for (k = 0; k<5; k++)
		{
			cout << " " << char(179); //print left border
			for (j = 0; j<8; j++)
				for (l = 0; l<7; l++)
					cout << (*board[i][j])[k][l];
			cout << char(179) << endl; // at end of line print bar and then newline
		}
	//before exiting print lower border
	cout << " ";
	for (i = 0; i<7 * 8; i++)
		cout << char(196);
	cout << endl;
	cout << "\n\n\n";


	BT(c);
}

int main() {

	q[0] = 0; // place first queen

	NextColumn(c);
}
