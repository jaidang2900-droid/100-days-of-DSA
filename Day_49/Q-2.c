struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    // Base case: if tree is empty, create new node
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // If value is smaller, insert in left subtree
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }
    // If value is greater, insert in right subtree
    else {
        root->right = insertIntoBST(root->right, val);
    }

    // Return root pointer
    return root;
}