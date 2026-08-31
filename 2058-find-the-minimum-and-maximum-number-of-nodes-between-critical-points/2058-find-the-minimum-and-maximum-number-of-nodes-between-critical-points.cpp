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
    bool isValid(ListNode* curr,ListNode* prev,ListNode* front){
        if(curr->val > prev->val && curr->val > front->val){
            return true;
        }
        if(curr->val < prev->val && curr->val < front->val){
            return true;
        }

        return false;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> vals;
        int cnt = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* front = NULL;
        if(curr->next->next == nullptr){
            return {-1,-1};
        }

        while(curr->next != nullptr){
            cnt++;
            front = curr->next;
            if(curr != head){
                if(isValid(curr,prev,front)){
                    vals.push_back(cnt);
                }
            }

            prev = curr;
            curr = front;

        }

        if(vals.size() < 2){
            return {-1,-1};
        }

        int maxDist = vals[vals.size()-1] - vals[0];
        int minDist = INT_MAX;
        


        for(int i = 1;i<vals.size();i++){
            minDist = min(minDist,vals[i]-vals[i-1]);
        }

        return {minDist,maxDist};
    }
};