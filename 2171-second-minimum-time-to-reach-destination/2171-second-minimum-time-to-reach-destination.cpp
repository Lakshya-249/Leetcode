class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>>graph;
        for(auto it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>>q;
        q.push({0,1});

        vector<int> visit(n+1,0);
        vector<int> dist(n+1,-1);

        while(!q.empty()){
            auto [t,node] = q.top();
            q.pop();

            if(dist[node] == t || visit[node] >= 2) continue;

            visit[node]++;
            dist[node] = t;

            if(node == n && visit[node] == 2) return dist[node];

            int val = t/change;
            if(val&1) t = (val+1)*change;
            // cout<<t<<endl;

            for(auto it: graph[node]){
                q.push({time+t,it});
            }
        }
        return -1;
    }
};