class Solution {
    int give_Integer(int val){
        int ans = 0;
        while(val>0){
            ans += val%10;
            val /= 10;
        }
        return ans;
    }
public:
    int getLucky(string s, int k) {
        string str = "";
        for(auto it:s){
            int val = (it-'a')+1;
            str += to_string(val);
        }
        int res = 0;
        for(auto it: str){
            res += (it-'0');
        }
        while(k-1>0){
            res = give_Integer(res);
            k--;
        }
        return res;
    }
};