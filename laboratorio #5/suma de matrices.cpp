#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
void gotoxy(int x,int y){ HANDLE hcon;
hcon = GetStdHandle(STD_OUTPUT_HANDLE); 
COORD dwPos; dwPos.X = x; dwPos.Y= y; 
SetConsoleCursorPosition(hcon,dwPos); }
main()
{
  int m,n,A[3][3],B[3][3],C[3][3];                 

  system ("cls");
  cout<<"\t\t\t\tEste programa Suma dos matrices de 3x3\n\n";
  srand(time(NULL));
  INICIO:
for(m=0;m<3;m++){
    for(n=0;n<3;n++){
      A[m][n]=1+rand()%(10-1);
      }
   }
   system("pause");
   cout<<"\n\n";
   cout<<"LA MATRIZ A ES:\n";
        	for (int m = 0;m<3;m++){
	              for(int n = 0;n<3;n++){
	                    cout<<"\t"<<A[m][n];
	                    
                	 }
	         cout<<"\n"; 
            }
     for(m=0;m<3;m++){
      for(n=0;n<3;n++){
          B[m][n]=1+rand()%(10-1);
                }
              }
   
    cout<<"\n";
   printf("LA MATRIZ  B ES:\n");
        	for (int m = 0;m<3;m++){
	              for(int n= 0;n<3;n++){
	                    cout<<"\t"<<B[m][n];
	                    
                	 }
	              cout<<"\n";
	            
	            
            }
              cout<<"\n";
  cout<<"La suma de ambas matrices Impresas en la matriz C es:\n\n"; 
  for(m=0;m<3;m++)
   {
       for(n=0;n<3;n++)
         {
             C[m][n]=A[m][n]+B[m][n];
                 cout<<"\t"<<C[m][n];
            }

  cout<<"\n";
   }
	
   goto INICIO;
}//fin main
