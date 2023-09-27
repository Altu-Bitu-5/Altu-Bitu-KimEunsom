#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력받기
    int n = 0;
    cin >> n;

    vector<long long> planet(n);
    for (int i = 0; i < n; i++) {
        cin >> planet[i];
    }
    
    //행성 이동 때 필요한 속도!
    long long velocity = planet[n - 1];
    
    //뒤의 행성부터 연산!
    for (int i = n - 2; i >= 0; i--) {
        if (velocity < planet[i]) { //필요한 속도보다 작은 경우
            velocity = planet[i];
        } 
        //배수 아니면, 양의 배수로 만들면서 앞으로 진행!
        else if (planet[i] < velocity && velocity % planet[i] != 0) {
            velocity = ((velocity / planet[i]) + 1) * planet[i];
        }
    }

    cout << velocity << "\n";

    return 0;
}
