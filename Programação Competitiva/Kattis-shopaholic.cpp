#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    

        long long int n;
        cin >> n;
        
        vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }
        
        sort(prices.begin(), prices.end(), greater<int>());
        
        long long int discount = 0;
        for (int i = 2; i < n; i += 3) {
            discount += prices[i];
        }
        
        cout << discount << endl;
    
    return 0;
}
