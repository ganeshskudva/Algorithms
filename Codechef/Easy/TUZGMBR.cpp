/*
* AUTHOR: Ganesh S Kudva
* https://www.codechef.com/problems/TUZGMBR
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000100;

const char *FIRST_PLAYER = "Tuzik";
const char *SECOND_PLAYER = "Vanya";

void readInt(int &x, int l, int r) {
  scanf("%d", &x);

  assert(l <= x && x <= r);
}

void solve() {
  int n, m; 

  readInt(n, 1, 1000000);
  readInt(m, 1, 1000000);

  int nim_value = ((n - 1) % 4) ^ ((m - 1) % 3);
  if (nim_value) {
    printf("%s\n", FIRST_PLAYER);
  } else {
    printf("%s\n", SECOND_PLAYER);
  }
}

int main() {
  int cases; readInt(cases, 1, 100);

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}
