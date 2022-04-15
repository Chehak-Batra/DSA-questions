#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> s;
    string str;
    bool flag=false;
    cin>>str;

    for(auto i:str)
    {
        if(i==')')
        {
            if(s.empty() || s.top()=='(')
             {
                cout<<"true";                         //needless bracket present
                flag=true;
                break;
             }
            else{
                while(s.top()!='(')
                {
                    s.pop();
                }
                s.pop();
            }
        }
        else{
            s.push(i);
        }
    }

    if(flag==false)
    cout<<"false";


    return 0;
}
