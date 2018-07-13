#include <iostream>
#define t 100

using namespace std;

struct generales {
	char cedu[t];
	char nomb[t];
	int edad;
	float peso;
	char sang[t];
	float esta;
	char estad_c[t];
	char fech_n[t];
	char gene[t];
};

struct generales g;

main(){
	cout<<"*DATOS PERSONALES*"<<endl;
	cout<<"\n1)Tu cedula es:" ;
	cin>>g.cedu;
	cout<<"\n2)Tu nombre es:";
	cin>>g.nomb;
    cout<<"\n3)Tu edad es:";
	cin>>g.edad;
	cout<<"\n4)Tu peso es:";
	cin>>g.peso;
	cout<<"\n5)Tu tipo de sangre es:";
	cin>>g.sang;
	cout<<"\n6)Tu estatura es:";
	cin>>g.esta;
	cout<<"\n7)Tu estado civil es:";
	cin>>g.estad_c;
	cout<<"\n8)Tu fecha de nacimiento es:";
	cin>>g.fech_n;
	cout<<"\n9)Tu genero es:";
	cin>>g.gene;
	
	if(g.esta>2){
		cout<<"\n\nSeleccionado para el equipo Dream team";
	}
	if(g.esta<2.0&&g.esta>=1.5){
		cout<<"\n\nSeleccionado para el equipo de basquetbol";
	}
	if(g.esta<1.5&&g.esta>1.0){
		cout<<"\n\nSeleccionado para el equipo de golf";
	}
	if(g.esta<=1.5){
		cout<<"\n\nSeleccionado para el equipo de ajedrez";
	}

}



