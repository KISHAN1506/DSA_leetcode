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

    ListNode* merge(ListNode* left,ListNode* right){
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while(left!=NULL && right!=NULL){
            if(left->val <= right->val){
                temp->next = left;
                left = left->next;
            }else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        
        if(left != NULL){
            temp->next = left;
            // left = left->next; not necessary because already LL is sorted 
        }else{
            temp->next = right;
            // right = right->next; not necessary because already LL is sorted 
        }

        return dummy.next;
        
    }

    ListNode* mergeSortLL(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* righthead = splitAtMid(head);

        // this is where the breaking of links will be required
        //  to get to know the where to split --> here till mid
        ListNode* left = mergeSortLL(head);
        ListNode* right = mergeSortLL(righthead);

        return merge(left,right);

    }


    ListNode* sortList(ListNode* head) {
        return mergeSortLL(head);
    }
};