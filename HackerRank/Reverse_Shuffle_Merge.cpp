/*
* AUTHOR: Ganesh S Kudva
* https://www.hackerrank.com/challenges/reverse-shuffle-merge/problem
*/

#include <bits/stdc++.h>

using namespace std;

string smallest_A(string &str) {
    reverse(str.begin(), str.end());    

    static string::size_type freq[26];
    static vector<string::size_type> positions[26];
    static typename vector<string::size_type>::size_type next_to_use[26];

    for (string::size_type i = 0; i < str.size(); i++) {
        freq[str[i]-'a']++;
        positions[str[i]-'a'].push_back(i);
    }

    for (size_t i = 0; i < sizeof(freq)/sizeof(*freq); i++) {
        freq[i] /= 2;
        next_to_use[i] = 0;
    }

    vector<string::size_type> needs(str.size());
    static string::size_type freq_seen[26];
    for (string::size_type i = 1; i <= str.size(); i++) {

        string::size_type j = str.size()-i;
        unsigned hash = str[j]-'a';

        needs[j] = freq[hash]-freq_seen[hash];
        freq_seen[hash] = min(freq_seen[hash]+1, freq[hash]);
    }

    string res;

    string::size_type next_bottleneck = 0;
    string::size_type last_pos = 0;
    static string::size_type written[26];

    while (res.size() != str.size()/2) {

        while (!(written[str[next_bottleneck]-'a'] < needs[next_bottleneck]))
            next_bottleneck++;    

        string::size_type next_char = 0;
        while (written[next_char] == freq[next_char] ||
               positions[next_char][next_to_use[next_char]] > next_bottleneck)
            next_char++;

        string::size_type str_pos = positions[next_char][next_to_use[next_char]];

        while (last_pos != str_pos) {
            next_to_use[str[last_pos]-'a']++;
            last_pos++;
        }

        do {
            res.push_back(next_char+'a');
            written[next_char]++;
            next_to_use[next_char]++;
        } while (written[next_char] < needs[str_pos]);

        last_pos = str_pos+1;

    }

    return res;
}

int main(void) {
    string str;
    cin >> str;
    cout << smallest_A(str) << endl;
    return 0;
}
