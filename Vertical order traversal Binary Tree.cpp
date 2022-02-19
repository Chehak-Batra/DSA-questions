 #include<bits/stdc++.h>
 using namespace std;

 vector<vector<int>> verticalTraversal(TreeNode* root) {

        //vertical_line height sorted nodes
        map<int,map<int,multiset<int>>> arr;


        queue<pair<TreeNode* , pair<int,int>>> q;        //node vline height

        q.push({root,{0,0}});

        while(!q.empty())
        {
            pair<TreeNode* , pair<int,int>> here=q.front();
            int vline=here.second.first;
            int height=here.second.second;
            q.pop();

            map<int,multiset<int>> um=arr[vline];
            um[height].insert(here.first->val);

            arr[vline]=um;

            if(here.first->left)
                q.push({here.first->left,{vline-1,height+1}});
            if(here.first->right)
                q.push({here.first->right,{vline+1,height+1}});
        }

        vector<vector<int>> ret;

        for(auto i:arr)
        {
            vector<int> z;

            for(auto j:i.second)
            {
                z.insert(z.end(),j.second.begin(),j.second.end());
            }

            ret.push_back(z);
        }
        return ret;
        }
