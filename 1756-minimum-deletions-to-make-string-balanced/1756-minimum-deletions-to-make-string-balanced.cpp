class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int res = 0;
        stack<int>st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() && (st.top()=='b' && s[i] == 'a')){
                st.pop();
                res++;
            }
            else st.push(s[i]);
        }
        return res;
    }
};