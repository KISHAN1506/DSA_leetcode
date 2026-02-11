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
        ListNode* temp = head;
        ListNode* front = NULL;
        ListNode* prev = NULL;

        while(temp != NULL){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        // return temp; previous is head of reversed LL
        return prev;
    }

    ListNode* splitAtMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev != NULL){
            prev->next = NULL;
        }

        return slow;
    }

    void reorderList(ListNode* head) {
        ListNode* right = splitAtMid(head);
        right = reverseLL(right);
        
        ListNode* left = head;
        ListNode* tail = NULL;
        while(right != NULL && left!=NULL){
            ListNode* leftNxt = left->next;
            ListNode* rightNxt = right->next;
            left->next = right;
            right->next = leftNxt;
            tail = right;
            left = leftNxt;
            right = rightNxt;
        }

        if(tail){
            tail->next = right;
        }

    }
};