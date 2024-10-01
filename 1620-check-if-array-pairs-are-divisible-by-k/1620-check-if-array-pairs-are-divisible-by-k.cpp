class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>fq(k,0);
        for(int it: arr){
            int rem = it%k;
            if(rem < 0) rem += k;
            fq[rem]++;
        }

        if(fq[0]%2 != 0) return false;

        for(int i=1;i<=k/2;i++){
            if(fq[i] != fq[k-i]) return false;
        }
        return true;
    }
};