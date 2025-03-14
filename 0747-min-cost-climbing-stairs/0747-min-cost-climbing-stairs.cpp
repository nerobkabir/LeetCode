class Solution {
public:
    int t[1001];
    int solve(vector<int>& cost, int n){
        if(n < 0) return 0;
        if(n== 0) return cost[0];

        if(t[n] != -1) return t[n];

        int oneStep =  solve(cost, n-1);

        int twoStep = solve(cost, n-2);

        if(n==cost.size()) return t[n] = min(oneStep, twoStep);

        return t[n]=cost[n]+min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(t, -1, sizeof(t));
        return solve(cost, n);
    }
};