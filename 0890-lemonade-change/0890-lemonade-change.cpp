class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int tr5 = 0,tr10 = 0;
        for(auto it: bills){
            if(it==5)tr5++;
            if(it==10){
                tr5--;
                tr10++;
                if(tr5<0)return false;
            }
            else if(it==20){
                if(tr10 == 0){
                    tr5 -= 3;
                    if(tr5<0)return false;
                }else{
                    tr10--;
                    tr5--;
                    if(tr10<0 || tr5<0) return false;
                }
            }
        }
        return true;
    }
};