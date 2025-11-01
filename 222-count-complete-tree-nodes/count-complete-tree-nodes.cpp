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
    int leftHeight(TreeNode* root){
        int h = 0;
        while(root){
            h++;
            root = root->left;
        }
        return h;
    }

    int rightHeight(TreeNode* root){
        int h = 0;
        while(root){
            h++;
            root = root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        // simply we are going to use the property of CBT , when the heights of left subtree and right subtree is equal then , number of nodes are 2^h -1
        if(lh==rh) return (1 << lh) - 1;

        // if height is not equal then we need to do it separatly for the left subtree and right subtree and +1 for the root node
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};