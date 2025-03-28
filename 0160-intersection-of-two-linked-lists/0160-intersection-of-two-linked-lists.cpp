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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_map<ListNode* ,int>mpp;
        // while(headA != nullptr || headB != nullptr){ 
        //     if(headA && mpp.find(headA) != mpp.end()){
        //         return headA;
        //     }
        //     mpp[headA] = 1;
        //     if(headB && mpp.find(headB) != mpp.end()){
        //         return headB;
        //     }
        //     mpp[headB] = 1;
        //     if(headA != nullptr) headA = headA->next;
        //     if(headB != nullptr) headB = headB->next;
        // }
        // return nullptr;
        ListNode* a = headA;
        ListNode* b = headB;

        while(a != b){
            a = a ? a->next : headB;
            b = b ? b->next : headA; 
        }
        return a;

    }
};