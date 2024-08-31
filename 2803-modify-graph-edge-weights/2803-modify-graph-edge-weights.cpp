class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for (auto& edge : edges) {
            int firstNode = edge[0], secondNode = edge[1], edgWt = edge[2];
            if (edgWt == -1) continue;
            adj[firstNode].emplace_back(secondNode, edgWt);
            adj[secondNode].emplace_back(firstNode, edgWt);
        }
        int dist = shortestPath(adj,n,source,destination);

        if(dist < target) return {};
        
        bool isTarget = (dist == target);

        for(int ind=0;ind<edges.size();ind++){
            int i = edges[ind][0],j = edges[ind][1],wt = edges[ind][2];
            if(wt != -1) continue;

            wt = isTarget ? 1e9 : 1;
            adj[i].push_back({j,wt});
            adj[j].push_back({i,wt});
            
            if(!isTarget){
                dist = shortestPath(adj,n,source,destination);
                if(dist <= target){
                    wt += (target - dist);
                    isTarget = true;
                }
            }
            edges[ind][2] = wt;
        }
        return isTarget ? edges : vector<vector<int>>{};
    }
private:
    int shortestPath(unordered_map<int, vector<pair<int, int>>> adj,int n,int source,int destination){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[source] = 0;
        pq.push({dist[source],source});

        while(!pq.empty()){
            auto [wt,node] = pq.top();
            pq.pop();
            for(auto [i,j]: adj[node]){
                if(dist[i]>wt+j){
                    dist[i] = wt+j;
                    pq.push({dist[i],i});
                }
            }
        } 
        return dist[destination];
    }
};
