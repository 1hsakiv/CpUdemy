// https://cp-algorithms.com/algebra/primality_tests.html#fermat-primality-test

// Fermat's little theorem states, that for a prime number  
// $p$  and a coprime integer  
// $a$  the following equation holds:
// a^p is congruent to a mod p
// where a and p are co prime and p is prime
// ****fermat little theorem does not generally holds for composite number
// Application in finding (a/b)%m = ((a%m) * ((b^(m-2)) % m) )%m
#include <bits/stdc++.h>
using namespace std;

#define int long long
int m = 1e9+7;
const int N = 1e7;
int fact[N+1];

int binpow(int a, int b)
{
    a %= m;
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}

int add(int a, int b)
{
    return (a + b) % m;
}

int sub(int a, int b)
{
    return ((a - b) % m + m) % m;
}

int mul(int a, int b)
{
    return (a * b) % m;
}

// this is fermat Little theorem function
int inv(int a){
    return binpow(a , m-2);
}

int divide(int a, int b)
{
    return mul(a, inv(b));
}

void calculate_factorial(){
    fact[0] = 1;
    for(int i=1;i<=N; i++){
        fact[i] = mul(fact[i-1] , i);
    }
}


int nCr(int n , int r){
    return mul(mul(fact[n] , inv(fact[r])) , inv(fact[n-r]) );
}

int nPr(int n, int r){
    return mul(nCr(n,r) , fact[r]);
}

int32_t main()
{
    // find (a/b) % m
    int a = 10, b = 2;
    // int a, b;
    // cin >> a >> b;
    calculate_factorial();
    cout << nPr(a,b) << endl;
    return 0;
}