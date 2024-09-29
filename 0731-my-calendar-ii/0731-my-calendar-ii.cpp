class MyCalendarTwo {
public:
    vector<pair<int,int>> overLap;
    vector<pair<int,int>> bookings;
    bool isLap(pair<int,int>p,int start,int end){
        return max(p.first,start) < min(p.second,end);
    }
    MyCalendarTwo() {}
    bool book(int start, int end) {
        for(auto it: overLap){
            if(isLap(it,start,end)) return false;
        }
        for(auto it: bookings){
            if(isLap(it,start,end)){
                overLap.push_back({max(it.first,start),min(it.second,end)});
            }
        }
        bookings.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */