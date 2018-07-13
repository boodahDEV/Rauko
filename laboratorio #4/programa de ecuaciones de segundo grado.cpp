#include <iostream>
#include <cmath>
#define H 40
using namespace std;

void menu();
void ecua(int);

main(){
	menu();
}

void menu(){
	int num;
	cout<<"Cuantos ecuaciones desea: ";
	cin>>num;
	system("cls");
	ecua(num);
}

void ecua (int x){
	int i;
	float a[H],b[H],c[H],dis[i],x1[i],x2[i];
	for( i=0;i<x;i++){
		system("cls");
		cout<<"\t\t\t   ##(Polinomio)##";
	    cout<<"\n\t\t\t     ax^2+bx+c=0";
	    cout<<"\n\n Ecuacion ["<<i+1<<"]:";
		cout<<"\n\n  valor de a:";
	    cin>>a[i];
	    cout<<"\n  valor de b:";
	    cin>>b[i];
	    cout<<"\n  valor de c:";
	    cin>>c[i];
	    dis[i]=b[i]*b[i]-4*a[i]*c[i];
	}
    cout<<"\n\n\t\tVALORES";
    cout<<"\n\tA\tB\tC\tRAIZ+\tRAIZ-";
	for(i=0;i<x;i++){
		if(dis[i]>0){
	      x1[i]=(-b[i]+(sqrt(dis[i])))/(2*a[i]);
	      x2[i]=(-b[i]-(sqrt(dis[i])))/(2*a[i]);	
	      cout<<"\n\n\t"<<a[i]<<"\t"<<b[i]<<"\t"<<c[i]<<"\t"<<x1[i]<<"\t"<<x2[i];
		}
		if(dis[i]<0){
	      cout<<"\n\n\t"<<a[i]<<"\t"<<b[i]<<"\t"<<c[i]<<"\tIMAGINARIA";	
		}
		if(dis[i]==0){
	      x1[i]=(-b[i]+(sqrt(dis[i])))/(2*a[i]);
	      x2[i]=(-b[i]-(sqrt(dis[i])))/(2*a[i]);
		  cout<<"\n\n\t"<<a[i]<<"\t"<<b[i]<<"\t"<<c[i]<<"\t"<<x1[i]<<"\t"<<x2[i];	
		}
	}	
}

