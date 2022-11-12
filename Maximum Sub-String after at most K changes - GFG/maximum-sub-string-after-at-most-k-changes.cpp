//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    int si = 0;
		    int ei = 0;
		    unordered_map<char,int> freq;
		    int n = s.length();
		    int ans = 0;
		    int maxfreq = 0;
		    while(ei < n)
		    {
		        freq[s[ei]]++;
		        maxfreq = max(maxfreq,freq[s[ei]]);
		        if((ei-si+1 - maxfreq) > k)
		        {
		            freq[s[si]]--;
		            si++;
		        }
		        ans = max(ans,(ei-si+1));
		        ei++;
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends