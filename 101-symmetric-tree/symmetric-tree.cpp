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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        // we are going to use a helper function, which is going to check recursively that left and right subtree are symmetric or not
        return isMirror(root->left,root->right);
    }

    bool isMirror(TreeNode* a,TreeNode* b){
        if(a==NULL || b==NULL) return a==b;

        if(a->val!=b->val) return false;

        // in mirror images , right node will be similar to left and left will be similar to right
        return isMirror(a->left,b->right) && isMirror(a->right,b->left);
    }
};