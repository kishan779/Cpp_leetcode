//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          unordered_map<char, int>map;
          int sum=0;
          int maxi = INT_MIN;
          int i;
          string str="";
          string ans;
          
          for(int i=0;i<n;i++){
              map[x[i]] = b[i];
          }
          for(i=0;i<w.size();i++){
              if(sum<0){
                  str = "";
                  sum=0;
              }
              if(map.find(w[i])!=map.end()){
                  sum += map[w[i]];
                  str += w[i];
              }
              else{
                  str += w[i];
                  if(islower(w[i])){
                      sum += ((w[i]-'a')+97);
                  }
                  else{
                      sum += ((w[i]-'A')+65);
                  }
              }
              
              if(sum>maxi){
                  maxi = sum;
                  ans = str;
              }
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
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends