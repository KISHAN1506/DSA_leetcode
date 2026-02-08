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
        ListNode* prev = NULL;
        ListNode* front = NULL;
        while(temp != nullptr){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if(head == nullptr || head->next == nullptr){
            return true;
        }
        // Optimization for space -> O(1);
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverseLL(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;
        while(second != NULL){
            if(first->val != second->val){
                reverseLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(newHead);
        return true;


        // Memory can be sorted using Stack :, but still solution is not taking O(1) sc
        // stack<int> st;
        // ListNode* mover = head;
        // while(mover != nullptr){
        //     st.push(mover->val);
        //     mover = mover->next;
        // }

        // ListNode* mover2 = head;
        // while(mover2 != nullptr){
        //     if(st.top() == mover2->val){
        //         st.pop();
        //     }
        //     mover2 = mover2->next;
        // }

        // if(st.empty()){
        //     return true;
        // }
        // return false;




        // Memory limit Exceeded
        // string str = "";
        // ListNode* mover = head;
        // while(mover != nullptr){
        //     str += mover->val;
        //     mover = mover->next;
        // }

        // string strRev= "";
        // for(int i = str.length()-1;i>=0;i--){
        //     strRev = strRev + str[i];
        // }

        // if(str == strRev){
        //     return true;
        // }
        // return false;

    }
};