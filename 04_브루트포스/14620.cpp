#include <iostream>
#include <algorithm>

using namespace std;

int groundCost[10][10];

/*11
23
43*/

//꽃 심는 좌표가 주어지면, 그 꽃의 가격 구하는 함수.
int calCost(int x, int y ) {
    
    int cost=groundCost[x][y]
            +groundCost[x-1][y]
            +groundCost[x+1][y]
            +groundCost[x][y-1]
            +groundCost[x][y+1];
        
    cout << x << " " << y << " 여기 땅에 심을 때 " << cost  << "\n";
        
    return cost;
}



//꽃 심는 좌표 3개가 주어지면, 죽는지 여부 판별하는 함수.
bool death(int x[3], int y[3]) {
    
    //x,y 좌표의 차가 3이상이어야 안죽어. 최소 3칸은 떨어져서 심어야 함.

    for(int i=0; i<2; i++) {
        int subX = max(x[i],x[i+1])-min(x[i],x[i+1]);
        int subY = max(y[i],y[i+1])-min(y[i],y[i+1]);
        if(subX+subY<3) {
            return true; //꽃 죽었다.
        }
    }

    return false; //꽃 살았다.
}



//꽃 심기
int plant(int n) {

    int res=0;
    int lastRes=0;
    int count=0;
    //꽃 심는 위치
    int x[3];
    int y[3];
    
    
    //꽃 심을 3개의 좌표 설정 : 완전탐색
    //꽃은 가장 테두리엔 심지 않는다. 1 ~ n-2만 탐색
    for(int i=1; i<n-1; i++) {
        for(int j=1; j<n-1; j++) {
            for(int k=1; k<n-1; k++) {
                    x[0]=i;
                    x[1]=j;
                    x[2]=k;
                    
                    y[0]=j;
                    y[1]=k;
                    y[2]=i;
                    
                    cout << x[0] << ", " << y[0] << '\n';
                    cout << x[1] << ", " << y[1] << '\n';
                    cout << x[2] << ", " << y[2] << "\n\n";
                    count++;

                    
                    if(!death(x, y)) { //세 꽃이 죽지 않으면
                        
                        res = 0; //현재 구할 변수는 초기화

                        //꽃 3송이 심는 데 드는 땅가격 계산
                        for(int i=0; i<3; i++) {
                            res+=calCost(x[i], y[i]);
                        }
                        cout << res << " " << lastRes << "@@@ \n"; 
                        
                        if(lastRes!=0){ //지난번 땅값 0이 아니라면, 즉 한번이라도 구해졌다면,
                            res=min(lastRes,res);
                        }
                        
                        lastRes = res; //지난 최솟값 저장해두고,

                    }
            }   
        }
    }
    
    cout << count;
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int res;

    //입력
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> groundCost[i][j];
        }
    }
    
    //연산
    res = plant(n);
    
    
    //출력
    cout << res << "\n";
    
    return 0;
}