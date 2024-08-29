class Solution {
    void traverse(vector<vector<int>>& graph,vector<int>& vis,int ind){
        vis[ind] = 1;
        for(auto it: graph[ind]){
            if(!vis[it]){
                traverse(graph,vis,it);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> graph(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || 
                stones[i][1] == stones[j][1]){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                traverse(graph,vis,i);
                cnt++;
            }
        }
        return n - cnt;
    }
};