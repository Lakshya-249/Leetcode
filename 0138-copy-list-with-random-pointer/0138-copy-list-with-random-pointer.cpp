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
        // unordered_map<Node*, Node*>mpp;
        // Node* node = head;
        // while(node){
        //     mpp[node] = new Node(node->val);
        //     node = node->next;
        // }
        // node = head;
        // while(node){
        //     mpp[node]->next = mpp[node->next];
        //     mpp[node]->random = mpp[node->random];
        //     node = node->next;
        // }
        // return mpp[head];
        if(!head) return head; 
        Node* node = head;
        while(node){
            Node* temp = new Node(node->val);
            temp->next = node->next;
            node->next = temp;
            node = temp->next;
        }
        node = head;
        while(node){
            Node* rand = node->random;
            node->next->random = rand ? rand->next : rand;
            node = node->next->next;
        }
        
        Node* newHead = head->next;
        Node* copy = newHead;
        node = head;

        while (node) {
            node->next = node->next->next;
            copy->next = copy->next ? copy->next->next : nullptr;
            node = node->next;
            copy = copy->next;
        }

        return newHead; 
    }
};