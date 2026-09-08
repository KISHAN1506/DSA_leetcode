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
    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;

        ListNode* firstBrk = &dummy;
        for(int i = 1;i<left;i++){
            firstBrk = firstBrk->next;
        }

        ListNode* newStart = firstBrk->next;
        ListNode* secondBrk = newStart;
        for (int i = left; i < right; i++) {
            secondBrk = secondBrk->next;
        }


        firstBrk->next = nullptr;
        ListNode* secConn = secondBrk->next;
        secondBrk->next = nullptr;

        ListNode* revStart = reverseLL(newStart);

        firstBrk->next = revStart;

        ListNode* newTemp = revStart;
        while(newTemp->next != nullptr){
            newTemp = newTemp->next;
        }

        newTemp->next = secConn;

        return dummy.next;
    }
};