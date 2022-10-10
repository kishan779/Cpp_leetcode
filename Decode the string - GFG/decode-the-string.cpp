//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
       stack<char> sk;
        string prev="";
        for(int i=0;i<s.size();i++)
        {
            sk.push(s[i]);
            if(sk.top()==']')
            {
                sk.pop();
                prev="";
                while(sk.top()!='[')
                {
                    prev+=(sk.top());
                    sk.pop();
                }
                sk.pop();
                string temp="";
                char ch=sk.top();
                while(isdigit(ch) && sk.size())
                {
                    temp+=ch;
                    sk.pop();
                    if(sk.size())
                    ch=sk.top();
                    else ch='a';
                }
                reverse(begin(temp), end(temp));
                int cnt=stoi(temp);
                temp=prev;
                while(cnt>1)
                {
                    prev+=temp;
                    cnt--;
                }
                int k=0;
                reverse(begin(prev), end(prev));
                while(k<prev.size())
                    sk.push(prev[k++]);
            }
        }
        string ans="";
            while(sk.size()!=0)
            {
                ans+=(sk.top());
                sk.pop();
            }
            reverse(begin(ans), end(ans));
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends