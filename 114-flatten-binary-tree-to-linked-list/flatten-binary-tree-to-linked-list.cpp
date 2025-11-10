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
    TreeNode* prev = NULL;
    // using reverse preorder
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        
        // flatten right subtree
        flatten(root->right);
        // flatten left subtree
        flatten(root->left);

        // store the last traversed node , coz we have to make connections
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};