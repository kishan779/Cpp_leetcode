//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution {
  public:
    long long maxGcd(int n) {
        int c=1;
        long long sum=n;
        for(long long int i=n-1;i>=2;i--)
        {
            if(__gcd(sum,i)==1)
            {
                sum=sum*i;
                c++;
            }
            if(c>=4)
            {
                break;
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends