class Solution {
    vector<int>ans;
    void dfs(int i,int n){
        if(i>n) return;
        int cur = i;
        ans.push_back(cur);
        for(int i=0;i<=9;i++){
            int temp = cur*10 + i;
            dfs(temp,n);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=9;i++){
            dfs(i,n);
        }
        return ans;
    }
};