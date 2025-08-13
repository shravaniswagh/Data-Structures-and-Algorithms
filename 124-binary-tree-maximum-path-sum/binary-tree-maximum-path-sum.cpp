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
    int height(TreeNode* root , int &diameter,int &sum){ 
        /*here we use int &diameter becuase updates to diameter are lost
         after returning from the recursion. We need to pass diameter
         by reference so that all recursive calls share the same variable*/
        if(root == NULL) return 0;
        int leftheight =max(0, height(root->left,diameter,sum));
        int rightheight = max(0,height(root->right,diameter,sum));
        sum = max(sum , leftheight + rightheight + root->val);
        return max(leftheight,rightheight) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int diameter = 0;
        int sum = INT_MIN;
        height(root,diameter,sum);
        return sum;
    }
};