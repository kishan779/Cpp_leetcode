//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {

  public:

    string baseEquiv(int n, int m){

        // code here

        string s="";

        for(int i=2;i<=32;i++)

        {

            int n1=n;

            int c=0;

            

            int flag=0;

            while(n1>0)

            {

                int mod=n1%i;

                c=c+1;

                if(c>m)

                {

                    flag=1;

                    break;

                }

                n1=n1/i;

            }

            if(c==m)

            {

               s="Yes";

               return s;

            }

        }

        s="No";

        return s;

    }

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends