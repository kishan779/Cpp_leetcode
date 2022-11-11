//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    bool checkprime(int x)

    {  for(int i=2;i<=sqrt(x);i++)

        {

            if(x%i==0)

                return 0;

        }

        return 1;

    }

    

    string isSumOfTwo(int N){

        // code here

        if(N==1 || N==2)

        {

            return "No";

        }

        

        if(N%2==0)//goldblech conjecture

        {// two even can always be presented as sum of two prime nos

            return "Yes";

        }

        

        //simple hint is that odd no. is that sum of a even no. and odd no.

        //now only even prime is 2 thus check if N-2 is prime or not 

        

        if(checkprime(N-2))

            return "Yes";        

        

        return "No";

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
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends