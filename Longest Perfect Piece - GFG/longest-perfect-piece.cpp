//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int longestPerfectPiece(int arr[], int n) {
        // code here
         vector<int>v,v1;
        int cnt=1;
        v.push_back(arr[0]);
        for(int i=1; i<n; i++)
        {
            if(v.back()!=arr[i])
            {
                v.push_back(arr[i]);
                v1.push_back(cnt);
                cnt=1;
            }
            else if(v.back()==arr[i])
            {
                cnt++;
            }
        }
        v1.push_back(cnt);
        
        if(v.size()==1) return v1[0];
        
        int sum=0, cnt1=0,a,b;
        
        for(int i=0; i<v.size(); i++)
        {
            cnt1=0;
            a=v[i]; b=v[i+1];
            
            if(abs(a-b)<=1)
            {
                for(int j=i; j<v.size(); j++)
                {
                    if(v[j]==a || v[j]==b)
                    {
                        cnt1+=v1[j];
                    }
                    else break;
                }
                sum=max(sum,cnt1);
            }
        }
        if(sum==0) sum=1;
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends