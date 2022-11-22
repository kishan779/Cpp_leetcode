//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    int count, min, max, n;
	    count = min = max = 0;
	    n = nums.size();
	    for(int j = 1; j<n-1; j++){ //select a 'j' between 0 and n (exclusive)
	        min = max = 0;
	        for(int i = 0; i < j; i++){
	            //total elements less than nums[j] in left of j (i.e. for i < j)
	            if(nums[i]<nums[j]){ min++; }
	        }
	        if(min == 0) continue;
	        for(int k = j+1; k<n; k++){
	            //total elements greater than nums[j] in right of j (i.e. for k > j)
	            if(nums[j]<nums[k]){ max++; }
	        }
	        count += min*max;
	    }
	    return count;
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends