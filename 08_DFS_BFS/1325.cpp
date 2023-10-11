#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> adj_list;
vector<bool> visited;
int n;

int dfs(int start) {
    stack<int> s;
    s.push(start);
    visited[start] = true;
    int nodes_visited = 1;

    while (!s.empty())  {
        int node = s.top();
        s.pop();

        for (int neighbor : adj_list[node]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
                visited[neighbor] = true;
                nodes_visited++;
            }
        }
    }

    return nodes_visited;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> n >> m;
    adj_list.resize(n + 1);
    visited.assign(n + 1, false);

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj_list[b].push_back(a);  // 역방향 그래프를 만듭니다.
    }

    vector<int> result(n + 1, 0);

    for (int v = 1; v <= n; v++) {
        fill(visited.begin(), visited.end(), false);  // visited 배열 초기화
        int nodes_visited = dfs(v);
        result[v] = nodes_visited;
    }

    int max_hacked = *max_element(result.begin(), result.end());

    for (int i = 1; i <= n; i++) {
        if (result[i] == max_hacked) {
            cout << i << " ";
        }
    }

    return 0;
}
