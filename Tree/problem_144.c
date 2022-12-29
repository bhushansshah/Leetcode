int * preorder(struct TreeNode *node, int *result, int *returnSize){
    if(!node){
        return result;
    }
    if(!result){
        result = malloc(sizeof(int));
        *returnSize = 1;
        result[0] = node->val;
    }
    else{
        (*returnSize)++;
        result = realloc(result, (*returnSize) * sizeof(int));
        result[*returnSize - 1] = node->val;
    }
    result = preorder(node->left, result, returnSize);
    return preorder(node->right, result, returnSize);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    return preorder(root, NULL, returnSize);
}
