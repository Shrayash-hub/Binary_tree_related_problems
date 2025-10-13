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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        // Check if the root is NULL,
        // return an empty result
        if(root == NULL){
            return result;
        }
        
        // Queue to perform
        // level order traversal
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        
        // Flag to determine the direction of
        // traversal (left to right or right to left)
        bool leftToRight = true;
        
        // Continue traversal until
        // the queue is empty
        while(!nodesQueue.empty()){
            // Get the number of nodes
            // at the current level
            int size = nodesQueue.size();
            
            // Vector to store the values
            // of nodes at the current level
            vector<int> row(size);
            
            // Traverse nodes at 
            // the current level
            for(int i = 0; i < size; i++){
                // Get the front node
                // from the queue
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                
                // Determine the index to insert the node's
                // value based on the traversal direction
                int index = leftToRight ? i : (size - 1 - i);
                
                // Insert the node's value at
                // the determined index
                row[index] = node->val;
                
                // Enqueue the left and right
                // children if they exist
                if(node->left){
                    nodesQueue.push(node->left);
                }
                if(node->right){
                    nodesQueue.push(node->right);
                }
            }
            
            // Switch the traversal
            // direction for the next level
            leftToRight = !leftToRight;
            
            // Add the current level's
            // values to the result vector
            result.push_back(row);
        }
        
        // Return the final result of
        // zigzag level order traversal
        return result;
    }
};