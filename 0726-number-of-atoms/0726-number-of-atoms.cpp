class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string,int>>st;
        st.push({});

        int i = 0, n = formula.size();

        while(i<n){
            if(formula[i] == '('){
                st.push({});
                i++;
            }else if(formula[i] == ')'){
                unordered_map<string,int>top = st.top();
                st.pop();
                i++;
                int start = i;
                while(i<n && isdigit(formula[i])){
                    i++;
                }
                int mult = start< i ? stoi(formula.substr(start,i-start)):1;
                for(auto &kv: top) st.top()[kv.first] += kv.second * mult;
            }else{
                int start = i++;
                while(i<n && islower(formula[i])){
                    i++;
                }
                string elem = formula.substr(start,i-start);
                start = i;
                while(i<n && isdigit(formula[i])) i++;
                int count = start<i ? stoi(formula.substr(start,i-start)):1;
                st.top()[elem] += count;
            }
        }
        unordered_map<string,int> res = st.top();
        vector<string> elem;
        for(auto it: res) elem.push_back(it.first);
        sort(elem.begin(),elem.end());
        string result;
        for(auto it: elem){
            result += it;
            if(res[it] > 1){
                result += to_string(res[it]);
            }
        }
        return result;
    }
};