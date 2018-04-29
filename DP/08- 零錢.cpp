#include<iostream>  
  
using namespace std;  
  
int main()  
{  
    const long long coin[4] = {  
        1, 5, 10, 50  
    };   
  
    long long dp[15001] = { 1 };  
    for (int i = 0; i < 4; i++)  
    for (int j = coin[i]; j < 15001; j++)  
        dp[j] += dp[j - coin[i]];  
  
    int n;  
    while (cin >> n)  
    cout << dp[n] << endl;  
    return 0;  
}  