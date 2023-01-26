//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string ans ="" ;
        string up ="" , lo = "" ;
        int b ;
        for(int i=0;i<n; i++) {
            if(str[i] >='a' && str[i] <='z') 
            lo += str[i] ;
            else 
            up += str[i] ;
        }
        sort(begin(up),end(up)) ;
        sort(begin(lo),end(lo)) ;
        int u =0 , l =0 ;
         for(int i=0;i<n; i++) {
            if(str[i] >='a' && str[i] <='z') 
            ans += lo[l++] ;
            else 
            ans += up[u++] ;
            
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends