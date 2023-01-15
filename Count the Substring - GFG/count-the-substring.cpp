//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define ll long long

class Solution {
public:
    ll query(vector<ll>& bit, ll x) {
        ll res = 0;
        for(ll i=x; i>0; i-=(i&(~i+1))) {
            res += bit[i];
        }
        return res;
    }

    void update(vector<ll>& bit, ll x, ll val) {
        for(ll i=x; i<bit.size(); i+=(i&(~i+1))) {
            bit[i] += val;
        }
    }
    
    ll countSubstring(string S){
        ll N = S.length();
        vector<ll> bit(2*N+2, 0);
        
        ll res = 0, sum = 0, shift = N+1;
        update(bit, shift, 1);
        for(ll i=0; i<N; i++) {
            sum += S[i] == '1' ? 1 : -1;
            res += query(bit, sum-1+shift);
            update(bit, sum+shift, 1);
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    string S;
    cin>>S;
    Solution obj;
    long long ans =obj.countSubstring(S);
    cout<<ans<<endl;
 }
}
// } Driver Code Ends