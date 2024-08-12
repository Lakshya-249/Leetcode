class KthLargest {
    vector<int>vec;
    int k;
    int getPosition(int val){
        int left = 0;
        int right = vec.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            int midval = vec[mid];
            if(midval == val) return mid;
            if(midval > val){
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        return left;
    }
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto it: nums)vec.push_back(it);
        sort(vec.begin(),vec.end());
    }
    
    int add(int val) {
        int index = getPosition(val);
        vec.insert(vec.begin()+index,val);
        return vec[vec.size()-k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */