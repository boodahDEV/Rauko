#include <iostream>
#include <string.h>
using namespace std;
struct generales{
	char nom[15];
	int rango;
	char cip[10];
	int Anio;
	float peso;
	struct guarda;
}gen;
struct guarda{
	char ran[15];
}guar;
main(){
int n,cont,ge,gj,fc,a=0,b=0,c=0,d=0;float ap=0,p=0;
	cout<<"\t\t\t\tDireccion de Investigacion Judicial\n\n"<<endl;
	cout<<"Cuantos policias hay en el departamento?"<<endl;
	cin>>n;	
	struct generales G[n];
	struct guarda E[n]; 
	for (int i=0;i<n;i++){
			system("cls");
		cout<<"Cual es el nombre?:"<<endl;
		cin>>G[i].nom;
		cout<<"Cual es la cedula?:"<<endl;
		cin>>G[i].cip;
		cout <<"  "<<endl;
	     system("cls");
		cout<<"\t1 -> sargento"<<endl;
		cout<<"\t2 -> cabo"<<endl;
		cout<<"\t3 -> comicionado"<<endl;
		cout<<"\t4 -> capitan\n"<<endl;
		cout<<"Cual es el rango:"<<endl;	cin>>G[i].rango;
	
		cout<<"Cuantos anios lleva de servicio?:"<<endl;
		cin>>G[i].Anio; ap=ap+G[i].Anio;
		cout<<"Cual es su peso:"<<endl;
		cin>>G[i].peso; 
		
}   for (int i=0;i<n;i++){

    switch (G[i].rango){
	  	case 1: {
			  a=a+1;  
	  		
			 // strcpy(E[i].e, p1);
	  		
			break;
		  }
		case 2:{ //////////////////////////////////////////////////////////////
	  			
			  b=b+1;  
	  		
			//  strcpy(E[i].e, p4);
			break;
		  }
	  case 3: {
	  	c=c+1;
	  	
		 // strcpy(E[i].e, p2);
			break;
		  }
		  case 4: {
		  	d=d+1;
	  
	  	//	strcpy(E[i].e, p3);
			break;
		  }
       } 
}
     p=ap/n;
        for (int i=0;i<n;i++){
        	if (G[i].peso<=120){
        		ge=+1;
			}else 
			  if (G[i].peso>120 && G[i].peso>=150){
			  	gj=+1;
			  }
        	else 
        	   fc=+1;
        	   
		}
		system("cls");
		system("color a");
	cout<<"\nLa cantidad por rango es de:"<<endl;
        cout<<"-> sargento \t"<<a<<endl;
		cout<<"-> cabo \t"<<b<<endl;
		cout<<"-> comicionado \t"<<c<<endl;
		cout<<"-> capitan \t"<<d<<endl;
    cout <<"  "<<endl;
    cout <<"  "<<endl;
    cout <<"CANTIDAD POR GRUPO"<<endl;
    
    cout<<"->Grupo Elite \t"<<ge<<endl;
    cout<<"\t->Fuera de combate \t"<<gj<<endl;
    cout<<"\t\t->Fuera de combate \t"<<fc<<endl;
	
	
	
	cout<<"\n\n\n\nEl anio promedio de servicios de los policias es de :"<<p<<endl;
	
	
	
	
}
