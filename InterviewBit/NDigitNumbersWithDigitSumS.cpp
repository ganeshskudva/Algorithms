int Solution::solve(int n, int s) {
    long long int dp[n][s];
    if(s<1||s>9*n) return 0;
    
    for(int i=0;i<s;i++){
        if(i+1<=9) dp[0][i]=1;
        else dp[0][i]=0;
    }
    for(int j=0;j<n;j++){
        dp[j][0]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<s;j++){
            dp[i][j]=0;
            int k=0;
            if(j>=9) k=j-9;
            for(;k<=j;k++)
             dp[i][j]=(dp[i][j]+dp[i-1][k])%1000000007;
             
        }
    }
    return dp[n-1][s-1];
}
