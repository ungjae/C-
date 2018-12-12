//stable marriage
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int q[3], c = 0;
int counter = 0;
void Print(int c);
void BT(int c);
void NextRow(int c);

bool OK(int q[], int c){
	
	//	mp	w0	w1	w2
    //	m0	0	2	1		values = rank of woman 
    //	m1	0	2	1
    //	m2	1	2	0

	int mp[3][3] = {
			{0,2,1},
			{0,2,1},
			{1,2,0}
	};
	int wp[3][3] = {
			{2,1,0},
			{0,1,2},
			{2,0,1}
	};	
	
    // newMan: c
	// newWoman: q[c]
	// currMan: i
	// currWoman: q[i]

	for (int i = 0; i < c; i++) {
		if (q[i] == q[c]) return false; //test 1
	
		if (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c])
			return false;

		if (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i])
			return false;
	}
	return true;
}

void NextColumn(int c) {
	c++;
	if (c == 3) Print(c);
	q[c] = -1;
	NextRow(c);
}

void NextRow(int c) {
	q[c]++;
	if (q[c] == 3) BT(c);

	for (int i = 0; i < c; i++)
		if (!OK(q, c)) {
			NextRow(c);
		}

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
	for (int c = 0; c < 3; c++) {
		cout << q[c] << " ";
	}
	cout << "] \n\n\n";


	BT(c);
}

int main() {

	q[0] = 0;
	NextColumn(c);
}
