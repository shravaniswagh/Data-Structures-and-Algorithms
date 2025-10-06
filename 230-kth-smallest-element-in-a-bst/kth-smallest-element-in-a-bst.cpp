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
    void dfs(TreeNode* root, vector<int>& store,int &cnt){
        if(root == NULL){
            return;
        }
        else{
            cnt++;
            store.push_back(root->val);
        }
        if(root->left != NULL){
            dfs(root->left,store,cnt);
        }
        if(root->right != NULL){
            dfs(root->right,store,cnt);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>store;
        int cnt = 0;
        dfs(root,store,cnt);
        sort(store.begin(),store.end());
        int finalans = 0;
        for(int i=0;i<k;i++){
            finalans = store[i];
        }
        return finalans;
    }
};