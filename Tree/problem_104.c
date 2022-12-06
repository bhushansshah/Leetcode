/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int calcDepth(struct TreeNode *node, int level, int maxLevel){ 
     if(!node){
         return maxLevel;
     }
     level++;
     if(maxLevel < level){
         maxLevel = level;
     }
     maxLevel = calcDepth(node->left, level, maxLevel);
     maxLevel = calcDepth(node->right, level, maxLevel);
     return maxLevel;
 }
int maxDepth(struct TreeNode* root){
    return calcDepth(root, 0, 0);
}
