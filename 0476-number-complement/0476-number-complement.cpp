class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int i = 0;
        while(num){
            ans += pow(2,i)*(num&1?0:1);
            num = num>>1;
            i++;
        }
        return ans;
    }
};