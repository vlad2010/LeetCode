/*

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
You may assume k is always valid, 1 = k = BST's total elements.

Example
Input: root = [3,1,4,null,2], k = 1
Output: 1


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3


What if the BST is modified (insert/delete operations) 
often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/


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

