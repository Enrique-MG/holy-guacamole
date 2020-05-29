#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

//ESTRUCTURA TRIVIAL
typedef struct
{
	char pregunta[80];
	char respuesta[25];
}inicio;

//FUNCIONES GLOBALES:
int imprime(char frase[], int s, int e); //funcion imprimir frase con animacion y dar s saltos de linea y e espacios
int numal(int num1,int num2); //Genera numeros aleatorios 
void semilla(); //Genera semilla

int hundirlaflota(int *tickets);

int instrucciones();

  
void main ()
{
FILE *us,*aux;
int salida=0,juego=0,administrador=0,tickets,punt,bandera;
char basura,admin[14],usuario[25],nombre[25],kudu[3];

imprime("",1,2);
imprime("Por favor, indica si eres jugador o administrador:",1,2);
scanf("%s",admin);
_strupr(admin);
system("cls");
while(strcmp(admin,"ADMINISTRADOR")!=0 && strcmp(admin,"JUGADOR")!=0)
{
	imprime("",1,2);
	imprime("Recuerda que tienes que escribir administrador o jugador",1,2);
	scanf("%s",admin);
	_strupr(admin);
	system("cls");
}
if(strcmp(admin,"ADMINISTRADOR")==0)
{
	while(administrador!=3)
	{
	imprime("",1,2);
  	imprime("BIENVENIDO ADMINISTRADOR",3,3);
  	imprime("Pulsa:",2,3);
  	imprime("1: Para aceder a la tienda",2,3);
  	imprime("2: Para acceder a la lista de animales",2,3);
  	imprime("3: Para salir del programa",2,3);
  	scanf(" %d", &administrador);
    scanf("%c",&basura);
    
    switch(administrador)
    {
    	case 1:
    		system("cls");
    		imprime("Al meterte en esta opcion, se borrara la informacion almacenada previamente, estas seguro?",1,0);
			scanf("%s",kudu);
			_strupr(kudu);
			while(strcmp(kudu,"SI")!=0 && strcmp(kudu,"NO")!=0)
			{	
				imprime("No me has contestado a la pregunta",2,0);
				imprime("Al meterte en esta opcion, se borrara la informacion almacenada previamente, estas seguro?",1,0);
				scanf("%s",kudu);
			}
			if(strcmp(kudu,"SI")==0){
    	    	listatienda();
    			}	
    	    break;
    	case 2:
    		system("cls");
    		imprime("Al meterte en esta opcion, se borrara la informacion almacenada previamente, estas seguro?",1,0);
			scanf("%s",kudu);
			_strupr(kudu);
			while(strcmp(kudu,"SI")!=0 && strcmp(kudu,"NO")!=0)
			{	
			imprime("No me has contestado a la pregunta",2,0);
			imprime("Al meterte en esta opcion, se borrara la informacion almacenada previamente, estas seguro?",1,0);
			scanf("%s",kudu);
			}
			if(strcmp(kudu,"SI")==0){
    	    	listanimales();
    		}
    	    break;
    	case 3:
    		imprime("",2,3);
	        imprime("Has cerrado el programa, hasta la proxima!",1,0);
            break;
        default:
   	        imprime("",2,6);
            imprime("ERROR: OPCION NO VALIDA",1,0);
            Sleep(700);
            system("cls");
            break;
	}
    }
}
else if(strcmp(admin,"JUGADOR")==0)
{
	imprime("",1,2);
	imprime("Como te llamas?",1,2);
	scanf("%c",&basura);
	gets(usuario);
	_strupr(usuario);
	us = fopen("usuarios.txt", "r"); 
	if (us == NULL) 
	{ 
	us = fopen("usuarios.txt", "w");
	fclose(us); 
	} 
	 else
	 {
	 	bandera=1;
	 	while(bandera==1&&fscanf(us,"%[^;];%d",nombre,&tickets)!=EOF)
	 	{
	 		if(strcmp(nombre,usuario)==0)
	 		{
	 			bandera=0;	
			}
		 }
		 fclose(us);
		 if(bandera==1)
		 {
		 	imprime("Es un nuevo usuario, bienvenido",1,2);
		 	imprime("Tu nueva puntuacion es 0",1,2);
		 	tickets=0;
		 }
		 else
		 {
		 	system("cls");
		 	imprime("",1,2);
		 	imprime("Bienvenido de nuevo ",0,0);
		 	printf("%s",usuario);
		 	imprime(",sus tickets son ",0,0);
		 	printf("%d\n\n",tickets);
		 	Sleep(2000);
		 }
	 }

    while (juego!=5) //preguntar al jugador a que juego quiere jugar
{
	system("cls");
  	imprime("",1,2);
  	imprime("BIENVENIDO ",0,0);
  	printf("%s!",usuario);
  	imprime("",3,3);
  	imprime("Pulsa:",2,3);
  	imprime("1: Para jugar a Cifras y Letras",2,3);
  	imprime("2: Para jugar a Hundir La Flota",2,3);
  	imprime("3: Para jugar al Trivial",2,3);
  	imprime("4: Para abrir la tienda",2,3);
  	imprime("5: Para salir del programa",2,3);
    scanf(" %d", &juego);
    scanf("%c",&basura);
     
  switch (juego)
{
	
	case 1: //JUEGO 1
	do
	{
        salida=cifrasyletras(&tickets);
        
	}while(salida==0);
    break;

    case 2: //JUEGO HUNDIR LA FLOTA
    do
	{
        salida=hundirlaflota(&tickets);
   	}while(salida==0);
	break;

    case 3: //JUEGO TRIVIAL
    do
	{
        salida=trivial(&tickets);
	}while(salida==0);
    break;
    
    case 4: //TIENDA
    tienda(&tickets);
    break;
   
    case 5:
   	imprime("",2,3);
	imprime("Has cerrado el programa, hasta la proxima!",1,0);
    break;
    
   default:
   	imprime("",2,6);
    imprime("ERROR: JUEGO NO VALIDO",1,0);
    Sleep(700);
    system("cls");
    break;
}
}
us = fopen("usuarios.txt", "r"); 
aux= fopen("auxiliar.txt", "w");
bandera=0;
while(fscanf(us,"%[^;];%d",nombre,&punt)!=EOF)
{
	if(strcmp(nombre,usuario)==0)
	{
	 	bandera=1;
	 	punt=tickets;
	}
	fprintf(aux,"%s;%d",nombre,punt);
}
if(bandera==0)
fprintf(aux,"%s;%d",usuario,tickets);
fclose(us);
fclose(aux);
remove("usuarios.txt"); // Eliminamos el archivo
rename("auxiliar.txt","usuarios.txt");// Renombramos el archivo
}
}



//------------------------------------HUNDIR LA FLOTA: JUEGO 2------------------------------------------------------------------------------------	

int hundirlaflota(int *tickets)
{
//-----------------------VARIABLES-----------------------------------------------------------------
	int fila,columna;//dependiendo del momento, estas variables se referiran a un punto en una determinada matriz
    int tablerojug[6][6]; //matriz que representa los disparos efectuados por el jugador
    int tablerocons[6][6]; //matriz que representa los disparos efectuados por la consola
    int matrizcons[6][6];//matriz que representa los barcos del cpu
	int matrizjug[6][6];//matriz que representa los barcos del jugador
	int barcojug=1; //contador para que el jugador vaya colocando sus 4 barcos
	int i,j,salida=0;//variables contador auxiliares
	int colocacionjug=0;//si la colocacion de los barcos del jugador ha sido un éxito, vale 1
	int fila1, fila2, columna1, columna2;//variables que almacenan los datos introducidos por el jugador para colocar sus barcos
	int ganador=0;//si vale 1 se acaba el juego
	int barcoscons=4, barcosjug=4;//numero de barcos que tiene la consola y el jugador
	int submarinocons=2, acorazadocons=3, destructorcons=4, portavionescons=5;//barcos de la consola y el espacio que ocupan
	int submarinojug=2,  acorazadojug=3, destructorjug=4, portavionesjug=5;//barcos del jugador y el espacio que ocupan
	int tocadojug, tocadocons;//Si vale 1, un barco ha sido tocado
	int numdisparos=0;//contador de numero de disparos que realiza el jugador
	int formatocoord=1,formatocoord2=1;//variable auxiliar para comprobar que las coordenadas introducidas tienen un formato correcto
	char coordport[2], coordport2[2];//vectores para las coordenadas de los barcos
	int punts,turra;//obtiene la puntuacion para gastar en la tienda 
	
//-----------------------------------------------FUNCIONES-------------------------------------------------------------------------------------------------------	
//Nota:en este juego las funciones modifican muchos datos entre en si, por lo que para optimizar codigo se colocan todas en hundirlaflota()

void animaciondisparo() //Animacion de disparo
{
	int i,j;
	printf("\n");
	
	for(i=3;i>0;i--)
	{
		printf("%i",i);
		Sleep(400);
			for (j=3;j>0;j--)
			{
				printf(" . ");
				Sleep(200);
			}
	}
	imprime("FUEGO!!",3,0);
}

int puntuacion(int n) //puntuacion obtenida si ganas
{
	if (n>0 && n<20)//100 puntos si eleminas la flota enemiga con menos de 20 disparos
	{
		return 100;//80 si esta entre 20 y 24
	}
	if (n>19 && n< 25)//60 si es mayor de 24
	{
		return 80;
	}
	if (n>24)
	{
		return 60;
	}
}
int generarbarcojug(int f1, int f2, int c1,int c2, int mat[6][6], int n) //si el barco introducido por el usuario no se choca con otros o se sale del tablero, construye la matriz
{
	
	int okupa=0; //variable que detecta si ya hay un barco en esa posicion
	int tipobarco=0, i;
	okupa=0;
	
	if(f1==f2)
	{
		if((c1<c2)&&((c2+1)-c1==n)) //El barco se construye en direccion a la derecha	
			if(c1 + n <= 6)
  			{ 
	  			for(i=c1;i<=(c1+n-1);i++)  	      			
	      				if(mat[f1][i]!=0) //si en esa posicion la matriz ya esta ocupada, vuelve a pedirle los datos al jugador
	    					okupa++;	      			
	   			if(okupa == 0)          //si esta libre, construye el barco
	  			{
  	  				for(i=c1;i<=(c1+n-1);i++)  
	    				mat[f1][i]= n;
	      			tipobarco++;
	      			return tipobarco;
	  		 	}
			}			
				
		if(c1>2&&((c1+1-c2)==n)) //El barco se construye en direccion a la izquierda		
			if(c1 + 1 >= n)
  			{ 
	 			for(i=c1;i>=(c1-n+1);i--)  	      		
	      			if(mat[f1][i]!=0)
	    				okupa++;	      		
	   			if(okupa == 0)
	   			{
					for(i=c1;i>=(c1-n+1);i--)  
	    				mat[f1][i]=n;
	      			tipobarco++;
	      			return tipobarco;
				}
			}								
	}
				
	if(c1==c2)
	{
		if((f1>f2)&&((f1+1-f2)==n)) //El barco se construye en direccion arriba		
			 if(f1 >= (n-1))
  			{ 
	  			for(i=f1;i>=(f1-n+1);i--)  	      		
	      			if(mat[i][c1]!=0)
	    				okupa++;	      		
	    		if(okupa == 0)
	  			{
  	  				for(i=f1;i>=(f1-n+1);i--)  
	    				mat[i][c1]=n;
	   				tipobarco++;
	      			return tipobarco;
				}
			}
		if((f1<f2)&&((f2-f1+1)==n)) //El barco se construye en direccion abajo		
			if(f1+n<=6)
  			{ 
				for(i=f1;i<=f1+n-1;i++)
					if(mat[i][c1]!=0)
	    				okupa++;
	  			if(okupa == 0)
	   			{
  	  				for(i=f1;i<=f1+n-1;i++)  
	    				mat[i][c1]=n;
	      			tipobarco++;
	      			return tipobarco;
	   			}
			}		
	}
}

int comprobarformatocoord(char coord[2]) //Comprueba que las coordenadas introducidas por el usuario estan en un formato valido
{
	if (coord[0]=='a'||coord[0]=='A') //asigna la letra introducida por el usuario a un numero (fila)
		fila=0;
	else
	{
		if (coord[0]=='b'||coord[0]=='B')
			fila=1;
		else
		{
			if (coord[0]=='c'||coord[0]=='C')
				fila=2;
			else
			{
				if (coord[0]=='d'||coord[0]=='D')
					fila=3;
				else
				{
					if (coord[0]=='e'||coord[0]=='E')
						fila=4;
					else
					{
						if (coord[0]=='f'||coord[0]=='F')
							fila=5;	
						else
							return 0;
					}
				}	
			}
		}
	}

	if ((coord[1]-1)>='0' && (coord[1]-1)<='5') //comprueba que la columna esta entre 1 y 6
	{
		columna=coord[1]-'1';
		return 1;
	}
	else
		return 0;
}

int generarbarco(int n, int mat[6][6], int barco) //Genera un barco de tamaño n aleatorio en una matriz, no se choca con otros barcos, no se sale del tablero y rellena la matriz
{
	int fila, colum, dir, exito = 0, okupa, i; 
	//generarbarco(5, matrizcons, 5);
	while(exito==0)
	{
		fila = rand() % (5+1); //Genera las coordenadas aleatorias
		colum = rand() % (5+1);
		dir = rand () % (4-1+1) + 1;
		okupa=0;
 
	if(dir==1)							//direccion arriba	
  		if(fila >= (n-1))
  		{ 
			for(i=fila;i>=(fila-n+1);i--)  	      	
	      		if(mat[i][colum]!=0)	    		
	    			okupa++;					      	
	    	if(okupa == 0)
	   		{
  	  			for(i=fila;i>=(fila-n+1);i--)  
	      			mat[i][colum]=barco;
	      		exito++;
	   		}
		}

	if(dir==2)							//direccion derecha
		if(colum + n <= 6)
  		{ 
	 		for(i=colum;i<=(colum+n-1);i++)  	      	
	      		if(mat[fila][i]!=0)	    	
	    			okupa++;					      	
	   		if(okupa == 0)
	   		{
  	  			for(i=colum;i<=(colum+n-1);i++)  	      		
	    			mat[fila][i]=barco;	      		
	   			exito++;
	    	}
		}

	if(dir==3)							//direccion abajo
		if(fila + n <= 6)
  		{ 
	    	for(i=fila;i<=fila+n-1;i++)  			
	    		if(mat[i][colum]!=0)	    		
	    			okupa++;					   	    
	    	if(okupa == 0)
	   		{
  	  			for(i=fila;i<=fila+n-1;i++)  	      		
	    			mat[i][colum]=barco;	      		
	   			exito++;
	   		}
		}

	if(dir==4)							//direccion izquierda
		if(colum + 1 >= n)
  		{ 
	  		for(i=colum;i>=(colum-n+1);i--)  	      	
	      		if(mat[fila][i]!=0)	    			
	    			okupa++;						      	
	    if(okupa == 0)
	   		{
				for(i=colum;i>=(colum-n+1);i--)  	      			
	    			mat[fila][i]=barco;	      			
	   			exito++;
	   		}
		}
	}
}
int imprimematriz(int mat[6][6]) //Imprime una matriz de tal forma que es legible al usuario y se muestra como un tablero
{
    int i;
    
    printf("   ");
    for(i=1;i<=6;i++)
		printf("   %i ",i);
	printf("\n\n");
	printf(" A ");
	for(i=0;i<6;i++)  
	    printf("   %i ",mat[0][i]);
	printf("\n\n B ");
	for(i=0;i<6;i++)  
	    printf("   %i ",mat[1][i]);
	printf("\n\n C ");
	for(i=0;i<6;i++)  
	   	printf("   %i ",mat[2][i]);
	printf("\n\n D ");
	for(i=0;i<6;i++)  
	   	printf("   %i ",mat[3][i]);
	printf("\n\n E ");
	for(i=0;i<6;i++)  
	   	printf("   %i ",mat[4][i]);
	printf("\n\n F ");
	for(i=0;i<6;i++)  
	    printf("   %i ",mat[5][i]);
}
int imprimematrizchar(int mat[6][6]){  //Imprime los caracteres de una matriz de tal forma que es legible al usuario y se muestra como un tablero
    int i;
    printf("   ");
    for(i=1;i<=6;i++)
		printf("   %i ",i);
	printf("\n\n");
	printf(" A ");
	for(i=0;i<6;i++)  
	    printf("   %c ",mat[0][i]);
	printf("\n\n B ");
	for(i=0;i<6;i++)  
	    printf("   %c ",mat[1][i]);
	printf("\n\n C ");
	for(i=0;i<6;i++)  
	    printf("   %c ",mat[2][i]);
	printf("\n\n D ");
	for(i=0;i<6;i++)  
	    printf("   %c ",mat[3][i]);
	printf("\n\n E ");
	for(i=0;i<6;i++)  
	    printf("   %c ",mat[4][i]);
	printf("\n\n F ");
	for(i=0;i<6;i++)  
	    printf("   %c ",mat[5][i]);
	      	
}

int disparojug() //Funcion disparo de jugador
{
	char coorddisp[2];//coordenadas que elige el jugador para disparar
	int disparo=0;//es uno cuando ya se ha efectuado el disparo, independientemente del resultado

	while(disparo==0)
	{
		imprime("\n\n  Almirante, introduzca las coordenadas del blanco",2,2);
		scanf(" %s", coorddisp); //el jugador introduce las coordenada que desea atacar
		comprobarformatocoord(coorddisp); //se comprueba que tiene un formato correcto
		if (comprobarformatocoord(coorddisp)==1)
			if (tablerojug[fila][columna]!='-') //comprueba si anteriormente habia disparado en esa posicion
				imprime("\n  Ya has disparado en esa posicion!",1,0);
			else
			{
				if (matrizcons[fila][columna] == 0) //si la posicion en la matriz de la consola es 0, ha dado agua y se refleja en el tablero que ha obtenido
				{
					system("cls");
					animaciondisparo();
					tablerojug[fila][columna]='~';
					imprime("AGUA!",2,0);
					return 0;
				}
				if (matrizcons[fila][columna] == 2) //si es 2 ha dado al submarino
				{
					system("cls");
					animaciondisparo();
					imprime("ESO ES!, has tocado el submarino",2,0);
					tablerojug[fila][columna]='2';
					return 2;
				}
				if (matrizcons[fila][columna] == 3)// si es 3 ha dado al acorazado
				{
					system("cls");
					animaciondisparo();
					imprime("ESO ES!, has tocado el acorazado",2,0);
					tablerojug[fila][columna]='3';
					return 3;
				}
				if (matrizcons[fila][columna] == 4)//si es 4 ha dado al destructor
				{
					system("cls");
					animaciondisparo();
					imprime("ESO ES!, has tocado el destructor",2,0);
					tablerojug[fila][columna]='4';
					return 4;
				}
				if (matrizcons[fila][columna] == 5) //si es 5 ha dado al portaviones
				{
					system("cls");
					animaciondisparo();
					imprime("ESO ES!, has tocado el portaviones",2,0);
					tablerojug[fila][columna]='5';
					return 5;
				}
			}
	}
}

int disparocons()//disparo de la consola aleatorio
{
	int f,c;
	int disparo=0;

	while(disparo==0)
	{
		f = rand() % (5+1); //coordenada aleatoria del disparo
		c = rand() % (5+1);
		if(tablerocons[f][c]=='-')//comprueba que no haya disparado ahi anteriormente 				
			if (matrizjug[f][c] == 0)//falla el disparo y da agua
			{
				tablerocons[f][c]='~';
				animaciondisparo();
				imprime("Tuvimos suerte almirante!, el enemigo fallo el disparo",3,0);
				return 0;
			}
			else
			{
				if (matrizjug[f][c] == 2)//toca el submarino
				{
					animaciondisparo();
					imprime("Malas noticias, el enemigo ha tocado nuestro submarino",3,0);
					tablerocons[f][c]='2';
					return 2;
				}
				if (matrizjug[f][c] == 3)//toca el acorazado
				{
					animaciondisparo();
					imprime("Malas noticias, el enemigo ha tocado nuestro acorazado",3,0);
					tablerocons[f][c]='3';
					return 3;
				}
				if (matrizjug[f][c] == 4)//toca el destructor
				{
					animaciondisparo();
					imprime("Malas noticias, el enemigo ha tocado nuestro destructor",3,0);
					tablerocons[f][c]='4';
					return 4;
				}
				if (matrizjug[f][c] == 5)//toca el portaviones
				{
					animaciondisparo();
					imprime("Malas noticias, el enemigo ha tocado nuestro portaviones",3,0);
					tablerocons[f][c]='5';
					return 5;
				}	
			}		
	}
}
//-------------------------------------------------------------EMPIEZA EL JUEGO--------------------------------------------------------------------------

	system("cls");
	
    //Instrucciones
    imprime("",1,3);
    imprime("Bienvenido almirante, la flota espera sus ordenes",2,3);
    turra=instrucciones();
    if(turra==0)
    {
    system("cls");
	imprime("Instrucciones:",2,3);
	imprime("-El objetivo consiste en acabar con los 4 barcos enemigos (portaviones, destructor, bombardero y submarino)",1,3);
    imprime("-Los barcos del enemigo se generan aleatoriamente",1,3);
    imprime("-Al jugador se le pide primero la fila (letra), seguido de la columna (numero)",1,3);
    imprime("-El juego acabara cuando uno de los dos acabe con todos los barcos del enemigo",3,5);
    imprime("Presione cualquier tecla para continuar...",1,0);
    }
    system("cls");
    
//llenar de 0 las matrices
	for (i=0; i<6; i++)
		for (j=0; j<6; j++)
			{
				matrizcons[i][j] = 0; 
				matrizjug[i][j] = 0;
			}		
			
//Llenar de "-" el tablero de disparos del jugador
	for (i=0; i<6; i++)
			for (j=0; j<6; j++)
			{
				tablerojug[i][j] = '-';
				tablerocons[i][j] = '-';
			}
				
	srand (time(NULL)); //genera semilla aleatoria
	
//Generar barcos consola 	
	generarbarco(5, matrizcons, 5);	//portaviones rellena la matriz de 5 
	generarbarco(4, matrizcons, 4);	//destructor rellena la matriz de 4
	generarbarco(3, matrizcons, 3);	//acorazado rellena la matriz de 3
  	generarbarco(2, matrizcons, 2);	//submarino rellena la matriz de 2
  	
//Colocacion de barcos por parte del jugador------------------------------
	do
	{
		if (barcojug==1) //Colocar el primer barco, portaviones
		{
			system("cls");
			if (formatocoord==0 || formatocoord2==0)//Si alguna de las coordenadas no es valida da error
				imprime("Error: Formato no valido, por favor, introduzca un formato de coordenada valido, como por ejemplo A5 o B4",2,0);
			imprimematriz(matrizjug);
			imprime("\n\n  Introduzca el primer punto del portaviones (5 casillas)",2,2);
			scanf(" %s", coordport);
			formatocoord = comprobarformatocoord(coordport);
			fila1=fila;
			columna1=columna;
			if (formatocoord==1) //Si la primera coordenada introducida es valida, introduce el segundo punto
			{
				imprime("\n  Introduzca el segundo punto del portaviones:",2,2);
				scanf(" %s", coordport2);
				formatocoord2 = comprobarformatocoord(coordport2);
				fila2=fila;
				columna2=columna;
				if (formatocoord2== 1)	//Si la segunda coordenada es valida, genera el barco		
					if (generarbarcojug(fila1, fila2, columna1, columna2, matrizjug, 5)==1)
						barcojug++;			
			}
		}
		
		if (barcojug==2) //colocar 2 barco
		{
			system("cls");
			if (formatocoord==0 || formatocoord2==0)
				imprime("Error: Formato no valido, por favor, introduzca un formato de coordenada valido, como por ejemplo A5 o B4",2,0);
			imprimematriz(matrizjug);
			imprime("\n\n  Introduzca el primer punto del destructor (4 casillas)",2,2);
			scanf(" %s", coordport);
			formatocoord = comprobarformatocoord(coordport);
			fila1=fila;
			columna1=columna;
			if (formatocoord==1)
			{
				imprime("\n  Introduzca el segundo punto del destructor:",2,2);
				scanf(" %s", coordport2);
				formatocoord2 = comprobarformatocoord(coordport2);
				fila2=fila;
				columna2=columna;
				if (formatocoord2== 1)				
					if (generarbarcojug(fila1, fila2, columna1, columna2, matrizjug, 4)==1)
						barcojug++;	;				
			}
		}
		
		if (barcojug==3) //colocar 3 barco
		{
			system("cls");
			if (formatocoord==0 || formatocoord2==0)
				imprime("Error: Formato no valido, por favor, introduzca un formato de coordenada valido, como por ejemplo A5 o B4",2,0);
			imprimematriz(matrizjug);
			imprime("\n\n  Introduzca el primer punto del acorazado (3 casillas)",2,2);
			scanf(" %s", coordport);
			formatocoord = comprobarformatocoord(coordport);
			fila1=fila;
			columna1=columna;
			if (formatocoord==1)
			{
				imprime("\n  Introduzca el segundo punto del acorazado:",2,2);
				scanf(" %s", coordport2);
				formatocoord2 = comprobarformatocoord(coordport2);
				fila2=fila;
				columna2=columna;
				if (formatocoord2== 1)				
					if (generarbarcojug(fila1, fila2, columna1, columna2, matrizjug, 3)==1)
						barcojug++;					
			}
		}
		
		if (barcojug==4)//colocar 4 barco
		{
			system("cls");
			if (formatocoord==0 || formatocoord2==0)
				imprime("Error: Formato no valido, por favor, introduzca un formato de coordenada valido, como por ejemplo A5 o B4",2,0);
			imprimematriz(matrizjug);
			imprime("\n\n  Introduzca el primer punto del submarino (2 casillas)",2,2);
			scanf(" %s", coordport);
			formatocoord = comprobarformatocoord(coordport);
			fila1=fila;
			columna1=columna;
			if (formatocoord==1)
			{
				imprime("\n  Introduzca el segundo punto del submarino:",2,2);
				scanf(" %s", coordport2);
				formatocoord2 = comprobarformatocoord(coordport2);
				fila2=fila;
				columna2=columna;
				if (formatocoord2== 1)				
					if (generarbarcojug(fila1, fila2, columna1, columna2, matrizjug, 2)==1)
						barcojug++;				
			}
		}
	
		if (barcojug==5) //se termina la colocacion de barcos por parte del jugador
		{
			colocacionjug++;
			break;
		}
	
    }while(colocacionjug==0);
//--------------------------------------------------------------------------------------------------------------

//Una vez colocados los barcos de la consola y del jugador, empiezan los disparos
    system("cls");
	imprime("",2,3);	
	imprime("Magnifica estrategia almirante, pero ahora empieza lo divertido.",2,3);
	imprime("Tomaremos ventaja sobre nuestro adversario, le sorprenderemos atacando primero",3,0);
	
	while(ganador==0)
	{
		imprimematrizchar(tablerojug);//muestra el tablero de disparos
		tocadojug=disparojug();  //Resultado de disparo de jugador
		numdisparos++;
		
		if(tocadojug==2) //Si el jugador toca el submarino
		{
			submarinocons--;//el submarino de la consola pierde una "vida"
			if(submarinocons==0)//si ha perdido todas sus "vidas", se hunde y la consola pierde un barco
			{
				imprime("ENHORABUENA, SUBMARINO ENEMIGO TOCADO Y HUNDIDO!!",2,0);
				barcoscons--;
			}
		}
		
		if(tocadojug==3)//jugador toca el acorazado
		{
			acorazadocons--;
			if(acorazadocons==0)
			{
				imprime("ENHORABUENA, ACORAZADO ENEMIGO TOCADO Y HUNDIDO!!",2,0);
				barcoscons--;
			}
		}
		
		if(tocadojug==4)//jugador toca el destructor
		{
			destructorcons--;
			if(destructorcons==0)
			{
				imprime("ENHORABUENA, DESTRUCTOR ENEMIGO TOCADO Y HUNDIDO!!",2,0);
				barcoscons--;
			}
		}
		
		if(tocadojug==5)//jugador toca el portaviones
		{
			portavionescons--;
			if(portavionescons==0)
			{
				imprime("ENHORABUENA, PORTAVIONES ENEMIGO TOCADO Y HUNDIDO!!",2,0);
				barcoscons--;
			}
		}
		
		if(barcoscons==0)//si la consola se queda sin barcos
		{
			punts=puntuacion(numdisparos);
			system("cls");
			imprime("",3,3);
			imprime("ENHORABUENA CAPITAN, HAS CONSEGUIDO ELIMINAR A TODA LA FLOTA ENEMIGA EN TAN SOLO ",0,0);	
			printf("%i",numdisparos);
			imprime(" DISPAROS!!",3,3);
			imprime("DISFRUTA DE TUS ",0,0);
			printf("%i ",punts);
			imprime("EN LA TIENDA",3,3);
			ganador++;
			break;
		}
		
		imprime("\n\nTurno del enemigo:",2,0);
		tocadocons=disparocons(); //Resultado disparo de la consola
		
		if(tocadocons==2)//si toca el submarino
		{
			submarinojug--;
			if(submarinojug==0)
			{
				imprime("MALDICION, EL ENEMIGO HA HUNDIDO NUESTRO SUBMARINO!",2,0);
				barcosjug--;
			}
		}
		
		if(tocadocons==3)//si toca el acorazado
		{
			acorazadojug--;
			if(acorazadojug==0)
			{
				imprime("MALDICION, EL ENEMIGO HA HUNDIDO NUESTRO ACORAZADO!",2,0);
				barcosjug--;
			}
		}
		
		if(tocadocons==4)//si toca el destructor
		{
			destructorjug--;
			if(destructorjug==0)
			{
				imprime("MALDICION, EL ENEMIGO HA HUNDIDO NUESTRO DESTRUCTOR!",2,0);
				barcosjug--;
			}
		}
		
		if(tocadocons==5)// si toca el portaviones
		{
			portavionesjug--;
			if(portavionesjug==0)
			{
				imprime("MALDICION, EL ENEMIGO HA HUNDIDO NUESTRO PORTAVIONES!",2,0);
				barcosjug--;
			}
		}
		
		if(barcosjug==0)//si el jugador se queda sin barcos, gana la consola
		{
			system("cls");
			imprime("",3,3);
			imprime("Hoy es un dia triste, el enemigo se ha hecho con toda nuestra flota.",2,0);
			ganador++;
			break;
		}
	}
	
//Salir del juego
    *tickets+=punts;
 	imprime("",3,0);
	imprime("Pulsa 0 para volver a jugar o pulse cualquier otro numero para salir del juego",2,0);
	scanf(" %d",&salida);
    system("cls");
    return salida;
}
//FUNCIONES GLOBALES

  //Imprime una frase letra por letra con un delay entre ellas
int imprime(char frase[], int s, int e){
	int i= 0;
 while (frase[i] != '\0') 
{
   printf("%c", frase[i]);
   Sleep(30);
   i++;
}
i= 0;
	for (i=0;i<s;i++) 
     printf("\n");
	for (i=0;i<e;i++) 
     printf(" ");
}
// Abre el catalogo de la tienda
void AbrirTienda()
{
	FILE *pf;
	char premio[20];
	int puntos;
	pf = fopen("tienda.txt", "r");
	if (pf == NULL) 
	{
	// Si el resultado es NULL mensaje de error 
	printf("Error al abrir el fichero.\n");  
	} 
	printf("Vamos a visualizar la tienda de premios: ");
	while(fscanf(pf, "%[^;];%d",premio,&puntos )!=EOF)
	{
		printf("\n\tPREMIO %s, PUNTOS: %d",premio,puntos);
	}
	fclose(pf);
}

 // Genera una semilla para generar un numero aleatorio
 void semilla()
 {
 	srand(time(NULL));
 }
 // Genera numeros aleatorios en el intervalo deseado
 int numal(int num1,int num2)
 {
 	int numero;
 	numero= rand() % (num2-num1+1) + num1;
 	return numero;
 }
 // Pregunta al jugador si quiere leer las instrucciones
 int instrucciones()
 {
 	char turra[3];
 	int fallo=0;
 	while(fallo==0)
 	{
 	imprime("Desea leer las instrucciones?. Escriba si o no",2,3);
 	gets(turra);
 	_strupr(turra); //Pasamos la respuesta a mayusuculas para que de igual si el concursante a puesto la respuesta en mayusuculas o minusculas
 	if(strcmp(turra,"SI")==0)
 	{
 		fallo=1;
 		return 0;
	}
	else if(strcmp(turra,"NO")==0)
	{
		fallo=1;
		return 1;
	}
	else
	    imprime("Recuerda que tienes que escribir si o no",2,0);
    }     	
 }
