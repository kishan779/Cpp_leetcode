//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++



class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int N){
      int i=0,j=0;
      long long int ans=0;
      while(i<N && j<N){
          if(arr[i]==0 || arr[i]<0)
          i++;
          else if(arr[j]==0 || arr[j]>0)
          j++;
          else if(arr[i]>0 && arr[j]<0){
              ans+=abs(j-i)*(min(abs(arr[i]),abs(arr[j])));
              if(abs(arr[i])<abs(arr[j])){
                  arr[j]+=arr[i];
                  arr[i]=0;
              }
              else if(abs(arr[i])>abs(arr[j]))
              {
                  arr[i]+=arr[j];
                  arr[j]=0;
              }
              else
              arr[i]=arr[j]=0;
          }
      }
      return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends