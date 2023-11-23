#include<iostream>
#include<vector>

using namespace std;

// 이진 검색 트리에서 후위 순회 수행하는 함수
void postOrder(int left, int right, vector<int>& tree) {
    if (left > right) {
        return; // 왼쪽 인덱스가 오른쪽 인덱스를 초과하면 반환 (재귀의 기본 케이스)
    }

    int root = tree[left]; // 이해하기 쉽게 루트 따로 저장!

    // 루트보다 큰 첫 번째 노드의 인덱스 찾기하여 새로운 left, right새로 설정
    int tmp = left + 1;
    for (int i = left + 1; i <= right; i++) {
        if (tree[i] > root) { // 루트보다 큰 값이 나타나면, 저장 후 break;
            tmp = i;
            break;
        }
    }

    // 후위 순회로 왼쪽 노드(루트보다 작은 값) 재귀 탐색
    postOrder(left + 1, tmp - 1, tree);

    // 후위 순회로 오른쪽 노드(루트보다 큰 값) 재귀 탐색
    postOrder(tmp, right, tree);

    // 왼쪽, 오른쪽 노드 탐색 후 루트 출력
    cout << root << '\n';
}

/*
* 이진 검색 트리: 루트의 왼쪽에 있는 트리
* 이진 검색 트리의 전위 순회 결과를 후위 순회 결과로 변환
* 전위 순회: 루트 왼쪽 오른쪽 -> 후위 순회: 왼쪽 오른쪽 루트
*  -> 탐색 결과: 루트 -> 루트보다 작은 노드(왼쪽) -> 루트보다 큰 노드(오른쪽)
*  -> 루트를 기준으로 왼쪽과 오른쪽을 나누어 후위 순회로 재귀 탐색
*/

// 메인 함수
int main() {

    ios::sync_with_stdio(false); // 속도 향상 코드
    cin.tie(0);
    cout.tie(0); 

    // 입력
    int num;
    vector<int> tree;
    while (cin >> num) {
        tree.push_back(num); // 전위 순회 결과를 입력받아 tree 벡터에 저장
    }

    // 연산 후 출력. 함수 호출
    postOrder(0, tree.size() - 1, tree);
}