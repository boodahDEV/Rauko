#include <iostream>
#include <string.h>
using namespace std;
struct generales{
	char nom[15];
	int esp;
	float sal;
	char cip[10];
	int fechaIn;
	int jub;
	struct especi;
};
struct especi{
     char e[15];
	char no[15];
	
};

main(){
	int n,e=0,z=0,z1=0,cont=0,v1[20]={0},v2[20]={0},v3[20]={0},v4[20]={0},a=0,b=0,c=0,d=0;float p=0,cs=0;
	char p1[10]="cirujano";
	char p2[10]="camillero";
	char p3[15]="odontologo";
	char p4[10]="pediatra";
	cout<<"\t\t\t\tPoliclinica Santa Barraza\n\n"<<endl;
	cout<<"cuantos medicos hay en la policlinica ?"<<endl;
	cin>>n;
	 struct generales G[n];   
	 struct especi E[n];
	
	
	for (int i=0;i<n;i++){
		system("cls");
		cout<<"Cual es el nombre?:"<<endl;
		cin>>G[i].nom;
		cout<<"Cual es la cedula?:"<<endl;
		cin>>G[i].cip;
	     cout <<"  "<<endl;
	     system("cls");
		cout<<"\t1 -> cirujano"<<endl;
		cout<<"\t2 -> pediatra"<<endl;
		cout<<"\t3 -> camillero"<<endl;
		cout<<"\t4 -> odontologo\n"<<endl;
		cout<<"Cual es la especialidad?:";	cin>>G[i].esp;
	
		cout<<"Cuantos anios lleva de servicio?:"<<endl;
		cin>>G[i].fechaIn;
		cout<<"Cual es su salario?:"<<endl;
		cin>>G[i].sal; cs=cs+G[i].sal;
		cout<<"Es jubilado?  1/0 :"<<endl;
		cin>>G[i].jub;
	}
	system("cls");
	for (int i=0;i<n;i++){
			if(G[i].esp== G[i].esp )
	//	e=+1;  E[i].espc=G[i].esp;
	  //  v[e]=+1;
	  switch (G[i].esp){
	  	case 1: {
	  		//v1[i]++;
			  b=b+1;  
	  		
			  strcpy(E[i].e, p1);
	  		
			break;
		  }
		case 2:{ //////////////////////////////////////////////////////////////
	  			//v2[i-1]++;
			  a=a+1;  
	  		
			  strcpy(E[i].e, p4);
			break;
		  }
	  case 3: {
	  	c=c+1;
	  		//e=+1;//E[i].espc=G[i].esp;
	  	//	v3[i]=e;
		  strcpy(E[i].e, p2);
			break;
		  }
		  case 4: {
		  	d=d+1;
	  	//	e=+1;//E[i].espc=G[i].esp;
	  		//v4[i]=e;
	  		strcpy(E[i].e, p3);
			break;
		  }
       } 
	}	 
	for (int i=0;i<n;i++){
		if(G[i].fechaIn>25 && G[i].jub !=0){
			z=1; z1++;
		}else {
		
		if(G[i].fechaIn == 25 && (G[i].jub!=1) ){
			cont=+1; strcpy(E[i].no,G[i].nom);
		}
	}
			}
	p=cs/n;
	cout<<"\nLas especialidades  son"<<endl;

      cout<<"cirujano ->"<<a<<endl;
      cout<<"pediatra ->"<<b<<endl;
       cout<<"camillero ->"<<c<<endl;
       cout<<"odontologo ->"<<d<<endl;
 
	if(z!=0){
		cout<<"\nya estan jubilados pero aun estan en el sistema"<<"->  "<<z1<<endl;
	}

	
	cout <<"\nLos proximos jubilados para el otro anio son"<<endl;
	for (int i=0;i<n;i++){
		cout <<" "<<E[i].no<<endl;
	 }
	cout <<" \n\n\n\n\tEl salario promedio de los medicos son:"<<p<<endl;
 }//fin main
	
