//Asteroid Collision leetcode stack

class Solution {
public:


//push only when stack empty or no collision condition
// Collision Cond: right(positive) left(negative)
// No collision if same sign or left right

    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> s;

        for(int i=0;i<asteroids.size();i++)
        {
            if(s.empty())
                s.push(asteroids[i]);

            else{
                if(asteroids[i]<0 && s.top()>=0)      //negative element after positive
                {
                    //collision

                    if(abs(asteroids[i])==s.top())     //equal magnitude both stay out
                      s.pop();

                    else if(s.top()<abs(asteroids[i]))       //stack element small pop out
                    {
                        s.pop();
                        i--;

                       // s.push(asteroids[i]);
                      //re evaluate present element for new stack top
                    }

                    //if present element small dont put it simply

                }

                else       //no collision condition
                    s.push(asteroids[i]);

            }
        }

        int n=s.size();
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--)
        {
            ans[i]=s.top();
            s.pop();
        }

        return ans;

    }
};
