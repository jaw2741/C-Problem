#include<iostream>  
#include<queue>  
  
using namespace std;  
  
int main()  
{  
    int n;  
  
    while (cin >> n)  
    {  
        int matric[10][10];  
        for (int i = 0; i < n; i++)  
        for (int j = 0; j < n; j++)  
            cin >> matric[i][j];  
  
        int temp[10][10] = { 0 };  
  
        for (int i = 0; i < n; i++)  
            temp[0][i] = matric[0][i];  
  
        for (int i = 1; i < n; i++)  
        for (int j = 1; j < n; j++)  
        {  
            temp[i][j] = temp[i - 1][j];  
  
            if (matric[i][j] == 1)  
            {  
                if (temp[i][j] > temp[i - 1][i] + 1   
                    || temp[i][j] == 0)  
                    temp[i][j] = temp[i - 1][i] + 1;  
            }         
        }  
  
        for (int i = 0; i < n; i++)  
        {     
            cout << temp[n - 1][i] + 1 << endl;  
        }  
    }  
    return 0;  
}  