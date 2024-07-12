class Solution {
    int value(string &s,string str,int val){
        int ans = 0;
        string st = "";
        for(auto it: s){
            if(!st.empty() && st.back() == str[0] && it == str[1]){
                ans += val;
                st.pop_back();
            }else st += it;
        }
        s = st;
        return ans;
    }
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if(x>y){
            ans += value(s,"ab",x);
            ans += value(s,"ba",y);
        }else{
            ans += value(s,"ba",y);
            ans += value(s,"ab",x);
        }
        return ans;
    }
};