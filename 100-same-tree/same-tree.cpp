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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // we have three diffrent cases
        // first is when both the roots are null ->  return true
        // when one of node is null -> return false
        // when both the nodes are not null , we will compare the root and left and right subtree
        if(!p && !q) return true;
        if(!p || !q) return false;

        return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};