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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mover1 = list1;
        ListNode* mover2 = list2;
        ListNode* ans = new ListNode(-1);
        ListNode* valAdder = ans;
        while(mover1 != NULL && mover2 != NULL){
            if((mover1->val)<(mover2->val)){
                ListNode* temp1 = new ListNode(mover1->val);
                valAdder->next = temp1;
                valAdder = valAdder->next;
                mover1 = mover1->next;
            }else if((mover1->val)>(mover2->val)){
                ListNode* temp2 = new ListNode(mover2->val);
                valAdder->next = temp2;
                valAdder = valAdder->next;
                mover2 = mover2->next;
            }else {
                ListNode* temp3 = new ListNode(mover1->val);
                valAdder->next = temp3;
                valAdder = valAdder->next;
                mover1 = mover1->next;
            }
        }
        while(mover1 != NULL){
            ListNode* temp = new ListNode(mover1->val);
            valAdder->next = temp;
            valAdder = valAdder->next;
            mover1 = mover1->next;
        }

        while(mover2 != NULL){
            ListNode* temp = new ListNode(mover2->val);
            valAdder->next = temp;
            valAdder = valAdder->next;
            mover2 = mover2->next;
        }

        return ans->next;
    }
};