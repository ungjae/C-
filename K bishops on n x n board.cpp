
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int counter = 0;
bool ok(int q[], int c, int n) {
	for (int i = 0; i < c; ++i) {
		if (q[c] == q[i] || abs(q[c] / n - q[i] / n) == abs(q[c] % n - q[i] % n)) {
			return false;
		}
	}
	return true;
}

void bishop(int n, int k) {
	int* q = new int[k];       
	q[0] = 0;
	int c = 0;
	counter = 0;
	while (c >= 0) {
		c++;
		if (c == k) {           
			counter++;
			c--;
		}
		else {
			q[c] = q[c - 1];
		}
		while (c >= 0) {
			q[c]++;
			if (q[c] == n * n) {
				c--;
			}
			else if (ok(q, c, n)) {
				break;
			}
		}
	}
	delete[] q;
	return;
}

int main() {
	int n, k;
	while (true) {
		cout << "Enter value for n, the size of the board: ";
		cin >> n;
		if (n == -1)
			break;
		cout << "Enter value for k, the number of bishops: ";
		cin >> k;
		if (k == -1)
			break;
		while (k > n) {
			cout << "The number of bishops should be greater or equal to n. Try again: ";
			cin >> k;
		}
		bishop(n, k);
		cout <<"\n"<< setw(12) << "Board Size" << setw(20) << "# of Bishops" <<  "    Total Number of Solutions\n" << setw(8) << n << " x " << n<< setw(20)  << k<<setw(29)<< counter << "\n\n";
	}

	cout << "Program exited\n";
	return 0;
}