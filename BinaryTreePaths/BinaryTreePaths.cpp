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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path("");
        addPath(result, path, root);
        return result;
    }
    void addPath(vector<string> &result, string path, TreeNode *root) {
        if (root != NULL) {
            path += to_string(root->val);
            
            if (root->left != NULL) {
                addPath(result, path + "->", root->left);
            }
            
            if (root->right != NULL) {
                addPath(result, path + "->", root->right);
            }
            if (root->left == NULL && root->right == NULL) {
                string rst(path);
                result.push_back(rst);
                return ;
            }
        }
    }
};

