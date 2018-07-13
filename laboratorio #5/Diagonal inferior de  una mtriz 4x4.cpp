#include <iostream>
using namespace std;
main(){
  int A[4][4];               

system ("cls");
  cout<<"\t\t\t\tEste programa que imprime la diagonal inferior\n\n"<<endl;
for(int m=0;m<4;m++)
   {
for(int n=0;n<4;n++)
{
  cout<<"Da un valor para A["<<m<<"]["<<n<<"]";
  cin>>A[m][n];
}
   }
    cout<<"\n\n";
    system("cls");
   cout<<"LA MATRIZ A ES:\n";
        	for (int m = 0;m<4;m++){
        		
	              for(int n = 0;n<4;n++){
	                    cout<<"  "<<A[m][n];
	                    
                	 }
	            cout<<"\n";
	            
	            
            }
            cout<<"\n\n\n";

cout<<"LA DIAGONAL INFERIOR DE LA MATRIZ A ES:\n";
for(int m=1;m<4;m++) {
for(int n=0;n<m;n++){
 cout<<"  "<<A[m][n];
      } 
 cout<<"\n";
}
 cout<<"\n\n\n";
system("pause");
}//fin main
