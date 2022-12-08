//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        vector<int> ans;
        int count;
        int j=0;
        while(j<q){
            count =0;
            for(int i=1; i<=query[j]; i++){
                if(isPerfectSquare(i) && isPrime(sqrt(i))) count++;
            }
            ans.push_back(count);
            j++;
        }
        return ans;
    }
    bool isPerfectSquare(long double x){
        if (x >= 0) {
            long long sr = sqrt(x);
            return (sr * sr == x);
        }
        return false;
    }
    bool isPrime(int n){
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); i++){
            if (n % i == 0)
            return false;
        }
        return true;
    }
};




//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends