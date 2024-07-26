class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>graph(n,vector<int>(n,1e9));
        for(auto it: edges){
            graph[it[0]][it[1]] = it[2];
            graph[it[1]][it[0]] = it[2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) graph[i][j] = 0;
                for(int k=0;k<n;k++){
                    graph[j][k] = min(graph[j][k],graph[j][i]+graph[i][k]);
                }
            }
        }
        int ans = 0;
        int min_num = n;
        for(int i=0;i<n;i++){
            int val = 0;
            for(int j=0;j<n;j++){
                if(graph[i][j] <= distanceThreshold) ++val;
            }
            // cout<<val<<endl;
            if(val<=min_num){
                min_num = val;
                ans = i;
            }
        }
        return ans;
    }
};