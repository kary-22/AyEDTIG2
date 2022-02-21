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

main()
{
	int b,x;
	char user1[32],password1[32];
	usuarios user;
	FILE *punU;
	
	do
	{
		printf("\n\n\n\t\t\t\t\t| *  INICIO DE SESION  * |\n\n\n\t\t\t\t\tUsuario: ");
		_flushall();
		gets(user1);
		printf("\n\t\t\t\t\tContraseña: ");
		_flushall();
		gets(password1);
		
		punU=fopen("Usuarios.dat","rb");
		if(punU==NULL)
		{
			printf("ERROR! EL ARCHIVO NO EXISTE\n");
			exit (EXIT_FAILURE);
		}
		else
		{
			fread(&user,sizeof(usuarios),1,punU);
			b=0;
			while(!feof(punU))
			{	
				if(strcmp(user1,user.usuario)==0 && strcmp(password1,user.contrasenia)==0)
				{
					printf("\n\n\n\n\n\t\t\t\t>>>   I N I C I A N D O    S E S I O N ...   <<<");//hace un ciclo infinito
					b=1;
					break;
				}
				else
				fread(&user,sizeof(usuarios),1,punU);				
			}
		}
		fclose(punU);
		if(b==0)
		{
			printf("\n\n<<< ERROR! Usuario y/o Contraseña invalidos.\nVerifique los datos ingresados. >>>");
			printf("\n\n\nDesea continuar?\n1=SI  2=NO, SALIR: ");
			scanf("%d",&x);
			while(x!=1 && x!=2)
			{
				printf("\n\n<<< ERROR! El numero ingresado es incorrecto. >>>\nIngrese 1=SI o 2=NO, SALIR.");
				scanf("%d",&x);
			}
		}
		else
		{
			printf("\n\n\n\n\n\n\n\n\n\n");
			exit(1);
		}
	}while(x!=2);
}
