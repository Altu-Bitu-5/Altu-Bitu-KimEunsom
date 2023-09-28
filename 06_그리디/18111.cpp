#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii; // 두 정수 저장하기 위해 typedef 선언

const int MAX_HEIGHT = 257; //최대 높이 상수로 저장
const int INF = 987'654'321; //가능한 최댓값이 12,800,000이므로 많이 쓰는 큰 수인 987654321을 사용했습니다! INF관련 글을 한번 읽어보세요!

// 모든 땅의 높이를 height로 만드는 비용 계산
int calcCost(int height, int n, int m, int b, vector<vector<int>>& blocks) {
    int cost = 0;       // 총 비용
    int added = 0;      // 추가해야 하는 블록의 총 개수
    int removed = 0;    // 제거해야 하는 블록의 총 개수

    // 모든 블록에 대해 이중 반복
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int gap = abs(height - blocks[i][j]); // 목표 높이와 현재 블록의 높이 차이 계산

            if (blocks[i][j] > height) {// 목표 높이보다 높은 칸인 경우,
                removed += gap; //gap개의 블록 제거
            }
            else if (blocks[i][j] < height) {// 목표 높이보다 낮은 칸인 경우,
                added += gap; //gap개의 블록 추가
            }
        }
    }

    // 전체 비용 계산
    cost = 2 * removed + added;

    // 블록 개수가 부족하다면 모든 땅의 높이를 height로 만드는 것이 불가능
    return (added > (b + removed)) ? INF : cost;
}

// 모든 땅의 높이를 같게 만드는 최소 비용과 그 때의 땅의 높이
pii makeGroundEven(int n, int m, int b, vector<vector<int>>& ground) {
    int minCost = INF; //최소 비용 초기화
    int height = 0; //최적 높이 초기화

    // 모든 가능한 높이에 대해 반복하며 최소 비용 찾기
    for (int i = 0; i < MAX_HEIGHT; i++) {
        int cost = calcCost(i, n, m, b, ground); // 현재 높이로 모든 땅의 높이를 맞출 때의 비용 계산
        if (cost <= minCost) { //최소 비용이 갱신됐다면,
            minCost = cost; //최소 비용 업데이트
            height = i; //현재 높이 저장
        }
    }

    return {minCost, height};
}

/**
 * 블록 높이의 최댓값이 256밖에 되지 않으므로
 * 모든 칸을 높이 n(0~256)으로 만드는 모든 경우를 시도해보고
 * 그 중에서 비용이 최소가 될 때를 찾는다.
 *
 * 모든 칸을 높이 n으로 만드는
 */

int main() {
    int n, m, b;

    // 입력 받기
    cin >> n >> m >> b;
    vector<vector<int>> ground(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ground[i][j];
        }
    }

    // 연산 수행
    pii answer = makeGroundEven(n, m, b, ground);

    // 출력
    cout << answer.first << " " << answer.second << "\n";

    return 0;
}