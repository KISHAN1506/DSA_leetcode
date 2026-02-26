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
    TreeNode* insert(TreeNode* root, int putVal){
        if(root == NULL) {
            return new TreeNode(putVal);
        }
        if(root->val > putVal) root->left = insert(root->left,putVal);
        else root->right = insert(root->right,putVal);

        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int putVal) {
        return insert(root,putVal);
    }
    // TreeNode* insert(TreeNode* root, int putVal){
    //     TreeNode* node = new TreeNode(putVal);
    //     if(root == NULL) return node;

    //     if(root->val > putVal){
    //         if(!root->left) insert(root->left,putVal);
    //         root->left = node;
    //         return root;
    //     }else if(root->val < putVal){
    //         if(!root->right) insert(root->right,putVal);
    //         root->right = node;
    //         return root;
    //     }
    //     return root;
    // }
    
};