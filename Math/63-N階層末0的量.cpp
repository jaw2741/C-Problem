#include<iostream>   
using namespace std;   
   
int main(){   
  int n;   
  int a = 0, b = 0;   
  cin >> n;   
  for(int i=2; i<=n; i++){   
    int v = i;   
    while(v%2==0){   
      a++;   
      v/=2;   
    }   
    while(v%5==0){   
      b++;   
      v/=5;   
    }   
  }   
  cout << (a>b?b:a) << endl;   
}  