/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// recursive solution
/*
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val != q->val)    return false;
        
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
*/

// Iterative solution

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        /* Return true if both trees are empty */
        if (p == NULL && q == NULL)
            return true;

        /* Return false if one is empty and other is not */

        if (p == NULL)
            return false;
        if (q == NULL)
            return false;

        /*  Create an empty queues for simultaneous traversals  */

        queue<TreeNode *> q1, q2;

        /* push root node into the queue */
        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty())
        {

            TreeNode *n1 = q1.front();
            TreeNode *n2 = q2.front();

            if (n1->val != n2->val)
                return false;

            // Remove front nodes from queues
            q1.pop(), q2.pop();

            /* Enqueue left children of both nodes */
            if (n1->left && n2->left)
            {
                q1.push(n1->left);
                q2.push(n2->left);
            }

            /* If one left child is empty and other is not */
            else if (n1->left || n2->left)
                return false;

            /* Right child code (Similar to left child code) */
            if (n1->right && n2->right)
            {
                q1.push(n1->right);
                q2.push(n2->right);
            }
            else if (n1->right || n2->right)
                return false;
        }

        return true;
    }
};