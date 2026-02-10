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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* st = head;
        for(int i = 1;i<k;i++){
            st = st->next;
        }
        ListNode* mover1 = st;
        ListNode* end = head;
        while(mover1->next != NULL){
            mover1 = mover1->next;
            end = end->next;
        }
        swap(st->val,end->val);
        return head;
    }
};