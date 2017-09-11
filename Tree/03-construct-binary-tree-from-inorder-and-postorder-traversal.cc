#include <vector>
#include <iostream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


class Solution{
public:
    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode * build(vector<int> &inorder, int inorderBegin, int inorderEnd, vector<int> &postorder, int postorderBegin, int postorderEnd){
        if( inorderBegin > inorderEnd || postorderBegin > postorderEnd){
            return NULL;
        }
        int rootVal = postorder[postorderEnd];
        TreeNode * node = new TreeNode(rootVal);
        int pos = -1;
        for(int i=inorderBegin; i<=inorderEnd; i++){
            if(inorder[i] ==  rootVal){
                pos = i;
                break;
            }
        }
        node->left = build(inorder, inorderBegin, pos -1, postorder, postorderBegin, postorderBegin + (pos - inorderEnd));
        node->right = build(inorder, pos + 1, inorderEnd, postorder, postorderBegin+(pos-inorderEnd), postorderEnd);
        return node;
    }

};