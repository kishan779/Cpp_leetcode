//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &v) 
    {
        stack<int> st;
        vector<int> ans;
        
        for(int i=0;i<N;i++)
        {
            if(st.empty())
            {
                if(v[i]<0)ans.push_back(v[i]);
                else st.push(v[i]);
            }
            // 3 5 -3 -24 56 79 -24 44 85 -1 57 3 -3
            else
            {
                if(v[i]<0)
                {
                    while(st.size()>0 && abs(v[i])>abs(st.top()))st.pop();
                    if(st.empty())ans.push_back(v[i]);
                    if(st.size()>0 && abs(v[i])==abs(st.top()))st.pop();
                }
                else st.push(v[i]);
            }
        }
        stack<int> rev;
        while(st.size()>0){rev.push(st.top());st.pop();}
        while(rev.size()>0){ans.push_back(rev.top());rev.pop();}
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends