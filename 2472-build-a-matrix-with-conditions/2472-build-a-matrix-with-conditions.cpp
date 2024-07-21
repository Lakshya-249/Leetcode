class Solution {
    vector<int> toposort(vector<vector<int>>& conditions, int k) {
        vector<vector<int>> graph(k + 1);
        vector<int> indegree(k + 1, 0);
        for (auto& condition : conditions) {
            graph[condition[0]].push_back(condition[1]);
            ++indegree[condition[1]];
        }
        
        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            for (int neighbor : graph[node]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return order.size() == k ? order : vector<int>();
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = toposort(rowConditions,k);
        vector<int> colOrder = toposort(colConditions,k);

        if(rowOrder.empty() || colOrder.empty()) return {};
        vector<vector<int>>ans(k,vector<int>(k,0));
        unordered_map<int,int>rowMap,colMap;
        for(int i=0;i<k;i++){
            rowMap[rowOrder[i]] = i;
            colMap[colOrder[i]] = i;
        }
        for(int i=1;i<=k;i++){
            ans[rowMap[i]][colMap[i]] = i;
        }
        return ans;
    }
};