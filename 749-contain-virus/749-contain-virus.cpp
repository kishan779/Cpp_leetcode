class Solution {
public:
    int n,m;
    int d[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    int find(vector<int>& nums,int i){
        if(nums[i]==-1) return i;
        else return nums[i] = find(nums,nums[i]);
    }
    void union_(vector<int>& nums,int x,int y){
        int i = find(nums,x), j = find(nums,y);
        if(i!=j){
            if(i<j) nums[j] = i;
            else nums[i] = j;
        }
    }
    int dfs(vector<vector<int>>& nums,int i,int j){  // returns no. of wall arround the infected region
        if(nums[i][j]==0) return 1;
        nums[i][j] = 2;
        int re = 0;
        for(int k = 0; k<4;++k){
            int x = i+d[k][0], y = j+d[k][1];
            if(!(x<0||x>=n||y<0||y>=m) && nums[x][y]!=2) re+=dfs(nums,x,y);
        }
        return re;
    }
    int dfs2(vector<vector<int>>& nums,vector<int>& dp,int p){  // returns no. of blocks going to infect in next 1 sec.
        int re = 0;
        for(int i = 0; i<n;++i){
            for(int j = 0; j<m; ++j){
                if(nums[i][j]!=0) continue;
                for(int k = 0; k<4;++k){
                    int x = i+d[k][0], y = j+d[k][1];
                    if(!(x<0||x>=n||y<0||y>=m) && nums[x][y]==1 && p==find(dp,x*m+y)){
                        re++; break;
                    }
                }
            }
        }
        return re;
    }
    int containVirus(vector<vector<int>>& nums) {
         n = nums.size(), m = nums[0].size();
        vector<int> dp(n*m+1,-1);
        for(int i = 0; i<n;++i){  // union all adjacent infected region
            for(int j = 0; j<m; ++j){
                if(nums[i][j]!=1) continue;
                for(int k = 0; k<4;++k){
                    int x = i+d[k][0], y = j+d[k][1];
                    if(!(x<0||x>=n||y<0||y>=m) && nums[x][y]==1)
                        union_(dp,i*m+j,x*m+y);
                }
            }
        }
        int re = 0;
        while(1){
            int p = -1,max_ = -1;
            for(int k = 0; k<n*m;++k){  // find the region going to infect maximum uninfected region in next 1 sec.
                int i = k/m; int j = k-i*m;
                if(dp[k]==-1 && nums[i][j]==1){
                    int t = dfs2(nums,dp,k);  // no. of uninfected going to infect in next 1 sec by some infect whose parent node if k.
                    if(t>max_){
                        max_ = t; p = k;
                    }
                }
            }
            if(p==-1) break; // break if there are no blocks to infect
            int i = p/m; int j = p-i*m;
            int tre = dfs(nums,i,j); // no. of wall
            re+=tre;
            vector<pair<int,int>> temp;
            for(int i = 0; i<n;++i){  // infect the uninfected region in next sec.
                for(int j = 0;j<m;++j){
                    if(nums[i][j]!=0) continue;
                    bool is= 0;
                    for(int k = 0; k<4;++k){
                        int x = i+d[k][0], y = j+d[k][1];
                        if(!(x<0||x>=n||y<0||y>=m) && nums[x][y]==1) {is = 1; break;}
                    }
                    if(is) temp.push_back({i,j});
                }
            }
            for(int i = 0; i<temp.size();++i) nums[temp[i].first][temp[i].second] = 1;  
            for(int k = 0; k<temp.size(); ++k){  // union newly infected cells to there adjacent
                int i = temp[k].first, j = temp[k].second;
                for(int l = 0; l<4;++l){
                    int x = i+d[l][0], y = j+d[l][1];
                    if(!(x<0||x>=n||y<0||y>=m) && nums[x][y]==1) union_(dp,i*m+j,x*m+y);
                } 
            }
        }
        return re;
    }
};
// Try for larger TestCase
// [[0,0,1,1,1,0,1,0,0,0],[1,1,1,0,0,0,1,1,0,1],[0,0,0,0,0,0,1,0,0,0],[0,0,0,0,1,0,1,0,0,0],[1,0,0,0,1,1,1,0,0,0],[0,0,0,1,0,1,1,0,0,0],[1,0,0,0,0,1,0,0,0,1],[1,0,0,0,0,0,0,0,0,1],[0,1,0,0,0,0,0,0,1,0],[1,1,0,0,0,1,0,1,0,0]]
