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
    // this problem is the extension of the diameter of the tree problem 
    // if we find the maxSum of the left subtree and right subtree for a node then the maxPath for that node will be node->val + maxRight + maxLeft 
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        FindMaximum(root,maxPath);
        return maxPath;
    }
    int FindMaximum(TreeNode* node,int &maxPath){
        if(node==NULL) return 0;
        
        // if a node returns a negative path sum then , for sure we are not going to take that path
        int maxLeft = max(0, FindMaximum(node->left, maxPath));
        int maxRight = max(0, FindMaximum(node->right, maxPath));

        maxPath = max(maxPath,node->val+maxLeft+maxRight);
        return node->val + max(maxLeft,maxRight);
    }
};