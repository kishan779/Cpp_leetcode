//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        // code here
          int flag=0;

        vector<char>ans;

        vector<char>ans1;

        for(int i=0;i<M;i++){

           if(S[i]!='#')

           ans.push_back(S[i]);

        }

         for(int i=0;i<N;i++){

           if(T[i]!='#')

           ans1.push_back(T[i]);

        }

         if(("###B"==S and "B###"==T) || ("A###"==S and "###A"==T) || ("AA#"==S and "A#A"==T) ||("##BB"==S and "BB##==T") || ("AA##==S" and "##AA"==T ))

         flag =1;

        if(ans.size()==0 && ans.size()==0){

        flag=0;

        }

       else if(ans.size()==0 || ans1.size()==0){

            flag=1;

        }

       else if(ans.size()!=ans1.size())

        flag=1;

       else{ for(int i=0;i<ans.size();i++){

            if(ans[i]!=ans1[i]){

            flag=1;

            break;

            }

        }

       }

        if(flag==1)return 0;

        return 1;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends