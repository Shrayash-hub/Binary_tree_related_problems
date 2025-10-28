/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if root is null or p and q , then LCA is going to be that node only
        if(root==NULL || root==p || root==q) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        // if one of side is null , return the another side
        if(left==NULL) return right;
        else if(right==NULL) return left;
        // if we found both the sides , then return the root -> coz its the lca
        else{
            return root;
        }
    }
};