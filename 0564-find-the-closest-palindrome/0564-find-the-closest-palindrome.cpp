class Solution {
public:
    string nearestPalindromic(string n) {
        int m = n.size();
        if(m==1){
            return to_string(stoi(n)-1);
        }
        vector<long long>nums;

        nums.push_back(pow(10,m-1)-1);
        nums.push_back(pow(10,m)+1);

        long long prefix = stoll(n.substr(0,(m+1)/2));
        for(int i=-1;i<2;i++){
            string p = to_string(prefix + i);
            string num = p + string(p.rbegin()+(m%2),p.rend());
            nums.push_back(stoll(num));
        }       

        long long original = stoll(n);
        long long closest = 0;

        for(auto it: nums){
            if(it == original) continue;
            if(abs(it - original)<abs(closest - original) || 
            (abs(it-original)==abs(closest-original) && it<closest)){
                closest = it;
            }
        }
        return to_string(closest);
    }
};