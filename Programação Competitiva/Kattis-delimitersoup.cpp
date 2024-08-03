#include <bits/stdc++.h>

using namespace std;

int main ()
{   
    int i=0;
    int tst;
    stack<char> exp;
    char ent;

    cin >> tst;

    cin.get(ent);

    while (i < tst) 
    {
        cin.get(ent);

        if (ent == '(' || ent == '[' || ent == '{') 
        {
            exp.push(ent);
        }
    

        else if (ent == ')') 
        {
            
            if (!exp.empty() && exp.top() == '(') 
            {
                exp.pop();
            }
            
            else 
            {
                cout << ent << " " << i << endl;
                break;
            }
        }
        
        else if (ent == ']') 
        {
            
            if (!exp.empty() && exp.top() == '[') 
            {
                exp.pop();
            }
            
            else 
            {
                cout << ent << " " << i << endl;
                break;
            }
        }
        
        else if (ent == '}') 
        {
            
            if (!exp.empty() && exp.top() == '{') 
            {
                exp.pop();
            }
            
            else 
            {
                cout << ent << " " << i << endl;
                break;
            }
        }

        i++;

    }


    if (i == tst) {
        cout << "ok so far" << endl;
    }

    return 0;

}
