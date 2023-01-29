//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int solve(int a, int b) 
    {
        // code here
        if(a==b) return 0;
        int small = a;
        int large = b;
        
        if(a>b)
        {
            large = a;
            small = b;
        }
        
        int count = 0;
        while(large!=small)
        {
            large = large&small;
            if(large < small)
            {
                int temp = small;
                small = large;
                large = temp;
            }
            count++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends