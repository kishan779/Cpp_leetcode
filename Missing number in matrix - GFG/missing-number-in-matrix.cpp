//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    long long int MissingNo(vector<vector<int> >& matrix) {
        // Code here
        int n=matrix.size();
        vector<long long int> row(n), col(n);
        int x=0, y=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                row[i] += matrix[i][j];
                col[j] += matrix[i][j];
                if(matrix[i][j]==0){
                    x = i; y = j;
                }
            }
        }
        long long int a=0, b=0;
        for(int i=0; i<n; i++){
            a += matrix[i][i];
            b += matrix[i][n-i-1];
        }
        bool flag = x==y;
        bool seen = x==(n-y-1);
        long long int sum=-1;
        for(int i=0; i<n; i++){
            if(i!=x && i!=y){
                if(row[i]!=col[i])   return -1;
                if(!flag && row[i]!=a)  return -1;
                if(!seen && row[i]!=b)  return -1;
                if(sum>-1 && row[i]!=sum)   return -1;
                sum = row[i];
            }
        }
        long long int res = sum-row[x];
        if(flag)    a += res;
        if(seen)    b += res;
        row[x] += res;
        col[y] += res;
        if(a!=b)    return -1;
        if(row[x]!=col[y])  return -1;
        if(res<=0)  return -1;
        return res;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends