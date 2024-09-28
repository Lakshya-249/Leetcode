struct Node{
    int count  = 0;
    Node *list[26] = {NULL};
    bool containKey(char ch){
        return list[ch - 'a'] != NULL;
    }
    Node *get(char ch){
        return list[ch-'a'];
    }
    void put(char ch,Node *new_node){
        list[ch-'a'] = new_node;
    }
    void inc(char ch){
        list[ch - 'a']->count++;
    }
    int retCount(char ch){
        return list[ch - 'a']->count;
    }
};

class Solution {
Node* root;
public:
    Solution(){
        root = new Node;
    }
    void insert(string word){
        Node *node = root;
        for(auto it: word){
            if(!node->containKey(it)) node->put(it,new Node);
            node->inc(it);
            node = node->get(it);
        }
    }
    int search(string word){
        Node *node = root;
        int cnt = 0;
        for(auto ch: word){
            cnt += node->retCount(ch);
            node = node->get(ch);
        }
        return cnt;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        for(auto it: words) insert(it);
        vector<int>res;
        for(auto it: words){
            int cnt = search(it);
            res.push_back(cnt);
        }
        return res;
    }
};