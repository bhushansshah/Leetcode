/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int calcDepth(struct TreeNode *node){
    if(!node){
        return 0;
    }
    int r = calcDepth(node->right);
    int l = calcDepth(node->left);
    if(r >= l){
        return 1 + r;
    }
    else{
        return 1 + l;
    }
}
bool isBalanced(struct TreeNode* root){
    if(!root){
        return true;
    }
    int r = calcDepth(root->right);
    int l = calcDepth(root->left);
    if(r - l >= 2 || r - l <= -2){
        return false;
    }
    else{
        return isBalanced(root->right) && isBalanced(root->left);
    }


}
