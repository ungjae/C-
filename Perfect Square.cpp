#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long i = 1;
    while ((i*i) % 2 == 0 || (((i*i)%100)/10)%2 == 0) i++;
    cout << i * i;
    return 0;
}
