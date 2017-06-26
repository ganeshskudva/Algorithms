/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/chief-hopper/problem
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector <long long int> Arr(n);
    for (int i=0;i<n;i++) {
        cin>>Arr[i];
    }
    long long int beg = Arr[n-1]/2 + Arr[n-1]%2;
    for (int i = n-2;i>=0;i--) {
        beg = (Arr[i] + beg)/2 + (Arr[i] + beg)%2;
    }
    cout<<beg<<endl;
    return 0;
}
