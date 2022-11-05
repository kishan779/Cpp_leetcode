//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int a[], int n, int k) {

        int count=0;

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){

            mp[a[i]%k]++;

        }

        if(mp.find(0)!=mp.end()) mp[0]=1;

        for(auto x:mp){

            if(mp.find(k-x.first)!=mp.end()){

                if(x.first==k-x.first) mp[x.first]=1;

                count+=max(mp[k-x.first],mp[x.first]);

                mp[k-x.first]=0;mp[x.first]=0;

            }

            else{

                count+=mp[x.first];

                mp[x.first]=0;

            }

        }

        return count;

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends