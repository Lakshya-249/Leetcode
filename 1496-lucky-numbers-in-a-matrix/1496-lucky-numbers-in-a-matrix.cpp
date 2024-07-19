class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>small,big;
        for(auto it: matrix){
            int smallnum = *min_element(it.begin(),it.end());
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
        for(auto it: small){
            for(auto itr: big){
                if(it == itr) return {it};
            }
        }
        return {};
    }
};