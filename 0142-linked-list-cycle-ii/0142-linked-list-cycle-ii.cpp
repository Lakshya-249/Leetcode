/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* node = head;
        unordered_map<ListNode*, int>mpp;
        while(node != nullptr){
            if(mpp.find(node) != mpp.end()) return node;
            mpp[node] = 1;
            node = node->next;
        }
        return nullptr;
    }
};