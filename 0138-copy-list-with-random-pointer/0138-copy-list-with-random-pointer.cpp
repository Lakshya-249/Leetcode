/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mpp;
        Node* node = head;
        while(node){
            mpp[node] = new Node(node->val);
            node = node->next;
        }
        node = head;
        while(node){
            mpp[node]->next = mpp[node->next];
            mpp[node]->random = mpp[node->random];
            node = node->next;
        }
        return mpp[head];
    }
};