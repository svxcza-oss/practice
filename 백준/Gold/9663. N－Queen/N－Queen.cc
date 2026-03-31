#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> matrix(16, vector<int>(16,0));
int res = 0;
int n;

bool IsP(int x, int y){
    for(int i = 0; i<x; i++) if(matrix[i][y]) return false;
    
    for(int i = 0; i<y; i++) if(matrix[x][i]) return false;
    
    int i = x; int j = y;
    while(i>=0 && j>=0){
        if(matrix[i--][j--]) return false;
    }
    
    i = x; j = y;
    while(i>=0 && j<n){
        if(matrix[i--][j++]) return false;
    }
    return true;
}

void Rec(int y){
    if(y == n){ //한줄씩, 끝까지 내려갔으면 종료이고
        res++;
        return;
    }
    
    for(int i = 0; i<n; i++){
        /*if(IsP(i,y)){ 이렇게 하면 열만 고정이니까 세로형태로 탐색을 하게 되는데 위의 종료조건과는 맞지않음 그냥 들어가자마자 끝
            matrix[i][y] = 1;
            Rec(y+1);
            matrix[i][y] = 0;
        }*/
        if(IsP(y,i)){ //애는 행고정이니까 가로줄로 탐색
            matrix[y][i] = 1;
            Rec(y+1);
            matrix[y][i] = 0;
        }
    }
}


int main(){
    cin >> n;

    if(n == 1) {cout << 1; return 0;}
    if(n<4) {cout << 0; return 0;}
    
    Rec(0);
    cout << res << endl;
    return 0;
}
