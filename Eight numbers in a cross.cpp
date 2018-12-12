#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

int counter = 0;

void BT(int &c){
    c--; 
    if (c == -1) {
        cout << "Total Number of Solutions: " << counter << "\n\n\n";
        exit(0);
    }
}

void print (int a[], int &counter) {
    cout << "Solution: " << counter << "\n\n  ";
    for(int c = 0; c < 2; c++) cout<<a[c]<<" ";
    cout << "\n";
    for(int c = 2; c < 6; c++) cout<<a[c]<<" ";
    cout << "\n  ";
    for(int c = 6; c < 8; c++) cout<<a[c]<<" ";
    cout << "\n\n\n";
  
}

bool okay(int a[8], int b, int c) {
    for(int i=0; i < b; i++) {
        if (a[i] == a[b] || (abs(a[b] - a[c]) == 1)) return false;
    }
    return true;
}


int main() {

    int q[8]={0}, c=0, i=0;
    int a[8][5] = {
    { -1 },         //0
    { 0,-1 },       //1
    { 0,-1 },       //2
    { 0,1,2,-1 },   //3
    { 0,1,3,-1 },   //4
    { 1,4,-1 },     //5
    { 2,3,4,-1 },   //6
    { 3,4,5,6,-1 }  //7
    };
    
    while(true) {
        while(c < 8) {
            q[c]++;
            if (q[c] > 8) {
                q[c] = 0;
                BT(c);
                continue;
            }
            for(i = 0; i < 5; i++) {
                if(a[c][i] == -1){
                    c++;
                    if(c == 8) {
                        print(q, ++counter);
                        BT(c);
                    }
                    break;
                }
                if(okay(q,c,a[c][i]) == false) break;
            }
            
        }
    }
}