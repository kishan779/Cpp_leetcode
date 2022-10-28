//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution {
	public:
		int NthTerm(int n){
		  long long int ans =2;
		  int M =1e9+7;
		  for(int i=2; i<=n; i++){
		       ans =  (ans*i+1)%M;
		   }
		   return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends