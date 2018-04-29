#include<iostream>  
#include<vector>  
  
using namespace std;  
  
int main()  
{  
    int p[4] = { 6, 28, 496, 8128 };  
  
    int m, n;  
    while (cin >> m >> n)  
    {  
        vector<int> temp;  
  
        for (int i = 0; i < 4; i++)  
        {  
            if (m <= p[i] && n >= p[i])  
                temp.push_back(p[i]);  
        }     
  
        if (temp.size() == 0)  
            cout << "null";  
        else  
        {  
            for (int i = 0; i < temp.size(); i++)  
            {  
                cout << temp[i];  
  
                if (i < temp.size() - 1)  
                    cout << " ";  
            }  
        }  
        cout << endl;  
    }  
    return 0;  
}  