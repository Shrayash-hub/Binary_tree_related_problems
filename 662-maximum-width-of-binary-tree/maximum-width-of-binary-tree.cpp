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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        int ans = 0;
        // to save the node,index
        queue<pair<TreeNode*,int>> q;
        // pushing the firsrt node
        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            // storing the first minimum index , to normalize the all other index using index-mmin
            int mmin = q.front().second;
            
            int first,last;
            for(int i=0;i<size;i++){
                // finding the normalized index to overcome overflow
                int curr_id = q.front().second-mmin;
                
                // level order traversal
                TreeNode* node = q.front().first;
                q.pop();
                
                // saving the first and last index of a level
                if(i==0) first = curr_id;
                if(i==size-1) last = curr_id;

                // pushing each child of a node , with index formula , left = 2*i+1  and right = 2*i+2
                if(node->left) q.push({node->left,curr_id*2LL+1LL});
                if(node->right) q.push({node->right,curr_id*2LL+2LL});
            }
            // updating the ans each time
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};