
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

void queen(int * q, int k);
int counter = 0;
int n;
int main() {

	cout << "Enter a value for the ___ queens problem: ";
	cin >> n;
	cout << "\n";
	int k = 1;
	int * q = new int[k];
	queen(q, k);
	cout << counter;
	delete[] q;
}


int c = 0;

void BT(int * q, int k, int c);
void NextRow(int * q, int k, int c);

void NextColumn(int * q, int k, int c) {
	c++;
	if (c == k) {
		counter++;
		BT(q, k, c);
	}
	q[c] = -1;
	NextRow(q, k, c);
}

void NextRow(int * q, int k, int c) {
	q[c]++;
	if (q[c] == k) BT(q, k, c);

	for (int i = 0; i < c; i++)
		if (q[c] == q[i] || c - i == abs(q[c] - q[i])) {
			NextRow(q, k, c);		}

	// queen implicitly placed

	NextColumn(q, k, c);
}

void BT(int * q, int k, int c) {
	c--;
	if (c == -1) {
		cout << k <<". There are " << setw(3) << counter << " solutions to the " << k << " queens problem.\n";
		if(k == n) exit(0); //
		counter = 0;
		k++;
		q = new int[k]; //
		queen(q, k);
	}

	NextRow(q, k, c);

}

void queen(int * q, int k) {

	q[0] = 0; // place first queen

	NextColumn(q, k, c);
	
}
