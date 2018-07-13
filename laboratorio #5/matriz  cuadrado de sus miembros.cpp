#include <iostream>
#include <cmath>

using namespace std;

main(){
	 int matriz [3][3]={1,3,2,2,1,4,2,1,4};
     int acu[3][3];
     cout<<"\n   La matriz es:\n\n";
     for( int i=0;i<3;i++){
     	for( int j=0;j<3;j++){
     		cout<<"     "<<matriz [i][j];
		 }cout<<"\n\n"; 
	 }
	 
	 cout<<"\n   El cuadrado de la matriz  es:\n\n";
     for( int i=0;i<3;i++){
     	for( int j=0;j<3;j++){
     		acu[i][j]=pow(matriz[i][j],2);
     		cout<<"     "<<acu[i][j];
		 }cout<<"\n\n"; 
	 }
}
