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
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;

        // Not good approach
        // if(head == NULL || head->next == NULL){
        //     return head;
        // }
        // ListNode* oddLL = head;
        // ListNode* evenLL = head->next;

        // ListNode* mover = head;

        // ListNode* left = oddLL;
        // ListNode* right = evenLL;
        // ListNode* tail = NULL;
        
        // while(mover != NULL && mover->next != NULL && evenLL != NULL && evenLL->next != NULL){
        //     oddLL->next = oddLL->next->next;
        //     evenLL->next = evenLL->next->next;
        //     tail = oddLL;
        //     oddLL = oddLL->next;
        //     evenLL = evenLL->next;
        //     mover = mover->next;
        // }
        // if(oddLL){
        //     tail->next = oddLL;
        //     tail = tail->next;
        // }

        // if(tail)tail->next = right;
        // return left;
    }
};