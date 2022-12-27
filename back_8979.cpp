#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct _nation {
    int id;
    int gold, silver, bronze;
    int rank;
} _nation;

vector<_nation> nation;

bool comp(_nation a, _nation b) {
    if (a.gold > b.gold) {
        return true;
    } else if (a.gold == b.gold) {
        if (a.silver > b.silver) {
            return true;
        } else if (a.silver == b.silver) {
            if (a.bronze > b.bronze) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int a, g, s, b;
        cin >> a >> g >> s >> b;
        nation.push_back({a, g, s, b, 1});
    }

    sort(nation.begin(), nation.end(), comp);

    for (int i = 1; i < N; i++) {
        if (nation[i].gold == nation[i - 1].gold &&
            nation[i].silver == nation[i - 1].silver &&
            nation[i].bronze == nation[i - 1].bronze) {
            nation[i].rank = nation[i - 1].rank;
        } else {
            nation[i].rank = i+1;
        }
    }

    for (int i = 0; i < N; i++) {
        if (nation[i].id == K) {
            cout << nation[i].rank;
            break;
        }
    }

    return 0;
}