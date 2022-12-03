//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin() , stalls.end());
        int low = 0 , high = stalls[n-1] , gap ,res =0  ;
        

        while(low <= high){
             gap = (high + low+1)/2;
          int  count=1 , left=0;
        for(int i=1;(i<n and count < k);i++){

            if(stalls[i] - stalls[left] >= gap){
                
                left=i;
                count++;
            }
         
            
        }
           if(count>=k){
                low=gap+1;
                res=gap;
            }
            
            else{
                high=gap-1;
            }
        
        }
        
        return res;
        
        
    }
};



//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends