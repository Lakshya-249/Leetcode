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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minnode = -1;
        int maxnode = -1;
        int minterm = INT_MAX;
        ListNode* prev = head;
        head = head->next;
        ListNode* curr = head;
        ListNode* nextr = head->next;
        int i = 0,ct = 0;
        while(nextr!=nullptr){
            if((curr->val<prev->val && curr->val<nextr->val) || (curr->val>prev->val && curr->val>nextr->val)){
                ct++;
                if(minnode == -1){
                    minnode = i;
                }
                if(maxnode != -1){
                    minterm = min(minterm, i - maxnode);
                }
                maxnode = i;
            }
            prev = curr;
            curr = nextr;
            nextr = nextr->next;
            i++;
        }
        if(ct<2) return {-1,-1};
        return {minterm,maxnode-minnode};
    }
};