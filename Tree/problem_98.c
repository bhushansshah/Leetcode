bool validBST(struct TreeNode *node, long lower, long upper){
    if(!node){
        return true;
    }
    if(node->val <= lower || node->val >= upper){
        return false;
    }
    return validBST(node->left, lower, node->val) && validBST(node->right, node->val, upper);
}
bool isValidBST(struct TreeNode* root){
    return validBST(root, LONG_MIN, LONG_MAX);
}
