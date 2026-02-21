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
    int heightOfTree(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int currHeight = 0;
        currHeight = max(heightOfTree(root->left),heightOfTree(root->right)) + 1;

        return currHeight;
    }

    int maxDepth(TreeNode* root) {
        int height = heightOfTree(root);
        return height;
    }
};