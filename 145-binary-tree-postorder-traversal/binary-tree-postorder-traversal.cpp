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
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* curr = root;
        while(!st.empty() || curr){
            // go to the extreme left node until left node do not exist
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            // if left node do not exist;
            else{
                // then go on the right node
                TreeNode* temp = st.top()->right;
                // if there is no right node , that means both the left and right node are processed , no process that root node
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    // if the current tops right is the previous top element , then also both right and left subtrees are proccessed
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                // else move to right part , coz all the left part is processed
                else{
                    curr = temp;
                }
            }
        }
        return ans;
    }
};