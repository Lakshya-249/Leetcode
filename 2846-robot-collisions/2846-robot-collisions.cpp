class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>>st;
        int n = healths.size();
        vector<vector<int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({positions[i],healths[i],directions[i],i});
        }
        sort(vec.begin(),vec.end());
        for(auto it: vec){
            if(it[2] == 'R' || st.empty() || st.back()[2] == 'l'){
                st.push_back(it);
            }
            else if(it[2] == 'L'){
                bool flag = true;
                while(!st.empty() && st.back()[2] == 'R' && flag){
                    int health = st.back()[1];
                    if(it[1] > health){
                        st.pop_back();
                        it[1]--;
                    }else if(it[1] < health){
                        st.back()[1]--;
                        flag = false;
                    }else{
                        st.pop_back();
                        flag = false;
                    }
                }
                if(flag){
                    st.push_back(it);
                } 
            }
        }
        vector<int>res;
        sort(st.begin(),st.end(),[](vector<int>&a ,vector<int>&b){
            return a[3]<b[3];
        });

        for(auto it: st) res.push_back(it[1]);
        return res;
    }
};