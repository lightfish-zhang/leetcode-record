#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(NULL == root){
            return false;
        }
        queue <TreeNode *> q1, q2;
        q1.push(root->left);
        q2.push(root->right);

        while(!q1.empty() || !q2.empty()){
            TreeNode * node1 = q1.front();
            q1.pop();
            TreeNode * node2 = q2.front();
            q2.pop();
            if(node1 == NULL && node2 == NULL){
                continue;
            }
            if(node1 == NULL || node2 == NULL){
                return false;
            }
            if(node1->val != node2->val){
                return false;
            }
            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->left);
            q2.push(node2->right);
        }
        return true;
    }
};
