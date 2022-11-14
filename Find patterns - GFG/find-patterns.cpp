//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int numberOfSubsequences(string s, string w){
        int n = s.size(), m = w.size(), j=0, ans=0;
        while(true)
        {
            vector<int> co;
            j = 0;
            for(int i=0; i<m; i++)
            {
                int cnt = 0;
                for(; j<n; j++)
                {
                    if(s[j] == w[i])
                    {
                        co.push_back(j); 
                        j++;
                        break;
                    }
                }
            }
            if(co.size() == m)
            {
                ans++;
                for(auto i:co)s[i] = '#';
            }
            else break;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends