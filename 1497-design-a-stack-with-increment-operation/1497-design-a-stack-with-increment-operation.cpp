class CustomStack {
    int n;
    int top;
    vector<int>stk;
public:
    CustomStack(int maxSize) {
        n = maxSize;
        top = 0;
        stk.resize(maxSize,-1);
    }
    
    void push(int x) {
        for(int i=0;i<n;i++){
            if(stk[i] == -1){
                stk[i] = x;
                top = i;
                return;
            }
        }
    }
    
    int pop() {
        int temp = stk[top];
        stk[top] = -1;
        top--;
        if(top<0) top = 0;
        return temp;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k;i++){
            if(i<n){
                if(stk[i] != -1) stk[i] += val;
            }  
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */