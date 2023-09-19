//��Ʃ��Ʃ 1���� 3�� ���� #���� <19636 ��� �ùķ��̼�>

#include <iostream>
#include <cmath>

using namespace std;;


//���ʴ�緮 ��ȭ ��� ���ϴ� ���
void nonchangeX(int w, int d, int l, int l0, int a) {
	w += d * (l - (l0 + a));

	if (w <= 0) {
		cout << "Danger Diet" << endl;
	}
	else {
		cout << w << " " << l0 << endl;
	}
}


//���ʴ�緮 ��ȭ ����ϴ� ���
void changeX(int w, int l0, int t, int d, int l, int a, int x) {

	int flag = 0; //Danger Diet�� ��쿣 flag�� 1�� �ٲٱ�.

	while (d > 0) {

		double res = l - (a + x);

		//ü�� ��ȭ
		w += res;

		//���ʴ�緮 ��ȭ
		if (abs(res) > t) {

			//������ ������ �� ����. c++�� -5/2�� -2�� �����Ƿ�, ������ ��� -1�� ���� ����� �ٲٰ� �ݿø��� ��, �ٽ� ������ �ٲ���.
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

	int x = l0; //x�� ���ʴ�緮 �� ���� ����

	nonchangeX(w, d, l, l0, a); //���ʴ�緮 ��ȭ ������ϴ� ���
	changeX(w, l0, t, d, l, a, x); //���ʴ�緮 ��ȭ ����ϴ� ���

	return 0;
}




