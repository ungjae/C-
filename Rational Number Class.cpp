
#include <iostream>
using namespace std;

// Rat class i.e. a class for rational numbers


class Rat {
private:
	int n = n;
	int d = d;

public:
	// constructors

	// default constructor
	Rat() {
		n = 0;
		d = 1;
	}

	// 2 parameter constructor
	Rat(int i, int j) {
		int k = gcd(i, j);
		n = i / k;
		d = j / k;
	}
	// conversion constructor
	Rat(int i) {
		n = i;
		d = 1;
	}

	//accessor functions (usually called get() and set(...) )
	int getN() { return n; }
	int getD() { return d; }
	void setN(int i) { n = i / gcd(i, d); }
	void setD(int i) { d = i / gcd(i, n); }
	void simplifly() {
		int k = gcd(n, d);
		n /= abs(k);
		d /= abs(k);
	}
	int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);

	}
	//arithmetic operators

	Rat operator+(Rat r) {
		Rat t;
		t.n = n * r.d + d * r.n;
		t.d = d * r.d;
		t.simplifly();
		return t;
	}
	
	Rat operator-(Rat r) {
		Rat t;
		t.n = n * r.d - d * r.n;
		t.d = d * r.d;
		t.simplifly();
		return t;
	}

	Rat operator*(Rat r) {
		Rat t;
		t.n = n * r.n;
		t.d = d * r.d;
		t.simplifly();
		return t;
	}

	Rat operator/(Rat r) {
		Rat t;
		t.n = n * r.d;
		t.d = d * r.n;
		t.simplifly();
		return t;
	}

	// 2 overloaded i/o operators
	friend ostream& operator<<(ostream& os, Rat r);
	friend istream& operator>>(istream& is, Rat& r);
}; //end Rat
// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
ostream& operator<<(ostream& os, Rat r) {
	if (r.n >= r.d || (r.n < 0 && r.n < -(r.d))) {
		if(r.n % r.d == 0) {
			os << r.n / r.d;
		}
		else {
			os << r.n / r.d << " " << abs(r.n%r.d) << "/" << abs(r.d);
		}
		return os;
	}


	os << r.n << "/" << r.d ;
	return os;
}

// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its provate parts.
istream& operator>>(istream& is, Rat& r) {
	is >> r.n >> r.d;
	r.simplifly();
	return is;
}
int main() {
	Rat x(1, 2), y(2, 3), z;
	z = x + y;
	cout << z << "\n";

	x.setN(3);
	y.setD(2);
	z = x + y;
	cout << z << "\n";
	cout << "Enter values for x: ";
	cin >> x;
	cout << x << "\n";
	cout <<"z: " << z << " x: " << x << " y: " << y <<"\n";
	z = x + y;
	cout << "z = x + y" << " z: " << z << "\n";
	z = x - y;
	cout << "z = x - y" << " z: " << z << "\n";
	z = x * y;
	cout << "z = x * y" << " z: " << z << "\n";
	z = x / y;
	cout << "z = x / y" << " z: " << z << "\n";
	system("pause");
	return 0;
}
