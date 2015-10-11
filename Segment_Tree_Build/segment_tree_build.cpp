/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        if (start <= end) {
            SegmentTreeNode *root = new SegmentTreeNode(start, end);
            if (start < end) {
                root->left = build(start, (start + end) / 2);
                root->right = build((start + end) / 2 + 1, end);
            } else {
                root->left = root->right = NULL;
            }
            return root;
        } else {
            return NULL;
        }
    }
};
