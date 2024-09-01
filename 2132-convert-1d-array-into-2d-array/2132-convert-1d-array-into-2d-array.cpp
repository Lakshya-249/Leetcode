class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz = original.size();
        if(sz != m*n)return {};
        vector<vector<int>>ans(m);
        for(int i=0;i<m;i++){
            for(int j=i*n;j<(i+1)*n;j++){
                ans[i].push_back(original[j]);
            }
        }
        return ans;
    }
};