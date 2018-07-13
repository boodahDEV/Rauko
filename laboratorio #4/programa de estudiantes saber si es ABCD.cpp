#include <iostream>
using namespace std;

main(){
	int E[30],n,a=0,b=0,c=0,d=0,f=0; float p=0,pb=0,pc=0,pd=0,pf=0,v=0,vb,vc,vd,vf;
		
	cout<<"\t\t\t\tCurso de programacion virtual \n\n"<<endl;
	cout<<"Cuantos Estudiantes tiene el curso?"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Ingrese el promedio del estudiante:\t";cin>>E[i];
 if(E[i]>=91){
v=v+E[i];
a++;
}else
 if(E[i]>=81 && E[i]<91){
vb=vb+E[i];
b++;
}else
if(E[i]>=71 && E[i]<81){
vc=vc+E[i];
c++;
}else
if(E[i]>=61 && E[i]<71){
vd=vd+E[i];
d++;
}else{
vf=vf+E[i];f++;
}
}
p=v/a;
pb=vb/b;
pc=vc/c;
pd=vd/d;
pf=vf/f;	
///////////////////////////////////////////////////////////////////////////////////////////////4
system("cls");
cout<<"\t\t\t\tEl promedio por cada rango de nota \n\n"<<endl;
	cout<<"\t\t\t"<<"Promedio";
	cout<<"\n_______________________________________________________________________\n";
cout<<"A:\t"<<a<<"\t\t "<<p<<endl;	
cout<<"B:\t"<<b<<"\t\t "<<pb<<endl;
cout<<"C:\t"<<c<<"\t\t "<<pc<<endl;
cout<<"D:\t"<<d<<"\t\t "<<pd<<endl;
cout<<"F:\t"<<f<<"\t\t "<<pf<<endl;
	}//fin for
	


