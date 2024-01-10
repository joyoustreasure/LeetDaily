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
    unordered_map<int, vector<int>> graph;
    void makeGraph(TreeNode* root){
        if (!root) {return;}
        if (root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if (root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        makeGraph(root->left);
        makeGraph(root->right);
    }

    
    int amountOfTime(TreeNode* root, int start) {
        makeGraph(root);

        queue<int> q;
        q.push(start);

        unordered_set<int> visited;
        visited.insert(start);

        int time = -1;
        while (!q.empty()) {
            ++time;
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                int curr = q.front();
                q.pop();

                for (int neighbor : graph[curr]) {
                    if (!visited.count(neighbor)) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
        }
        return time;}
};