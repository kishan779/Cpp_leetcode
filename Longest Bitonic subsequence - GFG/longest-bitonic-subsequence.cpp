//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    vector<int> Incre(nums.size(), 0 ), Dec(nums.size(), 0);
	    
	    Incre[0] = 1;
	    for(int i=1; i<nums.size(); i++){
	        int mx = 0;
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i])
	                mx = max(mx, Incre[j]);
	        }
	        Incre[i] = mx + 1;
	    }
	    
	    Dec[nums.size()-1] = 1;
	    for(int i=nums.size()-2; i>=0; i--){
	        int mx = 0;
	        for(int j=i+1;j<nums.size();j++){
	            if(nums[j]<nums[i])
	                mx = max(mx, Dec[j]);
	        }
	        Dec[i] = mx + 1;
	    }
	    
	    int ans = 0;
	    
	    for(int i=0; i<nums.size(); i++){
	        ans = max(ans, Incre[i] + Dec[i] - 1);
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
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends