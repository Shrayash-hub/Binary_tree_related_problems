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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {
            // 1. Go as left as possible
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            // 2. Process node
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);

            // 3. Go right
            curr = curr->right;
        }

        return ans;
    }
};