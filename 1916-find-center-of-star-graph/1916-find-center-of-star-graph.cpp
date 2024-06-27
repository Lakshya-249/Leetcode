class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mpp;
        for(auto it:edges){
            mpp[it[0]].push_back(it[1]);
            mpp[it[1]].push_back(it[0]);
            if(mpp[it[0]].size()>1){
                return it[0];
            }
            if(mpp[it[1]].size()>1) return it[1];
        }
        return -1;
    }
};