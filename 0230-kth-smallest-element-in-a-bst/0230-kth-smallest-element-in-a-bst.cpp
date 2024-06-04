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
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
         inorder(root,k,result);
         return result;
    }

    void inorder(TreeNode * root, int &k, int &result){
        if(!root) return;

        inorder(root->left, k,result);
        if(--k ==0){
            result = root->val;
            return;
        }
        inorder(root->right,k,result);

    }
};