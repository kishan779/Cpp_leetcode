//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution

{

  public:

  int maxWeightCell(int n, vector<int> Edge)

  {

      // code here

      int weight[n];

      memset(weight,0,sizeof(weight));

      for(int i=0;i<n;i++)

        {

          if(Edge[i]!=-1)

             weight[Edge[i]]+=i;

        }

      int max_weight=INT_MIN;

      int max_index=INT_MIN;

      for(int i=0;i<n;i++)

        {

           if(weight[i]>max_weight)

              {

                 max_weight=weight[i];

                 max_index=i;

              }

           else if(weight[i]==max_weight)

              {

                 max_index=max(max_index,i);

              }

        }

     return max_index;

 

   }

};



//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends