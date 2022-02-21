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
struct id
{
	int idp,contador=0;
};

void lista(int &paciente);
void tratamiento(int paciente);

main()
{
	int opcion,paciente;
	
	do
	{
		system("color 05");
		printf("\n");
		printf("\t\t\t:::::::::::   ::::         :::::::::::   ::::   ::::   :::::::::::    \n");
		printf("\t\t\t::::   ::::   ::::         ::::   ::::   ::::   ::::   ::::   ::::    \n");
		printf("\t\t\t::::   ::::   ::::         ::::   ::::   ::::   ::::   ::::   ::::    \n");
		printf("\t\t\t:::::::::::   ::::         ::::   ::::   :::::::::::   :::::::::::    \n");
		printf("\t\t\t::::   ::::   ::::::::::   :::::::::::   ::::   ::::   ::::   ::::    \n") ;
		printf("\n\t\t\t\t\t\t\t\t        CENTRO DE ESTETICA\n\n\n");
		printf("\t\t\t\t\t|*** MODULO ESPACIOS ***|\n\t\t\t\t\t========================\n\n");
		printf("\t\t\t\t\t1- Iniciar Sesion\n\t\t\t\t\t2- Visualizar Lista de Espera de Turnos (informe)\n\t\t\t\t\t3- Registrar Evolucion del tratamiento\n\t\t\t\t\t4- Cerrar la aplicacion\n\n\t\t\t\t\tIngrese una opcion: ");
		scanf("%d",&opcion);
		while(opcion<1 or opcion>4)
		{
			printf("\n\n\t\t\t\t\tERROR! La opcion seleccionada es incorrecta.\n\t\t\t\t\tElija un numero entre 1 y 4: ");
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
				lista(paciente);
				printf("\n\n");
				system("pause");
				system("cls"); break;
			case 3:
				tratamiento(paciente);
				printf("\n\n");
				system("pause");
				system("cls"); break;
			default: printf("\n\nFIN DEL PROGRAMA...");
				printf("\n\n");
				system("pause");
				system("cls"); break;
		}
	}while(opcion!=4);
}
void lista(int &paciente)
{
	FILE *punL,*Iden,*punT,*arch,*punP;
	lis list;
	turnos Turno;
	int x,dni,p,b,opcion,c=0;
	id profID;
	inf informe;
	prof profesional;
	
	punL=fopen("lista.dat","a+b");
	Iden=fopen("IDProfesionales.dat","a+b");
	punT=fopen("Turnos.dat","a+b");
	arch=fopen("Informe.dat","a+b");
	punP=fopen("Profesionales.dat","a+b");
	
	fread(&list,sizeof(lis),1,punL);
	while(!feof(punL))
	{
		if(list.borrado==false)
		{
			printf("\nID Profesional. %d\n\t\tApellido y nombre: %s\n\t\tDNI numero: %d",list.prof,list.paciente,list.dni);
		}
		fread(&list,sizeof(lis),1,punL);
	}
	rewind(punL);
	
	printf("\n\nDesea atender un Turno Programado? 1=SI  2=NO: ");
	scanf("%d",&x);
	while(x!=1 && x!=2)
	{
		printf("\n\nERROR! La opcion seleccionada es incorrecta.\nIngrese 1=SI  2=NO: ");
		scanf("%d",&x);
	}

	if(x==1)
	{
		do
		{
			printf("\n\nINGRESE DNI DEL CLIENTE QUE DESEA ATENDER: ");
			scanf("%d",&dni);
			printf("\n\nINGRESE SU ID PROFESIONAL: ");
			scanf("%d",&p);
			rewind(punL);
			fread(&list,sizeof(lis),1,punL);
			b=0;
			while(!feof(punL)&& b==0)
			{
				if(dni==list.dni && list.borrado==false && p==list.prof)
				{
					list.borrado=true;//verificar porque no se borra de la lista
					fseek(punL,- sizeof(lis),SEEK_CUR);
					fwrite(&list,sizeof(lis),1,punL);
					printf("\nCLIENTE MARCADO COMO 'ATENDIDO'");
					paciente=dni;
					b=1;
					rewind(Iden);
					fread(&profID,sizeof(id),1,Iden);
					while(!feof(Iden))
					{
						if(list.prof==profID.idp)
						{
							//printf("\n\nContador antes: %d",profID.contador);
							profID.contador++;//el contador aparece en 0 en los demas programas
							fwrite(&profID,sizeof(id),1,Iden);
							//printf("\n\nContador despues: %d",profID.contador);
							break;
						}
						else
						fread(&profID,sizeof(id),1,Iden);
					}
					rewind(Iden);
					
					fread(&Turno,sizeof(turnos),1,punT);
					while(!feof(punT))
					{
						if(paciente==Turno.dniCliente)
						{
							Turno.borrado=true;
							fseek(punT,- sizeof(turnos),SEEK_CUR);
							fwrite(&Turno,sizeof(turnos),1,punT);
							break;
						}
						else
						fread(&Turno,sizeof(turnos),1,punT);
					}
					rewind(punT);
					
					fread(&profesional,sizeof(prof),1,punP);
					while(!feof(punP))
					{
						if(list.prof==profesional.idprof)
						{
							strcpy(informe.aynP,profesional.apynom);
							strcpy(informe.aynC,list.paciente);
							informe.dni=paciente;
							informe.prof=list.prof;
							informe.fec=list.fec;
							fwrite(&informe,sizeof(inf),1,arch);
							break;
						}
						else
						fread(&profesional,sizeof(prof),1,punP);
					}
					rewind(punP);
					rewind(arch);
				}
				else
				fread(&list,sizeof(lis),1,punL);
			}
			rewind(punL);
			
			if(b==0)
			printf("\nERROR! DNI no encontrado.");
		}while(b==0);	
	}
	fclose(punL);
	fclose(Iden);
	fclose(punT);
	fclose(arch);
	fclose(punP);
}
void tratamiento(int paciente)
{
	int i;
	cliente Clientes;
	FILE *punC;
	
	_flushall();
	printf("EVOLUCION DEL TRATAMIENTO\n-------------------------\n\n");
	punC=fopen("Clientes.dat","a+b"); 
	
	fread(&Clientes,sizeof(cliente),1,punC);
	while(!feof(punC))
	{
		if(paciente==Clientes.dniCliente)
		{
			printf("\nCLIENTE: %s\nDNI num: %d\nDOMICILIO: %s\nEDAD: %d años\n\nDatos del Tratamiento: ",Clientes.apynom,Clientes.dniCliente,Clientes.dom,Clientes.edad);
			_flushall();
			gets(Clientes.detalle);
			fwrite(&Clientes,sizeof(cliente),1,punC);
			break;
		}
		else
		fread(&Clientes,sizeof(cliente),1,punC);
	}
	fclose(punC);
}
