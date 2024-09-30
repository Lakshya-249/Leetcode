class AllOne {
public:
    map<string,int>mpp;
    set<pair<int,string>>st;
    AllOne() {}
    
    void inc(string key) {
        int n = mpp[key];
        mpp[key]++;
        st.erase({n, key});
        st.insert({n+1, key});
    }
    
    void dec(string key) {
        int n = mpp[key];
        mpp[key]--;
        st.erase({n,key});   
        if(mpp[key]<=0) mpp.erase(key); 
        else st.insert({n-1,key});
    }
    
    string getMaxKey() {
        if(mpp.empty()) return "";
        return st.rbegin()->second;
    }
    
    string getMinKey() {
        if(mpp.empty()) return "";
        return st.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */