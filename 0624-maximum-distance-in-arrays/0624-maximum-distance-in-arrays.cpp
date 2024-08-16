class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxnum = arrays[0][0];
        int minnum = arrays[0].back();
        int ans = 0;

        for(auto it: arrays){
            int manum = it.back();
            int minum = it[0];
            ans = max(ans,manum-minnum);
            ans = max(ans,maxnum-minum);
            maxnum = max(manum,maxnum);
            minnum = min(minnum,minum);
        }
        return ans;
    }
};