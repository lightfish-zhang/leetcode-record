#include <vector>

using std::vector;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(NULL), right(NULL){}
};


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int> &num) {
        if(num.empty())
            return NULL;
        return helper(num, 0, num.size()-1);
    }

    TreeNode*  helper(vector<int> &num, int start,int end){
        int length = end - start;
        if(length < 0){
            return NULL;
        }
        int middle = length/2;
        TreeNode* root = new TreeNode(num[start+middle]);
        root->left = helper(num, start, start+middle-1);
        root->right = helper(num, start+middle+1, end);
        return root;
    }
};