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
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*,unsigned int>> q;      //(node index) indexing of elements 1 2 3 4 5..  level wise etc.

        q.push({root,1});                           //1 based indexing

        //root(1) nodes(2(1), 2(1)+1)  {2i,2i+1}

        unsigned int start=0;
        unsigned int end=0;
        int maxx=0;

        while(!q.empty())
        {
            int n=q.size();

            for(int i=0;i<n;i++)
            {
                auto here=q.front();
                q.pop();

               if(i==0)                           //first element of level ka index
                   start=here.second;

               if(i==n-1)                        //last element of level ka index
                    end=here.second;

               if(here.first->left)                              //left child 2i index
                   q.push({here.first->left,2*here.second});

                if(here.first->right)                            //right child 2i+1 index
                    q.push({here.first->right,2*here.second+1});
            }

            if(end-start+1>maxx)              // max gap in nodes of each level null or not null
            maxx=end-start+1;

        }

        return maxx;
    }
};
