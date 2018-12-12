
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int rows = 5;
const int cols = 6;
int m[rows][cols] = { 0 };
int n[rows][cols] = { 0 };

int weight[rows][cols] = {
	{ 3,4,1,2,8,6 },
	{ 6,1,8,2,7,4 },
	{ 5,9,3,9,9,5 },
	{ 8,4,1,3,2,6 },
	{ 3,7,2,8,6,4 } };

void print(int r, int c) {

	if (c == 0) {
		return;
	}

	

	if (c != 0) {
		int up = n[(r + 4) % 5][c - 1];
		int left = n[r][c - 1];
		int down = n[(r + 1) % 5][c - 1];
		int min = ((left < up ? left : up) < down ? (left < up ? left : up) : down);
		if (min == up) {
			print((r + 4) % 5, c - 1);
			cout << "For Column [" << c - 1 << "] Take Row [" << (r + 4) % 5 << "] with value [" << weight[(r + 4) % 5][c - 1] << "] \n";

		}
		else if (min == left) {
			print(r, c - 1);
			cout << "For Column [" << c - 1 << "] Take Row [" << r << "] with value [" << weight[r][c - 1] << "] \n";

		}
		else if (min == down) {
			print((r + 1) % 5, c - 1);
			cout << "For Column [" << c - 1 << "] Take Row [" << (r + 1) % 5 << "] with value [" << weight[(r + 1) % 5][c - 1] << "] \n";

		}
	}
	
	if (c == cols - 1)
		cout << "For Column [" << c << "] Take Row [" << r << "] with value [" << weight[r][c] << "] \n";


		
}


int costUp(int i, int j) { // i is the row, j is the column

	//base case
	
	int min;

	for (int k = 0; k < cols; k++)
		for (int l = 0; l < rows; l++) {
			if (k == 0)
				n[l][k] = weight[l][0];
			else {
				int up = n[(l + 4) % 5][k - 1];
				int left = n[l][k - 1];
				int down = n[(l + 1) % 5][k - 1];

				min = ((left < up ? left : up) < down ? (left < up ? left : up) : down);

				n[l][k] = min + weight[l][k];
			}
		}

	return n[i][j];

}

int main() {
	
	cout << "            Iterative\n\n";

	int up[rows];

	for (int i = 0; i<rows; i++)
		up[i] = costUp(i, cols - 1);

	int minUp = up[0];
	int minRowUp;
	for (int i = 1; i < rows; i++) {
		if (up[i] < minUp) {
			minUp = up[i];
			minRowUp = i;
		}
	}

	cout << "  Path Table n[] Previously m[]\n\n";

	for (int r = 0; r < rows; r++) {
		cout << "  ";
		for (int c = 0; c < cols; c++)
			cout <<"["<<setw(2) << n[r][c] << "] ";
		cout << "\n";
	}
	cout << "\n\n    Directions for the Shortest Path\n\n";

	print(minRowUp, cols - 1);

	cout << "\n      Total Cost to Travel: " << n[minRowUp][cols - 1] << "\n\n";

	system("PAUSE");
	return EXIT_SUCCESS;

}