#include <iostream>
#include <vector>
#define ll long long
using namespace std;

typedef vector<vector<ll>> matrix_t;

void mul(const matrix_t& a, const matrix_t& b, matrix_t& res, int n){
    matrix_t tmp(n,vector<ll>(n,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++) tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % 1000;
        }
    }
    res = tmp;
}

void power(matrix_t& a, ll m, int n){
    matrix_t res(n, vector<ll>(n,0));
    for(int i = 0; i<n; i++) res[i][i] = 1;
    
    matrix_t base = a;
    while(m > 0){
        if (m % 2) mul(res, base,res,n);
        mul(base,base,base,n);
        m /= 2;
    }
    a = res;
}

int main(void){
    int n; ll m;
    cin >> n >> m;
    
    matrix_t matrix(n, vector<ll>(n,0));
    
    for(int i=0; i<n; i++){
        for(int j =0; j<n; j++){
            cin >> matrix[i][j];
            matrix[i][j] %= 1000;
        }
    }
    
   power(matrix,m,n);
    
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) cout << matrix[i][j] << " ";
        cout << "\n";
    }
    
    return 0;
    
}
