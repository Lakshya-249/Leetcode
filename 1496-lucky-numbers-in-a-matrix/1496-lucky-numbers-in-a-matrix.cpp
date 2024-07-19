class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>small,big;
        for(auto it: matrix){
            int smallnum = INT_MAX;
            // cout<<smallnum;
            for(auto itr:it){
                smallnum = min(smallnum,itr);
            }
            small.push_back(smallnum);
        }
        cout<<small[0];
        int n = matrix[0].size();
        int m = matrix.size();
        for(int i=0;i<n;i++){
            int bignum = 0;
            for(int j=0;j<m;j++){
                bignum = max(bignum,matrix[j][i]);
            }
            big.push_back(bignum);
        }
        vector<int>ans;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j] == small[i] && matrix[i][j] == big[j]){
        //             ans.push_back(matrix[i][j]);
        //         }
        //     }
        // }
        for(auto it: small){
            for(auto itr: big){
                if(it == itr) ans.push_back(it);
            }
        }
        return ans;
    }
};