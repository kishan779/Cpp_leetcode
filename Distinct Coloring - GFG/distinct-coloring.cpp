//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++


class Solution{   
public:
    vector<vector<long long int>>dp;
    long long int find(int i, int last, int r[], int g[], int b[], int N)
    {
        if(i>=N)
        {
            return 0;
        }
        if(last!=-1 && dp[i][last]!=-1)
        {
            return dp[i][last];
        }
        long long int x,y,z;
        x=y=z=1e12;
        if(last!=0)
        {
            x=r[i]+find(i+1,0,r,g,b,N);
        }
        if(last!=1)
        {
            y=g[i]+find(i+1,1,r,g,b,N);
        }
        if(last!=2)
        {
            z=b[i]+find(i+1,2,r,g,b,N);
        }
        long long int ans=min(x,min(y,z));
        return last==-1?ans:dp[i][last]=ans;
    }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        dp=vector<vector<long long int >>(N,vector<long long int>(3,-1));
        return find(0,-1,r,g,b,N);
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends