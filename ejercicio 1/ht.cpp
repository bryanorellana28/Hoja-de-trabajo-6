#include <iostream>
#include <stdlib.h>
#include <fstream>
#include<string>
#include <regex> 	
#include <fstream>
#include <stdio.h>
#include <sstream> 
#include <regex>
#include <iomanip>

 
#define PP "archivoprincipal.txt"
#define bk "archivobackup.txt"
#define salto "\n"

using namespace std;

void numlineas();
	void mostrarregistro()
	
	{
	ifstream principal; 
		principal.open(PP,ios::in);
			int nregistro,numerodelineas,reg ; string linea1,fecha,flag,inota;
	string linea,tipo,fecha1,venta;
	string totalc;
		while (principal>>nregistro>>tipo>>fecha1>>totalc	){
				const auto obj = regex{ "_" };
	    		const auto repl = string{ " " };
	    		const auto valor = tipo;
				cout<<setw(3)<<nregistro<<"|"<<setw(18)<<regex_replace(valor, obj, repl)<<"|"<<setw(4)<<fecha1<<"|"<<setw(4)<<totalc<<endl;
				}	
			principal.close();
	}

void apertura()
{	ifstream PP1; 
	ofstream REMP2; 
	PP1.open(PP,ios::in);
	REMP2.open(bk,ios::app);
    
}
int  numlineas(int a){
	int lin=0;
 try{
    				ifstream entrada;

		entrada.open(PP,ios::in);

    	  while(entrada.good()) if(entrada.get()=='\n') lin++;
  entrada.close();	}
		catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");	}
   return lin;
}
float venta(float costo, int cantidad )
{
	float total;
	total=costo*cantidad;
	return total;
}

int main()
{
	int ciclo=0,seleccion,sventa,cantidad,indice=0,dia,lineas,loop;
	float mod,operacion;
	const float mod1=10,mode2=15,mod3=18.5,mod4=25;
		const string op1="Modelo 1",ope2="Modelo 2",op3="Modelo 3",op4="Modelo 4";
	string eleccion;
	
	while (ciclo==0)
	{
		cout<<"Bienvenido, seleccione alguna de las siguientes funciones \n 1. Realizar venta. \n 2. Modificar el numero de unidades vendidas. \n 3. Eliminar dia especifico \n 4. Estadisticas. \n	";
		cin>>seleccion;
		if  (seleccion==1)
		{	fflush(stdin);
			cout<<"Seleccione una de las siguientes opciones \n 1.Modelo#1  Q10.00 \n 2.Modelo#2  Q15.00 \n 3.Modelo#3  Q18.50 \n 4.Modelo#4  Q25.00 \n";
			cin>>sventa;
			mod=sventa==1 ? mod1:(sventa==2 ? mode2:(sventa==3 ? mod3:mod4));
				eleccion=sventa==1 ? op1:(sventa==2 ? ope2:(sventa==3 ? op3:op4));
			cout<<"Seleccione la cantidad del modelo \n";
			cin>>cantidad;
				cout<<"Seleccione el dia de la venta \n";
			cin>>dia;
			operacion=venta(mod,cantidad);
			const auto obj = regex{ " " };
    const auto repl = string{ "_" };
    const auto valor = eleccion;
    lineas=numlineas(cantidad);
		try {		ofstream entrada;
		entrada.open(PP,ios::app);
		entrada<<++lineas<<"\t"<<regex_replace(valor, obj, repl) <<"\t"<<dia<<"\t"<<cantidad<<endl;   //"|"
		entrada.close();}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");
	}	
					cout<<salto<<"Desea regresar al menu principal escriba 0, desea salir del programa escriba 1 "<<endl;
					cin>>ciclo;
							system("cls");	}
	
	else {
	
	if(seleccion==2)
	{
			system("cls");
						fflush(stdin);

//se crea un archivo donde se enviaran los datos que deseamos y luego de realizar toda la operacion remplazara al archivo principal //
//se creo una definicion al principio del codigo para la ruta de los archivos//
int nregistro,numerodelineas,flag ; string reg, linea1,fecha,cambio;
string linea,tipo,fecha1,venta;
char  totalc;
	char respuesta;
	remove(bk);
	numerodelineas=numlineas(numerodelineas);
				cout<<"Registro    "<<"  Modelo     " <<"Dia  "<<"Cantidad "<<endl;

		mostrarregistro();
		cout<<salto<<"Seleccion un registro a modificar"<<endl;
		cin>>reg;
		cout<<salto<<"Indique la cantidad a modificar"<<endl;
		cin>>cambio;
		ifstream PP1; 
	ofstream REMP2; 
	PP1.open(PP,ios::in);
	REMP2.open(bk,ios::app);
string linea2,tipo2,fecha2,total2;
		while (PP1>>linea2>>tipo2>>fecha2>>total2){
				const auto obj = regex{ " " };
    const auto repl = string{ "_" };
    const auto valor = tipo2;
		if(reg==linea2){
			REMP2<<linea2<<"\t"<<tipo2<<"\t"<<fecha2<<"\t"<<cambio<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag =1;	}			
		else if(reg!=linea2)
			REMP2<<linea2<<"\t"<<tipo2<<"\t"<<fecha2<<"\t"<<total2<<endl;
	}
	PP1.close();
	REMP2.close();
	
	if (flag==1){
		remove(PP);
		rename(bk,PP);
	}		cout<<"Desea regresar al menu principal escriba 0, desea salir del programa escriba 1 "<<endl;
					cin>>ciclo;

	}	
	else
	{
	    
	    if (seleccion==3)
	    
	    {	
	    system("cls");	fflush(stdin);

		remove(bk);

	string delete1,linea3,tipo3,fecha3,total3;int resta,flag,cambio11,conver1,conver2;
					cout<<"Registro    "<<"  Modelo     " <<"Dia  "<<"Cantidad "<<endl;

	        		mostrarregistro();
cout<<"Indique el registro a Eliminar"<<endl;
cin>>delete1;

	        
	        ifstream PP2; 
	ofstream REMP3; 
	PP2.open(PP,ios::in);
	REMP3.open(bk,ios::app);
while (PP2>>linea3>>tipo3>>fecha3>>total3){
				const auto obj = regex{ " " };
    const auto repl = string{ "_" };
    const auto valor = tipo3;
		if(delete1==linea3){
			cout<<"se elimino el registro.... " <<linea3<<endl;
			flag =1;	}			
		else if(delete1!=linea3){
		    conver1=atoi(delete1.c_str());
		    conver2=atoi(linea3.c_str());
		    if (conver1>conver2)
		    {

			REMP3<<linea3<<"\t"<<tipo3<<"\t"<<fecha3<<"\t"<<total3<<endl;}
			else{
resta=conver2-1;
			REMP3<<resta<<"\t"<<tipo3<<"\t"<<fecha3<<"\t"<<total3<<endl;}

	}
}
	       	PP2.close();
	REMP3.close();

		remove(PP);
		rename(bk,PP);
			
	
	        cout<<"Desea regresar al menu principal escriba 0, desea salir del programa escriba 1 "<<endl;
					cin>>ciclo;
	    }
	    else{
	        if(seleccion==4)
	        {
	            
     ifstream PP3; 
	ofstream REMP4; 
	PP3.open(PP,ios::in);
	REMP4.open(bk,ios::app);
		string linea4,tipo4,fecha4,total4,comparativa;
		float mul1=0,mul2=0,mul3=0,mul4=0, suma1=0,suma2=0,suma3=0,suma4=0,flag,cambio11,conver3,conver4,totalporventa; int selec;

while (PP3>>linea4>>tipo4>>fecha4>>total4){
				const auto obj = regex{ " " };
    const auto repl = string{ "_" };
    const auto valor = tipo4;
    comparativa=regex_replace(valor, obj, repl);
    conver4=atoi(total4.c_str());
selec=comparativa=="Modelo_1" ? 1:(comparativa=="Modelo_2" ? 2:(comparativa=="Modelo_3" ? 3:4));
switch(selec){

case 1:
suma1=suma1+conver4;
break;
case 2:
suma2=suma2+conver4;

break;
case 3:
suma3=suma3+conver4;

break;
case 4:
suma4=suma4+conver4;

break;
}

}
		mostrarregistro();

mul1=suma1*10;
mul2=suma2*15;
mul3=suma3*18.5;
mul4=suma4*25;
cout<<salto<<"Suma de modelo  1 "<<suma1<<endl;
cout<<"Total de modelo 1 "<<mul1<<endl;
cout<<"Suma de modelo  2 "<<suma2<<endl;
cout<<"Total de modelo 2 "<<mul2<<endl;
cout<<"Suma de modelo  3 "<<suma3<<endl;
cout<<"Total de modelo 3 "<<mul3<<endl;
cout<<"Suma de modelo  4 "<<suma4<<endl;
cout<<"Total de modelo 4 "<<mul4<<endl;
string mayor;
if (suma1 > suma2 && suma1 > suma3 && suma1 > suma4 ){
mayor= "El modelo  1 fue el mas vendido";}
if (suma2 > suma1 && suma2 > suma3 && suma2 > suma4 ){
mayor= "El modelo  2 fue el mas vendido";}
if (suma3 > suma1 && suma3 > suma2 && suma3 > suma4 ){
mayor= "El modelo  3 fue el mas vendido";}
if (suma4 > suma2 && suma4 > suma3 && suma4 > suma1 ){
mayor= "El modelo 4 fue el mas vendido";}
cout<<mayor<<salto<<salto;


	        }
	    }
	    	cout<<"Desea regresar al menu principal escriba 0, desea salir del programa escriba 1 "<<endl;
					cin>>ciclo;
 system("cls")	 ;   
	}

		
		
	
	}
	
}	
	     

	}
	
	
	


