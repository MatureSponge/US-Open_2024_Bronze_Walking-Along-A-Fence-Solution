#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, P;
    int distance = 1;
    int max_dist;
    cin >> N >> P;

    vector<vector<int>> dist(1001, vector<int> (1001, 0));
    vector<pair<int, int>> post(P);
    for (int i = 0; i < P; i++) {
        cin >> post[i].first >> post[i].second;
    }

    for (int i = 0; i < P; i++) {
        if (post[i].first == post[(i+1)%P].first) {
            if (post[i].second > post[(i+1)%P].second) {
                for (int y = post[i].second-1; y >= post[(i+1)%P].second; y--) {
                    dist[post[i].first][y] = distance;
                    distance++;
                }
            } else {
                for (int y = post[i].second+1; y <= post[(i+1)%P].second; y++) {
                    dist[post[i].first][y] = distance;
                    distance++;
                }
            }
        } else {
            if (post[i].first > post[(i+1)%P].first) {
                for (int x = post[i].first-1; x >= post[(i+1)%P].first; x--) {
                    dist[x][post[i].second] = distance;
                    distance++;
                }
            } else {
                for (int x = post[i].first+1; x <= post[(i+1)%P].first; x++) {
                    dist[x][post[i].second] = distance;
                    distance++;
                }
            }
        }
    }
    max_dist = distance-1;
    dist[post[0].first][post[0].second] = 0;

    while (N--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int walk = abs(dist[x2][y2]-dist[x1][y1]);
        if (dist[x2][y2] > dist[x1][y1]) {
            walk = min(walk, max_dist-dist[x2][y2]+dist[x1][y1]);
        } else {
            walk = min(walk, max_dist-dist[x1][y1]+dist[x2][y2]);
        }

        cout << walk << '\n';
    }

    return 0;
}
