
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

// NOTE: This program uses the vector container from the stl.
using namespace std;


int main() {
	vector<int> t[3]; // three towers A,B,C represented as an array of 3 vectors
	int n, candidate, to, from, move = 0; // move counts the move number
	cout << "Please enter a number of rings to move: ";
	cin >> n;
	cout << endl;
	//intitialize the 3 towers
	for (int i = n + 1; i >= 1; i--) {
		t[0].push_back(i);
	}
	t[1].push_back(n + 1);
	t[2].push_back(n + 1);
	
	// initialize towers and candidate

	// simpler solution?

	for (int i = 1; i <= pow(2, n) - 1; i++) {

		if (i % 3 == 1) {
			from = (t[0].back() < t[2].back() ? 0 : 2);
			to = (t[0].back() > t[2].back() ? 0 : 2);
		}
		else if (i % 3 == 2) {
			from = (t[0].back() < t[1].back() ? 0 : 1);
			to = (t[0].back() > t[1].back() ? 0 : 1);
		}
		else {
			from = (t[1].back() < t[2].back() ? 1 : 2);
			to = (t[1].back() > t[2].back() ? 1 : 2);
		}
		
		candidate = t[from].back(); // it’s on the top of the current “from tower”

		cout << "Move Number " << setw(3) << ++move << ": Transfer ring " << candidate <<
			" from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;
  
		t[to].push_back(t[from].back());
		t[from].pop_back();
	}
}