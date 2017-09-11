#include <queue>
#include <algorithm>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    int minDepth(TreeNode * root){
        if(root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int ret = 0;
        while(!q.empty()){
            ret++;
            int k = q.size();
            for(int i=0; i<k; i++){
                TreeNode * f = q.front();
                q.pop();
                if(f->left==NULL && f->right == NULL){
                    return ret;
                }
                if(f->left != NULL){
                    q.push(f->left);
                }
                if(f->right != NULL){
                    q.push(f->right);
                }
            }
        }
        return -1;
    }
};

#ifdef DEBUG

#include <ostream>

int
main()
{
    Solution s;
    
    return 0;
}

#endif