/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/common-child/problem
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int max(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int main() {
    string a, b;
    int i, j, l1, l2, temp;
    cin >> a >> b;
    l1 = a.length();    l1++;
    l2 = b.length();    l2++;
    //cout << l1 << "\t" << l2 <<"\n";
    int c[3][l2];
    for(i = 0; i < l2; i++)
    {
        c[0][i] = 0;
        c[1][i] = 0;
        c[2][i] = 0;
    }
    for(i = 1; i < l1; i++){
        for(j = 1; j < l2; j++){
            temp = i;
            temp = temp % 2; temp++;
            if(temp == 1){
                if(a[i-1] == b[j-1])
                    c[temp][j] = c[temp-1][j-1] + 1;
                else
                    c[temp][j] = max(c[temp][j-1], c[temp-1][j]);
            }
            else{
                if(a[i-1] == b[j-1]){
                    c[temp][j] = c[temp-1][j-1] + 1;
                    c[0][j] = c[temp][j];
                }
                else{
                    c[temp][j] = max(c[temp][j-1], c[temp-1][j]);
                    c[0][j] = c[temp][j];
                }
            }
            //cout <<temp <<","<<c[temp][j]<<a[i-1]<<b[j-1] << "\t";
        }
        //cout << "\n";
    }
    if(c[1][l2-1] > c[2][l2-1])
        cout << c[1][l2-1];
    else
        cout << c[2][l2-1];
    
    
    return 0;
}
