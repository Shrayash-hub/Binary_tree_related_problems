/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";

        // creating a queue to iterate over tree -> level order traversal
        queue<TreeNode*> q;
        // to save the result
        string s = "";

        q.push(root);
        // taking each node and checking that they have child or not
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            // if they have child , firsly put them in result and then child into queue
            if(node!=NULL){
                s+= (to_string(node->val) + ",");
                q.push(node->left);
                q.push(node->right);
            }
            // no child , add null to the answer , to maintain the structure
            else{
                s+= ("null,");
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;

        // this is use to parse the string , if we have "1,2,3,null,5" converted to ("1","2","3","null",..)
        stringstream s(data);
        string str;

        // we have to give stringstream object 's' as the first parameter,the variable in which we have to store value -> serial wise , and last as delimeter
        getline(s,str,',');
        
        // create a root node with the first value -> as its going to be root
        TreeNode* root = new TreeNode(stoi(str));

        // for BFS traversal
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            // for checking left child
            getline(s,str,',');
            if(str=="null"){
                node->left=NULL;
            }
            else{
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            // for checking right child
            getline(s,str,',');
            if(str=="null"){
                node->right=NULL;
            }
            else{
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));