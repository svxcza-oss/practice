#include <stdio.h>
#include <string.h>
#define ll long long
#define MOD 1000000007

void mul(ll (*matrix_A)[2],ll (*matrix_B)[2],ll (*matrix_res)[2]){
    ll m_res[2][2] = {0,};//임시결과 저장
    
    for(int i = 0; i<2; i++){//행
        for(int j = 0; j<2; j++){//열
            for(int k = 0; k<2; k++){
                //i,j는 좌표같은 거고 k는 안쪽 원소 위치
                m_res[i][j] += (matrix_A[i][k] * matrix_B[k][j]) % MOD;
                m_res[i][j] %= MOD; //계속 MOD로 나눠주기(넘침 방지)
            }
        }
    }
    memcpy(matrix_res,m_res,sizeof(m_res));//중간 계산값(m_res)을 결과배열(matrix_res)에 저장. 카피카피
}

void power(ll (*matrix_A)[2], ll n, ll (*matrix_res)[2]){
    if(n == 1){ //종료조건. 계산완료되는 시점
        memcpy(matrix_res, matrix_A,sizeof(ll)*2*2);
        return;
    }
    
    ll H[2][2];
    power(matrix_A, n/2, H); //재귀로 A^n * A^n 연산의 A^n하나만 계산해주고
    mul(H,H,matrix_res);//반쪽 계산한 값을 다시 mul에 넣어서
    
    if(n%2){ //n%2 == 1 n이 홀수일때
        ll H2[2][2];
        memcpy(H2, matrix_res, sizeof(H2)); //만약 n==5, A^1 * A^4에서 A^1만 또 계산해주기
        mul(H2,matrix_A,matrix_res);
    }
}



int main(void){
    ll n; ll matrix_A [2][2] = {1,1,1,0};
    ll matrix_res [2][2] = {0,0,0,0};
    scanf("%lld", &n);
    
    power(matrix_A, n, matrix_res);
    printf("%lld\n", matrix_res[0][1]); //계산 완료후 Fn이 있는 곳만 출력.
    return 0;
}
