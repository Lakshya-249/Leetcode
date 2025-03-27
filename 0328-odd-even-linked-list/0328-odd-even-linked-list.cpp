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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        queue<ListNode*>odd,even;
        ListNode* node = head;
        int i = 1;
        while(node != nullptr){
            if(i%2 == 0) even.push(node);
            else odd.push(node);
            node = node->next;
            i++;
        }
        ListNode* newhead = odd.front();
        odd.pop();
        node = newhead;
        while(!odd.empty()){
            node->next = odd.front();
            odd.pop();
            node = node->next;
        }
        while(!even.empty()){
            node->next = even.front();
            even.pop();
            node = node->next;
        }
        node->next = nullptr;
        return newhead;
    }
};