//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
	vector<vector<int>> ans;

    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<int> arr;
        ans.clear();
        for(int i=0; i<n; i++) arr.push_back(i+1);
        vector<int> op;
        solve(arr, n, n, op);
        return ans;
    }
    void solve(vector<int>& arr, int n, int target, vector<int>& op) {
        if(target==0) {
            ans.push_back(op);
            return;
        }
        if(n<=0) return;
        if(arr[n-1]<=target) {
            op.push_back(arr[n-1]);
            solve(arr, n, target-arr[n-1], op);
            op.pop_back();
        }
        solve(arr, n-1, target, op);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends