#include <iostream>  
#include <string>  
#include <stack>  
#include <vector>  
#include <sstream>  
  
using namespace std;  
  
int main() {  
    string buffer;  
    while (getline(cin, buffer)) {  
        stack<int> s;  
        vector<string> in;  
  
        istringstream ss(buffer);  
        while (getline(ss, buffer, ' ')) {  
            in.push_back(buffer);  
        }  
  
        for (int i = 0; i < in.size(); i++) {  
            if (isdigit(in[i][0])) {  
                s.push(atoi(in[i].c_str()));  
            }  
            else {  
                int x = s.top();  
                s.pop();  
                int y = s.top();  
                s.pop();  
  
                switch (in[i][0]) {  
                    case '+':  
                        s.push(y + x);  
                        break;  
                    case '-':  
                        s.push(y - x);  
                        break;  
                    case '*':  
                        s.push(y * x);  
                        break;  
                    case '/':  
                        s.push(y / x);  
                        break;  
                    case '%':  
                        s.push(y % x);  
                        break;  
                }  
            }  
        }  
  
        cout << s.top() << endl;  
    }  
    return 0;  
}  