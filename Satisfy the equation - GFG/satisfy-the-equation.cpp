//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
     map<int , vector<pair<int, int>>> mp;
    
    for (int i = 0; i < N; i++){
        for (int j = i+1 ; j < N ; j++){
            int sum = A[i] + A[j];
            mp[sum].push_back({i , j}); // storing every sum pair in map
        }
    }
    
    vector<int> ok;
    
    for (auto x : mp){
        sort(x.second.begin() , x.second.end()); // sorting so as to get smallest 
        if (x.second.size() >= 2){
            for (int i = 1 ; i < x.second.size() ; i++){
                // a b c d are the indexes 
                // a  < b and c < d  and b != c and b != d and a + b = c + d these are the conditions required
                if (x.second[0].first  < x.second[i].first and x.second[0].second != x.second[i].first and x.second[0].second != x.second[i].second){
                   vector<int> curr; // stroing curr ans 
                   curr = {x.second[0].first , x.second[0].second , x.second[i].first, x.second[i].second}; 
                   if (ok.empty()){
                   ok = curr;
                   }
                   else if (ok > curr){
                   ok = curr;
                   }
                }
            }
        }    
    }
    if (ok.empty())
    return {-1 ,-1 , -1 , -1};
    return ok;    // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends