class Solution {
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int row,int col,int n,int m){
        vis[row][col] = 1;
        int direcR[] = {-1,0,1,0};
        int direcC[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow= row+direcR[i], ncol= col+direcC[i];
            if(nrow>=n || nrow<0 || ncol<0 || ncol>=m || 
            !grid[nrow][ncol] || vis[nrow][ncol]) continue;
            // cout<<island<<" ";
            dfs(grid,vis,nrow,ncol,n,m);
        }
    }

    int countIslands(vector<vector<int>>& grid,int n,int m){
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j] || vis[i][j]) continue;
                count++;
                dfs(grid,vis,i,j,n,m);    
            }
        }
        return count;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(countIslands(grid,n,m)!=1) return 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    if(countIslands(grid,n,m) != 1)return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};