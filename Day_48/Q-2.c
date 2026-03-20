int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    // Check if left child exists and is a leaf
    if (root->left != NULL) {
        if (root->left->left == NULL && root->left->right == NULL) {
            sum += root->left->val;
        } else {
            sum += sumOfLeftLeaves(root->left);
        }
    }

    // Always check right subtree
    sum += sumOfLeftLeaves(root->right);

    return sum;
}