#include <iostream>
#include <vector>

using namespace std;

const int CLEAN = 2; //청소한 상태는 2로 저장
int cnt = 0; //청소한 칸 개수

//현재 칸 기준 4가지 방향: { 북, 동, 남, 서 }
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int clean(int n, int m, int r, int c, int d, vector<vector<int>>& board) {
    int cnt = 0; //청소한 칸 개수 초기화

    while (true) { //무한 루프
        //1. 
        if (board[r][c] != CLEAN) { //현재 칸이 아직 청소되지 않은 경우, 
            cnt++; //청소한 칸 수를 늘리고,
            board[r][c] = CLEAN; //현재 칸을 청소한다.
        }

        bool find = false; //현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는가
        for (int i = 0; i < 4; i++) { //3-1. 반시계 방향으로 90º 회전
            int nd = (d - i + 3) % 4; //0->3->2->1->0->3 ... 의 순서로 돌며 계속 방향 회전함
            int nr = r + dy[nd], nc = c + dx[nd]; //바라보는 방향 기준, 한 칸 전진한 값

            if (board[nr][nc] == 0) { //3-2. 
                find = true; //아직 청소되지 않은 빈 칸 발견
                r = nr; c = nc; d = nd; //전진
                break;
            }
        }
        if (find) { //3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우 1번으로 돌아감
            continue;
        }

        //2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        int bd = (d + 2) % 4; //방향 180도 전환해서
        int br = r + dy[bd], bc = c + dx[bd]; //전진 좌표 저장 (즉, 원래 위치에서의 후진 좌표)

        //[바라보는 방향을 유지한 채로 한 칸 후진할 수 있는가]
        //2-2. 
        if (board[br][bc] == 1) { //뒤쪽 칸이 벽이라 후진할 수 없는 경우
            return cnt; // 종료. 무한루프 탈출
        }
        
        //2-1. 바라보는 방향을 유지한 채로 한 칸 후진
        r = br; c = bc; //후진
    }
    return cnt; // 청소한 칸 수 리턴
}

/*
[로봇 청소기 작동]
1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
    2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
    2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
    3-1. 반시계 방향으로 90º 회전한다.
    3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
    3-3. 1번으로 돌아간다.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int n, m, r, c, d; //방 크기, 로봇 청소기 정보
    cin >> n >> m;
    cin >> r >> c >> d;

    vector<vector<int>> board(n, vector<int>(m, 0)); //이차원 벡터
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //연산 & 출력
    cout << clean(n, m, r, c, d, board);

    return 0;
}