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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = new ListNode(0);
        ListNode* node = ans;
        while(l1 || l2){
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int num3 = num1 + num2 + carry;
            carry = (int) num3/10;
            ListNode* temp = new ListNode(num3%10);
            node->next = temp;
            node = node->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry){
            ListNode* temp = new ListNode(carry);
            node->next = temp;
        }
        return ans->next;
    }
};