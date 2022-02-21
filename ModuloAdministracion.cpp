#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>

struct usuarios
{
	char usuario[32],contrasenia[32],apynom[30];
	bool borrado;
};
struct fecha
{
	int dia,mes,anio;
};
struct rec
{
	char apynom[30];
	int dni,tel;
	bool borrado;
};
struct prof
{
	char apynom[30],tel[10];
	int idprof,dni;
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
	int idp,contador;
};

void registroP();
void registroR();
void atencion();
void ranking();

main()
{
	int opcion;
	
	do
	{
		system("color 09");
		printf("\n");
		printf("\t\t\t:::::::::::   ::::         :::::::::::   ::::   ::::   :::::::::::    \n");
		printf("\t\t\t::::   ::::   ::::         ::::   ::::   ::::   ::::   ::::   ::::    \n");
		printf("\t\t\t::::   ::::   ::::         ::::   ::::   ::::   ::::   ::::   ::::    \n");
		printf("\t\t\t:::::::::::   ::::         ::::   ::::   :::::::::::   :::::::::::    \n");
		printf("\t\t\t::::   ::::   ::::::::::   :::::::::::   ::::   ::::   ::::   ::::    \n") ;
		printf("\n\t\t\t\t\t\t\t\t        CENTRO DE ESTETICA\n\n\n");
		printf("\t\t\t\t\t|*** MODULO ADMINISTRACION ***|\n\t\t\t\t\t==============================\n\n");
		printf("\t\t\t\t\t1- Registrar Profesional\n\t\t\t\t\t2- Registrar Usuario Recepcionista\n\t\t\t\t\t3- Atenciones por Profesional\n\t\t\t\t\t4- Ranking de Atenciones por Profesionales\n\t\t\t\t\t5- Cerrar la aplicacion\n\n\t\t\t\t\tIngrese una opcion: ");
		scanf("%d",&opcion);
		while(opcion<1 or opcion>5)
		{
			printf("\n\n\t\t\t\t\tERROR! La opcion seleccionada es incorrecta.\n\t\t\t\t\tElija un numero entre 1 y 5: ");
			scanf("&d",&opcion);
		}
		system("cls");
		switch(opcion)
		{
			case 1:
				registroP();
				printf("\n\n");
				system("pause");
				system("cls"); break;
			case 2:
				registroR();
				printf("\n\n");
				system("pause");
				system("cls"); break;
			case 3:
				atencion();
				printf("\n\n");
				system("pause");
				system("cls"); break;
			case 4:
				ranking();
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
void registroP()
{
	FILE *punU,*punP,*Iden;
	int n,i,j,k,b,contM,contD,contm=0,ban=0;
	prof profesional;
	usuarios user;
	char v[32],c[32];
	id profID;
	
	punU=fopen("Usuarios.dat","a+b");
	punP=fopen("Profesionales.dat","a+b");
	//Iden=fopen("IDProfesionales.dat","a+b");
	
	printf("Cantidad de Profesionales a Registrar: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("\n\n* PROFESIONAL %d *\n-----------------\n\nApellido y Nombre: ",i+1);
		_flushall();
		gets(profesional.apynom);
		strupr(profesional.apynom);
		do
		{
			printf("ID Profesional numero: ");
			scanf("%d",&profesional.idprof);
			Iden=fopen("IDProfesionales.dat","a+b");
			fread(&profID,sizeof(id),1,Iden);
			b=0;
			while(!feof(Iden))
			{
				if(profesional.idprof==profID.idp)
				{
					printf("\n\n<<< ERROR! El ID ingresado ya existe para otro Profesional >>>\n\n");
					b=1;
					break;
				}	
				else
				fread(&profID,sizeof(id),1,Iden);
			}
			rewind(Iden);
		}while(b==1);
		profID.idp=profesional.idprof;
		fwrite(&profID,sizeof(id),1,Iden);
		printf("DNI numero: ");
		scanf("%d",&profesional.dni);
		printf("Telefono numero: ");
		_flushall();
		gets(profesional.tel);
		profesional.borrado=false;
		fwrite(&profesional,sizeof(prof),1,punP);
		printf("\n\n");
		system("pause");
		system("cls");
		printf("* ALTA DE USUARIO Y CONTRASEÑA *\n--------------------------------\n\n");
		strcpy(profesional.apynom,user.apynom);
			
		do
		{
			printf("CONFORMACION DE USUARIO.\n\n\tREQUISITOS:\n\t- Contener entre 6 y 10 Caracteres (Letras, Numeros y Simbolos permitidos {+,-,/,*,?,¿,!,¡}).\n\t- Comenzar con una letra MINUSCULA.\n\t- Tener al menos 2 MAYUSCULAS.\n\t- Tener como maximo 3 DIGITOS.");
			_flushall();
			printf("\n\n\tINGRESE UN USUARIO: ");
			gets(v);
			contM=0;
			contD=0;
			fread(&user,sizeof(usuarios),1,punU);
			ban=0;
			while(!feof(punU))
			{
				if(strcmp(v,user.usuario)==0)
				{
					printf("\n\n<<< ERROR! El Usuario ingresado ya existe.  Pruebe otras alternativas >>>\n\n");
					ban=1;
				}
				fread(&user,sizeof(usuarios),1,punU);
			}
			rewind(punU);
			if(strlen(v)<6 || strlen(v)>10)
			{
				printf("\n\n<<< ERROR! El Usuario debe contener entre 6 y 10 caracteres >>>\n\n");
				ban=1;
			}
			else
			{
				for(j=0;j<strlen(v);j++)
				{
					if(j==0)
					{
						if(isalpha(v[j]))
						{
							
							if(isupper(v[j]))
							{
								printf("\n\n<<< ERROR! El Usuario debe comenzar con una Letra Minuscula >>>\n\n");
								ban=1;
							}
						}
						else
						{
							printf("\n\n<<< ERROR! El Usuario debe comenzar con una Letra (Minuscula) >>>\n\n");
							ban=1;
						}
					}
					else
					{
						if(isalpha(v[j]) && isupper(v[j]))
						contM++;
						else
						{
							if(isdigit(v[j]))
							contD++;
							/*else
							{
								//if((strcmp(v[j],"+")!=0) && (strcmp(v[j],"-")!=0) && (strcmp(v[j],"/")!=0) && (strcmp(v[j],"*")!=0) && (strcmp(v[j],"?")!=0) && (strcmp(v[j],"¿")!=0) && (strcmp(v[j],"!")!=0) && (strcmp(v[j],"¡")!=0));
								if(v[j]!='+' && v[j]!='-' && v[j]!='/' && v[j]!='*' && v[j]!='?' && v[j]!='¿' && v[j]!='!' && v[j]!='¡')
								{
									printf("\n\n<<< ERROR! Simbolos permitidos {+,-,/,*,?,¿,!,¡} %d>>>\n\n",j+1);
									ban=1;
								}
							}*/
						}	
					}
				}
			}
			if(contM<2)
			{
				printf("\n\n<<< ERROR! El Usuario debe contener al menos 2 Letras Mayusculas >>>\n\n");
				ban=1;
			}
			if(contD>3)
			{
				printf("\n\n<<< ERROR! El Usuario debe contener como maximo 3 Digitos >>>\n\n");
				ban=1;
			}					
		}while(ban==1);
		strcpy(user.usuario,v);
		system("cls");
		
		do
		{
			printf("\n\n\nCONFORMACION DE CONTRASEÑA.\n\n\tREQUISITOS:\n\t- Contener entre 6 y 32 Caracteres Alfanumericos.\n\t- No podra contener SIGNOS de Puntuacion, ni Acentos, ni Espacios\n\t- Tener al menos una letra MINUSCULA, una letra MAYUSCULA y un NUMERO.\n\t- No tener mas de 3 NUMEROS consecutivos.\n\t- No tener 2 o mas LETRAS consecutivas (alfabeticamente).");
			_flushall();
			printf("\n\n\tINGRESE UNA CONTRASEÑA: ");
			gets(user.contrasenia);
			ban=0;
			contM=0;
			contD=0;
			if(strlen(user.contrasenia)<6 || strlen(user.contrasenia)>32)
			{
				printf("\n\n<<< ERROR! La Contraseña debe contener entre 6 y 32 caracteres >>>\n\n");
				ban=1;
			}
			else
			{
				strcpy(c,user.contrasenia);
				for(k=0;k<strlen(user.contrasenia);k++)
				{
					if(isalpha(c[k]) && isupper(c[k]))
					contM++;
					else
					{
						if(isalpha(c[k]) && islower(c[k]))
						contm++;
						else
						{
							if(isdigit(c[k]))
							contD++;
							else
							{
								if(ispunct(c[k]) || isspace(c[k]));//ver para buscar acentos tambien
								{
									printf("\n\n<<< ERROR! La Contraseña No podra contener SIGNOS de Puntuacion, ni Acentos, ni Espacios >>>\n\n");
									ban=1;
								}
							}
						}	
					}
				}
			}
			if(contM<1 || contm<1 || contD<1)
			{
				printf("\n\n<<< ERROR! La Contraseña debe contener al menos 1 Letra Mayuscula, 1 Letra Minuscula y 1 Numero >>>\n\n");
				ban=1;
			}
		}while(ban==1);
		user.borrado=false;
		fwrite(&user,sizeof(usuarios),1,punU);
		system("cls");
	}
	fclose(punP);
	fclose(punU);
	fclose(Iden);
}
void registroR()
{
	FILE *punU,*punR;
	int n,i,j,k,contM=0,contD=0,contm=0,ban;
	rec recep;
	usuarios user;
	char v[32],c[32];
	
	punU=fopen("Usuarios.dat","a+b");
	punR=fopen("Recepcionistas.dat","a+b");
	
	printf("Cantidad de Recepcionistas a Registrar: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\n\n* RECEPCIONISTA %d *\n-------------------\n\nApellido y Nombre: ",i+1);
		_flushall();
		gets(recep.apynom);
		strupr(recep.apynom);
		printf("DNI numero: ");
		scanf("%d",&recep.dni);
		printf("Telefono numero: ");
		scanf("%d",&recep.tel);
		recep.borrado=false;
		fwrite(&recep,sizeof(rec),1,punR);
		printf("\n\n");
		system("pause");
		system("cls");
		printf("* ALTA DE USUARIO Y CONTRASEÑA *\n--------------------------------\n\n");
		strcpy(recep.apynom,user.apynom);
		do
		{
			printf("CONFORMACION DE USUARIO.\n\n\tREQUISITOS:\n\t- Contener entre 6 y 10 Caracteres (Letras, Numeros y Simbolos permitidos {+,-,/,*,?,¿,!,¡}).\n\t- Comenzar con una letra MINUSCULA.\n\t- Tener al menos 2 MAYUSCULAS.\n\t- Tener como maximo 3 DIGITOS.");
			_flushall();
			printf("\n\n\tINGRESE UN USUARIO: ");
			gets(user.usuario);
			ban=0;
			contM=0;
			contD=0;
			if(strlen(user.usuario)<6 || strlen(user.usuario)>10)
			{
				printf("\n\n<<< ERROR! El Usuario debe contener entre 6 y 10 caracteres >>>\n\n");
				ban=1;
			}
			else
			{
				strcpy(v,user.usuario);
				for(j=0;j<strlen(user.usuario);j++)
				{
					if(j==0)
					{
						if(isalpha(v[j]))
						{
							
							if(isupper(v[j]))
							{
								printf("\n\n<<< ERROR! El Usuario debe comenzar con una Letra Minuscula >>>\n\n");
								ban=1;
							}
						}
						else
						{
							printf("\n\n<<< ERROR! El Usuario debe comenzar con una Letra (Minuscula) >>>\n\n");
							ban=1;
						}
					}
					else
					{
						if(isalpha(v[j]) && isupper(v[j]))
						contM++;
						else
						{
							if(isdigit(v[j]))
							contD++;
							/*else
							{
								if((strcmp(v[j],'+')!=0) && (strcmp(v[j],'-')!=0) && (strcmp(v[j],'/')!=0) && (strcmp(v[j],'*')!=0) && (strcmp(v[j],'?')!=0) && (strcmp(v[j],'¿')!=0) && (strcmp(v[j],'!')!=0) && (strcmp(v[j],'¡')!=0));
								{
									printf("\n\n<<< ERROR! Simbolos permitidos {+,-,/,*,?,¿,!,¡} >>>\n\n");
									ban=1;
								}
							}*/
						}	
					}
				}
			}
			if(contM<2)
			{
				printf("\n\n<<< ERROR! El Usuario debe contener al menos 2 Letras Mayusculas >>>\n\n");
				ban=1;
			}
			if(contD>3)
			{
				printf("\n\n<<< ERROR! El Usuario debe contener como maximo 3 Digitos >>>\n\n");
				ban=1;
			}					
		}while(ban==1);
		system("cls");
		
		do
		{
			printf("\n\n\nCONFORMACION DE CONTRASEÑA.\n\n\tREQUISITOS:\n\t- Contener entre 6 y 32 Caracteres Alfanumericos.\n\t- No podra contener SIGNOS de Puntuacion, ni Acentos, ni Espacios\n\t- Tener al menos una letra MINUSCULA, una letra MAYUSCULA y un NUMERO.\n\t- No tener mas de 3 NUMEROS consecutivos.\n\t- No tener 2 o mas LETRAS consecutivas (alfabeticamente).");
			_flushall();
			printf("\n\n\tINGRESE UNA CONTRASEÑA: ");
			gets(user.contrasenia);
			ban=0;
			contM=0;
			contD=0;
			if(strlen(user.contrasenia)<6 || strlen(user.contrasenia)>32)
			{
				printf("\n\n<<< ERROR! La Contraseña debe contener entre 6 y 32 caracteres >>>\n\n");
				ban=1;
			}
			else
			{
				strcpy(c,user.contrasenia);
				for(k=0;k<strlen(user.contrasenia);k++)
				{
					if(isalpha(c[k]) && isupper(c[k]))
					contM++;
					else
					{
						if(isalpha(c[k]) && islower(c[k]))
						contm++;
						else
						{
							if(isdigit(c[k]))
							contD++;
							else
							{
								if(ispunct(c[k]) || isspace(c[k]));
								{
									printf("\n\n<<< ERROR! La Contraseña No podra contener SIGNOS de Puntuacion, ni Acentos, ni Espacios >>>\n\n");
									ban=1;
								}
							}
						}	
					}
				}
			}
			if(contM<1 || contm<1 || contD<1)
			{
				printf("\n\n<<< ERROR! La Contraseña debe contener al menos 1 Letra Mayuscula, 1 Letra Minuscula y 1 Numero >>>\n\n");
				ban=1;
			}
		}while(ban==1);
		user.borrado=false;
		fwrite(&user,sizeof(usuarios),1,punU);
		system("cls");
	}
	fclose(punR);
	fclose(punU);
}
void atencion()
{
	inf informe;
	FILE *arch;
	
	arch=fopen("Informe.dat","rb");
	if(arch==NULL)
	{
		printf("ERROR! EL ARCHIVO NO EXSTE\n");
		exit (EXIT_FAILURE);
	}
	else
	{
		printf("|* INFORME DE ATENCION POR PROFESIONAL *|\n-----------------------------------------\n");
		fread(&informe,sizeof(inf),1,arch);
		while(!feof(arch))
		{
			printf("\n\nID Profesional: %d\n\t\tDNI Cliente: %d\n\t\tFecha de Atencion: %d/%d/%d",informe.prof,informe.dni,informe.fec.dia,informe.fec.mes,informe.fec.anio);
			
			fread(&informe,sizeof(inf),1,arch);
		}
	}	
	fclose(arch);
}
void ranking()
{
	id profID;
	FILE *Iden;
	int i=0,x,b,Id[50],c[50],auxId,auxc;
	
	Iden=fopen("IDProfesionales.dat","rb");
	if(Iden==NULL)
	{
		printf("ERROR! EL ARCHIVO NO EXSTE\n");
		exit (EXIT_FAILURE);
	}
	else
	{
		fread(&profID,sizeof(id),1,Iden);
		while(!feof(Iden))
		{
			//printf("\n\nid profesional: %d\ncontador: %d\n",profID.idp,profID.contador);
			Id[i]=profID.idp;
			c[i]=profID.contador;//corregir el contador
			i++;
			fread(&profID,sizeof(id),1,Iden);
		}
		x=i;
	}
	fclose(Iden);
	do
	{
		b=0;
		for(i=0;i<x-1;i++)
		{
			if(c[i]<c[i+1])
			{
				auxId=Id[i];
				Id[i]=Id[i+1];
				Id[i+1]=auxId;
				b=1;
			}
		}
	}while (b==1);
	for(i=0;i<1;i++)
	{
		printf("|* BONO MENSUAL *|\n\nProfesional: %d\nCantidad de Turnos Atendidos: %d",Id[i],c[i]);
	}
}
