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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        list<ListNode*>lst;
        ListNode* node = head;
        while(node != nullptr){
            lst.push_back(node);
            node = node->next;
        }
        k = k % lst.size();
        while(k){
            ListNode* rght = lst.back();
            lst.pop_back();
            rght->next = lst.front();
            lst.push_front(rght);
            lst.back()->next = nullptr;
            k--;
        }
        return lst.front();
    }
};