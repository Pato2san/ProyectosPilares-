#include <stdio.h>		
#include <conio.h>		
#include <math.h>		 
#include <iostream>		
using namespace std;

float Pregulador;
float Pbulbo;
float Pcable;
char Pn;
string Tnombre;
int op;
int s;
int Cusario;
int TCosecha;
int l1;
int l2;
int i;
int j;

int NumLista[] = {1,2,3,4,5,6,7,8,9,10};		// declaracion de arreglo unidimensonal para el numero de la lista y nombres
string NomLista[]={"Base","Altura","Area","Cable","Reguladores","Bulbos","CostoCable","CostoBulbos","CostoReguladores","CostoTotal"};
string Nombres[10];								// decllaracion de variable para los nombres, 5 en total
string Pestado[10];
char letraLista[]={'a','b','c','d','e','f','g','h','i','j'};
float DatNum[10][10];							// aqui esta la matris con los datos introducidos y los calculos :)
float Pvalor[10];

int *p_NumLista;						//iniciando los punteros
string *p_Nombres;

void MensajeBienvenida();			//prototipo de funciones
void CambioPrecios();
void TodoUsuario();
void DetalleUsuario();
void Tabla(int i,int j);
int MenuPrincipal(int op);
int ListaUsuarios(int Cusario);
int ListaUsuario(int l1);
int ListaDetalle(int l2);


int main()
{
	//los valores preestablecidos
	Pregulador=300;
	Pbulbo=250;
	Pcable=200;
	Cusario=0;							//poniendo a cero al contador de usarios
	s=0;								//Poniendo a cero la bandera de salida
	MensajeBienvenida();				//funcion qyue muestra un mensaje de biemvenida
	
	CambioPrecios();					//funcion que pregunta si quieres cambiar los precios
	
	p_NumLista=NumLista;				//iniciando los punteros
	p_Nombres=Nombres;
		
	while (s==0)						//bucle pricipal si la bandera es 1 sale
	{
		s=0;							//variables usadas a cero
		l1=0;
		l2=0;
		i=0;
		j=0;
		cout<<"\n";
		cout<<"Usuarios en la Lista : "<<Cusario<<"\n";     //muestra la cantidade de usarios ingresados
		switch (MenuPrincipal(0))						//llama a la funcion menu principal y devuelve el valor a switch
		{
			case 1:									//caso 1: introcir lista de usarios
				cout<<"\n";				
				Cusario=ListaUsuarios(Cusario);
				system("cls");				
				break;
			case 2:									//muestra todos los datos de un usario
				cout<<"\n";
				TodoUsuario();
				system("cls");
				break;	
			case 3:									//muestra a detalle los datos guardados
				cout<<"\n";
				DetalleUsuario();
				system("cls");
				break;
			case 4:									//imprime todos los datos de todos los usarios
				cout<<"\n";
				cout<<"Los Datos de los usuarios son: "<<"\n";
				cout<<"\n";
				Tabla(0,0);
				system("cls");
				break;
			case 5:									//salida cambia la bandera S a 1 y muestra mensaje despedida
				cout<<"\n";
				cout<<"\n";
				cout<<"\n";
				cout<<"\n";
				cout<<"************Hasta luego*************"<<"\n";
				cout<<"\n";
				cout<<"\n";
				cout<<"\n";
				cout<<"\n";
				s=1;
				break;
			default:										//si la opcion es incorrecta muestra este mensaje
				cout<<"\n";
				cout<<"Por Favor seleccione la opcion correcta"<<endl;			
				cout<<"\n";
		}
	}
	return(0);
}

//Definicion de Funciones

//Mensaje de bienvenida
void MensajeBienvenida()			//muestra el mensaje de bienvenida con datos preestablecidos
{
	printf("\n");
	printf("\n");													
	printf("Proyecto Final - Pilares programacion en C \n");
	printf("\n");													
	printf("ABRAHAM SANCHEZ 426LB010\n");
	printf("\n");
	printf("****Bienvenidos a este programa de ayuda****\n");
	printf("    te ayudare a calcular los costos en\n");
	printf("       tu hibernadero de champiñones \n");
	printf("\n");
	printf("\n");
	
	printf("  Los datos predeterminados por metro cuadrado son:\n");
	printf("\n");
	//muestra los valores preestablecidos
	printf("   2 Reguladores de voltaje para los Bulbos LED\n");
	printf("   2 bulbos Led Azules\n");
	printf("   5 metros de cable doble para bulbos Led\n");
	printf("   8 meses (Caducidad de bulbo LED)\n");		
	printf("   Precio pieza de Regulador = 300 pesos\n");
	printf("   Precio pieza de Bulbos =    250 pesos\n");
	printf("   Precio Metro de cable  =    200 pesos\n");
	printf("\n");
	printf("\n");
	printf("\n");
	system("pause");
	system("cls");
}

//cambio de precios

void CambioPrecios()				//funcion para cambiar los precios por la inflacion
{
	do								//	bucle para preguntar el precio						
	{
		cout<<"\n";
		//muestra precios preestablecidos
		cout<<"Precio Regulador: "<<Pregulador<<" pesos"<<"\n";
		cout<<"Precio Bulbo:     "<<Pbulbo<<" pesos"<<"\n";
		cout<<"Precio Cable:     "<<Pcable<<" pesos"<<"\n";
		cout<<"\n";
		cout<<"\n";
		cout<<"Desea Cambiar los Precios: S / N :";					//pregunta el cambio
		cin>>Pn;
		if (Pn == 's' or Pn == 'S' )			//acepta letras en mayusculas o minusculas
		{
			//ingreso de nuevos precios
			cout<<"\n";
			cout<<"Ingrese Nuevo Precio para Regulador: ";
			cin>>Pregulador;
			if(cin.fail()==true)		// era muy comun que me equivocara ingresando un caracter con esto se corrige el error
			{
				cin.clear();
				cin.ignore(1000,'\n');
				Pregulador=0;
			}
			else
			{
				cout<<"\n";
			}
			cout<<"Ingrese Nuevo Precio para Bulbo: ";
			cin>>Pbulbo;
			if(cin.fail()==true)		// era muy comun que me equivocara ingresando un caracter con esto se corrige el error
			{
				cin.clear();
				cin.ignore(1000,'\n');
				Pbulbo=0;
			}
			else
			{
				cout<<"\n";
			}
			cout<<"Ingrese Nuevo Precio para Cable: ";
			cin>>Pcable;
			if(cin.fail()==true)		// era muy comun que me equivocara ingresando un caracter con esto se corrige el error
			{
				cin.clear();
				cin.ignore(1000,'\n');
				Pcable=0;
			}
			else
			{
				cout<<"\n";
			}
			cout<<"\n";
			cout<<"\n";
			//muestra los nuevos precios
			cout<<"Nuevo Precio Regulador: "<<Pregulador<<" pesos"<<"\n";
			cout<<"Nuevo Precio Bulbo:     "<<Pbulbo<<" pesos"<<"\n";
			cout<<"Nuevo Precio Cable:     "<<Pcable<<" pesos"<<"\n";
			cout<<"\n";
			if (Pregulador == 0 or Pbulbo == 0 or Pcable == 0 )
			{
				system("cls");
				cout<<"\n";
				cout<<"\n";
				cout<<"\n";
				cout<<"\n";
				cout<<"Ingrese Un Valor Valido";
				cout<<"\n";
				cout<<"\n";
				cout<<"\n";
				cout<<"\n";
				Pn = 'k';				
				system("pause");
			}
			else
			{
				Pn = 's';
			}
			
		}
		else 
		{
			if (Pn == 'n' or Pn == 'N' )					//acepta letras en mayusculas o minusculas
			{
				Pn = 's';									//cambua a s para salir
			}
			else
			{
				cout<<"Elija una opcion correcta"<<"\n";	//si se presiona otra cosa que no sea S,s,N,n
				
			}
		}
	}while (Pn != 's');				//sale si hay una s minuscula 
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	system("pause");
	system("cls");
}

//menu principal

int MenuPrincipal(int op)				//muestra el menu pricipal
{
	cout<<"\n";
	cout<<"Por Favor selecciona la opcion deseada"<<"\n";     			 // inicia el menu principal
	cout<<"\n";
	cout<<"1)"<<"Introducir Usuario nuevo"<<"\n";
	cout<<"2)"<<"Mostrar La Toda la informacion de un usario"<<"\n";
	cout<<"3)"<<"Mostrar informacion detallada de un usario"<<"\n";
	cout<<"4)"<<"Imprimir los Datos de todos los usuarios"<<"\n";
	cout<<"5)"<<"Salir"<<"\n";
	cout<<"\n";
	cin>>op;
	if(cin.fail()==true)		// era muy comun que me equivocara ingresando un caracter con esto se corrige el error
	{
		cin.clear();
		cin.ignore(1000,'\n');
		op=0;
	}
	else
	{
		cout<<"\n";
	}
	system("cls");
	return 	op;
}

//proceso de la lista de usuarios

int ListaUsuarios(int Cusario)  //para mostrar la lista de usarios
{
	if (Cusario < 10)          //condicion para mostrar solo los usuarios ingresados
	{		
		cout<<"\n";
		cin.ignore();		// habia problemas para leer la cadena se pone esto para borrar el salto, aprendi por las malas
		cout<<"ingrese su nombre de usario ("<<NumLista[Cusario]<<" de 10) :  ";
		getline(cin, Tnombre);						//lee la cadena de usarios con espacios :)
		Nombres[Cusario]=Tnombre;					//introduce la cadena al arreglo nombres
		cout<<"ingrese Los m^2 de base:         ";	//otros datos ingresados
		cin>>DatNum[Cusario][0];
		cout<<"ingrese Los m^2 de Altura:       ";
		cin>>DatNum[Cusario][1];
		cout<<"ingrese el Tiempo de cosecha:    ";
		cin>>TCosecha;
		cout<<"ingrese Su Presupuesto:        $ ";
		cin>>Pvalor[Cusario];
		//comienza los calculos y metelos en la matriz acuerdate que lalista va hacia abajo en la tabla 
		DatNum[Cusario][2]=DatNum[Cusario][0]*DatNum[Cusario][1];   	//calculo area=DatNum[i][2]				
		DatNum[Cusario][3]=DatNum[Cusario][2]*2;   						//Calculo Cables=DatNum[i][3]
		DatNum[Cusario][4]=DatNum[Cusario][2]*2;			   			//Calculo Reguladores=DatNum[i][4]
		DatNum[Cusario][5]=(DatNum[Cusario][2]*2*TCosecha)/8;			//Calculo de Bulbos=DatNum[i][5]
	
		DatNum[Cusario][6]=DatNum[Cusario][3]*Pcable;				//costo de cables=DatNum[i][6]
		DatNum[Cusario][7]=DatNum[Cusario][4]*Pregulador;				//Costo de Reguladores=DatNum[i][7]
		DatNum[Cusario][8]=DatNum[Cusario][5]*Pbulbo;				//costo de Bulbos=DatNum[i][8]
	
		DatNum[Cusario][9]=DatNum[Cusario][6]+DatNum[Cusario][7]+DatNum[Cusario][8];		//Coto total=DatNum[i][9]
		
		cout<<"\n";										// comienza aqui el resultado e los calculos 
		cout<<"Tus Calculos son: "<<"\n";
		cout<<"\n";
		// se uso la lista asi por razones esteticas
		cout<<"Usuario "<<letraLista[Cusario]<<") "<<Nombres[Cusario]<<"\n";
		cout<<NomLista[0]<<":     "<<DatNum[Cusario][0]<<" m"<<"\n";
		cout<<NomLista[1]<<":   "<<DatNum[Cusario][1]<<" m"<<"\n";
		cout<<NomLista[2]<<":     "<<DatNum[Cusario][2]<<" m^2"<<"\n";
		cout<<NomLista[3]<<":      "<<DatNum[Cusario][3]<<" m "<<"\n";
		cout<<NomLista[4]<<":  "<<DatNum[Cusario][4]<<" Pza"<<"\n";
		cout<<NomLista[5]<<":       "<<DatNum[Cusario][5]<<" Pza"<<"\n";
		cout<<NomLista[6]<<":         $ "<<DatNum[Cusario][6]<<"\n";
		cout<<NomLista[7]<<":        $ "<<DatNum[Cusario][7]<<"\n";
		cout<<NomLista[8]<<":   $ "<<DatNum[Cusario][8]<<"\n";
		cout<<NomLista[9]<<":         $ "<<DatNum[Cusario][9]<<"\n";
		cout<<"\n";
	
		if (DatNum[Cusario][9]<=Pvalor[Cusario])		//condicion para saber si alcanza el dinero
		{
			cout<<"   Muy bien nos alcanza el dinero "<<"\n";
			Pestado[Cusario]="DineroSuficiente";		//guardado en una cadena de caracteres de suficiencia
			cout<<"\n";
			cout<<"    Presupuesto de $ "<<Pvalor[Cusario]<<" : "<<Pestado[Cusario]<<"\n";  	
		}
		else
		{
			cout<<"   Malas noticias: Supera nuestro Presupuesto "<<"\n";
			Pestado[Cusario]="DineroInsuficiente";		//guardado en una cadena de caracteres de insuficiencia
			cout<<"    Presupuesto de $ "<<Pvalor[Cusario]<<" : "<<Pestado[Cusario]<<"\n";
		}
		Cusario = Cusario + 1;		//contador agrega un usario para mostrar en las listas
	}
	else
	{								//si la lista esta llena muestra este mensaje
		cout<<"\n";
		cout<<"*************Lista Llena********"<<"\n";
		cout<<"\n";
	}
	system("pause");
	return 	Cusario;				//regresa el numero de usario
}

//Para mostrar todos los datos de un usuario

void TodoUsuario()
{
	i=ListaUsuario(0);			//despliega la lista y devielve el valor i
	system("cls");
	cout<<"\n";
	cout<<"    Usuario ("<<NumLista[i]<<")  "<<Nombres[i]<<"\n";							// aqui se imprime los datos del nombre seleccionado
	cout<<"\n";
	for(l1=0;l1<10;l1++)								// muestra los nombres y el numero de lista usando arreglos
		{
			cout<<NomLista[l1]<<": "<<DatNum[i][l1]<<"\n";		//no imprime esteticamente bien	pero reduce codigo
		}
	cout<<"\n";
	cout<<"Presupuesto de Usuario "<<NumLista[i]<<") "<<Nombres[i]<<" = $ "<<Pvalor[i]<<" : "<<Pestado[i]<<"\n";
	system("pause");	
}

//para mostrar a detalle los datos de un usuario

void DetalleUsuario()
{
	i=ListaUsuario(0);			//despliega la lista usarios y devielve el valor i
	system("cls");
	j=ListaDetalle(0);			//despliega la lista opciones y devielve el valor j
	system("cls");
	cout<<"\n";	
	cout<<"\n";																	//imprime la lista y el dato seleccionado
	cout<<"usuario ("<<NumLista[i]<<") : "<<Nombres[i]<<"\n";
	cout<<"\n";	
	cout<<"\n";	
	cout<<"Tu dato es : ("<<NomLista[j]<<") = "<<DatNum[i][j]<<"\n";
	cout<<"\n";	
	cout<<"\n";		
	system("pause");
}


//Para desplegar la lista de los usuarios y sellecionar en la lista

int ListaUsuario(int l1)
{
	cout<<"\n";
	cout<<"Listas de Usuarios" <<"\n";	
	cout<<"\n";
	
	p_NumLista=NumLista;							//pon esto de nuevo cunado se usa una ves cambia el valor
	p_Nombres=Nombres;								//lo aprendi por las malas
	
	for(l1=0;l1<Cusario;l1++)								// muestra los nombres y el numero de lista 
		{
			cout<<"Usuario: "<<*p_NumLista++<<") "<<*p_Nombres++<<endl;		
		}
	cout<<"\n";	
	do												//bucle selleciona nombre y no dejes entrar si es menor que 0 o mayor a 5
	{
		cout<<"Por Favor Selecciona usario ";
		cin>>l1;
		if(cin.fail()==true)						//para evitar error de sellecionar caracter
		{
			cin.clear();
			cin.ignore(1000,'\n');
			l1=0;
		}
		else
		{
			cout<<"\n";
		}
		
		if (l1<=0)					//si se ingresa un numero no mostrado en la lista
		{
			
			cout<<"Por favor ingrese el numero de usuario correcto:  ";
			l1=11;
			cout<<"\n";				
		}
		else
		{
			if (l1>=11)
			{
				cout<<"\n";
				cout<<"Por favor ingrese el numero de usuario correcto:  ";
				l1=11;
				cout<<"\n";	
			}
			else
			{
				if(l1<=Cusario)				//si se ingresa un numero mayor a los usuarios mostrados
				{
					i=l1-1;
				}
				else
				{
					cout<<"\n";
					cout<<"Por favor ingrese el numero de usuario correcto:  ";
					l1=11;
					cout<<"\n";
				}
			}
		}
		cout<<"\n";		
	}while (l1>=11);			//fin del bucle de lista de usarios
	return 	i;
}

//para desplegar la lista de detalles y seleccionar

int ListaDetalle(int l2)
{
	cout<<"\n";
	cout<<"Listas de Detalles" <<"\n";	
	cout<<"\n";
	cout<<"1)Tamaño de la base m"<<"\n";
	cout<<"2)Tamaño de la Altura m"<<"\n";
	cout<<"3)Tamaño del Area m^2"<<"\n";
	cout<<"4)Metros de Cable"<<"\n";
	cout<<"5)Reguladores"<<"\n";
	cout<<"6)Bulbos"<<"\n";
	cout<<"7)Costo del Cable"<<"\n";
	cout<<"8)Costo Regulador"<<"\n";
	cout<<"9)Costo Bulbos"<<"\n";
	cout<<"10)Costo total"<<"\n";
	cout<<"\n";
	do 																			//muestra y selecciona datos
	{
		cout<<"Por Favor Selecciona La informacion que deseas ver: ";
		cin>>l2;
		if(cin.fail()==true)			//para evitar el errror de caracter ingresado
		{
			cin.clear();
			cin.ignore(1000,'\n');
			l2=0;
		}
		else
		{
			cout<<"\n";
		}	
		if (l2<=0)																//para evitar el 0 y menores
		{
			
			cout <<"seleccione una opcion correcta"<<endl;
			l2=11;
			cout<<"\n";
			
		} 
		else
		{
			if (l2>=11)															// para evitar el 12 y mayores
			{
				cout<<"\n";
				cout<<"Por favor ingrese el numero de usuario correcto:  ";
				l2=11;
				cout<<"\n";					
			}
			else
			{
				j=l2-1;
			}
		}
	}while (l2>=11);	  //fin del bucle
	return 	j;
}

// ´para desplegar una tabla con todos los datos

void Tabla(int i,int j)     //funcion se ingresa con dos variables 
{
	for(i=0;i<Cusario;i++)  //imprime la lista hacia abajo
	{
		cout<<"Usuario: ("<<NumLista[i]<<" - "<<Nombres[i]<<") \n";
		for(j=0;j<10;j++)											//imprime la lista hacia la izquierda
		{
			cout<<NomLista[j]<<" : "<<DatNum[i][j]<<"\n";
		}
		cout<<"\n";													// un salto hacia abajo
	}
	system("pause");
}

//fin  T.T

