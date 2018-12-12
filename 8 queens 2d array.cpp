// Example program
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int b[8][8] = {0}, r, c, counter = 0;
    b[0][0] = 1;

NC: c++;
    if (c == 8) goto Print;
    r = -1;
    
NR: r++;
    if (r == 8) goto BT;
    
    for(int i=0; i < c; i++)
        if(b[r][i] == 1) goto NR;
    for(int i=1; r-i>=0 && c-i>=0; i++)
        if(b[r-i][c-i] == 1) goto NR;
    for(int i=1; r+i<8 && c-i>=0; i++)
        if(b[r+i][c-i] == 1) goto NR;
    b[r][c] = 1;
    goto NC;
    
BT: c--;
    if(c == -1) {
        cout << "Total Number of Solutions: " << counter << "\n"; 
        return 0;
    }
    r=0;
    while(b[r][c] != 1) r++;
    b[r][c] = 0;
    goto NR;
    
Print:
    counter++;
    cout << "Solution: " << counter << "\n\n";
    for(int c = 0; c < 8; c++) {
        for(int r = 0; r < 8; r++)
            cout << b[r][c] << " ";
        cout << "\n";
    }
    cout <<"\n";

    
    goto BT;
}
