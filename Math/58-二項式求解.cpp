#include <stdio.h>  
int main() {  
     
    int a, b, c,i;      
           scanf("%d,%d,%d", &a, &b, &c);  
    for(i=0;i<=c/a;i++){  
            if((c-a*i)%b==0)  
             printf("%d,%d\n", i ,(c-a*i)/b );  
        }  
     return 0;  
} 