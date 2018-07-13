#include <iostream>
using namespace std;

main(){
	int n, Dia[n],j=0;float Temp[n],mte=0,p=0,sut=0;
	
	
	cout<<"\t\t\t\tTemperatura de los dias del mes de abril \n\n"<<endl;
	cout<<"Cuantos dias tiene el mes de abril ?"<<endl;
	cin>>n;
		for(int i=0;i<n;i++){
	
		cout<<"Ingrese la fecha a registrar:\t"; cin>>Dia[i];
		cout<<"LA TEMPERATURA DEL DIA REGISTRADO ES DE:\t";cin>>Temp[i];
			if (Temp[i]>mte){
			mte=Temp[i];
			j=i; }
		sut=sut+Temp[i];	
			
		
	}
	p=sut/n;
	for (int i=0;i<n;i++){
		if (j==i){
	//	system("cls");
		cout<<"\n\nLa Temperatura mayor fue:\t"<<mte<<"\tEn el dia:\t"<<Dia[j]<<endl;}
	}
	cout<<"El promedio te temperatura del mes de ABRIL fue de:"<<p<<endl;
}
		
