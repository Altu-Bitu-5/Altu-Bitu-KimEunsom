#include <iostream>
#include <set> //set 헤더파일

using namespace std;

/*
* set::find 함수 사용 (key 값이 존재하면 해당 iterator, 존재하지 않으면 set::end 반환)
* vector를 이용하면 원소를 탐색하면 시간 복잡도가 O(n) (시간 초과)
* set은 이진트리 구조를 사용하므로 원소 탐색의 시간 복잡도가 O(log2n)
* 1. find 함수 사용
* 2. count 함수 사용
*/

int main()
{
	int n, m, cnt = 0; //두 문자열의 크기를 담을 n,m 변수와 최종 포함 문자열 갯수를 담을 cnt 변수
	set<string> s; //set 선언
	string input; //set에 담을 문자열 변수
	cin >> n >> m; //n,m 입력

	while (n--) { //비교할 문자열 집합 n개 입력받기
		cin >> input; //문자열 입력
		s.insert(input); // set에 방금 input에 저장한 문자열을 원소로 추가
	}


	// 연산
	while (m--) { //m개의 문자열이 앞의 문자열에 포함됐는지 확인하는 과정
		cin >> input; //문자열 입력

		// 1. find 함수 사용
		if (s.find(input) != s.end()) { // set에 원소가 포함되어 있는지 확인
			cnt++; //포함되어있다면, 카운트 변수 +1
		}
		//  2. count 함수 사용
		// cnt += s.count(input); // set에 해당 원소의 존재 여부를 int형으로 리턴
	}

	// 출력
	cout << cnt << '\n'; //줄바꿔서 총 포함된 문자열 갯수 출력
	return 0;
}