#include <iostream>        
using namespace std;        
        
int main() {        
      
    int N, M;        
    cin >> N >> M;        
    int food[N][N];        
    int x, y, a, b;        
    int s = 0;        
    for(int i = 0;i < N;i++)        
    {        
        for(int j = 0;j < N;j++)        
        {        
            cin >> food [i][j];        
        }        
    }        
    for(int i = 0;i < M;i++)        
    {        
        cin >> x >> y >> a >> b ;        
        for(int j = x-1 ;j <= a-1;j++)        
        {        
            for(int k = y-1; k <= b-1;k++)        
            {        
                s = s + food[j][k];        
            }        
        }        
        cout << s << endl;       
        s = 0;  
    }        
    return 0;        
}  