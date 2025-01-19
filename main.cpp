#include <bits/stdc++.h>
#define vv vector<vector<char>>
#define vec2d(type, name, rows, cols) \
    std::vector<std::vector<type>> name(rows, std::vector<type>(cols))

using namespace std;

bool cmpTrees(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

bool cmpIntervals(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

int main() {
    int t;
    cin >> t;

    while ( t-- ) {

        int n, k;
        cin >> n >> k;

        vector <pair<int, int>> trees;
        for ( int i = 0; i < n; i++) {
            int f;
            cin >> f;

            trees.push_back({f, 0});
        }

        // 0 - L, 1 - R, 2 - K, 3 - TreeVal
        vector<vector<int>> intervals;
        for ( int i = 0; i < k; i++ ) {
            int l, r, k;
            cin >> l >> r >> k;

            vector<int> bob = {l, r, k, 0};
            intervals.push_back(bob);
        }

        int j = 0;
        // cnt how many times each tree appears and in what interval
        for ( int i = 0; i < trees.size(); i++ ) {
            for ( int j = 0; j < intervals.size(); j++ ) {
                if ( trees[i].first >= intervals[j][0] && trees[i].first <= intervals[j][1] ) {
                    intervals[j][3] += 1;
                    //cout << "INC: " << trees[i].first << " " << j << endl;
                    trees[i].second += 1;
                }
            }
        }

        sort(trees.begin(), trees.end(), cmpTrees);
        //cout << "TF: " << trees[0].second << endl;
        //sort(intervals.begin(), intervals.end(), cmpIntervals);
        //cout << trees[i].first << endl;
        
        for ( int i =0 ; i < trees.size(); i++ ) {
            cout << trees[i].first << " " << trees[i].second << endl;
        }

        for ( int j =0 ; j < intervals.size(); j++ ) {
            cout << intervals[j][0] << " " << intervals[j][1] << " | " << intervals[j][2] << " " << intervals[j][3] << endl;
        }

        int numDels = 0;
        for ( int i = 0; i < trees.size(); i++ ) {
            bool canDel = true;

            for ( int j = 0; j < intervals.size(); j++ ) {
                if ( trees[i].first >= intervals[j][0] && trees[i].first <= intervals[j][1] ) {
                    if ( intervals[j][3] - 1 < intervals[j][2] ) {
                        canDel = false;
                    }
                }
            }

            if (canDel == true) {
                numDels += 1;

                for ( int j = 0; j < intervals.size(); j++ ) {
                    if ( trees[i].first >= intervals[j][0] && trees[i].first <= intervals[j][1] ) {
                            intervals[j][3] -= 1;
                    }
                } 
            }
        }
        cout << numDels << endl;
    }

}
