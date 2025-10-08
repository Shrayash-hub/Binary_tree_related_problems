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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

        // we will be visiting the left node and then right node recursively
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        // height till any node is 1 + max(height_of_right_subtree,height_of_left_subtree);
        return 1+ max(leftHeight,rightHeight);
    }
};