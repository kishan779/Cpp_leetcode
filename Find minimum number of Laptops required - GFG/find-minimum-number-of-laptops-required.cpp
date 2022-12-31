//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        sort(start, start+N);
        sort(end, end+N);
        
        queue<pair<int, int>> q; 
        q.push({start[0], end[0]});
        for(int i=1; i<N; i++){
            auto temp = q.front();
            if(temp.second<=start[i]){
                q.pop();
            }
            q.push({start[i], end[i]});
        }
        return q.size();
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends