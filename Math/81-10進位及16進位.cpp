#include<iostream>  
#include<sstream>  
#include<string>  
using namespace std;  
   
int main()  
{  
    string s;  
    while(cin >> s)  
    {  
        int temp;  
        if(s[0] == '0' && s[1] == 'x')  
        {  
            istringstream(s) >> hex >> temp;  
            cout << dec << temp << endl;    
        }  
        else  
        {  
            istringstream(s) >> dec >> temp;  
            cout << "0x";  
            cout << hex << uppercase << temp << endl;  
        }  
    }  
    return 0;  
}  