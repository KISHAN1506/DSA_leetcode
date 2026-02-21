/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void ansLevelOrder(TreeNode* root,vector<vector<int>> &ans){
        queue<TreeNode*> q;
        if(root != NULL) q.push(root);
        if(q.empty()){
            // ans = {};
            return;
        }

        while(!q.empty()){
            // to make it as a pair take size of q then push 
            // all the whole level will be in the queue when we start
            int size = q.size();
            vector<int> temp;

            for(int i = 0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();

                temp.push_back(curr->val);
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }

            ans.push_back(temp);

        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        ansLevelOrder(root,ans);
        return ans;
    }
};