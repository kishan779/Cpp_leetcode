//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution
{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	    int as=A.size();
	    int bs=B.size();
	    int i,j;
	    if(as>=bs)
	    { 
	        i=as-1;
	        j=bs-1;
	        
	    }
	    else
	    {
	        
	        i=bs-1;
	        j=as-1;
	        string temp=A;
	        A=B;
	        B=temp;
	    }
	    char c='0';
	    string s;
	    for(; i>=0; i--, j--)
	    {
	        if(j>=0)
	        {
	            if(A[i]==B[j] && A[i]=='0')
	            {
	                s+=c;
	                c='0';
	            }
	            else if(A[i]==B[j] && A[i]=='1')
	            {
	                if(c=='0')
	                {
	                    s+='0';
	                    c='1';
	                }
	                else 
	                {
	                    s+='1';
	                    c='1';
	                    
	                }
	            }
	            else 
	            {
	                if(c=='0')
	                {
	                    s+='1';
	                }
	                else {
	                    s+='0';
	                    c='1';
	                }
	            }
	        }
	        else 
	        {
	            if(A[i]==c && c=='0')s+='0';
	            else if(A[i]==c && c=='1'){
	                s+='0';
	            }
	            else 
	            {
	                s+='1';
	                c='0';
	            }
	        }
	    }
	    s+=c;
	    int f=0;
	    string res;
	    for(int k=s.size()-1;  k>=0; k--)
	    {
	        if(s[k]=='1')f=1;
	        if(f==1)
	        {
	            res+=s[k];
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends