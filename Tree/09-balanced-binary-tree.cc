#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

// O(n*n), 最糟糕情况下，每个节点遍历两次，一次是找出高度，一次是判断子树是否平衡
class Solution{
    bool isBalanced(TreeNode * root){
         return (abs(depth(root->left) - depth(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }

    int depth(TreeNode * node){
        return node == NULL ? 0 : 1 + max(depth(node->left), depth(node->right));
    }
};

// O(n), 最糟糕情况下，每个节点遍历一次，找出高度差，只要发现一处子树不平衡，直接-1递归返回
class Solution2{
    bool isBalanced(TreeNode* root){
        if(root == NULL)
            return true;
        return helper(root) != -1;
    }

    // return int in Enum{-1, 0, 1}
    int helper(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        // else +1
        int leftDepth = helper(node->left); 
        int rightDepth = helper(node->right);
        
        // 减少运算
        if(leftDepth == -1 || rightDepth == -1 ||  abs(leftDepth - rightDepth) > 1){
            return -1;
        }

        return 1 + max(leftDepth, rightDepth);
    }
};