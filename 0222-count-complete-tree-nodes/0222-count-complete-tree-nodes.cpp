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
    // this has TC O(n)
    // int countNode(TreeNode* root){
    //     if(root == NULL){
    //         return 0;
    //     }
    //     int count = countNode(root->left) + countNode(root->right) + 1;
    //     return count;
    // }

    int findHeightLeft(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }
    int findHeightRight(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        // 1<<lh --> it is equivalent to 2^lh
        if(lh == rh) return (1<<lh) - 1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};