class MyCircularDeque {
    int n;
    vector<int>dq;
public:
    MyCircularDeque(int k) {
        dq.resize(k,-1);
        n = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        for(int i=0;i<n;i++){
            if(value == -1)continue;
            int temp = dq[i];
            dq[i] = value;
            value = temp;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        for(int i=n-1;i>=0;i--){
            if(value == -1)continue;
            int temp = dq[i];
            dq[i] = value;
            value = temp;
        }
        return true;
    }
    
    bool deleteFront() {
        for(int i=0;i<n;i++){
            if(dq[i] != -1){
                dq[i] = -1;
                return true;
            }
        }
        return false;
    }
    
    bool deleteLast() {
        for(int i=n-1;i>=0;i--){
            if(dq[i] != -1){
                dq[i] = -1;
                return true;
            }
        }
        return false;;
    }
    
    int getFront() {
        for(auto it: dq){
            if(it != -1) return it;
        }
        return -1;
    }
    
    int getRear() {
        for(int i=n-1;i>=0;i--){
            if(dq[i] != -1) return dq[i];
        }
        return -1;
    }
    
    bool isEmpty() {
        for(auto it: dq){
            if(it != -1) return false;
        }
        return true;;
    }
    
    bool isFull() {
        for(auto it: dq){
            if(it == -1)return false;
        }
        return true;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */