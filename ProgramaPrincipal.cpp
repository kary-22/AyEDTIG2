#include<stdio.h>
#include<stdlib.h>

main()
{
	int x;
	
	system("color 30");
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t:::::::::::   ::::         :::::::::::   ::::   ::::   :::::::::::    \n");
	printf("\t\t\t::::   ::::   ::::         ::::   ::::   ::::   ::::   ::::   ::::    \n");
	printf("\t\t\t::::   ::::   ::::         ::::   ::::   ::::   ::::   ::::   ::::    \n");
	printf("\t\t\t:::::::::::   ::::         ::::   ::::   :::::::::::   :::::::::::    \n");
	printf("\t\t\t::::   ::::   ::::::::::   :::::::::::   ::::   ::::   ::::   ::::    \n") ;
	printf("\n\t\t\t\t\t\t\t\t        CENTRO DE ESTETICA\n\n\n\n\n\n\n\n\n\n\n");
	system("pause");
	system("cls");
	
	do
	{
		system("color 03");
		printf("\n");
		printf("\t\t\t:::::::::::   ::::         :::::::::::   ::::   ::::   :::::::::::    \n");
		printf("\t\t\t::::   ::::   ::::         ::::   ::::   ::::   ::::   ::::   ::::    \n");
		printf("\t\t\t::::   ::::   ::::         ::::   ::::   ::::   ::::   ::::   ::::    \n");
		printf("\t\t\t:::::::::::   ::::         ::::   ::::   :::::::::::   :::::::::::    \n");
		printf("\t\t\t::::   ::::   ::::::::::   :::::::::::   ::::   ::::   ::::   ::::    \n") ;
		printf("\n\t\t\t\t\t\t\t\t        CENTRO DE ESTETICA\n\n\n"); 	
		printf("\n\n\t\t\t\t\t\t|* BIENVENIDO/A *|\n\n\n\t\t\t\t\tElija el modulo al que desea ingresar: \n");
		printf("\n\t\t\t\t\t1- MODULO ESPACIOS\n\t\t\t\t\t2- MODULO DEL RECEPCIONISTA\n\t\t\t\t\t3- MODULO ADMINISTRACION\n\t\t\t\t\t4- Salir\n\n\t\t\t\t\tSu eleccion: ");
		scanf("%d",&x);
		while(x<1 or x>4)
		{
			printf("\n\n\t\t\t\t\tERROR! La opcion seleccionada es incorrecta.\n\t\t\t\t\tElija un numero entre 1 y 4: ");
			scanf("%d",&x);
		}
		system("cls");
		
		switch(x)
		{
			case 1: system("ModuloEspacios.exe"); break;
			case 2: system("ModuloRecepcion.exe"); break;
			case 3: system("ModuloAdministracion.exe"); break;
			default: printf("\n\nFIN DEL PROGRAMA..."); break;
		}
	}while(x!=4);
}
