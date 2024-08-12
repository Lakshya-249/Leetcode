class KthLargest {
    int k;
    priority_queue<int,vector<int>,greater<int>>pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto it: nums){
            if(pq.size()<k)pq.push(it);
            else if(it>pq.top()){
                pq.push(it);
                if(pq.size()>k) pq.pop();
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<k)pq.push(val);
        else if(val>pq.top()){
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */