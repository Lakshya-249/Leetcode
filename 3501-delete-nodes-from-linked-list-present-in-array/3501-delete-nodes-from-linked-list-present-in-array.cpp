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
private:
    ListNode* traverseList(set<int>st, ListNode* &head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        // ListNode* next = nullptr;
        while(curr != nullptr){
            if(st.find(curr->val) != st.end()){
                ListNode* temp = curr;
                if(curr == head){
                    head = curr->next;
                }else{
                    prev->next = curr->next;
                }
                curr = curr->next;
                delete temp;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st;
        for(auto it:nums) st.insert(it);
        ListNode* newHead = traverseList(st,head);
        return newHead;        
    }
};