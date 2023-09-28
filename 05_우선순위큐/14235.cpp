#include <iostream>
#include <queue>

using namespace std;

int main()
{
    
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    int n,a;
    priority_queue<int, vector<int>, less<int>> pq;
    //큰 것 부터 나오는 less<int>
    
    cin >> n;
    
    while(n--) {
        cin >> a;
        
        //아이들 만남
        if(a==0) {
            
            if (pq.empty()) { //줄 선물 없으면 -1 출력
				cout << "-1\n";
			} else{ //가장 가치 큰 선물이 맨 위로 정렬되어 있으니, top, pop!
			    cout << pq.top() << "\n";
				pq.pop();
			}
			
        } 
        
        //선물 충전
        else {
            for(int i=0; i<a; i++) {
                int gift=0;
                cin >> gift;
                pq.push(gift);
            }
        }
        
    }

    return 0;
}