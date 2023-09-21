#include <iostream>
#include <queue> //큐 헤더파일

using namespace std;

/*
HINT : 상위 n개의 숫자에서 n번째 숫자는 가장 작은 숫자네요!
*/

/*
입력되는 수 중 n번째로 큰 수를 찾자!
-> 최종으로 상위 n개를 저장할 수 있는 구조 -> n개 이상일 때 가장 작은 값을 삭제할 수 있는 구조
-> 최소힙을 이용하자
-> 입력을 최소힙에 push하고 힙의 사이즈가 n보다 크다면 top값을 제거해주자
->최종적으로 상위 n개의 숫자가 저장되고 top값이 n번째 큰 수가 된다!
*/


int main() {
    
    //속도 향상 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int n, num; //n과 각 숫자를 담을 변수
	priority_queue<int, vector<int>, greater<int>> pq; //최소힙. 
	//greater : 오름차순 정렬 / 가장 작은 수가 스택 탑에!

	//입력
	cin >> n;

	//연산
	for (int i = 0; i < n * n; i++) {
		cin >> num; //n^2개 숫자 입력받기
		pq.push(num); //스택에 입력받은 수 넣기

		//pq의 size를 n개 이하로 유지하여 메모리 초과 방지
		if (pq.size() > n) {
			pq.pop(); //pq에서 가장 작은 값 제거
		}
	}

	//출력
	//pq에 n * n개의 수 중 가장 큰 n개가 남았으므로 그 중 가장 작은 값(top)이 n번째로 큰 수
	cout << pq.top();

	return 0;
}