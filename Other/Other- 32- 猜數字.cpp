#include <stdio.h>    
  
int main() {    
    int a, b, c;  
    int n;    
    scanf("%d",&n);   
    for(a=0;a<10;a++)    
        for(b=0;b<10;b++)   
            for(c=0;c<10;c++)   
                if(n == ((a+b+c)*222-(a*100+b*10+c)))    
                    
                    printf("%d%d%d\n",a,b,c);    
                    
                
          
          
    return 0;      
}  