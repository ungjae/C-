#include <iostream>
#include <string>

using namespace std;

bool equivalent(int a[], int b[], int n) {
    for (int s = 0; s < n; s++){
        for (int i = 0; i < n; i++){
            if (a[i] != b[(i+s)%n]) break;
            if (i == n-1) return true;
        }
    }
    return false;
}

int main()
{

    int a[5]={3,2,3,4,5};
    int b[5]={3,4,5,3,2};
    cout << (equivalent(a, b, 5) == 1 ? "True" : "False") << "\n";


}

