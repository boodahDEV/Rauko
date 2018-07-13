#include <iostream>

#include <string.h>
//#define w 2
using namespace std;
struct equipo{
	int Njug;
	char Nom[15];
	char Apo[15];
	int Pos;
	int edad;
	int Leg;
	struct Titular;
}E[23];
struct Titular{
	int leg;
	int pos;
	char no[15];
	
}T[11];

main(){
	char resp; int Eacu=0, med,j,L=0,w; float p=0;
	
	cout<<"Cuantos jugadores ingresara?:"<<endl;
    cin>>w;
	 for(int i=0;i<w;i++){
	  system("cls");
		cout << "Nombre del jugador:";
		cin>>E[i].Nom;
		cout << "\n\tNumero del jugador:";
		cout<<"\t\t";     cin>>E[i].Njug;
		cout << "\n\tPosicion del jugador:";
		cout<<"\t\t";   cin>>E[i].Pos;
		cout << "\n\tApodo del jugador:";
	    cout<<"\t\t";cin>>E[i].Apo;
		cout << "\n\tEdad del jugador:";
	    cout<<"\t\t";	cin>>E[i].edad;
	    Eacu=Eacu+E[i].edad;
	    	if (E[i].edad < med){
	      	   med=E[i].edad;
	      	   j=i;
				 } 
	    cout << "\n\tEs legionario? 1/0:";
	    cout<<"\t\t";	cin>>E[i].Leg ;
	    if(E[i].Leg !=0 ){
	    	L=L+1;
		}
} 
///////////////////////////////////////////////////////////////////////////
  for(int i=0;i<11;i++){
  	if (E[i].Leg==1){
  	  switch (E[i].Pos){
  	  	case 1: 
  	  	   T[i].pos=E[i].Pos;
  	  	   strcpy( T[i].no,E[i].Nom);
  	  	    break;
  	  	case 2:
  	  		T[i].pos=E[i].Pos;
  	  	    strcpy( T[i].no,E[i].Nom);
  	  	    break;
  	  	case 3:
  	  		T[i].pos=E[i].Pos;
  	  	   strcpy( T[i].no,E[i].Nom);
  	  	     break;
  	  	case 4: 
  	  	    T[i].pos=E[i].Pos;
  	  	   strcpy( T[i].no,E[i].Nom);
  	  	     break;
  	  	case 5:
  	  	   T[i].pos=E[i].Pos;
  	  	    strcpy( T[i].no,E[i].Nom);
  	  	     break;
  	  	case 6:
  	  	T[i].pos=E[i].Pos;
  	  	    strcpy( T[i].no,E[i].Nom);
  	  	     break;
  	  	case 7: 
  	  	   T[i].pos=E[i].Pos;
  	  	  strcpy( T[i].no,E[i].Nom);
  	  	     break;
  	  	case 8:
  	  	    T[i].pos=E[i].Pos;
  	  	    strcpy( T[i].no,E[i].Nom);
  	  	     break;
  	  	case 9:
  	  	 T[i].pos=E[i].Pos;
  	  	    strcpy( T[i].no,E[i].Nom);
  	  	     break;
		case 10: 
  	  	     T[i].pos=E[i].Pos;
  	  	   strcpy( T[i].no,E[i].Nom);
  	  	     break;
  	  	    
  	  	case 11:
  	  	     T[i].pos=E[i].Pos;
  	  	   strcpy( T[i].no,E[i].Nom);
  	  	     break;
		}
	  }
  	
  }
    system("cls");
    cout<<"NOMBRE DEL JUGADOR"<<"\tPOSICION DEL JUGADOR"<<endl;
    cout<<"__________________________________________________________\n";
    for(int i = 0; i < L; i++){
    	cout<<" "<<T[i].no<<"  \t\t\t"<<T[i].pos<<endl;
	}
	
//////////////////////////////////////////////////////////////////////////////	
	p=Eacu/w;
      for(int i=0;i<w;i++){
      	if(j==i)
      		cout <<"\n\n\n\n\n\n La edad menor es:"<<med<<endl;   }
  cout<<"\n\n\n\nEl promedio de edades del equipo es:"<<p<<endl;
}
