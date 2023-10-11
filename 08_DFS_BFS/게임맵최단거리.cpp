#include <vector>
#include <queue>
using namespace std;

struct Pos {
    int x;
    int y;
    Pos(int _y, int _x) : y(_y), x(_x) {}
};

int solution(vector<vector<int> > maps) {
    const int n = maps.size(); // 행의 개수
    const int m = maps[0].size(); // 열의 개수
    // 방향 (상, 우, 하, 좌)
    int deltaY[4] = { -1, 0, 1, 0 };
    int deltaX[4] = { 0, 1, 0, -1 };

    vector<vector<int>> dist(n, vector<int>(m, -1)); // 출발지로부터 해당 위치까지의 최단 거리
    queue<Pos> q; // 큐

    // 출발지는 예약 작업을 할 수 없고 바로 방문해야 하니 미리 작업
    q.push(Pos(0, 0));  // 큐에 출발지 좌표를 넣어 시작
    dist[0][0] = 1; // 출발지의 거리는 1

    while (!q.empty()) {
        // 방문할 위치를 큐에서 꺼냄
        Pos pos = q.front();
        q.pop();
        int nowY = pos.y;
        int nowX = pos.x;

        // 상, 우, 하, 좌 방향을 탐색
        for (int i = 0; i < 4; ++i) {
            int nextY = nowY + deltaY[i];
            int nextX = nowX + deltaX[i];

            // 다음에 방문할 수 있는지 체크
            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) // 맵을 벗어난다면 예약할 수 없는 방향
                continue;
            if (maps[nextY][nextX] == 0) // 벽이라면 예약할 수 없는 방향
                continue;
            if (dist[nextY][nextX] != -1) // 이미 최단거리가 업데이트되었다면 스킵
                continue;

            // 다음에 방문할 수 있는 곳이니 큐에 넣어 예약하고, 그와 동시에 최단거리 업데이트
            q.push(Pos(nextY, nextX));
            dist[nextY][nextX] = dist[nowY][nowX] + 1; // 최단 거리 업데이트 (방문 노드에서 +1 하면 최단 거리)
        }
    }

    if (dist[n - 1][m - 1] == -1) // 도착지까지 도달할 수 없는 경우
        return -1;
    else
        return dist[n - 1][m - 1]; // 도착지의 최단거리 리턴
}
