#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //입력 & 연산
    int n, k;
    int idx =0; 
    int flag = 0;
    
    cin >> n >> k;
    
    vector<char> v(n); //n만큼 벡터 생성 후 스페이스로 초기화
    
    //벡터 '0'으로 초기화
    for(int i=0; i<n; i++) {
        v[i]='0';
    }
    
    //fill(v.begin(), v.end(), '0');
    
    
    for(int i=0; i<k; i++) {
        
        int s;
        char c;
        
        cin >> s >> c;
        
        idx += s; //현재 화살표의 위치를 담는 변수 idx
        if(idx>=n) {
            idx%=n;
        }
        
        //몇 번 바뀌었는지!! 그니까 중복은 카운트하지 말아야함.
        for(int i=0; i<s; i++) {
            //벡터 한바퀴만큼 n만큼 돌 되, s번 바뀌면 브레이크. 거기서 화살표!
        }
        
        
        if(v[idx]=='0') { //바퀴 칸 비어있으면, 입력값 넣기
            v[idx]=c;
        } else if (v[idx]!=c){ //이미 바퀴 칸 차있는데 다른 문자와 중복
            flag = 1;
        }
        
    }
    
    
    //출력
    if(flag==1) {
        cout << "!";
    } else {
        int count = n;
        int i=idx;

        while(count>0) {
            
            if(i<0) {
                i+=n;
            }
            
            if(v[i]=='0') { 
                //바퀴 칸 비어있으면(배열의 값이 초기값 그대로 0이면), 모르는 것이므로 ? 출력
                cout << "?";
            } else { 
                //바퀴칸이 배열의 초기화값인 0이 아니라면, 출력
                cout << v[i];
            }
            
            count--;
            i--;
    }
        
    }
    
    
    
    return 0;
}