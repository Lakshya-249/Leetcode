class Solution {
    bool issafe(vector<vector<char>>&board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c && i!=row) return false;
            if(board[row][i]==c && i!=col) return false;
            int nrow = 3*(row/3) + i/3;
            int ncol = 3*(col/3) + i%3;
            if(board[nrow][ncol] == c && (nrow!=row && ncol!=col)) return false;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<board.size();row++){
            for(int col=0;col<board[0].size();col++){
                if(board[row][col]=='.') continue;
                if(!issafe(board,row,col,board[row][col])) return false;
            }
        }
        return true;
    }
};