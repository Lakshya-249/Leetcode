class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir= {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>ans;
        int n = rows*cols;
        for(int step=1,direction=0;ans.size()<n;){
            for(int i=0;i<2;i++){
                for(int j=0;j<step;j++){
                    if(rStart<rows && rStart>=0 && cStart<cols && cStart>=0){
                        ans.push_back({rStart,cStart});
                    }
                    rStart += dir[direction][0];
                    cStart += dir[direction][1];
                }
                direction = (direction+1)%4;
            }
            step++;
        }
        return ans;
    }
};