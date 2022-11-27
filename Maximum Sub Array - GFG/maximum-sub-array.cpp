//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    vector<int> ans;
     int s = 0;
     long long currSum = 0;
     long long sumSoFar = 0;
     int start = 0;
     int end = 0;
     bool flag = true;
     for(int i=0;i<n;i++){
         if(a[i] < 0){
             s = i + 1;
             currSum = 0;
         }else{
             flag = false;
             currSum+= a[i];
         }
         if(currSum == sumSoFar){
             if(i-s > end-start){
                 start = s;
                 end = i;
             }
         }
         if(sumSoFar < currSum){
             sumSoFar = currSum;
             start = s;
             end = i;
         }
     }
     if(flag){
         return {-1};
     }
     for(int i=start;i<=end;i++){
         ans.push_back(a[i]);
     }
     return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends