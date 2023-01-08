//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
long long countPairs(int n, int arr[], int k) {
    // code here
    long long cnt = 0;
    int *a = new int[k]();
    for(int i = 0; i < n; i++){
        arr[i] %= k;
        cnt += a[arr[i]];
        a[arr[i]]++;
    }
    return cnt;
}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends