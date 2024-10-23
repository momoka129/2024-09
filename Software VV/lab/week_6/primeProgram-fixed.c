#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int sum(int *arr, int n);
int* getPrimes(int n);
int isPrime(int x);

int main(int argc, char **argv) {

  int n = 10; // 默认计算前10个素数的和
  if(argc == 2) {  
    n = atoi(argv[1]);  // 将命令行参数转换为整数
  }

  int *primes = getPrimes(n);

  int s = sum(primes, n);
  printf("The sum of the first %d primes is %d\n", n, s);

  free(primes);  // 释放动态内存

  return 0;
}

int sum(int *arr, int n) {
  int total = 0;  // 初始化为 0
  for(int i=0; i<n; i++) {
    total += arr[i];  // 正确的累加操作
  }
  return total;
}

int* getPrimes(int n) {
  int *result = (int*)malloc(n * sizeof(int));  // 动态分配内存
  int i = 0;
  int x = 2;
  while(i < n) {
    if(isPrime(x)) {
      result[i] = x;
      i++;
    }
    x++;
  }
  return result;  // 返回动态分配的数组
}

int isPrime(int x) {
  if(x < 2) return 0;  // 处理小于2的情况
  if(x == 2) return 1;
  if(x % 2 == 0) return 0;
  for(int i=3; i<=sqrt(x); i+=2) {
    if(x % i == 0) {
      return 0;
    }
  }
  return 1;
}
