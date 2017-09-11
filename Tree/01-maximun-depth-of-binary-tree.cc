#include <algorithm>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// simple
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root == NULL)
//             return 0;
//         tmp = 0;
//         travel(root, 1);
//         return tmp;
//     }
//     void travel(TreeNode* root, int level){
//         if(root->left == NULL && root->right == NULL){
//             tmp = max(tmp, level);
//             return;
//         }
//         if(root->left != NULL){
//             travel(root->left, level+1);
//         }
//         if(root->right != NULL){
//             travel(root->right, level+1);
//         }
//     }
// private:
//     int tmp;
// };

// one line, Depth-first-search
int maxDepth(TreeNode * root){
    return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
}