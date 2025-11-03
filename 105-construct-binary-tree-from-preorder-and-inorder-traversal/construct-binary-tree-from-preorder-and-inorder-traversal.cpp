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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder is to tell the value of root node and inorder is tell the index of root node and the leftsubtree and right subtree
        map<int,int> inMap;

        // hash mapping all the values of the inorder , because we have to find the index of root in inorder , found from preoder 
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        // calling the overloaded helper function first time
        TreeNode* root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }

    TreeNode* buildTree(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int> &inMap){
        // taking the pointers at the start and end of preorder and inorder , to reduce the size
        if(preEnd<preStart || inStart>inEnd) return NULL;

        // first element from the preorder is going to be the root as preorder is root -> left -> right
        TreeNode* root = new TreeNode(preorder[preStart]);

        // finding the index of element with the same value , in inorder
        int inRoot = inMap[root->val];
        //           |   numleft   |    -> this portion is dedicated to left subtree
        // inorder = [instart      inRoot        inEnd]
        int numleft = inRoot-inStart;

        // rebuilding the right child and left child
        //                          |    numleft    |               | for right   |
        // preorder = [preStart(root)                prestart+numleft       preEnd]
        root->left = buildTree(preorder,preStart+1,preStart+numleft,inorder,inStart,inRoot-1,inMap);
        root->right = buildTree(preorder,preStart+numleft+1,preEnd,inorder,inRoot+1,inEnd,inMap);

        return root;
    }
};