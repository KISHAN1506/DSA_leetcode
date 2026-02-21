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
    int countNode(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int count = countNode(root->left) + countNode(root->right) + 1;
        return count;
    }

    int countNodes(TreeNode* root) {
        return countNode(root);
    }
};