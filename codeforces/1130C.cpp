#include <bits/stdc++.h>
#define position pair<int, int>
#define MAX 100
#define LAND '0'
#define VISITED 1

using namespace std;

string planet[MAX];
vector<position> current_land;
vector<position> destiny_land;

void calculate_land(int x, int y, vector<position> &land) {
    position p;
    if(x >= 0 && x < MAX && y >= 0 && y < MAX && planet[x][y] == LAND) {
        p.first = x;
        p.second = y;
        planet[x][y] = VISITED;
        land.push_back(p);
        calculate_land(x + 1, y, land);
        calculate_land(x - 1, y, land);
        calculate_land(x, y + 1, land);
        calculate_land(x, y - 1, land);
    }
}

bool land_contains(int x, int y, vector<position> &land) {
    for (int i = 0; i < land.size(); i++) {
        if (land[i].first == x && land[i].second == y) return true;
    }
    return false;
}

int main() {
    int n;
    position start, end;
    int less_cost = 100010, cost;
    int x1, x2, y1, y2;

    cin >> n;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    for (int i = 0; i < n; i++) {
        cin >> planet[i];
    }

    calculate_land(x1 - 1, y1 - 1, current_land);
    calculate_land(x2 - 1, y2 - 1, destiny_land);

    if ((x1 == x2 && y1 == y2) || land_contains(x2 - 1, y2 - 1, current_land)) {
        less_cost = 0;
    } else {
        for (int i = 0; i < current_land.size(); i++) {
            x1 = current_land[i].first;
            y1 = current_land[i].second;
            for (int j = 0; j < destiny_land.size(); j++) {
                x2 = destiny_land[j].first;
                y2 = destiny_land[j].second;
                less_cost = min(less_cost, (((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2))));
            }
        }
    }

    cout << less_cost << endl;

    return 0;
}