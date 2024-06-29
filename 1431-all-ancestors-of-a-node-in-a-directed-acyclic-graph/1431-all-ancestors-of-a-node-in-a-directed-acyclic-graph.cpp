class Solution {
    void dfs(vector<vector<int>>&ans,int val,int curr,
    vector<vector<int>>& graph,vector<int>&visit){
        visit[curr] = 1;
        for(auto it:graph[curr]){
            if(!visit[it]){
                ans[it].push_back(val);
                dfs(ans,val,it,graph,visit);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans(n);
        vector<vector<int>>graph(n);
        for(auto it: edges){
            graph[it[0]].push_back(it[1]);
        }
        for(int i=0;i<n;i++){
            vector<int>visit(n,0);
            dfs(ans,i,i,graph,visit);
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};