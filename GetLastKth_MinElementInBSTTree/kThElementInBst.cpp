/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// solution based on the fact that elements in BST already ordered .
// minimum elements are in left->left  
// we just should calculate the numbers frm the let side 
 
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
       int res = 0;
       calculate(root, k, res);
       return res;
    }
    
private:
    
    void calculate(TreeNode *root, int &k, int &res)    {
        
		if(root->left)
            calculate(root->left,k,res);
        k-=1;
        if(k==0) {
            res=root->val;
            return;
        }
        if(root->right)
            calculate(root->right,k,res);
    }
};

