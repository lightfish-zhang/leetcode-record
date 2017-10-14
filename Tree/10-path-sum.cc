// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum

#include <iostream>

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
    bool hasPathSum(TreeNode * root, int target){
        if(root == NULL)
            return false;
        return helperDFS(root, target, 0);
    }

    bool helperDFS(TreeNode * node, int target, int sum){
        if(node == NULL){
            return target == sum;
        }
        sum += node->val;
        if(target == sum){
            return true;
        }
        return helperDFS(node->left, target, sum) || helperDFS(node->right, target, sum);
    }
};