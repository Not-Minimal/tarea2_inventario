#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>

// ? id goblal parte en 700 y se le sube en 1 en 1
int id=700; 

// todo ***************************ESTRUCTURAS******************************************
typedef struct
{
    int id;
    char marca[15];
    char modelo[10];
    char idioma[10];
    int stock;
} estructura_teclado;
estructura_teclado teclado[20]; // * DEFINIMOS TECLADOS 

typedef struct
{
    int id;
    char marca[15];
    char modelo[10];
    int stock;
} estructura_mouse;
estructura_mouse mouse[20]; // * DEFINIMOS MOUSE

typedef struct
{
    int id;
    char marca[15];
    char modelo[10];
    float pulgadas; //! PULGADAS > 7
    int stock;
} estructura_monitor;
estructura_monitor monitor[20]; // * DEFINIMOS MONITOR

typedef struct
{
    int id;
    char marca[15];
    char modelo[10];
    int ram; //! RAM SIEMPRE POTENCIA DE 2
    char procesador[15]; //todo AGREGO EL [15]
    float pulgadas; //! PULGADAS > 11
    int stock;
} estructura_notebook;
estructura_notebook note[20]; // * DEFINIMOS NOTEBOOK

typedef struct
{
    int id;
    char marca[15];
    char modelo[10];
    int ram; //! RAM SIEMPRE POTENCIA DE 2
    char procesador[15]; //todo AGREGO EL [15]
    
    estructura_teclado pc_teclado;
    estructura_mouse pc_mouse;
    estructura_monitor pc_monitor;
    int stock;
} estructura_pc;
estructura_pc pc[20]; // * DEFINIMOS TORRE/PC


typedef struct
{
    int id;
    char nombreuser[11];
    char nombres[25];
    char apellidom[10];
    char apellidop[10];
    char contrasena[5];
} usuario;
usuario user;

// todo ********************************************************************************

void llenar_user();
void llenar_datos_struct();
void mostrar_user();
int login();

void llenar_teclado(int i, int a);
void llenar_mouse(int i, int a);
void llenar_monitor(int i, int a);


void lista_produc();
void opciones(); //* MENU AGREGAR PROD 
int sub_op(); //* SUB MENU TIPO PROD Y SEGUN TIPO DE PROD, SE PIDEN DATOS ESPECIFICOS

int actualizar_productos();
//todo ************************************ MAIN ****************************************
int main(int argc, char const *argv[])
{
    int bandera = 1, i;
    system("title login inventario");
    llenar_user();
    llenar_datos_struct();
    /*
    do
    {
        bandera = login();
    }while(bandera == 1);

    system("cls");
    printf("Cargando...\n");
    for (i = 0; i <= 100; i++)
    {
        printf("\r%d%%", i);
        usleep(100000); //! manda warning pero solo en visual estudio en devc del profe todo oki
    }
    system("title vegeta");
    system("cls");
    printf(" .----------------.  .----------------.  .----------------. \n");
    printf("| .--------------. || .--------------. || .--------------. |\n");
    printf("| |  ________    | || |    ___       | || | ____    ____ | |\n");
    printf("| | |_   ___ `.  | || |  .' _ '.     | || ||_   \\  /   _|| |\n");
    printf("| |   | |   `. \\ | || |  | (_) '___  | || |  |   \\/   |  | |\n");
    printf("| |   | |    | | | || |  .`___'/ _/  | || |  | |\\  /| |  | |\n");
    printf("| |  _| |___.' / | || | | (___)  \\_  | || | _| |_\\/_| |_ | |\n");
    printf("| | |________.'  | || | `._____.\\__| | || ||_____||_____|| |\n");
    printf("| |              | || |              | || |              | |\n");
    printf("| '--------------' || '--------------' || '--------------' |\n");
    printf(" '----------------'  '----------------'  '----------------'\n");
    printf("D&M productions presentan:\n");
    printf("  _                      _             _       \n");
    printf(" (_)                    | |           (_)      \n");
    printf("  _ _ ____   _____ _ __ | |_ __ _ _ __ _  ___  \n");
    printf(" | | '_ \\ \\ / / _ \\ '_ \\| __/ _` | '__| |/ _ \\ \n");
    printf(" | | | | \\ V /  __/ | | | || (_| | |  | | (_) |\n");
    printf(" |_|_| |_|\\_/ \\___|_| |_|\\__\\__,_|_|  |_|\\___/ \n");
    system("pause");
    system("cls");
*/
    opciones();
    system("pause");
    return 0;
}
// todo ********************************************************************************

int login() // NUEVO LOGIN MODIFICADO
{

    char contra[5];
    char usuario[11];
    int bandera = 1, i = -1, cont = 0, banderauser=1; // todo bandera vale menos 1 porque es un do while que suma 1 al i al inicio y para que i valga 0 al
    // todo empezar
    char bande; // todo bandera de character que sirve para que meta el enter

    system("cls");
    printf("Ingrese su nombre de usuario\n");
    gets(usuario);
    fflush(stdin);

    // todo aqui ahora es un do while que lee hasta 5 characteres o termina si uno es enter
    printf("Ingrese su contrasena\n");
    do
    {
        i = i + 1;
        contra[i] = _getch();
        printf("*");

    } while (i <= 3 && contra[i] != 13);
	
	// todo aqui si ingreso 5 characteres debe ingresar un enter para mandarlos , si ingreso 3 seria que ya metio un enter,
	// todo y no se mete aqui
	
    if (contra[i]!= 13)
    {
        do
        {
            bande = _getch();
        } while (bande != 13 );
    }
    
    // ! verificacion del usuario
    // todo aqui leeo el usuario con gets, pregunto si es igual al de la base de dato"""
    // todo si es igual pasa a la contrasena sino returna 1 y printea que reingrese los datos
    cont = 0;
    for (i = 0; user.nombreuser[i] != '\0'; i++)
    {
        if (usuario[i] != user.nombreuser[i])
        {
            system("cls");
            printf("datos incorrectos, reingrese los datos nuevamente\n");
            system("pause");
            return 1;
        }
    }

    cont = 0;
    for (i = 0; i<5; i++)
    {
        if (contra[i] == user.contrasena[i])
        {
            cont = cont + 1;
            if (cont == 5 && contra[i+1]== 13)
            {
                return 0;
            }
        }
        else
        {
            system("cls");
            printf("datos incorrectos, reingrese los datos nuevamente\n");
            system("pause");
            return 1;
        }
    }
}


void opciones(){

    //Debe poder agregar un producto, actualizar un producto, listar los productos y eliminar un
    //producto (CRUD).
    //• Debe poder realizar una búsqueda por la marca del producto.
    //• Debe contar con un menú para poder realizar las operaciones mencionadas.
    //• Debe indicar la cantidad de existencias de cada producto.

    int opcion, bandera = 0;
    do{
        system("cls");
        printf("Ingrese su opcion\n");
        printf("1 agregar un producto\n");
        printf("2 actualizar un producto\n");
        printf("3 listar un tipo de productos\n");
        printf("4 eliminar un producto\n");
        printf("5 buscar un producto por su marca\n");// de forma recursiva
        printf("6 cerrar progama\n");
        opcion = _getch(); //! ME DETECTA EL 1 COMO 49 Y [DEMAS NUMEROS COMO N + 48] NOSE PORQUE

        
        // ! al entrar en el case llamamos una funcion 
        // ! sabemos siempre habra 3 minimo comentame cual es tu idea para  para saber en que posisicion vamos del
        // ! ejemplo teclado[i].marca como sabemos el i si esque elimino alguno o nose comentame tu idea
        
        switch(opcion-48){

            case 1:
                do
                {
                    opcion = sub_op();
                    if(opcion > 5 || opcion < 1)system("cls");
                }while(opcion > 5 || opcion < 1);
                break;
            case 2:
                actualizar_productos();
                break;
            case 3:
                system("cls");
                lista_produc();
                break;
            case 4:
                
                break;
            case 5:

                break;
            case 6:
                bandera = 1;
                break;
            default:
                printf("ERROR OPCION INVALIDA, REINGRESE DATO\n");
                system("pause");
                break;
        }
        if(bandera == 1)
        {
            printf("SALIENDO CON EXITO DEL PROGRAMA\n");
            break;
        }
    }while(opcion !=6);
}


int sub_op()//!FUNCION INCOMPLETA DE AGREGAR PRODUCTO
{
    int i, bandera = 0, op;

    system("cls");
    printf("Ingrese tipo de producto a agregar:\n");
    printf("1 Teclado\n");
    printf("2 Mouse\n");
    printf("3 Monitor\n");
    printf("4 Notebook\n");
    printf("5 PC de escritorio\n");
    op = _getch();
    fflush(stdin);
    for(i = 0; i < 20; i++)
    {
        switch(op-48)
        {
            case 1: //*TECLADO
                if(teclado[i].stock == 0)
                {
                    system("cls");
                    llenar_teclado(i, 0);
                    system("pause");
                    bandera = 1;
                    if(i == 20 && teclado[i].stock != 0)printf("STOCK LLENO");
                }
                
                break;
            case 2: //*MOUSE
                if(mouse[i].stock == 0)
                {
                    system("cls");
                    llenar_mouse(i, 0);
                    system("pause");
                    bandera = 1;
                    if(i == 20 && mouse[i].stock != 0)printf("STOCK LLENO");
                }
                
                break;
            case 3: //*MONITOR
                if(monitor[i].stock == 0)
                {
                    system("cls");
                    llenar_monitor(i, 0);
                    system("pause");
                    bandera = 1;
                    if(i == 20 && monitor[i].stock != 0)printf("STOCK LLENO");
                }
                
                break;
            case 4: //*NOTEBOOK
                if(note[i].stock == 0)
                {
                    system("cls");
                    note[i].id=id;
                    id++;
                    note[i].stock = 1;
                    printf("Ingrese marca\n ");
                    gets(note[i].marca);
                    fflush(stdin);

                    printf("Ingrese modelo\n");
                    gets(note[i].modelo);
                    fflush(stdin);

                    // ? ram minimo 2
                    do
                    {
                        printf("Ingrese memoria ram\n");
                        scanf("%d", &note[i].ram);
                        fflush(stdin);
                        if (note[i].ram<2);
                        {
                            printf("Dato erroneo, reingrese dato\n");
                        }
                        
                    } while (note[i].ram<2);

                    printf("Ingrese procesador\n");
                    gets(note[i].procesador);
                    fflush(stdin);

                    do{   
                        printf("Ingrese pulgadas\n");
                        scanf("%f", &note[i].pulgadas); 
                        fflush(stdin);
                        if (note[i].pulgadas<7)
                        {
                            printf("Pulgadas no validos, reingrese el dato\n");
                        }
                    } while (note[i].pulgadas<7);

                    system("pause");
                    bandera = 1;
                    if(i == 20 && note[i].stock != 0)printf("STOCK LLENO");
                }
                
                break;
            case 5: //*PC ESCRITORIO
                if(pc[i].stock == 0)
                {
                    system("cls");
                    pc[i].id=id;
                    id++;
                    pc[i].stock = 1;

                    printf("Ingrese marca\n ");
                    gets(pc[i].marca);
                    fflush(stdin);
                    printf("Ingrese modelo\n");
                    gets(pc[i].modelo);
                    fflush(stdin);

                     //?MINIMO 2? // bueno
                     //!FALTA VALIDACION
                    do
                    {
                        printf("Ingrese memoria ram\n");
                        scanf("%d", &pc[i].ram);
                        fflush(stdin);
                        if (pc[i].ram<2);
                        {
                            printf("Dato erroneo, reingrese dato\n");
                        }
                        
                    } while (pc[i].ram<2);
                    

                    printf("Ingrese procesador\n");
                    gets(pc[i].procesador);
                    fflush(stdin);

                    llenar_teclado(i, 1);
                    llenar_mouse(i, 1);
                    llenar_monitor(i, 1);
                    system("pause");
                    bandera = 1;
                    if(i == 20 && pc[i].stock != 0)printf("STOCK LLENO");
                }
                
                break;
            default:
                system("cls");
                printf("ERROR OPCION INVALIDA, REINGRESE DATO\n");
                system("pause");
                bandera = 1;
                break;
        }

        if( bandera == 1)break;//*BREAK PARA SALIR DEL FOR UNA VEZ HECHO EL LLENADO
        
    }
    return op-48;//*DEVUELVO LA OPCION ESCOGIDA PARA REPETIR PROCESO O NO
}

void llenar_teclado(int i, int a)//todo ESTO ES PARA DIVIDIR TECLADO DE PC_TECLADO
{
    teclado[i].id=id;
    id++;
    teclado[i].stock = 1;
    printf("Ingrese marca\n ");
    if(a != 0)
    {
        gets(teclado[i].marca);
        fflush(stdin);
    }else//todo ESTO ES PC
    {
        gets(pc[i].pc_teclado.marca);
        fflush(stdin);
    }
    printf("Ingrese modelo\n");
    if(a != 0)
    {
        gets(teclado[i].modelo);
        fflush(stdin);
    }else//todo ESTO ES PC
    {
        gets(pc[i].pc_teclado.modelo);
        fflush(stdin);
    }
    printf("Ingrese Idioma\n");
    if(a != 0)
    {
        gets(teclado[i].idioma);
        fflush(stdin);
    }else//todo ESTO ES PC
    {
        gets(pc[i].pc_teclado.idioma);
        fflush(stdin);
    }
}

void llenar_mouse(int i, int a)//todo ESTO ES PARA DIVIDIR MOUSE DE PC_TECLADO
{
    mouse[i].id=id;
    id++;
    mouse[i].stock = 1;
    printf("Ingrese marca\n ");
    if(a != 0)
    {
        gets(mouse[i].marca);
        fflush(stdin);
    }else//todo ESTO ES PC
    {
        gets(pc[i].pc_mouse.marca);
        fflush(stdin);
    }
    printf("Ingrese modelo\n");
    if(a != 0)
    {
        gets(mouse[i].modelo);
        fflush(stdin);
    }else//todo ESTO ES PC
    {
        gets(pc[i].pc_mouse.modelo);
        fflush(stdin);
    }
}

void llenar_monitor(int i, int a)
{
    monitor[i].id=id;
    id++;
    monitor[i].stock = 1;

    printf("Ingrese marca\n ");
    if(a != 0)
    {
        gets(monitor[i].marca);
        fflush(stdin);
    }else//todo ESTO ES PC
    {
        gets(pc[i].pc_monitor.marca);
        fflush(stdin);
    }
    printf("Ingrese modelo\n");
    if(a != 0)
    {
        gets(monitor[i].modelo);
        fflush(stdin);
    }else//todo ESTO ES PC
    {
        gets(pc[i].pc_monitor.modelo);
        fflush(stdin);
    }
    
    if(a != 0)
    {
        do
        {   
            printf("Ingrese pulgadas\n");
            scanf("%f", &monitor[i].pulgadas); 
            fflush(stdin);
            if (monitor[i].pulgadas<7)
            {
                printf("Pulgadas no validos, reingrese el dato\n");
            }
            
        } while (monitor[i].pulgadas<7);
    }else//todo ESTO ES PC
    {
        do
        {   
            printf("Ingrese pulgadas\n");
            scanf("%f", &pc[i].pc_monitor.pulgadas); 
            fflush(stdin);
            if (pc[i].pc_monitor.pulgadas<7)
            {
                printf("Pulgadas no validos, reingrese el dato\n");
            }
        } while (pc[i].pc_monitor.pulgadas<7);
    }
}


void lista_produc()
{
    int i;
    printf("********************** TECLADOS *********************\n");
    printf("ID     MARCA      MODELO           IDIOMA       STOCK\n");
    for( i = 0; i < 20; i++)
    {
        if (teclado[i].stock != 0)
        {
            
            printf("%d  ", teclado[i].id);
            printf("%s  ", teclado[i].marca);
            printf("%s  ", teclado[i].modelo);
            printf("%s  ",teclado[i].idioma);
            printf("%d  ", teclado[i].stock );
            printf("\n----------------------------------------------------- \n");
        }
    }
    system("pause");
    
}

void llenar_datos_struct(){
    int i;
    for(i=0; i<20; i++){

        if(i==0 || i== 1 || i==2 ){ // * CONDICION PARA LLENAR STOCK SOLO LOS 3 PRIMEROS PRODUCTOS

            teclado[i].stock=1;
            mouse[i].stock=1;
            monitor[i].stock=1;
            note[i].stock=1;
            pc[i].stock=1;
            
            // ? ids
            
            teclado[i].id=id;
            id++;
            mouse[i].id=id;
            id++;
            monitor[i].id=id;
            id++;
            note[i].id=id;
            id++;
            pc[i].id=id;
            id++;
            pc[i].pc_teclado.id=id;
            id++;
            pc[i].pc_monitor.id=id;
            id++;
            pc[i].pc_mouse.id=id;
            id++;
            
        // ? marcas 
            strcpy(teclado[i].marca, "Razer");
            strcpy(mouse[i].marca, "Razer");
            strcpy(monitor[i].marca, "MSI");
            strcpy(note[i].marca, "MSI");
            strcpy(pc[i].marca, "MSI");


            strcpy(pc[i].pc_teclado.marca, "Razer");
            strcpy(pc[i].pc_monitor.marca, "MSI");
            strcpy(pc[i].pc_mouse.marca, "Razer");

            // ? modelos 
            strcpy(teclado[i].modelo, "BLACKWIDOW");
            printf("%s\n", teclado[i].modelo);//! aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

            strcpy(mouse[i].modelo, "Viper");
            strcpy(monitor[i].modelo, "Optix G271");
            strcpy(note[i].modelo, "Crosshair 15 ");
            strcpy(pc[i].modelo, "gaming xc");

            strcpy(pc[i].pc_teclado.modelo, "BLACKWIDOW");
            strcpy(pc[i].pc_monitor.modelo, "Optix G271");
            strcpy(pc[i].pc_mouse.modelo, "Razer Viper");

            // ? idioma solo teclados
            strcpy(teclado[i].idioma, "Ingles");
            printf("%s\n", teclado[i].modelo);//! aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

            strcpy(pc[i].pc_teclado.idioma, "Ingles");

            //? pulgadas note y monitor
            monitor[i].pulgadas=19;
            note[i].pulgadas=16;
            pc[i].pc_monitor.pulgadas=20;

            //? rams y procesador note y pc 
            note[i].ram=8;
            pc[i].ram=16;
            strcpy(pc[i].procesador, "I9 9900K");
            strcpy(note[i].procesador, "I5 10300H");

        }else{ // * LLENA LOS OTROS STOCK COMO 0
            teclado[i].stock=0;
            mouse[i].stock=0;
            monitor[i].stock=0;
            note[i].stock=0;
            pc[i].stock=0;
        }
    }
}

int actualizar_productos(){

    int op,i;
    do
    {
        system("cls");
        printf("Ingrese tipo de producto a actulizar:\n");
        printf("1 Teclado\n");
        printf("2 Mouse\n");
        printf("3 Monitor\n");
        printf("4 Notebook\n");
        printf("5 PC de escritorio\n");
        scanf("%d",&op);
        fflush(stdin);
        if (op<1 || op>5)
        {
            system("cls");
            printf("Error su opcion no es valida, reingrese dato\n");
            system("pause");
        }
        
    } while (op<1 || op>5);



    
    int id_leido;
    // ! ahora le mstramos todos los productos de ese tipo y leemos el id que quiere editar en la variable id_leido
    // ! validar que primero ese tipo de producto tenga stocks al menos 1;
    // ! va a ser mucho codigo pero con un swcht y un for por case y una bandera se hace xd;

    // ! solo esta echo el teclado pero es lo mismo para los demas
    switch (op)
    {
    case 1:
        for ( i = 0; i < 20; i++)
        {
            if (teclado[i].stock==1)
            {
                if (teclado[i].id==id_leido)
                {
                    
                    printf("Ingrese marca\n ");
                    gets(teclado[i].marca);
                    fflush(stdin);

                    printf("Ingrese modelo\n");
                    gets(teclado[i].modelo);
                    fflush(stdin);

                    printf("Ingrese Idioma\n");
                    gets(teclado[i].idioma);
                    fflush(stdin);

                    break;
                }
                
            }
            
        }
        
        break;

    case 2:
        /* code */
        break;

    case 3:
        /* code */
        break;

    case 4:
        /* code */
        break;

    case 5:
        /* code */
        break;

    default:

        break;
    }





}

void llenar_user()
{
    user.id = 777;
    strcpy(user.nombres, "juanito alcachofa");
    strcpy(user.apellidom, "aguilera");
    strcpy(user.apellidop, "arenas");
    strcpy(user.nombreuser, "vegeta");
    strcpy(user.contrasena, "12345");
}
void mostrar_user()
{
    printf("El nombre de usuario es %s\ny su contrasena es: %s\n", user.nombreuser, user.contrasena);
    printf("sus nombres son %s \n", user.nombres);
    printf("sus apellidos son %s %s\n", user.apellidop, user.apellidom);
    printf("y su id es %d\n", user.id);
}
