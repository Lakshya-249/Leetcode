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
    int numberOfNodes(ListNode* head){
        int cnt = 0;
        ListNode* curr = head;
        while(curr != nullptr) {
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = numberOfNodes(head);
        int num1 = cnt/k;
        int num2 = cnt%k;
        cout<<num1<<","<<num2;
        vector<ListNode*>res;
        while(k>0){
            ListNode* prev = head;
            k--;
            if(head!=nullptr){
                res.push_back(head);
            }else res.push_back(nullptr);
            for(int i=0;i<num1;i++){
                if(head == nullptr)break;
                prev = head;
                head = head->next;
            }
            if(num2 > 0 && head != nullptr){
                prev = head;
                head = head->next;
            }
            if(prev != nullptr) prev->next = nullptr;
            num2--;
        }
        return res;
    }
};