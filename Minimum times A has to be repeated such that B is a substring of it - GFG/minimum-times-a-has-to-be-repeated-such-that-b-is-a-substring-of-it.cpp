//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        // code here
        int i = 0, n = a.length(), j = 0;
        while(i < n){
            if(a[i] == b[0]){
                j = i;
                while(j-i < b.length()){
                    if(a[j%n] != b[(j-i)])  break;
                    j++;
                    if(j-i == b.length())   return j/n + (j%n != 0 ? 1 : 0);
                }
            }
            i++;
        }
        return -1;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends