//{ Driver Code Starts
// Initial Template for C++

// Initial Template for C++
// Back-end complete function Template for C++
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
#define ll long long
    ll giveMeLCM(ll a, ll b, ll c)
    {
        ll lcm = (a * b) / __gcd(a, b);
        return (lcm * c) / __gcd(lcm, c);
    }
    long long lcmTriplets(long long n)
    {
        if (n == 1)
            return 1;
        if(n==2)
            return 2;
        if (n & 1)
            return giveMeLCM(n, n - 1, n - 2);
        ll GCD = __gcd(n, n - 3);
        if (GCD == 1)
            return giveMeLCM(n, n - 1, n - 3);
        return giveMeLCM(n - 1, n - 2, n - 3);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    }
}
// } Driver Code Ends