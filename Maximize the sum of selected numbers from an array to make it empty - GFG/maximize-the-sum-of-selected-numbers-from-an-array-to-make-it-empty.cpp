//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
     public:
    int maximizeSum(int a[], int n) 
    {
       sort(a,a+n);
       vector<int>num(a[n-1]+1,0);
       for(int i =0;i<n;i++) num[a[i]]++;
       int ans=0;
       for(int i=num.size()-1;i>=1;i--){
           ans+=num[i]*i;
           num[i-1]-=min(num[i],num[i-1]);
       }
       
       
       return ans;
    }

};

//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends