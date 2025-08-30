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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* node = new TreeNode(val);
            return node;
        };
        TreeNode* tode = root;
        if(tode->left == NULL && val < tode->val){
            TreeNode* node = new TreeNode(val);
            tode->left = node;
        } 
        if(tode->right == NULL && val > tode->val){
            TreeNode* node = new TreeNode(val);
            tode->right = node;
        }
        if(val < tode->val){
            insertIntoBST(tode->left , val);
        }
        if(val > tode->val){
            insertIntoBST(tode->right, val);
        }
        return tode;
    }
};