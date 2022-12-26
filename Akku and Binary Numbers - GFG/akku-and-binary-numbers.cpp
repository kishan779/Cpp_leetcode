//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    void precompute()
    {
        // Code Here
    }
    long long solve(long long l, long long r){
        // Code Here
        long long count = 0;
       for(int i=0; i<64&&(1<<i)<r; i++){
       for(int j=i+1; j<64; j++){
           for(int k=j+1; k<64; k++){
            long long n = 0;
             n = n|((long long)1<<i)|((long long)1<<j)|((long long)1<<k);  
              if(n>=l && n<=r){
                  count++;
              }
              if(n>r)
              {
                 break;
              }              
               }
           }
       }
       return count;
    }  
};


//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends