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
    void dfs(TreeNode* root, int &count){
        if(root == NULL){
            return;
        }
        if(root->left != NULL){
            count++;
            dfs(root->left , count);
        }
        if(root->right != NULL){
            count++;
            dfs(root->right, count);
        }
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int count = 1;
        dfs(root,count);
        return count;
    }
};