#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val):val(val),left(NULL),right(NULL){}
};


class Solution {
public:
    /**
     * @param T1: The roots of binary tree T1.
     * @param T2: The roots of binary tree T2.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode * T1, TreeNode * T2) {
        if(T2 == NULL) return true;
        if(T1 == NULL) return false;
        return isSameTree(T1, T2) || isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }
private:
    bool isSameTree(TreeNode * T1, TreeNode * T2) {
        if(T1 == NULL && T2 == NULL ) return true;
        if(T1 == NULL || T2 == NULL) return false;
        if(T1->val != T2->val ) return false;
        return isSameTree(T1->left, T2->left) && isSameTree(T1->right, T2->right);
    }
};