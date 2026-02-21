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
        if(root == NULL) return 0;
        int height = max(heightOfTree(root->right),heightOfTree(root->left)) + 1;
        return height;
    }

    int diaOfTree(TreeNode* root){
        if(root == NULL) return 0;
        int currDiam = heightOfTree(root->left)+heightOfTree(root->right);
        int leftDiam = diaOfTree(root->left);
        int rightDiam = diaOfTree(root->right);

        return max(currDiam,max(leftDiam,rightDiam));
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diaOfTree(root);
    }
};