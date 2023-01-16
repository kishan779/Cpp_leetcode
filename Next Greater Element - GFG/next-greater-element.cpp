//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution


class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        stack<long long> st;
        st.push(-1);
        vector<long long> ans(n);
        for(int i = n-1; i>= 0; i--) {
            long long curr = arr[i];
            while(st.top() != -1 && st.top() <= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(curr);
        }
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
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends