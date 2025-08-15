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
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        vector<vector<int>>finalans;
        if(root == NULL) return finalans;
        st1.push(root);
        while(!st1.empty() || !st2.empty()){
            vector<int>temp1;
            while(!st1.empty()){
                TreeNode* curr1 = st1.top();
                st1.pop();
                temp1.push_back(curr1->val);
                if(curr1->left != NULL) st2.push(curr1->left);
                if(curr1->right != NULL) st2.push(curr1->right);
            }
            if(!temp1.empty()){
                finalans.push_back(temp1);
            }
            vector<int>temp2;
            while(!st2.empty()){
                TreeNode* curr2 = st2.top();
                st2.pop();
                temp2.push_back(curr2->val);
                if(curr2->right != NULL) st1.push(curr2->right);
                if(curr2->left != NULL) st1.push(curr2->left);
            }
            if(!temp2.empty()){
                finalans.push_back(temp2);
            }        
        }
        return finalans;
    }
};