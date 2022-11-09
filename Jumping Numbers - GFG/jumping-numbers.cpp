//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   long long bfs(long long X,long long num,vector<long long>& res)
 {
     queue<long long> q;
     q.push(num);
     while(!q.empty())
     {
         num=q.front();
         q.pop();
         if(num<=X)
         {
             res.push_back(num);
             int last=num%10;
             
             if(last==0)
             q.push(num*10 + last+1);
             
             else if(last==9)
             q.push(num*10+ last-1);
             
             else
             {
                 q.push(num*10 + last-1);
                 q.push(num*10 +last+1);
             }
         }
     }
 }
   long long jumpingNums(long long X) {
       // code here
       //use bfs or dfs
       vector<long long> res;
       for(int i=1;i<=9 && i<=X;i++)
       {
           bfs(X,i,res);
       }
       return *max_element(res.begin(),res.end());

   }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends