/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* node = new ListNode();
        ListNode* nhead = node;
        head = head->next;
        int count = 0;
        while(head!=nullptr){
            if(head->val == 0){
                nhead->next = new ListNode(count);
                nhead = nhead->next;
                count = 0;
            }
            count += head->val;
            head = head->next;
        }
        return node->next;
    }
};