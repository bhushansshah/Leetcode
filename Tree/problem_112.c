/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool isPresent(struct TreeNode *node, int sum, int target){
     if(!node){
         return false;
     }
     sum += node->val;
     if(!node->left && !node->right){
        if(sum == target){
            return true;
        }
        else{
            return false;
        }
     }
     else if(node->left && !node->right){
         return isPresent(node->left, sum, target);
     }
     else if(node->right && !node->left){
         return isPresent(node->right, sum, target);
     }
     else{
         return isPresent(node->left, sum, target) || isPresent(node->right,sum, target);
     }
 }
bool hasPathSum(struct TreeNode* root, int targetSum){
    return isPresent(root, 0, targetSum);
}
