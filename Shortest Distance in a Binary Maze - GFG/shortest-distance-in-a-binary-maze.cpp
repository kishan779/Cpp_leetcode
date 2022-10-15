//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,

                     pair<int, int> destination) 

    {

        int n=grid.size();

        int m=grid[0].size();

        queue<pair<int,pair<int,int>>>q;

        vector<vector<int>>vis(n,vector<int>(m,0));

        q.push({0,source});

        vis[source.first][source.second]=1;

        while(!q.empty())

        {

            int dist=q.front().first;

            int x=q.front().second.first;

            int y=q.front().second.second;

            if(destination.first==x && destination.second==y)

            {

                return dist;

            }

            q.pop();

            if(x+1<n && vis[x+1][y]==0 && grid[x+1][y]==1)

            {

                q.push({dist+1,{x+1,y}});

                vis[x+1][y]=1;

            }

            if(x-1>=0 && vis[x-1][y]==0 && grid[x-1][y]==1)

            {

                q.push({dist+1,{x-1,y}});

                vis[x-1][y]=1;

            }

            if(y+1<m && vis[x][y+1]==0 && grid[x][y+1]==1)

            {

                q.push({dist+1,{x,y+1}});

                vis[x][y+1]=1;

            }

            if(y-1>=0 && vis[x][y-1]==0 && grid[x][y-1]==1)

            {

                q.push({dist+1,{x,y-1}});

                vis[x][y-1]=1;

            }

        }

        

        return -1;

    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends