 void postOrder(struct TreeNode *node, int *result, int *returnSize){
     if(!node){
         return;
     }
     postOrder(node->left, result, returnSize);
     postOrder(node->right, result, returnSize);
     (*returnSize)++;
     if(*returnSize == 1){
	     result[0] = node->val;
     
     }
     else{
     	     result = realloc(result, (*returnSize) * sizeof(int));
	     result[*returnSize - 1] = node->val;
     }
 }
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    if(!root){
        return NULL;
    }
    *returnSize = 0;
    int *result = malloc(sizeof(int));
    postOrder(root, result, returnSize);
    return result;
}



int * preorder(struct TreeNode *node, int *result, int *returnSize){
    if(!node){
        return result;
    }

    result = preorder(node->left, result, returnSize);
    result = preorder(node->right, result, returnSize);
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
    return result;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    return preorder(root, NULL, returnSize);
}
