#include <iostream>
using namespace std;

int map[200][200];
int white = 0;
int blue = 0;

bool IsT(int r, int c, int size){//끝까지 다 쪼개졌는가?
    int first = map[r][c];
    
    for(int i = r; i < r+size; i++){
        for(int j = c; j<c+size; j++){
            if(map[i][j] != first) return false;
        }
    }
    return true;
}

void Isp(int r, int c, int size){
    if(IsT(r,c,size)){
        if(map[r][c] == 0) white++;
        else blue++;
        return;
    }
    
    int half = size/2;
    Isp(r,c,half); //1사분면
    Isp(r,c+half,half); //2사분면
    Isp(r+half,c,half); //3사분면
    Isp(r+half,c+half,half); //4사분면
}

int main(){
    int n;
    cin >> n;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) cin >> map[i][j];
    }
    
    Isp(0, 0, n);
    cout << white << "\n" << blue << "\n";

}
