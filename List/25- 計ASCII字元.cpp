#include <iostream>        
#include <vector>        
#include <algorithm>        
#include <string>        
        
using namespace std;        
int main() {        
    string word1;        
    vector <char> number1;        
    vector <int> number;        
    getline(cin, word1);            
    sort(word1.begin(),word1.end());        
    reverse(word1.begin(), word1.end());                
    for (int i = 0; i < word1.size(); i++) {        
        if (word1[i] != word1[i + 1]) {        
            number1.push_back(word1[i]);        
        }        
    }        
    int j = 1;        
    for (int i = 0; i < word1.size(); i++) {        
        if (word1[i] == word1[i + 1]) {        
            j++;        
        }        
        else {        
            number.push_back(j);        
            j = 1;        
        }        
    }        
    for (int i = 0; i < number1.size(); i++) {        
        cout << (int)number1[i] << " ";        
        cout << number[i] << endl;        
    }        
    return 0;        
}  