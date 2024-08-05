#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int left, right;
};

bool operator<(const Segment& a, const Segment& b) {
    return a.left < b.left;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m;
        cin >> m;

        vector<Segment> segments;
        int l, r;
        while (cin >> l >> r, l != 0 || r != 0) {
            if (l <= 0 && r > 0) {
                segments.push_back({l, r});
            }
        }

        sort(segments.begin(), segments.end());

        int n = segments.size();
        int covered = 0;
        int i = 0, j = 0;
        vector<int> chosen;
        while (covered < m && i < n) {
            int best_j = -1;
            int best_right = covered;
            while (j < n && segments[j].left <= covered) {
                if (segments[j].right > best_right) {
                    best_right = segments[j].right;
                    best_j = j;
                }
                j++;
            }
            if (best_j == -1) {
                break;
            }
            chosen.push_back(best_j);
            covered = best_right;
            i = j;
        }

        if (covered < m) {
            cout << "0\n";
        } else {
            cout << chosen.size() << "\n";
            for (int idx : chosen) {
                cout << segments[idx].left << " " << segments[idx].right << "\n";
            }
        }

        if (t > 0) {
            cout << "\n";
        }
    }

    return 0;
}