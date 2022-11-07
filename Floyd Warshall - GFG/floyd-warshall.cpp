//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    for(int k=0;k<n;k++){
	        for(int row=0;row<n;row++){
	            for(int col=0;col<n;col++){
	                if(row==k or col==k or matrix[row][k]==-1 or matrix[k][col]==-1) continue;
	                else if(matrix[row][col]==-1) matrix[row][col]=1e6;
	                matrix[row][col] = min(matrix[row][col], matrix[row][k]+matrix[k][col]);
	            }
	        }
	    }
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends