//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        int i = 0; 
        while(i < k)
        {
            while(!pq.empty() && arr[i] > pq.top().first)
            {
                pq.pop();
            }
            pq.push({arr[i], i});
            i++;
        }
        int j = 0;
        while(i < n)
        {
            while(j > 0 && pq.top().second < j)
            {
                pq.pop();
            }
            
            ans.push_back(pq.top().first);
            
            if(j == pq.top().second)
            {
                pq.pop();
            }
            
            while(!pq.empty() && arr[i] > pq.top().first)
            {
                pq.pop();
            }
            pq.push({arr[i], i});
            
            j++;
            i++;
        }
        ans.push_back(pq.top().first);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends