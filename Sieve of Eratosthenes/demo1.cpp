//目标：得到自然数n以内的全部素数
//Goal: To pick prime number
//方法：把不大于根号n的所有素数的倍数剔除，剩下的就是素数。
//Way:  To get rid of all multiples of primes that are not greater than the square root of n, and all I'm going to get is prime.

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
 
const long long maxn = 10000007 + 10;
const long long maxp = 700000;
int vis[maxn];    // i是合数vis为1，i是素数，vis为0
long long prime[maxp];
 
void sieve(long long n){
    long long m = (long long)sqrt(n + 0.5);
    memset(vis, 0, sizeof(vis));
    vis[2] = 0;
    for (long long i = 3; i <= m; i += 2) {
        if(!vis[i])
            for (long long j = i * i; j <= n; j += i)
                vis[j] = 1;
        if(i * i > n)
            break;
    }
}
 
long long gen(long long n){
    sieve(n);
    long long c = 1;
    prime[0] = 2;
    for (long long i = 3; i <= n; i += 2)
        if(!vis[i])
            prime[c++] = i;
    return c;
}
 
int main()
{
    long long n, c;
    cout << "刷素数到n：";
    cin >> n;
    c = gen(n);
    for (long long i = 0; i < c; i++)
        printf("%lld", prime[i]);
    cout << endl << c;
    return 0;
}
