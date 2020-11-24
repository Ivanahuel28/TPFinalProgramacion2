#include "aleatorios.h"

/*************************************************************//**
*
* \brief Genera un archivo con clientes aleatoriamente
* \param char nomArch[] - nombre del archivo a generar
* \param int n - cantidad de clientes que contendra el archivo
* \return void
*
*****************************************************************/
void generarArchivoClientesAleatorio(char nomArch[],int n)
{
	FILE *pArch = fopen(nomArch,"ab");
	int nuevoId = ultimoIdCliente() + 1 ;

	if (pArch)
	{
	    stCliente cliente;

	    for(int i=0 ; i<n ; i++)
	    {
	        cliente = getClienteRandom();

	        cliente.idCliente = nuevoId + i;
	        cliente.nroCliente = cliente.idCliente;

	        fwrite(&cliente,sizeof(stCliente),1,pArch); // genero el archivo
	    }

		fclose(pArch);
	}
}

/*************************************************************//**
*
* \brief retorna un cliente con datos aleatorios
* \return stCliente aux - Cliente con datos aleatorios
*
*****************************************************************/
stCliente getClienteRandom()
{
	stCliente aux;

	/*
    int idCliente; /// campo �nico y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[15];
    char email[30];
    char domicilio[45];
    char movil[15];
    int baja; /// 0 si est� activo - 1 si est� de baja
	*/

	getApellido(aux.apellido);
	getNombre(aux.nombre);
	getDNI(aux.dni);
	getEMail(aux.email,aux);
	getDomicilio(aux.domicilio);
	getMovil(aux.movil);

	aux.baja = 0;

	return aux;
}


/*************************************************************//**
*
* \brief Funcion que asigna al string recibido un apellido al azar
* \return void
*
*****************************************************************/
void getApellido(char apellido[])
{
    char apellidos[][30] = {"Gomez","Perez","Rodriguez","Latorre","Fernandez","Torquemada", "Marijuan", "Roca", "Mitre", "Rivadavia",
                            "San Martin", "Alvarez", "Comizo", "Borges", "Zama", "Recato", "Olvido", "Gil", "Trapero", "Restinga",
                            "De Antonio", "Ramirez", "Spinetta", "Cortez", "Gonzalez", "Andujar", "San Juan", "Bautista", "Anchorena", "Paso",
                            "Gaboto","Vega","Vargas","Lloret","Linares","Suarez","Sierra","Amenabar","Blanco","White","Black"};

    strcpy(apellido,apellidos[rand()%( sizeof(apellidos) / (sizeof(char)*30) )]);
}

/*************************************************************//**
*
* \brief Funcion que asigna al string recibido un nombre al azar
* \return void
*
*****************************************************************/
void getNombre(char nombre[])
{
    char nombres[][30] = {"Amalio","Juan","Roberto","Antonio","Fernando","Anibal","Mariano","Jose",
                           "Anastasio","Arturo","Mario","Tamaro","Adolfo","Pedro","Alfredo","Arnaldo",
                           "Mauro","Benicio","Ildefonso","Cuchuflito","Remilgo","Miguel","Reinaldo"};

    strcpy(nombre,nombres[rand()%( sizeof(nombres) / (sizeof(char)*30) )]);
}

/*************************************************************//**
*
* \brief Funcion que retorna un DNI entre 20 y 50 millones
* \return int;
*
*****************************************************************/
void getDNI(char dni[]){

    //dni[0]='\0';

    itoa((rand()%(368-208)+208) * (rand()%(368-208)+208) * (rand()%(368-208)+208),dni,10); // de 50 a 9 millones
}


/*************************************************************//**
*
* \brief Funcion que elabora un email por parametros recibidos
* \return int;
*
*****************************************************************/
void getEMail(char email[],stCliente cliente)
{
    //char ultimos3[3];
    char dominios [][15] = {"@gmail.com","@live.com.ar"};

    strcpy(email,"");   //limpia

    strcat(email,cliente.apellido); //agrega apellido
    strcat(email,"."); // agrega punto separador
    strcat(email,cliente.nombre); //agrega nombre

    //strcpy(ultimos3,dni[5]); // obtengo ultimos 3 digitos

    //strcat(email,ultimos3);    /// copio ultimos 3 digitos del DNI

    strcat(email,dominios[rand()%( sizeof(dominios) / (sizeof(char)*15) )]);
}

void getDomicilio(char domicilio[])
{
    char calles[][30] = {"San Juan","Funes","Gaboto","San Martin","Colon","Rivadavia", "Alsina", "Roca", "Mitre", "Belgrano",
                            "Paso", "11 de Septiembre", "3 de Febrero", "Balcarce", "Libertad", "Magallanes", "Irala", "Ayolas", "Moreno", "Brown",
                            "Bolivar", "Alberti", "Gascon", "La Rioja", "Catamarca", "Salta", "Jujuy", "XX de Septiembre", "14 de Julio", "Dorrego",
                            "Hernandarias","Don Orione","Juramento","Lanzilota","Estrada","Tierra del Fuego","Mendoza","Chubut","Rio Negro","Misiones","Edison"};

    strcpy(domicilio,calles[rand()%( sizeof(calles) / (sizeof(char)*30) )]);

    char nro[5];

    itoa(rand()%10000,nro,10);

    strcat(domicilio," ");
    strcat(domicilio,nro);
}

void getMovil(char movil[])
{
    strcpy(movil,"223 4");

    char nro[6];

    itoa(rand()%888888+111111,nro,10);

    strcat(movil,nro);
}
