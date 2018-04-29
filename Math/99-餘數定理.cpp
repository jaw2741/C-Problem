#include<iostream>  
#include<vector>  
#include<utility>  
using namespace std;  
  
int main(){  
  vector<pair<int,int> > in;  
  int a, b;  
  while(cin >> a >> b)  
    in.push_back(make_pair(a, b));  
  unsigned long long t = 1;  
  for(int i = 0; i<in.size(); ++i)  
    t *= in[i].first;  
  for(int j=0; j<t; j++){  
    bool ok = true;  
    for(int i=0; i<in.size() && ok ; ++i)  
      if(j%in[i].first != in[i].second)  
        ok = false;  
    if(ok){  
      cout << j << endl;  
      return 0;  
    }  
  }  
}  