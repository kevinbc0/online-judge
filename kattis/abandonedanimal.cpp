#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

constexpr int MAXN = 1000003;

vector<unordered_set<string>> stores;
vector<string> item_list;
int next_store[MAXN];
int num_stores;

void solve() {
    int cur_store = 0;
    int last_store = -1;
    vector<string> last_item;
    last_item.push_back("");
    for (int i = 0; i < item_list.size(); i++) {
         while (stores[cur_store].count(item_list[i]) == 0) {
            cur_store++;
            last_item.push_back("");
            if (cur_store == num_stores) {
                cout << "impossible\n";
                return;
            }
         }

         next_store[last_store] = cur_store;
         last_store = cur_store;

         last_item[cur_store] = item_list[i];
    }
    next_store[last_store] = num_stores - 1;
    while(last_item.size() < num_stores + 1) {
        last_item.push_back("");
    }

    int cur = 0;
    for (; cur < num_stores; cur++) {
        if (last_item[cur] != "") {
            break;
        }
    }

    string last = last_item[cur];
    int next = next_store[cur];
    cur++;
    while (cur < num_stores) {
        for (; cur <= next; cur++) {
            if (stores[cur].count(last) != 0) {
                cout << "ambiguous\n";
                return;
            }
        }

        last = last_item[cur - 1];
        next = next_store[cur - 1];
    }

    cout << "unique\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> num_stores;
    for (int i = 0; i < num_stores; i++) {
        stores.push_back(unordered_set<string>());
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int store_no;
        string item;
        cin >> store_no >> item;
        stores[store_no].insert(item);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string item;
        cin >> item;
        item_list.push_back(item);
    }

    solve();
}
