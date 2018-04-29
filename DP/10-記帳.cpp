#include<iostream>  
#include<map>  
#include<string>  
#include<vector>  
  
using namespace std;  
  
int main()  
{  
    int n;  
    while (cin >> n)  
    {  
        //input  
        vector<string> name;  
        map<string, int> p;  
        for (int i = 0; i < n; i++)  
        {  
            string t; cin >> t;  
            name.push_back(t);  
            p[t] = 0;  
        }  
  
        string t;  
        while (cin >> t && t != "0")  
        {  
            int out; cin >> out;  
            p[t] -= out;  
  
            int m; cin >> m;  
            for (int i = 0; i < m; i++)  
            {  
                cin >> t;  
                p[t] += out / m;  
            }  
        }  
  
        //output  
        for (int i = 0; i < n; i++)  
        cout << name[i] << " " << p[name[i]] << endl;  
    }  
    return 0;  
}  