class Solution {
    void solution(vector<vector<int>>& ans,int ind,int target,
    int n,vector<int>val,vector<int> candidates){
        if(target == 0) ans.push_back(val);
        for(int i=ind;i<n;i++){
            if(i>ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            val.push_back(candidates[i]);
            solution(ans,i+1,target-candidates[i],n,val,candidates);
            val.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>val;
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        solution(ans,0,target,n,val,candidates);
        return ans;
    }
};