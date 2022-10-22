//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int fillingBucket(int N) {
        
        int MOD = 100000000;     // Storing the value of MOD
        
        int fib[N+1];
        fib[0] = fib[1] = 1;      // First two terms of the series are 1.
        for(int i=2; i<=N; i++)
            fib[i] = (fib[i-1]+fib[i-2]) % MOD;
            
        return fib[N];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends