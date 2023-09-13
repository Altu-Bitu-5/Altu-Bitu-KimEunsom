#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k; 
    
    cin >> n >> k;
    
    int res = 0;
    
    for(res ; ; res++){
        int count = 0;
        int temp = n;
        
        //반복문 돌면서 두개씩 묶음만들기!!
        while(temp!=0){
            if(temp%2) {
                count++;
                temp/=2;
            } else {
                temp/=2;
            }
        }
        if(count<=k) break;
        n++;
    }
    
    cout<<res;
}