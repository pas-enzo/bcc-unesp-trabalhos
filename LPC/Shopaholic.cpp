#include <bits/stdc++.h>

using namespace std;

int main ()
{   
    int num, aux, t=0, c=0;
    vector<int> items;

    cin >> num;

    while (c < num)
    {   
        cin >> aux;
        items.push_back(aux);
        c++;
    }

    sort(items.begin(), items.end(), greater<int>());
    
    for(int i=0; i<num; i++) 
    {
    	cout << items[i] << " " << endl;
	}

    for (int i=2; i<num; i+=3)
    {
        t += items[i];
    }

    cout << t << endl;

    return 0;
}