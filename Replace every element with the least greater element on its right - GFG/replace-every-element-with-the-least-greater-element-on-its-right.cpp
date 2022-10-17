//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
         vector<int>ans;
        set<int>st;
        for(int i=n-1;i>=0;i--){
            auto itr=st.upper_bound(arr[i]);
            if(itr==st.end())ans.push_back(-1);
            else ans.push_back(*(itr));
            st.insert(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};





//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends