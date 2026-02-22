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
    // Optimal Approach: --> O(n) calculating height and diameter simultaneously by using LeftHeight and rightHeight
    int height(TreeNode* root,int &diameter){
        if(root == NULL){
            return 0;
        }
        int lh = height(root->left,diameter);
        int rh = height(root->right,diameter);
        diameter = max(diameter,lh+rh); // this is finding and updating diameter accordingly in every call
        return 1+max(lh,rh); // this is calculating height of the tree
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root,diameter);
        return diameter;
    }


    // Naive Approach --> O(n^2)
    // int heightOfTree(TreeNode* root){
    //     if(root == NULL) return 0;
    //     int height = max(heightOfTree(root->right),heightOfTree(root->left)) + 1;
    //     return height;
    // }

    // int diaOfTree(TreeNode* root){
    //     if(root == NULL) return 0;
    //     int currDiam = heightOfTree(root->left)+heightOfTree(root->right);
    //     int leftDiam = diaOfTree(root->left);
    //     int rightDiam = diaOfTree(root->right);

    //     return max(currDiam,max(leftDiam,rightDiam));
        
    // }

    // int diameterOfBinaryTree(TreeNode* root) {
    //     return diaOfTree(root);
    // }
};