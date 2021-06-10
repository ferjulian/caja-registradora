#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int calcular(int operando1, int operando2, char operador){
	
	int resultado = 0;
	
	switch(operador) {
    	case 's':
    		resultado=(operando1+operando2);
    	break;
    	case 'r':
    		resultado=(operando1-operando2);
    	break;
    	case 'm':
    		resultado=(operando1*operando2);
    	break;
		case 'd':
		    resultado=(operando1/operando2);
		break;

	}
	
	
	printf(" \n El resultado es %i \n", resultado);
	return resultado;
	
	
	
}



void carga (int operando1, int operando2, char operador, int *vc1, int *vc2, char *vc3,int i){
	
	*(vc1+i)= operando1;
	*(vc2+i) = operando2;
	*(vc3+i) = operador;
	
}


void mostrarDatos(int *vc1, int *vc2, char *vc3, int i){
	
	int x;
	
	for(x= 0; x<i; x++){
		
		printf(" \n \n Datos de la operacion %i", x);
		printf(" \n Primer Operando: %i", *(vc1+x));
		printf(" \n Segundo Operando: %i", *(vc2+x));
		printf(" \n Operador: %c", *(vc3+x));
	}
	
	char tipoOp;
	int contS=0;
	int contR=0;
	int contM=0;
	int contD=0;
	
	for(x=0; x<i ; x++){
		
		tipoOp = *(vc3+x);
		
	switch(tipoOp) {
    	case 's':
    		contS = contS +1;
    	break;
    	case 'r':
    		contR = contR +1;
    	break;
    	case 'm':
    		contM = contM +1;
    	break;
		case 'd':
		    contD = contD +1;
		break;

	}
		
	}
	
	printf("\n \n Cantidad de sumas:  %i", contS);
	printf("\n Cantidad de restas:  %i", contR);
	printf("\n Cantidad de multiplicaciones:  %i", contM);
	printf("\n Cantidad de divisiones:  %i", contD);
	
}


main(){
	
	char respuesta;
	int operando1;
	int operando2;
	char operador;
	int vc1[10]={0};
	int vc2[10]={0};
	char vc3[10]={'z'};
	int i = 0;
	
	
	
	
	while(respuesta != 'c'){
		
		/* Menú */
		
	printf("\t\t <Caja Registradora>");
	printf("\n \n 1. Si desea efectuar calculos ingrese (a) \n ");
	printf("2. Para emitir un informe de las operaciones realizadas ingrese (b) \n ");
	printf("3. Si desea salir ingrese (c) \n" );
	fflush(stdin);
	scanf("%c", &respuesta);
	
	/*Ingreso de datos*/
		
		switch(respuesta){
		case 'a':
	
	system("cls");
			
	printf(" \n Ingrese el primer numero: ");
	fflush(stdin);
	scanf("%i", &operando1);	
	
	printf(" \n Ingrese el segundo numero: ");
	fflush(stdin);
	scanf("%i", &operando2);	
	
	printf(" \n Seleccione la operacion:\n");
	printf("(s). Suma.\n");
	printf("(r). Resta.\n");
	printf("(m). Multiplicacion.\n");
	printf("(d). Division.\n");
	fflush(stdin);
	scanf("%c", &operador);
	
	
	/*Funcion calcular y carga*/
	
	calcular(operando1, operando2, operador);
	carga(operando1, operando2, operador, vc1, vc2, vc3, i);
	
	 i = i+1;
			
			break;
		case 'b':
			
		/*Informes*/
		
		mostrarDatos(vc1, vc2, vc3, i);
			
			break;
		case 'c':
			
			break;
		default:
			printf("error");
	}
		
	}
	

}
