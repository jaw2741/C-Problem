#include <iostream>    
#include <algorithm>    
    
using namespace std;    
    
int main() {    
    int n;    
    while(cin >> n) {    
        int two = 0;    
        int five = 0;    
            
        int temp = n;    
        while(temp) {    
            two += temp / 2;    
            temp /= 2;    
        }    
            
        temp = n;    
        while(temp) {    
            five += temp / 5;    
            temp /= 5;    
        }    
        cout << min(two, five) << endl;    
    }    
    return 0;    
}  