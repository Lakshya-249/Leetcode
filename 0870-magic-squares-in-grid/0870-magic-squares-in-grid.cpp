class Solution {
    bool isSafe(vector<vector<int>>& grid,int row,int col){
        int check[10] = {0};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int num = grid[row+i][col+j];
                if(num<1 || num>9 || check[num]) return false;
                check[num]++;
            }
        }

        int diag1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int diag2 = grid[row+2][col] + grid[row+1][col+1] + grid[row][col+2];

        if(diag1 != diag2) return false;
        int nrow[3] = {0};
        for(int i=0;i<3;i++){
            nrow[i] = grid[row+i][col] + grid[row+i][col+1] + grid[row+i][col+2];
        }
        if(!(nrow[1]==diag1 && nrow[2]==diag1 && nrow[0]==diag1)) return false;
        int ncol[3] = {0};
        for(int i=0;i<3;i++){
            ncol[i] = grid[row][col+i] + grid[row+1][col+i] + grid[row+2][col+i];
        }
        if(!(ncol[0]==diag1 && ncol[1]==diag1 && ncol[2]==diag1)) return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
       int ans = 0;
       int m = grid.size();
       int n = grid[0].size();
       for(int row=0;row+2<m;row++){
        for(int col=0;col+2<n;col++){
            if(isSafe(grid,row,col)) ans++;
        }
       }
       return ans;
    }


};