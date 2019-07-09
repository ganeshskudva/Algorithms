// 70. Climbing Stairs
class Solution {
public:
    int fib(int n){
        vector<int> f;
        f.push_back(1);
        f.push_back(1);
        for(int i=2;i<=n;i++){
            f.push_back(f[i-1]+f[i-2]);
        }
        return f[n];
    }
    
    
    int climbStairs(int n) {
        return fib(n);
    }
};
