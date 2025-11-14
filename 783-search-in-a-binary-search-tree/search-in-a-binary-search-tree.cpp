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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;

        if(root->val==val) return root;
        // if target is greater than the root then search in right subtree
        if(val<root->val){
            return searchBST(root->left,val);
        }
        // if target is smaller than the root then search in the left subtree
        if(val>root->val){
            return searchBST(root->right,val);
        }
        return NULL;
    }
};