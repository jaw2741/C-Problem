#include<iostream>  
#include<cstdio>  
using namespace std;  
const int N = 101;  
int m, n;  
int segs[N], ary[N][N];  
int table[N][N], bt[N][N], seln[N][N];  
int sol(int mm, int pick){  
  int maxv = -1;  
  int tak = -1;  
  int pre = -1;  
  if(mm == 0 || pick == 0){  
    return 0;}  
  if(bt[mm][pick] != -1){  
    return table[mm][pick];}  
  for(int i=0; i<=pick; ++i){  
    const int thisn = pick -i;  
    const int prevn = i;  
    int v = sol(mm-1, prevn);  
    int t = 0;  
    if(thisn>0){  
      if(thisn<=segs[mm-1]){  
        t = thisn;  
        v += ary[mm-1][t-1];  
      }else{  
        t = segs[mm-1];  
        v += ary[mm-1][t-1]; }}  
    if( v > maxv ){  
      maxv = v;  
      pre = prevn;  
      tak = t; }}  
  table[mm][pick] = maxv;  
  bt[mm][pick] = pre;  
  seln[mm][pick] = tak;  
  return maxv;}  
bool first_trace = true;  
void btrace(int mm, int nn){  
  if(mm <= 0)  
    return;  
  btrace( mm-1, bt[mm][nn] );  
  if(seln[mm][nn] > 0){  
    if(first_trace)  
      first_trace = false;  
    else  
      cout << ' ' ;  
    cout << '(' << mm << ',' << seln[mm][nn] << ')' ;}}  
int main(){  
  for(int i=0; i<N; ++i)  
    for(int j=0; j<N; ++j)  
      table[i][j] = bt[i][j] = -1;  
  cin >> m >> n ;  
  for(int i=0; i<m; ++i)  
    cin >> segs[i];  
  for(int i=0; i<m; ++i){  
    for(int j=0; j<segs[i]; ++j){  
      cin >> ary[i][j];  
      if(j>0)  
        ary[i][j] += ary[i][j-1];}}  
  cout << sol(m, n) << endl;  
  btrace(m, n);  
  cout << endl;}  