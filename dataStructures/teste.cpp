#include<bits/stdc++.h>

using namespace std;

inline void print_arr(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

inline void print_table(vector<vector<int>> table) {
    for (int i = 0; i < table.size() - 1; i++) {
        print_arr(table[i]);
    }
}

inline int lg(int num) {
    return __builtin_clz(1) - __builtin_clz(num);
}

inline int func(int a, int b) {
    return max(a, b);
}

inline vector<vector<int>> build_table(vector<int> &list) {
    int aux, log_max = lg((int) list.size());
    vector<vector<int>> table(list.size());
    for (int i = 0; i < list.size(); i++) {
        vector<int> row(log_max + 1);
        table[i] = row;
        table[i][0] = list[i];
    }

    for (int j = 1; j <= log_max; j++) {
        for (int i = 0; i + (1 << j) <= list.size(); i++) {
            aux = i + (1 << (j - 1));
            table[i][j] = func(table[i][j - 1], table[aux][j - 1]);
        }
    }

    return table;
}

inline int query(vector<vector<int>> &table, int l, int r) {
    int log_diff = lg(r - l + 1);
    return func(table[l][log_diff], table[r - (1 << log_diff) + 1][log_diff]);
}

int table_binary_search(vector<vector<int>> &table, int t_pos, int d) {
    int l = 0, r = t_pos, ans = 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (query(table, mid, t_pos) <= d) {
            r = mid - 1;
        } else {
            ans = mid + 2;
            l = mid + 1;
        }
    }

    return ans;
}

int binary_search(vector<int> &list, int num) {
    int l = 1;
    int r = list.size() - 1;
    int mid;
    while (l <= r) {
        mid = (r + l) / 2;
        if (list[mid] <= num) {
            l = mid + 1;
            if (num < list[mid + 1]) {
                return mid;
            }
        } else if (list[mid] > num) {
            r = mid - 1;
        }
    }
    return mid;
}

int main() {
    int n, t, d;
    scanf("%d", &n);
    vector<int> list(n + 2);
    vector<int> list_diff(n - 1);
    list[0] = -1;
    scanf("%d", &list[1]);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &list[i]);
        list_diff[i - 2] = list[i] - list[i - 1];
    }
    list[n + 1] = 1000009;

    vector<vector<int>> table = build_table(list_diff);

    int q, t_pos, ans;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &t, &d);
        t_pos = binary_search(list, t) - 2;
        ans = table_binary_search(table, t_pos, d);
        printf("%d\n", ans);
    }

    return 0;
}
