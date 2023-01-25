//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int count=0;
        int flag=0;
        while(s.length())
        {
            if(s.length() & 1)
            {
                count++;
                s.pop_back();
            }
            else
            {
                if(flag==0)
                {
                    int n=s.length();
                    if(s.substr(0,n/2) == s.substr(n/2))
                    {
                        count++;
                        for(int i=0;i<n/2;i++)
                            s.pop_back();
                        flag=1;
                    }
                    else
                    {
                        count++;
                        s.pop_back();
                    }
                }
                else
                {
                    count+=s.length();
                    break;
                }
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends