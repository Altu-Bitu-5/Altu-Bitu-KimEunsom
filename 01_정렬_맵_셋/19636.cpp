//알튜비튜 1주차 3번 과제 #구현 <19636 요요 시뮬레이션>

#include <iostream>
#include <cmath>

using namespace std;;


//기초대사량 변화 고려 안하는 경우
void nonchangeX(int w, int d, int l, int l0, int a) {
	w += d * (l - (l0 + a));

	if (w <= 0) {
		cout << "Danger Diet" << endl;
	}
	else {
		cout << w << " " << l0 << endl;
	}
}


//기초대사량 변화 고려하는 경우
void changeX(int w, int l0, int t, int d, int l, int a, int x) {

	int flag = 0; //Danger Diet인 경우엔 flag값 1로 바꾸기.

	while (d > 0) {

		double res = l - (a + x);

		//체중 변화
		w += res;

		//기초대사량 변화
		if (abs(res) > t) {

			//음수의 나눗셈 값 보정. c++은 -5/2가 -2로 나오므로, 음수인 경우 -1을 곱해 양수로 바꾸고 반올림한 후, 다시 음수로 바꿔줌.
			if (res < 0) {
				res *= -1;
				res = round(res / 2.0);
				res *= -1;
			}

			x += res;
		}

		if (w <= 0 || x <= 0) {
			cout << "Danger Diet";
			flag = 1;
			break;
		}

		d--;
	}

	if (flag == 0) {

		cout << w << " " << x;
		if (l0 <= x) {
			cout << " NO";
		}
		else {
			cout << " YOYO";
		}
	}
}

int main() {
	int w, l0, t, d, l, a;

	cin >> w >> l0 >> t;
	cin >> d >> l >> a;

	int x = l0; //x는 기초대사량 값 담을 변수

	nonchangeX(w, d, l, l0, a); //기초대사량 변화 고려안하는 경우
	changeX(w, l0, t, d, l, a, x); //기초대사량 변화 고려하는 경우

	return 0;
}




