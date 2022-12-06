/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int traverse(struct TreeNode *node, int ind, int *result){
     if(node == NULL){
         return ind;
     }
    int i = traverse(node->left, ind, result);
    result[i++] = node->val;
    i = traverse(node->right, i, result);
    return i;
 }
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *result = malloc(100 * sizeof(int));
    int len = traverse(root, 0, result);
    *returnSize = len;
    return result;

}
