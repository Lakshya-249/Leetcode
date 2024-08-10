class Solution {
    void traversal(int row,int col,vector<vector<int>>&vec,vector<vector<int>>&vis){
        vis[row][col] = 1;
        int n = vec.size(), m = vec[0].size();
        int dicrow[] = {-1,0,1,0};
        int diccol[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = row+dicrow[i], ncol = col+diccol[i];
            if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || vec[nrow][ncol]!=0 || vis[nrow][ncol]){
                continue;
            }
            traversal(nrow,ncol,vec,vis);
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>>vec(n*3,vector<int>(n*3,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    vec[i*3][j*3+2] = 1;
                    vec[i*3+1][j*3+1] = 1;
                    vec[i*3+2][j*3] = 1;
                }else if(grid[i][j]=='\\'){
                    vec[i*3][j*3] = 1;
                    vec[i*3+1][j*3+1] = 1;
                    vec[i*3+2][j*3+2] = 1;
                }
            }
        }
        int ans = 0;
        vector<vector<int>>vis(n*3,vector<int>(n*3,0));
        for(int i=0;i<n*3;i++){
            for(int j=0;j<n*3;j++){
                if(vec[i][j]==0 && !vis[i][j]){
                    ans++;
                    traversal(i,j,vec,vis);
                }
            }
        }
        return ans;
    }
};