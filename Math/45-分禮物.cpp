#include<iostream>  
#include<vector>  
#include<string>  
#include<utility>  
#include<sstream>  
using namespace std;  
int n ;   
vector<pair<string,string> > in;  
vector<char> marked;  
vector<int> permu;  
ostringstream sout;  
  
unsigned long long ocnt;  
void out(){  
  for(int i=0; i<permu.size(); ++i)  
    sout << in[i].first << ' ' << in[permu[i]].second << (i<permu.size()-1?',':'\n') ;   
  ++ ocnt ;  
  
}  
  
void run(int d){  
  if(d==n){  
    out();  
    return;  
  }  
  for(int i=0; i<n; ++i){  
    if(i!=d && !marked[i]){  
      marked[i] = 1;  
      permu.push_back(i);  
      run(d+1);  
      permu.pop_back();  
      marked[i] = 0;  
    }  
  }  
}  
int main(){  
  string s, t ;   
  cin >> n ;   
  marked = vector<char>(n, 0);  
  for(int i=0; i<n; ++i){  
    cin >> s >> t  ;   
    in.push_back(make_pair(s,t));  
  }  
  run(0);  
  cout << ocnt << endl;  
  cout << sout.str() ;  
}  