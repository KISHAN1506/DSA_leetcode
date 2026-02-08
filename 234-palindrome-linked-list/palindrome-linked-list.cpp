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
    bool isPalindrome(ListNode* head) {

        // Memory can be sorted using Stack :
        stack<int> st;
        ListNode* mover = head;
        while(mover != nullptr){
            st.push(mover->val);
            mover = mover->next;
        }

        ListNode* mover2 = head;
        while(mover2 != nullptr){
            if(st.top() == mover2->val){
                st.pop();
            }
            mover2 = mover2->next;
        }

        if(st.empty()){
            return true;
        }
        return false;




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