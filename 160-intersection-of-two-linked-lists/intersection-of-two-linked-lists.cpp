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
        ListNode* mover1 = headA;
        while(mover1 != NULL){
            ListNode* mover2 = headB;
            while(mover2 != NULL){
                if(mover1 == mover2){
                    return mover1;
                }
                mover2 = mover2->next;
            }
            mover1 = mover1->next;
        }
        return NULL;
    }
};