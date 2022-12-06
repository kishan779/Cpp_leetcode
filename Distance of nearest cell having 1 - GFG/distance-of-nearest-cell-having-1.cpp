//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    // bfs algorithm will be used only
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>>dist(n, vector<int>(m, 0));
	    vector<vector<int>>vis(n, vector<int>(m, 0));
	    queue<pair<pair<int, int>, int>> q;
	    
	   //pushing all the elements whose value is 1 and marking them at a distance of 0;
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < m ; j++){
	            if(grid[i][j]==1){
	                vis[i][j] = 1;
	                q.push({{i, j}, 0});
	            }
	        }
	    }
	    
	    // moving in all four directions
	    int delrow[] = {1, 0, -1, 0};
	    int delcol[] = {0, -1, 0, +1};
	    
	    while(!q.empty()){
	        int row = q.front().first.first; //row
	        int col = q.front().first.second; //col
	        int steps = q.front().second; //steps
	        q.pop();
	        dist[row][col] = steps;  // marking steps
	        
	        for(int i = 0; i < 4; i++){
	            int nrow = row + delrow[i];
	            int ncol = col + delcol[i];
	            if(nrow>=0 && nrow<n && ncol>=0 & ncol<m && !vis[nrow][ncol]){
	                vis[nrow][ncol] = 1;
	                q.push({{nrow, ncol}, steps+1}); //adding +1 to next 0's distance
	            }
	        }
	    }
	    return dist;
	    
	}
};





//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends