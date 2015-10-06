/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == value) {
            if (root->left == NULL) {
                return root->right;
            } else if (root->left->right == NULL) {
                root->left->right = root->right;
                return root->left;
            } else {
                if (root->right == NULL) {
                    return root->left;
                } else {
                    TreeNode *right = root->right;
                    while (right->left != NULL) {
                        right = right->left;
                    }
                    right->left = root->left->right;
                    root->left->right = root->right;
                    return root->left;
                }
            }
        } else if (root->val > value) {
            TreeNode *left = removeNode(root->left, value);
            root->left = left;
        } else {
            TreeNode *right = removeNode(root->right, value);
            root->right = right;
        }
        return root;
    }
};
