class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = cost.size();
        vector<vector<long long>>graph(26,vector<long long>(26,1e9));
        for(int i=0;i<n;i++){
            int val = graph[original[i]-'a'][changed[i]-'a'];
            graph[original[i]-'a'][changed[i]-'a'] = min(val,cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){ 
                    graph[j][j] = 0;
                    graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
        for(auto it: graph){
            for(auto itr: it){
                if(itr >= 1e9) cout<<"I"<<" ";
                else cout<<itr<<" ";
            }
            cout<<endl;
        }
        long long res = 0;
        for(int i=0;i<target.size();i++){
            // if((source[i]-'a') == (target[i]-'a')) continue;
            if(graph[source[i]-'a'][target[i]-'a'] == 1e9) return -1;
            res += graph[source[i]-'a'][target[i]-'a'];
        }
        return res;
    }
};