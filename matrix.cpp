#include "Matrix.h" 
#include <stdafx>
#include <iostream> 
#include <fstream> 
int main() 
{ 


Matrix a(3, 3); 
Matrix b(3, 3); 
cout « a; 
cout « b; 

Matrix c(3, 3); 
c = a * b; 
cout « c; 
Matrix f(3, 3); 
f = a + b; 
cout « f; 

a[1][1] = 2; 
cout « "\n"; 
cout « a[1][1]; 

int n = a.columns(); 
cout « "\n"; 
cout « n; 
int m = a.lines(); 
cout « "\n"; 
cout « m; 

system("pause"); 
return 0; 
}
