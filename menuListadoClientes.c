

void menuListadoClientes(nodoArbol * arbol)
{
    char op ;

    do
    {
        system("cls");
        encabezado();

        fflush();
        op = getch();

        printf()

        switch (op)
        {
            case '1':
                menuMostrarFiltrando(arbol);
                break;

            case '2':
                mostrarArbolClientes(arbol);
                break;

            case '3':
                /// modificar cliente
                break;

            case '4':
                /// ver detalle;
                break;

            default:
                printf("\n\tOpcion invalida");
                break;
        }


    } while ( op != 27);
}

void encabezado()
{
    printf("\n\t___________________________________________________________________________________________");
    printf("\n\n\t [1] - FILTRAR\t[2] - VER TODO\t[3] - MODIFICAR CLIENTE\t[4] - VER DETALLE\t[ESC] - SALIR");
    printf("\n\t___________________________________________________________________________________________");
}

void menuMostrarFiltrando(nodoArbol * arbol)
{
    char op, apellido[30], nombre[30];

    do
    {
        mostrarOpcionesDeFiltro();
        op = getch();

        switch (op)
        {
            case '1':
                printf("\n\tIngrese un Apellido, o parte del mismo :");
                fflush(stdin);
                gets(apellido);
                mostrarFiltrandoXApellido(arbolTemp,arbol);
                break;

            case '2':
                printf("\n\tIngrese un Nombre, o parte del mismo :");
                fflush(stdin);
                gets(nombre);
                mostrarFiltrandoXNombre(arbolTemp,arbol);
                break;

            case '3':
                mostrarFiltrandoXEstado(arbol,0);
                break;

            case '4':
                mostrarFiltrandoXEstado(arbol,1);
                break;

            default:
                printf("\n\tOpcion invalida");
                break;
        }


    } while ( op != 27 );

    return arbolTemp;
}

void mostrarOpcionesDeFiltro()
{
    printf("\n\n\tSeleccione una opcion : ");
    printf("\n\t\t[1] - Por Apellido : ");
    printf("\n\t\t[2] - Por Nombre : ");
    printf("\n\t\t[3] - En Alta : ");
    printf("\n\t\t[4] - En Baja : ");
    printf("\n\n\t\t[ESC] - Cancelar");
}

void mostrarFiltrandoXApellido(nodoArbol * arbol,char apellido[])
{
    if (arbol)
    {
        if ( strncmp(arbol->dato.apellido,apellido,strlen(apellido)) == 0)
        {
            mostrarCliente(arbol->dato);
        }

        mostrarFiltrandoXApellido(arbol->izq,apellido);
        mostrarFiltrandoXApellido(arbol->der,apellido);
    }
}

void mostrarFiltrandoXNombre(nodoArbol * arbol,char nombre[])
{
    if (arbol)
    {
        if ( strncmp(arbol->dato.nombre,nombre,strlen(nombre)) == 0)
        {
            mostrarCliente(arbol->dato);
        }

        mostrarFiltrandoXNombre(arbol->izq,nombre);
        mostrarFiltrandoXNombre(arbol->der,nombre);
    }
}

void mostrarFiltrandoXEstado(nodoArbol * arbol,int estado)
{
    if (arbol)
    {
        if ( arbol->dato.baja == estado )
        {
            mostrarCliente(arbol->dato);
        }

        mostrarFiltrandoXEstado(arbol->izq,estado);
        mostrarFiltrandoXEstado(arbol->der,estado);
    }
}


void
