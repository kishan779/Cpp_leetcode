//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	#define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    // code here
	    ll c=0;
	    ll total = (ll)n*(n+1)/2;
	    for(int i=0;i<n;i++){
	        if(arr[i]<=k) c++;
	        else{
	            total -= (c*(c+1)/2);
	            c=0;
	        }
	    }
	    
	    return total-(c*(c+1)/2);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends