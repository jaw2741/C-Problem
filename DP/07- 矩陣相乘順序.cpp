#include<iostream>  
#include<climits>  
 
#define MAX 101  
  
using namespace std;  
  
int dp[MAX][MAX];  
int table[MAX][MAX];  
  
void print(int x, int y)  
{  
    if (x == y)  
        cout << "M" << x + 1;  
    else  
    {  
        int k = table[x][y] - 1;  
        cout << "(";  
        print(x, k);  
        print(k + 1, y);  
        cout << ")";  
    }  
}  
  
int main()  
{  
    int n;  
    while (cin >> n)  
    {  
        //input  
        int m[MAX][2];  
        for (int i = 0; i < n; i++)  
        cin >> m[i][0] >> m[i][1];  
  
        int p[MAX];  
        for (int i = 0; i < n; i++)  
            p[i] = m[i][0];  
        p[n] = m[n - 1][1];  
        p[n + 1] = m[0][0];  
  
  
        //initialize table  
        for (int i = 0; i < n; i++)  
        {  
            dp[i][i] = 0;  
            table[i][i] = 0;  
        }  
  
        for (int i = 1; i <= n; i++)  
        for (int j = 0; j <= n - i; j++)  
        {  
            //current i i + j  
            int min = INT_MAX;  
            for (int k = j; k < i + j; k++)  
            {  
                int temp = 0;  
                temp += dp[j][k];  
                temp += dp[k + 1][i + j];  
                temp += p[j] * p[k + 1] * p[i + j + 1];  
  
                if (min > temp)  
                {  
                    min = temp;  
                    table[j][i + j] = k + 1;  
                }  
            }  
            dp[j][i + j] = min;  
        }  
  
        //output  
        print(0, n - 1);  
        cout << endl;  
        cout << dp[0][n - 1] << endl;  
    }  
    return 0;  
}  