/*********************************************************//**
*
* \brief Funcion que da de baja un Cliente
* \param char nombreArchivo[]
* \param int id Cliente
* \return void
*
*************************************************************/
void bajaCliente(char nombreArchivo[], int idCliBaja)
{
    stCliente c;

    FILE *pArchCliente = fopen(nombreArchivo,"r+b");

    if(pArchCliente)
    {
        fseek(pArchCliente, sizeof(stCliente)*buscaPos(idCliBaja, nombreArchivo), SEEK_SET);
        fread(&c, sizeof(stCliente), 1, pArchCliente);
        c.baja = 1;
        fseek(pArchCliente, sizeof(stCliente)*buscaPos(idCliBaja, nombreArchivo), SEEK_SET);
        fwrite(&c, sizeof(stCliente), 1, pArchCliente);
        fclose(pArchCliente);
    }
}
/*********************************************************//**
*
* \brief Funcion que muestra un Cliente en un archivo de Clientes
* \param char nombreArchivo[]
* \param arreglo stCliente
* \param int id del Cliente
* \return void
*
*************************************************************/
void modificaRegistro(char nombreArchivo[], stCliente c, int idCliente)/// En c están los datos nuevos que se quieren guardar
{   /// e idCliente el id del cliente cuyos datos se quieren pisar
    FILE *pArchClientes = fopen(nombreArchivo, "r+b");

    if(pArchClientes)
    {
        fseek(pArchClientes, sizeof(stCliente)*idCliente, SEEK_SET);
        if (existeCliente(nombreArchivo, c.id)==0)
        {
            fwrite(&c, sizeof(stCliente), 1, pArchClientes);
        }
        fclose(pArchClientes);
    }
}
/*********************************************************//**
*
* \brief Funcion que busca al posición de un Cliente en un archivo
* \param int id del cliente
* \param char nombre del archivo
* \return int posición
*
*************************************************************/
int buscaPos(int id, char nombreArchivo[])
{
    int pos = -1;

    stCliente c;

    FILE *pArchClientes = fopen(nombreArchivo, "rb");

    if(pArchClientes)
    {
        while(pos==-1 && fread(&c, sizeof(stCliente), 1, pArchClientes) > 0)
        {
            if(c.id == id)
            {
                pos = ftell(pArchClientes)/sizeof(stCliente)-1;
            }
        }
        fclose(pArchClientes);
    }

    return pos;
}
/*********************************************************//**
*
* \brief Funcion que carga Clientes en un archivo
* \param char nombre del archivo
* \return void
*
*************************************************************/
void cargaArchivoClientes(char nombreArchivo[])
{
    char opcion=0;

    stCliente c;

    while(opcion!=27)
    {
        system("cls");

        printf("\n Carga de Clientes \n");

        c = cargaUnCliente();
        c.id=buscaUltimoIdCliente(nombreArchivo)+1;

        if (existeCliente(nombreArchivo,c.nroCliente) == 0)
        {
            guardaUnCliente(c, nombreArchivo);
        }
        else
        {
            printf("\nEl cliente con Numero de Cliente %d ya existe.", c.nroCliente);
        }

        printf("\n\n ESC para salir ");
        opcion=getch();
    }
}
/*********************************************************//**
*
* \brief Funcion que retorna 1 si encuentra un Cliente dado su n° de Cliente
* \param char nombreArchivo[]
* \param int cliente
* \return int flag
*
*************************************************************/
int existeCliente(char nombreArchivo[], int cliente)
{
    stCliente c;

    int flag = 0;

    FILE *pArchCliente = fopen(nombreArchivo,"rb");

    if(pArchCliente)
    {
        while(fread(&c,sizeof(stCliente),1,pArchCliente) > 0)
        {
            if (c.nroCliente == cliente)
            {
                flag = 1;
            }
        }
        fclose(pArchCliente);
    }
    return flag;
}
/*********************************************************//**
*
* \brief Funcion que guarda un Cliente en un archivo
* \param arreglo stCliente
* \param char nombre del archivo
* \return void
*
*************************************************************/
void guardaUnCliente(stCliente c, char nombreArchivo[])
{
    FILE *pArchCliente = fopen(nombreArchivo,"ab");

    if(pArchCliente != NULL)  /// if(pArchCliente)
    {
        fwrite(&c,sizeof(stCliente),1,pArchCliente);
        fclose(pArchCliente);
    }
}
/*********************************************************//**
*
* \brief Funcion que busca el último ID del Cliente cargado en un archivo
* \param char nombre del archivo
* \return int id
*
*************************************************************/
int buscaUltimoIdCliente(char nombreArchivo[])
{
    stCliente c;

    int id = -1;
    FILE *pArchCliente = fopen(nombreArchivo,"rb");
    if(pArchCliente)
    {
        fseek(pArchCliente, sizeof(stCliente)*(-1),SEEK_END);

        if(fread(&c,sizeof(stCliente),1,pArchCliente) > 0)
        {
            id = c.id;
        }
        fclose(pArchCliente);
    }
    return id;
}
/*********************************************************//**
*
* \brief Funcion que carga un Cliente
* \return arreglo stCliente
*
*************************************************************/
stCliente cargaUnCliente()
{
    stCliente c;

    do
    {
        printf("\n Ingrese el nro de Cliente..........: ");
        scanf(" %d", &c.nroCliente);
    }
    while(c.nroCliente<0 || c.nroCliente>9999999);

    printf(" Ingrese el Nombre..................: ");
    fflush(stdin);
    gets(c.nombre);

    printf(" Ingrese el Apellido................: ");
    fflush(stdin);
    gets(c.apellido);

    printf(" Ingrese el DNI.....................: ");
    scanf(" %d", &c.dni);

    do
    {
        printf(" Ingrese el EMail...................: ");
        fflush(stdin);
        gets(c.email);
        if (!validaEmail(c.email))
        {
            printf("\nEl mail ingresado no existe. Ingreselo correctamente.\n");
        }
    }
    while(!validaEmail(c.email));

    printf(" Ingrese el Domicilio...................: ");
    fflush(stdin);
    gets(c.domicilio);

    printf(" Ingrese el Numero de celular...........: ");
    fflush(stdin);
    gets(c.movil);

    c.baja=0;

    return c;
}
/*********************************************************//**
*
* \brief Funcion valida un mail corroborando que tenga un @ la variable char
* \param char email[]
* \return int flag
*
*************************************************************/
int validaEmail(char email[])
{
    int v=strlen(email);
    int i=0;
    int flag=0;
    while(i<v && flag == 0)
    {
        if(email[i]==64)
        {
            flag=1;
        }
        i++;
    }
    return flag;
}
/*********************************************************//**
*
* \brief Funcion que muestra un archivo de Clientes
* \param char nombre del archivo
* \return void
*
*************************************************************/
void muestraArch(char nombreArchivo[])
{
    stCliente c;

    FILE *pArchCliente = fopen(nombreArchivo,"rb");

    if(pArchCliente)
    {
        while(fread(&c,sizeof(stCliente),1,pArchCliente) > 0)
        {
            muestraUnCliente(c);
        }
    }
    printf("\n");
}
/*********************************************************//**
*
* \brief Funcion que muestra un Cliente
* \param arreglo stCliente
* \return void
*
*************************************************************/
void muestraUnCliente(stCliente c)
{
    printf("\n  -----------------------------------------------------------------");
    printf("\n  ID......................: %d", c.id);
    printf("\n  Nro de Cliente..........: %d", c.nroCliente);
    printf("\n  Nombre..................: %s", c.nombre);
    printf("\n  Apellido................: %s", c.apellido);
    printf("\n  DNI.....................: %d", c.dni);
    printf("\n  EMail...................: %s", c.email);
    printf("\n  Domicilio...............: %s", c.domicilio);
    printf("\n  Nro de Celular..........: %s", c.movil);
    printf("\n  Baja s/n................: %s", (c.baja)?"SI":"NO");
}
