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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       if(root==NULL) return {};

       // for storing clm -> vector of {row,value} we will take a map
       map<int,vector<pair<int,int>>> mpp;

       // for iterating and  storing pair of node and {row,clm} we will take an queue
       queue<pair<TreeNode*, pair<int,int>>> q;

       q.push({root,{0,0}}) ;// root : row =0 , clm = 0

       while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int row = p.second.first;
            int clm = p.second.second;

            mpp[clm].push_back({row,node->val});

            // for left child horizontal distance -1
            if(node->left){
                q.push({node->left,{row+1,clm-1}});
            }
            // for right child horizontal distance +1
            if(node->right){
                q.push({node->right,{row+1,clm+1}});
            }
        }

        // transfering values from map to vector
        vector<vector<int>> ans;

        for(auto &it: mpp){
            // firstly we will extract vector which contains {row,value} from the map
            auto &vec = it.second;

            // no we will sort if according to rows and then according to clms
            sort(vec.begin(),vec.end());

            // now we will extract values from that vector
            vector<int> col;
            for(auto &p:vec){
                col.push_back(p.second);
            }
            // push back the nodes at same clm to the ans
            ans.push_back(col);
        }
       
       return ans;
    }
};