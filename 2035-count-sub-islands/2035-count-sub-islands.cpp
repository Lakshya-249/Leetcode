class Solution {
    bool isSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2,
    vector<vector<int>>& vis,int x,int y){
        int n = grid1.size();
        int m = grid1[0].size();
        vis[x][y] = 1;
        int nrow[] = {0,1,0,-1};
        int ncol[] = {-1,0,1,0};
        bool isSubisland = grid1[x][y];
        for(int i=0;i<4;i++){
            int row = nrow[i] + x;
            int col = ncol[i] + y;
            if(row<n && row>=0 && col<m && col>=0 && !vis[row][col] && grid2[row][col]){
                bool val = isSubIsland(grid1,grid2,vis,row,col);
                isSubisland = isSubisland && val;
            }
        }
        return isSubisland;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int cnt = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j]){
                    if(isSubIsland(grid1,grid2,vis,i,j)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};