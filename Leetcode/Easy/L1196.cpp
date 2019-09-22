// 1196. How Many Apples Can You Put into the Basket
class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        int cnt = 0, sum = 0;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        if (sum + arr[i]> 5000) 
            break;
        
        sum += arr[i];
        cnt++;
    }

    return cnt;
    }
};
