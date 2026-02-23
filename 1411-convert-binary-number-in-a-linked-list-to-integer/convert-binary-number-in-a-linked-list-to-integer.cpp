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
    // Optimal O(n)
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        
        while (head != NULL) {
            ans = ans * 2 + head->val;
            head = head->next;
        }
        
        return ans;
    }
    
    // int powFix(int a,int n){
    //     if(n == 0){
    //         return 1;
    //     }

    //     if(n%2 == 1){
    //         return a*powFix(a,n-1);
    //     }else{
    //         int val = powFix(a,n/2);
    //         return val*val;
    //     }
    // }

    // int getDecimalValue(ListNode* head) {
    //     ListNode* mover = head;
    //     vector<int> vals;
    //     while(mover != NULL){
    //         vals.push_back(mover->val);
    //         mover = mover->next;
    //     }
    //     int n = 0;
    //     int ans = 0;

    //     for(int i = vals.size()-1;i>=0;i--){
    //         int digit = vals[i];
    //         if(digit != 0) ans += powFix(2,n)*digit;
    //         n++;
    //     }
    //     return ans;
    // }

};