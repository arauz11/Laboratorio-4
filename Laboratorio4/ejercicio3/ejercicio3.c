#include<stdio.h>
#include<stdlib.h>

typedef struct user{
	char name[20];
	int ID;
	int elapsed;
}
USER;
void printMenu()
{
	printf("Presione 1 para ver la lista de usuarios\n");
	printf("Presione 2 para ver el estado del usuario\n");
	printf("Presione 3 para buscar al usuario por la ultima vez que accesó\n");
	printf("Presione 4 para actulizar los datos del usuario\n");
	printf("Presione 5 para salir\n");
	printf("Ingrese su opción: ");

}
int main()
{
	FILE *ftpr;

	USER user_details[20];// Objeto de estructura para almacenar los detalles del usuario. 
	USER dup_user; // Variable para duplicar.
	int curr_pos=0,i,j,choice,id,flag_id; // Abre el puntero ftpr en la lectura
	ftpr=fopen("user_list.txt","r");// Con este comando se lee del documento .txt.
	while(fscanf(ftpr,"%s",user_details[curr_pos].name)!=EOF)
	{

	fscanf(ftpr,"%d",&user_details[curr_pos].ID);
	fscanf(ftpr,"%d",&user_details[curr_pos].elapsed);
	curr_pos++; // Avanza al siguiente.
	}

	fclose(ftpr); // Cierra el archivo.

	// True hasta que salga el usuario.
	while(1)
	{
		printMenu(); // Imprime el menú.
		scanf("%d",&choice); // Se lee la opción ingresada por el usuario.
		if(choice==1){

		printf("\nDETALLES DEL USUARIO	\n");
			printf("%-20s%-12s%s\n","NOMBRE","ID","ULTIMO ACCESO\n");
			for(i=0;i<curr_pos;i++)
			{
				printf("%-20s%-12d%d\n",user_details[i].name,user_details[i].ID,user_details[i].elapsed);
			}
			printf("\n");

		}
		else if(choice==2){

			for(i=0;i<curr_pos;i++)
                   	{
				printf("%s: ",user_details[i].name);
				if(user_details[i].elapsed==0)
				{
					printf("ACTIVADO\n");
				}
				else if(user_details[i].elapsed==1)
				{
					printf("RECIENTE\n");
				}
				else{
					printf("INACTIVO\n");
				}
			}
			printf("\n");

		}
		else if(choice==3){ // Buscar.
			for(i=0;i<curr_pos-1;i++)
			{
				for(j=0;j<curr_pos-i-1;j++)
				{
					if(user_details[j].elapsed>user_details[j+1].elapsed){
						// Intercambiando.
						dup_user=user_details[j];
						user_details[j]=user_details[j+1];
						user_details[j+1]=dup_user;
					}
				}
			}
			// Imprime la lista de usuarios.
			printf("%-20s%-12s%s\n","NOMBRE","ID","ULTIMO ACCESO");
			for(i=0;i<curr_pos;i++)
			{
				printf("%-20s%-12d%d\n",user_details[i].name,user_details[i].ID,user_details[i].elapsed);
			}
			printf("\n");

		}
		else if(choice==4) {
			printf("Ingrese el ID del usuario: ");
			scanf("%d",&id);// Se lee el ID del usuario.
			flag_id=0;
			// Buscando. 
			for(i=0;i<curr_pos;i++)
			{
				if(id==user_details[i].ID)
				{
					// Actualizandose. 
					printf("Ingrese el nombre del usuario: ");
					scanf("%s",user_details[i].name);
					printf("Ingrese la ultima vez accesado: ");
					scanf("%d",&user_details[i].elapsed);
					flag_id=1;

				}
			}
			if(flag_id==0)
			{
				printf("No se encontró el ID");
			}
			printf("\n");
 		}
		else if(choice==5){
			ftpr=fopen("user_list.txt","w");
			for(i=0;i<curr_pos;i++)
			{
				fprintf(ftpr,"%s\n%d\n%d\n",user_details[i].name,user_details[i].ID,user_details[i].elapsed);
			}

			fclose(ftpr);

			exit(0);
		}
		else{ printf("Opción Invalida \n\n");

		}
	}

}

