class Solution {
    vector<int> arr;
    vector<int> right;

public:
   void leftbound(Node *root)            //top to down printing  (print then call)
   {
       if(!root)
         return;

       if(root->left)
       {
           arr.push_back(root->data);
           leftbound(root->left);
       }
       else if(root->right)
       {
           arr.push_back(root->data);
           leftbound(root->right);
       }

   }

   void rightbound(Node *root)                   //reverse printing (call first, print while backtracking)
   {
      if(!root)
         return;

    if(root->right)
    {
        rightbound(root->right);
        arr.push_back(root->data);
    }
    else if(root->left)
    {
        rightbound(root->left);
        arr.push_back(root->data);
    }

   }

   void leaf(Node* root)                               //inorder left root right
   {
       if(!root)
         return;

        leaf(root->left);

        if(!(root->left) && !(root->right))
        arr.push_back(root->data);

        leaf(root->right);
   }

    vector<int> boundary(Node *root)
    {
        if(root==NULL)
        return arr;

        arr.push_back(root->data);                                //print root node

        leftbound(root->left);                                    //all nodes on left

        leaf(root->left);                                         //leaves from left and right
        leaf(root->right);

        rightbound(root->right);                                 //all nodes on right

        return arr;
    }
};
