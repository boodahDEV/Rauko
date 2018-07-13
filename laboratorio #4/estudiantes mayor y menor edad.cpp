#include <iostream>
using namespace std;
struct est{
	char nom[20];
	int edad;
};
main(){
	int n,Edad=0,e=0,j=0,k=0;
	
	
	cout<<"\t\t\t\tCurso de progrmacion II \n\n"<<endl;
	cout<<"cuantos estudiantes hay en el curso ?"<<endl;
	cin>>n;
	struct est E[n];
	for(int i=0;i<n;i++){
	
		cout<<"Cual es el nombre del estudiante:\t"; cin>>E[i].nom;
		cout<<"Cual es su edad:\t";  cin>>E[i].edad;
		if (E[i].edad>Edad){
			Edad=E[i].edad;
			j==i;
		}
		  e=Edad;
		  k=0;
			if (E[i].edad<e){
			e=E[i].edad;
			k==i;
		}
			
	
	}
		for (int i=0;i<n;i++){
		if (j==i){
		cout<<"\n\n";system("cls");system("color c");
		cout<<"La edad mayor es:\t"<<Edad<<endl;}
		if(k==i)
		cout<<"La edad menor es:\t"<<e<<endl;	
	}
	
}//fin main

