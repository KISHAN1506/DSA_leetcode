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
    void ansPreOrder(TreeNode* root,vector<int> &ans){
        if(root == NULL){
            return;
        }

        ans.push_back(root->val);
        ansPreOrder(root->left,ans);
        ansPreOrder(root->right,ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        ansPreOrder(root,ans);
        return ans;
    }
};