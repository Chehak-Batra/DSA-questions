//User function Template for C++

class Solution {
  public:
   unordered_map<Node*,Node*> makeparent(Node* root,Node* &target,int t)            // (node parent mapping) (target node find)
    {
        queue<Node*> q;
        unordered_map<Node*,Node*> um;

        q.push(root);

        while(!q.empty())
        {
           Node* node=q.front();
            q.pop();

            if(node->data==t)
            target=node;

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

    int minTime(Node* root, int target)                          //burning all nodes radially from target node
    {
        if(!root)
            return 0;

        Node* t;
        unordered_map<Node*,Node*> parent=makeparent(root,t,target);

        unordered_set<Node*> visited;

        queue<Node*> q;
        q.push(t);

        int dist=0;
        while(!q.empty())
        {
            int n=q.size();
            bool flag=false;

            for(int i=0;i<n;i++)
            {
               Node* here=q.front();
                q.pop();

                visited.insert(here);

                if(here->left && visited.find(here->left)==visited.end())
                {
                    q.push(here->left);
                    flag=true;
                }

                if(here->right && visited.find(here->right)==visited.end())
                {
                    q.push(here->right);
                    flag=true;
                }


            if(parent.find(here)!=parent.end() && visited.find(parent[here])==visited.end())
                {
                     //node has parent which is not visited
                    q.push(parent[here]);
                    flag=true;
                }
            }

            if(flag)           // burned something on next level
            dist++;
        }

   return dist;
    }
};
