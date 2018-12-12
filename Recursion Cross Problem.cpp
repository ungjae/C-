#include <iostream>

using namespace std;

bool ok(int q[8], int col) {

    static int r[8][5] = {
    { -1 },         //0
    { 0,-1 },       //1
    { 0,-1 },       //2
    { 0,1,2,-1 },   //3
    { 0,1,3,-1 },   //4
    { 1,4,-1 },     //5
    { 2,3,4,-1 },   //6
    { 3,4,5,6,-1 }  //7
    };

    for (int i = 0; i < col; i++) {
        if (q[i] == q[col]) return false;
    }

    for (int i = 0; r[col][i] != -1; i++) {
        if (q[r[col][i]] == q[col] || (abs(q[r[col][i]] - q[col]) == 1)) return false;
    }
    return true;
}

void print(int * q)
{
    static int count = 0;
    cout << "Solution " << ++count << "\n  ";
    for (int c = 0; c < 2; c++) cout << q[c] << " ";
    cout << "\n";
    for (int c = 2; c < 6; c++) cout << q[c] << " ";
    cout << "\n  ";
    for (int c = 6; c < 8; c++) cout << q[c] << " ";
    cout << "\n\n\n";
}
void move(int* q, int i) // try place in col i
{
    if (i == 8)
    {
        print(q);
        return;
    }

    for (int j = 1; j <= 8; j++) // j is the row value
    {
        q[i] = j;
        if (ok(q, i)) // try and place a queen in row j of col i,if yes
            move(q, i + 1); // go to next column otherwise try next j
    }

    // no value of j worked so return;
};
int main()
{
    int q[8];
    move(q, 0);
    system("pause");
}

