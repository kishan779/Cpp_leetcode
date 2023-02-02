//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//User function Template for C++
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class Solution {
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = 0, r = 0;
        while (i >= 0 and i < n and j >= 0 and j < m) {
            if (matrix[i][j]) {
                matrix[i][j] = 0;
                r = (r+1) % 4;
            }
            i += dx[r], j += dy[r];
        }
        return {min(max(0, i), n-1), min(max(0, j), m-1)};
    }
};



//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends