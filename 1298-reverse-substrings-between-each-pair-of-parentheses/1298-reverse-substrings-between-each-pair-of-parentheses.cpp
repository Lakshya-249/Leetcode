class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        string res = "";
        for(auto it:s){
            if(it == ')'){
                string str = "";
                while(st.top() != '('){
                    char val = st.top();
                    st.pop();
                    str += val;   
                }
                st.pop();
                for(auto itr :str) st.push(itr);
            }else st.push(it);
        }
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};