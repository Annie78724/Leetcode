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
class Solution {
public:
    vector<int>ans;
    void fun(TreeNode* root)
    {
        if(!root) return;
        fun(root->left);
        ans.push_back(root->val);
        fun(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        fun(root);
        unordered_map<int,int>m;
        for(int i=0;i<ans.size();i++)
        {
            if(m[k-ans[i]])
                return true;
            m[ans[i]]++;
        }
        return false;
        
    }
};