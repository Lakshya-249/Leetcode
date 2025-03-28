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
    ListNode* sortList(ListNode* head) {
        vector<ListNode*> lst;
        ListNode* node = head;
        while(node != nullptr) {
            lst.push_back(node);
            node = node->next;
        }
        sort(lst.begin(),lst.end(),[&](ListNode* node1,ListNode* node2){
            return node1->val < node2->val;
        });
        ListNode* ans = new ListNode();
        node = ans;
        for (int i=0;i<lst.size();i++){
            node->next = lst[i];
            node = node->next;
        }
        node->next = nullptr;
        return ans->next;
    }
};