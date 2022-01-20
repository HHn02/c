#include <stdio.h>
#include <math.h>
bool is_prime[1000];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++){
        is_prime[i] = true;                    //初始化所有的数为素数
    }
    for(int i = 2; i <= sqrt(n); i++){         //从第一个素数2开始筛选
        if(is_prime[i]){                       //如果是素数
            for(int j = i*i; j <= n; j += i){  //则剔除掉它的倍数
                is_prime[j] = false;
            }
        }
    }
    for(int i = 2; i <= n; i++){
         if(is_prime[i]){
             printf("%d\n", i);
         }
    }
    return 0;
}
