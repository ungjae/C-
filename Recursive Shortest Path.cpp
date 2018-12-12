#include <iostream>
#include <string>

using namespace std;

const int rows = 5;
const int cols = 6;
int m[5][6] = { 0 };

void print(int r, int c) {
	int weight[rows][cols] = {
		{ 3,4,1,2,8,6 },
	{ 6,1,8,2,7,4 },
	{ 5,9,3,9,9,5 },
	{ 8,4,1,3,2,6 },
	{ 3,7,2,8,6,4 } };

	if (c == 0) {
		return;
	}

	

	if (c != 0) {
		int up = m[(r + 4) % 5][c - 1];
		int left = m[r][c - 1];
		int down = m[(r + 1) % 5][c - 1];
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

int cost(int i, int j) { // i is the row, j is the column
	int weight[rows][cols] = {
	{ 3,4,1,2,8,6 },
	{ 6,1,8,2,7,4 },
	{ 5,9,3,9,9,5 },
	{ 8,4,1,3,2,6 },
	{ 3,7,2,8,6,4 } };

	
	//base case
	if (j == 0)
		return weight[i][0];
	int min;


	if (m[i][j] == 0) {
		// recursive call
		int up = cost((i + 4) % 5, j - 1);
		int left = cost(i, j - 1);
		int down = cost((i + 1) % 5, j - 1);

		// find the value of the shortest path through cell (i,j)
		min = ((left < up ? left : up) < down ? (left < up ? left : up) : down);

		m[i][j] = min + weight[i][j];
	}
	

	
	return m[i][j];
		
}

int main() {
	int ex[rows];

	// get the shortest path out of each cell on the right
	for (int i = 0; i<rows; i++)
		ex[i] = cost(i, cols - 1);

	// now find the smallest of them
	int min = ex[0];
	int minRow;
	for (int i = 1; i < rows; i++) {
		if (ex[i] < min) {
			min = ex[i];
			minRow = i;
		}
	}

	print(minRow, cols - 1);
	cout <<"Total Cost to Travel: " << cost(minRow, cols - 1) << "\n";
	
	system("PAUSE");
	return EXIT_SUCCESS;

}