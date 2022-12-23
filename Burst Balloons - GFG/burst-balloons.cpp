//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxCoins(int N, vector<int> &arr) {
        // code here
        int n = N;
        vector<int>a;
        a = arr;
        a.push_back(1);
        a.insert(a.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        int maxi=INT_MIN;
        for(int i=n;i>=1;i--){
            for(int j=1; j<=n;j++){
                if(i>j) continue;
                maxi = INT_MIN;
                for(int idx=i;idx<=j;idx++){
                    int cost=a[i-1]*a[idx]*a[j+1]+dp[idx+1][j]+dp[i][idx-1];
                    maxi=max(cost,maxi);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends