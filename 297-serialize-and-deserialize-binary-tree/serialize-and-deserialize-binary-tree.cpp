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
        if(!root) return "";
        string data = "[";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL) data.append("null,");
            else data.append(to_string(curr->val) + ',');
            if(curr != NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        data += ']';
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        if(data.front() == '[') data = data.substr(1, data.size()-2);         
        stringstream s(data); //creates the string characters into objects
        string str;
        getline(s,str,',');   //gets us the line from the data stream and ',' is the seperator
        
        if(str == "null") return NULL;

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            getline(s,str,',');
            if(str == "null"){
                curr->left = NULL;
            }
            else{
                TreeNode* leftnode = new TreeNode(stoi(str));
                curr->left = leftnode;
                q.push(leftnode);
            }

            getline(s,str,',');
            if(str == "null"){
                curr->right = NULL;
            }
            else{
                TreeNode* rightnode = new TreeNode(stoi(str));
                curr->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));