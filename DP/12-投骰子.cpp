#include<iostream>  
#include<cmath>  
using namespace std;  
  
long long gcd(long long x, long long y)  
{  
    while (x %= y)  
        swap(x, y);  
    return y;  
}  
  
int main()  
{  
    long long dp[21][130];  
    for (int i = 0; i < 21; i++)  
    for (int j = 0; j < 130; j++)  
        dp[i][j] = 0;  
    for (int i = 1; i < 7; i++)  
        dp[1][i] = 1;  
  
    for (int i = 2; i < 21; i++)  
    for (int j = i; j < i * 6 + 1; j++)  
    for (int k = j - 6; k < j; k++)  
        dp[i][j] += dp[i - 1][k];  
    int n, x;  
    while (cin >> n >> x)  
    {  
        long long p = 0;  
        for (int i = x; i < n * 6 + 1; i++)  
            p += dp[n][i];  
  
        long long t = pow(6, (double)n);  
        long long g = gcd(p, t);  
          
        if (n * 6 < x)  
            cout << 0 << endl;  
        else  
        {  
            cout << p / g << " / ";  
            cout << t / g << endl;  
        }     
    }  
    return 0;  
}  