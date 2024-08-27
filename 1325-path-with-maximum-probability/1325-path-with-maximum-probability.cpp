class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>,vector<pair<double,int>>>pq;
        vector<double>dist(n,0);
        pq.push({1.0,start_node});
        dist[start_node] = 1.0;
        while(!pq.empty()){
            auto [wt,edge] = pq.top();
            pq.pop();
            if(edge == end_node) return wt;
            for(auto [i,j]: adj[edge]){
                double val = wt*j;
                if(dist[i]<val){
                    dist[i] = wt*j;
                    pq.push({dist[i],i});
                }
                
            }
        }
        return 0.0;
    }
};