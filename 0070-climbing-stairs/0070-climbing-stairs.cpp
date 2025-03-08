class Solution {
public:
    int dp[47];
    int fibo(int n){
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = fibo(n - 1) + fibo(n - 2);
        return dp[n];
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        int ans = fibo(n);
        return ans;
    }
};