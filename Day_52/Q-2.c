struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    // Base case
    if (root == NULL)
        return NULL;

    // If current node is either p or q
    if (root == p || root == q)
        return root;

    // Recur for left and right subtrees
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both left and right are not NULL, root is LCA
    if (left != NULL && right != NULL)
        return root;

    // Otherwise return the non-NULL child
    return (left != NULL) ? left : right;
}