

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        
        dp[0]=0;
        
        for(int i =1; i<=n;i++){
            int answer = (1<<30);
            for( int j =1; j*j<=i; j++){
                answer= min(answer, 1+dp[i-j*j]);
            }
            dp[i] = answer;
        }
        return dp[n];
    }
};