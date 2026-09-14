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
    vector<pair<int,int>> v;

    void go(TreeNode* root, int level){
        if(root==nullptr) return;
    
        v.push_back({level, root->val});
        go(root->left, level+1);
        go(root->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        go(root, 0);

        stable_sort(begin(v), end(v), [&](
            const pair<int,int> &p1,
            const pair<int,int> &p2
        ){
            return p1.first < p2.first; 
        });

        vector<int> tmp;
        for(int i = 0; i < v.size();){
            int j = i;
            for(; j < v.size();j++){
                if(v[i].first != v[j].first) break;
                tmp.push_back(v[j].second);
            }
            ret.push_back(tmp);
            tmp.clear();
            i = max(j, i+1);
        }

        return ret;
    }
};