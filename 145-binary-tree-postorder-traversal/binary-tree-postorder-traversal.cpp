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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while(curr || !st.empty()){
            // go as left as possible
            if(curr){
                st.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* node = st.top();
                // if right child exists and not yet processed
                if(node->right && lastVisited != node->right){
                    curr = node->right;
                }
                else {
                    ans.push_back(node->val);
                    st.pop();
                    lastVisited = node;
                }
            }
        }
        return ans;
    }
};