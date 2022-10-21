//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int r, int c, vector<vector<int>>&a)  {
     
            vector<int>v;
       int left=0,top=0;
       int right=c-1,bottom=r-1;
       while(left<=right && top<=bottom){
           for(int i=left;i<=right;i++){
               v.push_back(a[top][i]);
           }
           top++;
           for(int i=top;i<=bottom;i++){
               v.push_back(a[i][right]);
           }
           right--;
           if(top<=bottom){
           for(int i=right;i>=left;i--){
               v.push_back(a[bottom][i]);
           }
           bottom--;
           }
           if(left<=right){
           for(int i=bottom;i>=top;i--){
               v.push_back(a[i][left]);
           }
           left++;
           }
       }
       
       reverse(v.begin(),v.end());
       return v;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends