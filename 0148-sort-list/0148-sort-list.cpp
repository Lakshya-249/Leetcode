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
    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* ans = new ListNode(0);
        ListNode* dummy = ans;
        while(first != nullptr && second != nullptr){
            if (first->val < second->val){
                dummy->next = first;
                first = first->next;
            }else {
                dummy->next = second;
                second = second->next;
            }
            dummy = dummy->next;
        }
        if (first != nullptr){
            dummy->next = first;
        }
        if(second != nullptr) {
            dummy->next = second;
        }
        return ans->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        // vector<ListNode*> lst;
        // ListNode* node = head;
        // while(node != nullptr) {
        //     lst.push_back(node);
        //     node = node->next;
        // }
        // sort(lst.begin(),lst.end(),[&](ListNode* node1,ListNode* node2){
        //     return node1->val < node2->val;
        // });
        // ListNode* ans = new ListNode();
        // node = ans;
        // for (int i=0;i<lst.size();i++){
        //     node->next = lst[i];
        //     node = node->next;
        // }
        // node->next = nullptr;
        // return ans->next;
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondNode = slow->next;
        slow->next = nullptr;
        ListNode* first = sortList(head);
        ListNode* second = sortList(secondNode);
        return merge(first,second);
    }
};