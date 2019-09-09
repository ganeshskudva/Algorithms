// 1186. Maximum Subarray Sum with One Deletion
class Solution {
public:
int maximumSum(vector<int> &arr)
{   
    int n = arr.size(), i;
    if (n == 0)
        return 0;
    
    int fw[n], bw[n];
    int curMax = arr[0], maxSoFar = arr[0];

    fw[0] = arr[0];
    for (i = 1; i < n; i++) {
        curMax = max(arr[i], curMax + arr[i]);
        maxSoFar = max(maxSoFar, curMax);

        fw[i] = curMax;
    }

    curMax = arr[n-1];
    maxSoFar = arr[n-1];
    bw[n-1] = arr[n-1];
    for (i = n-2; i >= 0; i--) {
        curMax = max(arr[i], curMax + arr[i]);
        maxSoFar = max(maxSoFar, curMax);

        bw[i] = curMax;
    }

    int fin = maxSoFar;

    for (i = 1; i < n-1; i++)
        fin = max(fin, fw[i-1]+bw[i+1]);

    return fin;
}
};
