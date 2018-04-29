#include <iostream>  
using namespace std;  
  
int main() {  
    // your code goes here  
    int n;  
    cin>>n;  
    int a[n][n];  
    for(int i=0 ; i<n ; i++)  
        for(int j=0 ; j<n ; j++)  
            cin >> a[i][j];  
            int D=0;  
            for(int i=0 ; i<n ; i++){  
                int t=0;  
                for(int j=0 ; j<n ; j++){  
                    if(i==j) t+=2 * a[i][j];  
                    else t += a[i][j];  
                }  
                if(t % 2) D++;  
            }  
            cout<< D <<endl;  
            if(D==0 || D==2 ) cout <<"Y"<<endl;  
            else cout<< "N" <<endl;  
    return 0;  
}  