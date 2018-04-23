#include <iostream>
#include <vector>
using namespace std;
//#include <algorithm>

class TreeNode{
public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int v): val(v), left(NULL), right(NULL){}
};

class Solution {
public:
    vector<int> searchRange(TreeNode * root, int k1, int k2){
        vector<int> ret;
        helper(ret, root, k1, k2);
        return ret;
    }

private:
    void helper(vector<int> &ret, TreeNode * node, int k1, int k2){
        if(NULL == node){
            return;
        }
        if(node->left != NULL && node->val > k1){
            helper(ret, node->left, k1, k2);
        }
        if(node->val >= k1 && node->val <= k2){
            ret.push_back(node->val);
        }
        if(node->right != NULL && node->val < k2){
            helper(ret, node->right, k1, k2);
        }
    }
};

