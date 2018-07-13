#include <iostream>
#define N 20

using namespace std;

struct estudiantes{
	char CIP[N];
	char nombre[N];
	char apellido[N];
	float cal;
	int Id_ca;
}est[N];

main(){

	int n=0,ac=0,x=0;
	float Pcal=0,Mcal=0,Scal=0;
	cout<<"Ingrese el numero de estudiantes:";
	cin>>n;
	for(x=0;x<n;x++){
		system("cls");
		cout<<"\n\n*DATOS PERSONALES*"<<endl;
		cout<<"\n1)Tu cedula es:";
	    cin>>est[x].CIP;
	    cout<<"\n2)Tu nombre es:";
	    cin>>est[x].nombre;
        cout<<"\n3)Tu apellido es:";
	    cin>>est[x].apellido;
	    cout<<"\n4)Calificacion:";
	    cin>>est[x].cal;
	    cout<<"\n5)Tu ID de la carrera es:";
	    cin>>est[x].Id_ca;
	    
	    Scal=Scal+est[x].cal;
	    
	    if(est[x].cal>Mcal){
	    	Mcal=est[x].cal;
	    	ac=x;	
		}
	}
	Pcal=Scal/n;
	system("cls");system("color a");
	cout<<"\n\n  CIP"<<"        NOMBRE"<<"    APELLIDO"<<"    CALIFICION"<<"    ID\n";
	cout<<"_______________________________________________________________________________\n";
	for(x=0;x<n;x++){
		cout<<"\n "<<est[x].CIP<<"    "<<est[x].nombre<<"    "<<est[x].apellido<<"       "<<est[x].cal<<"        "<<est[x].Id_ca<<endl;
	}
	cout<<"\n\nLa mayor calificacion fue de:";
	for(x=0;x<n;x++){
		if(x==ac){
		cout<<"\t "<<est[x].nombre<<"  con calificacion de:\t "<<Mcal<<endl;
	  }
	}
	cout<<"\nPromedio total del salon es de:"<<Pcal<<endl;
}
