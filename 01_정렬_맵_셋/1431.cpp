//��Ʃ��Ʃ 1���� 1�� ���� #���� <1431 �ø��� ��ȣ>

#include <iostream>
#include <algorithm>

using namespace std;

//�ڸ��� �� ���ϴ� �Լ�
int sumNum(string str) {
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] <= 57 && str[i] >= 48) {
			sum += str[i] - 48;
		}
	}
	return sum;
}

//���Լ�
bool cmp(const string& w1, const string& w2) {
	int l1 = w1.length();
	int l2 = w2.length();

	//���� ���� ��� : �ڸ��� ���
	if (l1 == l2) {
		int sum1 = sumNum(w1);
		int sum2 = sumNum(w2);

		if (sum1 == sum2) {
			//�ڸ��� ������ ������ ����
			return w1 < w2;
		}
		else {
			return sum1 < sum2; //�ڸ��� �� ���� �������� ����
		}
	}

	//���� �ٸ� ��� : ���� ���� �������� ����
	else {
		return l1 < l2;
	}

}

int main() {

	int n;
	cin >> n;

	string word[50];
	int l[50];

	//�Է�
	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}
	
	//����
	sort(word, word + n, cmp); //���Լ�


	//���ĵ� ���ڿ� �迭�� ���
	for (int i = 0; i < n; i++) {
		cout << word[i] << endl;
	}

	return 0;
}