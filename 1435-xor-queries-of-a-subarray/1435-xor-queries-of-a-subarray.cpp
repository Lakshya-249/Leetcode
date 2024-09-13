class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>vec(n,0);
        vector<int>ans(queries.size(),0);

        int nxor = 0;
        for(int i=0;i<n;i++){
            nxor ^= arr[i];
            vec[i] = nxor;
        }
        for(int i=0;i<queries.size();i++){
            int k = queries[i][0];
            int j = queries[i][1];
            if(k==0) ans[i] = vec[j];
            else ans[i] = vec[j] ^ vec[k-1];
        }
        return ans;
    }
};