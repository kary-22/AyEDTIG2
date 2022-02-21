#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<ctime>

struct usuarios
{
	char usuario[32],contrasenia[32],apynom[30];
	bool borrado;
};
struct prof
{
	char apynom[30],tel[10];
	int idprof,dni;
	bool borrado;
};
struct fecha
{
	int dia,mes,anio;
};
struct cliente
{
	char apynom[30],dom[50],loc[50],tel[10],detalle[100];//cambiar luego a detalle[380]
	int dniCliente,edad;
	float peso;
	fecha fec;
	bool borrado;
};
struct turnos
{
	int idprof,dniCliente;
	char ayn[30];
	fecha fec;
	bool borrado;
};
struct lis
{
	char paciente[30];
	int dni,prof;
	fecha fec;
	bool borrado;
};
struct inf
{
	int dni,prof;
	char aynC[30],aynP[30];
	fecha fec;
};

void regClientes();
void regTurnos();
void lista();

main()
{
	int opcion;
	
	do
	{
		system("color 02");
		printf("\n");
		printf("\t\t\t:::::::::::   ::::         :::::::::::   ::::   ::::   :::::::::::    \n");
		printf("\t\t\t::::   ::::   ::::         ::::   ::::   ::::   ::::   ::::   ::::    \n");
		printf("\t\t\t::::   ::::   ::::         ::::   ::::   ::::   ::::   ::::   ::::    \n");
		printf("\t\t\t:::::::::::   ::::         ::::   ::::   :::::::::::   :::::::::::    \n");
		printf("\t\t\t::::   ::::   ::::::::::   :::::::::::   ::::   ::::   ::::   ::::    \n") ;
		printf("\n\t\t\t\t\t\t\t\t        CENTRO DE ESTETICA\n\n\n");
		printf("\t\t\t\t\t|*** MODULO DEL RECEPCIONISTA ***|\n\t\t\t\t\t==================================\n\n");
		printf("\t\t\t\t\t1- Iniciar Sesion\n\t\t\t\t\t2- Registrar Cliente\n\t\t\t\t\t3- Registrar Turno\n\t\t\t\t\t4- Listado de Atenciones por Profesional y Fecha\n\t\t\t\t\t5- Cerrar la aplicacion\n\n\t\t\t\t\tIngrese una opcion: ");
		scanf("%d",&opcion);
		while(opcion<1 or opcion>5)
		{
			printf("\n\n\t\t\t\t\tERROR! La opcion seleccionada es incorrecta.\n\t\t\t\t\tElija un numero entre 1 y 5: ");
			scanf("%d",&opcion);
		}
		system("cls");
		switch(opcion)
		{
			case 1:
				system("InicioSesion.exe");
				printf("\n\n");
				system("pause");
				system("cls"); break;
			case 2:
				regClientes();
				printf("\n\n");
				system("pause");
				system("cls"); break;
			case 3:
				regTurnos();
				printf("\n\n");
				system("pause");
				system("cls"); break;
			case 4:
				lista();
				printf("\n\n");
				system("pause");
				system("cls"); break;
			default: printf("\n\nFIN DEL PROGRAMA...");
				printf("\n\n");
				system("pause");
				system("cls"); break;
		}
	}while (opcion!=5);
}
void regClientes()
{
	FILE *punC;
	int i,n;
	cliente Clientes;
	fecha fecActual;
	
	time_t t = time(NULL);
	struct tm today = *localtime(&t);
	
	fecActual.dia=today.tm_mday;
	fecActual.mes=today.tm_mon+1;
	fecActual.anio=(today.tm_year+1900);
	
	punC=fopen("Clientes.dat","a+b"); 
	printf("Cantidad de Clientes a registrar: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n\nCLIENTE %d\n----------\nApellido y nombre: ",i+1);
		_flushall();
		gets(Clientes.apynom);
		strupr(Clientes.apynom);
		printf("Domicilio: ");
		_flushall();
		gets(Clientes.dom);
		strupr(Clientes.dom);
		printf("DNI Numero: ");
		scanf("%d",&Clientes.dniCliente);
		printf("Localidad: ");
		_flushall();
		gets(Clientes.loc);
		strupr(Clientes.loc);
		printf("Fecha de Nacimiento:\nDia: ");
		scanf("%d",&Clientes.fec.dia);
		printf("Mes: ");
		scanf("%d",&Clientes.fec.mes);
		printf("Anio: ");
		scanf("%d",&Clientes.fec.anio);
		Clientes.edad=fecActual.anio-Clientes.fec.anio;
		printf("Peso: ");
		scanf("%f",&Clientes.peso);
		printf("Telefono: ");
		_flushall();
		gets(Clientes.tel);
		Clientes.borrado=false;
		fwrite(&Clientes,sizeof(cliente),1,punC);
	}
	fclose(punC);
}
void regTurnos()
{
	turnos Turno;
	lis list;
	lis listaux[50],aux;
	int i,n,b,x,ban;
	FILE *punT,*punL,*punC;
	fecha fecActual;
	char ApyNom[30];
	cliente Clientes;
	
	time_t t = time(NULL);
	struct tm today = *localtime(&t);
	
	fecActual.dia=today.tm_mday;
	fecActual.mes=today.tm_mon+1;
	fecActual.anio=(today.tm_year+1900);
	
	punT=fopen("Turnos.dat","a+b");  
	
	printf("Cantidad de Turnos a registrar: ");
	scanf("%d",&n);
				
	for(i=0;i<n;i++)
	{
		printf("\n\nTURNO %d\n----------\nID Profesional: ",i+1);
		scanf("%d",&Turno.idprof);
		printf("Fecha:\nDia: ");
		scanf("%d",&Turno.fec.dia);
		printf("Mes: ");
		scanf("%d",&Turno.fec.mes);
		printf("Anio: ");
		scanf("%d",&Turno.fec.anio);
		printf("DNI del Cliente: ");
		scanf("%d",&Turno.dniCliente);
		_flushall();
		printf("Apellido y Nombre del Cliente: ");
		gets(Turno.ayn);
		strupr(Turno.ayn);
		Turno.borrado=false;
		fwrite(&Turno,sizeof(turnos),1,punT);
		
		punC=fopen("Clientes.dat","rb");
		if(punC==NULL)
		{
			printf("ERROR! EL ARCHIVO NO EXISTE\n");
			exit (EXIT_FAILURE);
		}
		else
		{
			fread(&Clientes,sizeof(cliente),1,punC);	
			ban=0;
			while(!feof(punC))
			{
				if(Clientes.dniCliente==Turno.dniCliente)
				{
					printf("\n<<< Cliente Registrado >>>");
					ban=1;
					break;
				}
				else
				fread(&Clientes,sizeof(cliente),1,punC);
			}
			fclose(punC);
			if(ban==0)
			printf("\n<<< Cliente NO Registrado, Completar Registro (Opcion 2 del Menu) >>>");
		}
	}
	rewind(punT);
				
	punL=fopen("lista.dat","a+b");
	fread(&Turno,sizeof(turnos),1,punT);
	while(!feof(punT))
	{
		if(Turno.fec.dia==fecActual.dia && Turno.fec.mes==fecActual.mes && Turno.fec.anio==fecActual.anio)
		{
			list.dni=Turno.dniCliente;
			list.prof=Turno.idprof;
			list.borrado=false;
			list.fec=fecActual;
			strcpy(list.paciente,Turno.ayn);
			fwrite(&list,sizeof(lis),1,punL);
		}
		fread(&Turno,sizeof(turnos),1,punT);
	}
	fclose(punT);
	rewind(punL);
	
	printf("\n\nLista del dia:\n\n");//muestra repetidos los turnos del dia a veces
	fread(&list,sizeof(lis),1,punL);
	while(!feof(punL))
	{
		printf("ID Profesional: %d\n\t\tDNI Cliente: %d\n\n",list.prof,list.dni);
		fread(&list,sizeof(lis),1,punL);
	}
	fclose(punL);
}
void lista()
{
	inf informe;
	FILE *arch;
	int x,opcion,b;
	
	arch=fopen("Informe.dat","rb");
	if(arch==NULL)
	{
		printf("ERROR! EL ARCHIVO NO EXISTE\n");
		exit (EXIT_FAILURE);
	}
	else
	{
		do
		{
			printf("\n\nINGRESE EL DNI DEL CLIENTE A BUSCAR: ");
			scanf("%d",&x);
			fread(&informe,sizeof(inf),1,arch);
			b=0;
			while(!feof(arch))
			{
				if(x==informe.dni)//solo muestra el primer turno atendido de cada cliente
				{
					printf("\nApellido y Nombre del Cliente: %s\nDNI Cliente: %d\nFecha de Atencion: %d/%d/%d\nAtendido por: %s\t\tID Profesional: %d\n",informe.aynC,informe.dni,informe.fec.dia,informe.fec.mes,informe.fec.anio,informe.aynP,informe.prof);
					b=1;
					break;
				}
				else
				fread(&informe,sizeof(inf),1,arch);
			}
			rewind(arch);
			if(b==0)
			{
				printf("\n\n<<< ERROR! Cliente no encontrado. >>>");
			}
			printf("\n\nDesea buscar otro Cliente? Ingrese 1=SI  2=NO, SALIR: ");
			scanf("%d",&opcion);
			while(opcion!=1 && opcion!=2)
			{
				printf("\n\n<<< ERROR! El numero ingresado no es valido. >>>\n\nIngrese 1=SI  2=NO, SALIR: ");
				scanf("%d",&opcion);
			}
		}while(opcion==1);	
	}
	fclose(arch);
}
