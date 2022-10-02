class Solution {
public:
    const int mod = 1e9+7;
    int dp[31][1000];
    int solve(int n, int k, int target){
        if (n == 0 && target == 0){
            return 1;
        }
        if (n == 0){
            return 0;
        }
        if (dp[n][target] != -1){
            return dp[n][target];
        }
        int ans = 0;
        for (auto i = 1; i <= k; i++){
            if (target - i >= 0){
                ans += solve(n-1,k,target-i);
                ans %= mod;
            }
            else {
                break;
            }
        }
        dp[n][target] = ans;
        return ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,target);
    }
};