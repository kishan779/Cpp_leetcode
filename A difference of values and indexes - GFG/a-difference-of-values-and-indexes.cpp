//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends


class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        int a1,a2,a3,a4;
        a1=a2=a3=a4=INT_MIN;
        for(int i=0; i<n ;i++){
            a1=max(a1,-(arr[i]+i));
            a2=max(a2,arr[i]+i);
            a3=max(a3,arr[i]-i);
            a4=max(a4,-(arr[i]-i));
        }
        return max(a3+a4,a1+a2);
    } 
};




//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends