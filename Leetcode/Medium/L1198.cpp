// 1199. Minimum Time to Build Blocks
class Solution {
public:
int smallestCommonElement(vector<vector<int>> &mat) {
    map<int, int> mp;
    int i,j, M = mat.size(), N = mat[0].size();
    int mini = INT_MAX;
    bool found = false;

    for (j = 0; j < N; j++) {
        mp[mat[0][j]] = 1;
    }

    for (i = 1; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (mp[mat[i][j]] == i) {
                mp[mat[i][j]] = i+1;
            }

            if (i == M - 1) {
                if (mp[mat[i][j]] == M && mat[i][j] < mini) {
                    found = true;
                    mini = mat[i][j];
                }
            }
        }
    }

/*
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second == M) {
            if (it->first < mini)
                mini = it->first;
        }
    }
    */


    if (found)
        return mini;
    else 
        return -1;
}
};
