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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr){
            return head;
        }
        while(head != nullptr && head->val == val){
            head = head->next;
        }
        ListNode* mover = head;
        while(mover!=nullptr && mover->next != nullptr){
            if(mover->next->val == val){
                mover->next = mover->next->next;
            }else{
                mover = mover->next;
            }
        }
        return head;

    }
};