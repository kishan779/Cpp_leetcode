//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int Xor = 0 , res1 = 0 , res2 = 0;
        vector<long long int>ans;
        for(long long int i = 0 ; i < N ; i++){
            Xor = Xor ^ Arr[i];
        }
        long long int Sn = Xor & ~(Xor-1);
        for(long long int i = 0 ; i < N ; i++){
            if((Arr[i] & Sn) != 0)
             res1 = res1^Arr[i];
             else
             res2 = res2^Arr[i];
        }
        if(res1 > res2){
            ans.push_back(res1);
            ans.push_back(res2);
        }
        else{
            ans.push_back(res2);
            ans.push_back(res1);
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
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends