/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> makeparent(TreeNode* root)                        // (node,parent)
    {
        queue<TreeNode*> q;
        unordered_map<TreeNode*,TreeNode*> um;

        q.push(root);

        while(!q.empty())
        {
           TreeNode* node=q.front();
            q.pop();

            if(node->left)
            {
                q.push(node->left);
                um[node->left]=node;
            }

            if(node->right)
            {
                q.push(node->right);
                um[node->right]=node;
            }
        }

        return um;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> arr;

        if(!root)
            return arr;

        unordered_map<TreeNode*,TreeNode*> parent=makeparent(root);                  // node parent
        unordered_set<TreeNode*> visited;                                            //visited nodes

        queue<TreeNode*> q;
        q.push(target);

        int dist=0;

        while(dist<k && !q.empty())
        {

            int n=q.size();

            for(int i=0;i<n;i++)
            {
               TreeNode* here=q.front();
                q.pop();

                visited.insert(here);                                                   //mark present node as visited

                if(here->left && visited.find(here->left)==visited.end())               //left node present and not visited
                {
                    q.push(here->left);
                }

                if(here->right && visited.find(here->right)==visited.end())             //right node present and not visited
                {
                    q.push(here->right);
                }

                                                                                        //parent node exists and not visited
            if(parent.find(here)!=parent.end() && visited.find(parent[here])==visited.end())
                {
                    q.push(parent[here]);
                }
            }

            dist++;                    // distance increases after covering left,right,parent radially
        }

        while(!q.empty())
        {
            arr.push_back(q.front()->val);
            q.pop();
        }

        return arr;
    }

};
