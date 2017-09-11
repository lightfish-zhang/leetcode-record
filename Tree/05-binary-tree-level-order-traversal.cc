#include <vector>
#include <iostream>
#include <queue>

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if(root == NULL){
            return ret;
        }
        queue<TreeNode *> tmp;
        tmp.push(root);
        while(!tmp.empty()){
            int size = tmp.size();
            vector<int> sub_ret;
            for(int i=0; i<size; i++){
                TreeNode * node = tmp.front();
                tmp.pop();
                sub_ret.push_back(node->val);
                if(node->left != NULL){
                    tmp.push(node->left);
                }
                if(node->right != NULL){
                    tmp.push(node->right);
                }
            }
            ret.push_back(sub_ret);
        }
        return ret;
    }

};