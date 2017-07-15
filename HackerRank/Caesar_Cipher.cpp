/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/caesar-cipher-1/problem
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int k;
    cin >> k;

    k %= 26;
    for (int i = 0;i < n; i++) {
        int c = s[i];
        if (c >= 'a' && c <= 'z') { // Lowercase characters
            c += k;
            if (c > 'z') { // C exceeds the ascii range of lowercase characters.
               c = 96 + (c % 122); // wrapping from z to a
            }
        } else if(c >= 'A' && c <= 'Z') { // Uppercase characters
            c += k;
            if(c > 'Z') { // C exceeds the ascii range of uppercase characters.
                c = 64 + (c % 90); //wrapping from Z to A
            }
        }
        cout << (char)c;
    }
    cout << endl;
    return 0;
}
