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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int llsize = 0;
        ListNode* mover1 = head;

        while(mover1 != nullptr){
            llsize++;
            mover1 = mover1->next;
        }

        if(n == llsize){
            head = head->next;
            return head;
        }

        int nfromlast = llsize - n;

        ListNode* mover2 = head;

        for(int i = 0;i<nfromlast-1;i++){
            mover2 = mover2->next;
        }


        mover2->next = mover2->next->next;
        return head;
    }
};