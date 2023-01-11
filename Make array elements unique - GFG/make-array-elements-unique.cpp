//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> a, int n) {
        sort(a.begin(),a.end());
        int count=0;
        int diff;
        for(int i=0;i<n;i++){
            if(a[i-1]>=a[i]){
                diff=a[i-1]-a[i];
                count+=diff+1;
                a[i]=a[i]+diff+1;
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends