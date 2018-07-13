#include <iostream>
#define H 40
using namespace std;

void menu();
void ciclo(int);

main(){	
	menu();
}

void menu(){
	int a;
	cout<<"Cuantos trapecios ?:\t";
	cin>>a;
	system("cls");
	ciclo(a);
}

void ciclo (int x){
	float Bs[H],Bm[H],h[H],res[H],P1,sum;
	for(int i=0;i<x;i++){
		system("cls");
		cout<<"\t\t\t   ****";//AREA DE TRAPECIOS
	    cout<<"\n\t\t\t\tA=(B+b).h/2";
		cout<<"\n\n Numero "<<i+1<<":";
		cout<<"\n\n  Base menor b= ";
	    cin>>Bs[i];
	    cout<<"\n   Base mayor B= ";
	    cin>>Bm[i];
	    cout<<"\n\tAltura h= ";
	    cin>>h[i];
	    res[i]=((Bs[i]+Bm[i])*h[i])/2;
	    sum+=res[i];
	   
	}
	 P1=sum/x;
	system("cls");
	cout<<"\t\t\t   **AREA DE TRAPECIOS**";
	cout<<"\n\t\t\t\tA=(B+b).h/2";
	cout<<"\n\n\n\tAREA\t\tDESVIACION";
	for(int s=0;s<x;s++){
	cout<<"\n\t"<<s+1<<")  "<<res[s]<<"           "<<res[s]-P1;
	}
	cout<<"\n\n\tPROMEDIO DE LAS AREAS:"<<P1;
}
