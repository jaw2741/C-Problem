#include<algorithm>          
#include <math.h>         
#include<iostream>           
#include<cstring>           
#include<fstream>           
#include<sstream>           
#include<vector>           
#include<string>           
#include<cstdio>           
#include<bitset>           
#include<queue>           
#include<stack>           
#include<cmath>           
#include<map>           
#include<set>         
          
using namespace std;           
           
struct Point           
{           
    double x, y, z;           
    Point(double x=0, double y=0, double z=0) : x(x), y(y),z(z){}           
};           
typedef Point Vector;           
           
Vector operator + (Vector a, Vector b) { return Vector(a.x+b.x, a.y+b.y, a.z+b.z); };           
Vector operator - (Vector a, Vector b) { return Vector(a.x-b.x, a.y-b.y, a.z-b.z); };           
Vector operator * (Vector a, double p) { return Vector(a.x*p, a.y*p, a.z*p); }           
Vector operator / (Vector a, double p) { return Vector(a.x/p, a.y/p, a.z/p); }           
           
double Dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y + a.z*b.z; }           
double Length(Vector a) { return sqrt(Dot(a, a)); }           
Vector Cross(Point a, Point b)           
{           
    return Vector(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);           
}           
           
Point a1, b1, a2, b2;           
int main()           
{           
        scanf("%lf %lf %lf", &a1.x, &a1.y, &a1.z);           
        scanf("%lf %lf %lf", &b1.x, &b1.y, &b1.z);           
        scanf("%lf %lf %lf", &a2.x, &a2.y, &a2.z);           
        scanf("%lf %lf %lf", &b2.x, &b2.y, &b2.z);           
        Vector v1 = (a1-b1), v2 = (a2-b2);           
        Vector N = Cross(v1, v2);           
        Vector ab = (a1-a2);           
        double ans = Dot(N, ab) / Length(N);           
        Point p1 = a1, p2 = a2;           
        Vector d1 = b1-a1, d2 = b2-a2;           
        Point ans1, ans2;           
        double t1, t2;           
        t1 = Dot((Cross(p2-p1, d2)), Cross(d1, d2));           
        t2 = Dot((Cross(p2-p1, d1)), Cross(d1, d2));           
        double dd = Length((Cross(d1, d2)));           
        t1 /= dd*dd;           
        t2 /= dd*dd;           
        ans1 = (a1 + (b1-a1)*t1);           
        ans2 = (a2 + (b2-a2)*t2);           
        double F;         
        ans = ans * 100000;   
        ans += 0.5;      
        F = floor(ans);  
        F = ans / 100000;              
        printf("%.0f\n", abs(F));           
               
    return 0;           
}  