
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int q[8], c = 0;
int counter = 0;
void Print(int c);
void BT(int c);
void NextRow(int c);

void NextColumn(int c) {
	c++;
	if (c == 8) Print(c);
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

void Print(int c) {
	counter++;
	cout << "Solution: " << counter << "\n\n[ ";
	for (int c = 0; c < 8; c++) {
		cout << q[c] << " ";
	}
	cout << "] \n\n\n";


	BT(c);
}

int main() {

	q[0] = 0; // place first queen
	NextColumn(c);
}