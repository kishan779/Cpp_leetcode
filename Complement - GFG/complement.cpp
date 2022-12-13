//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    vector<int> findRange(string str, int n) {
        int l = 0, local_max = 0, 
        global_max = 0, left = 0, right = -1;
        for(int i=0; i<n; i++){
            int num = str[i] == '0' ? 1 : -1;
            if(local_max < 0){
                if(num == 1){
                    l = i;
                    local_max = num;
                }
            }
            else{
                local_max = local_max+num;
            }
            if(local_max > global_max){
                global_max = local_max;
                left  = l;
                right = i;
            }
        }
        if(right == -1)
            return {-1};
        return {left+1, right+1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends