#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

/*BASICAS*/
nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(stDatos dato);

/*INSERCION*/
nodoArbol * insertar(nodoArbol * arbol, stDatos dato);

/*MUESTRA / RECORRIDO*/
void preorder(nodoArbol * arbol);
void inorder(nodoArbol * arbol);
void postorder(nodoArbol * arbol);

/*BUSQUEDA*/
nodoArbol * buscar(nodoArbol * arbol,stDatos dato);
nodoArbol * buscarNodoDiferido(nodoArbol * arbol,stDatos dato);

/*CONTADORES*/
int contarElementos(nodoArbol * arbol);
int contarTerminales(nodoArbol * arbol);
int contarNiveles(nodoArbol * arbol);

/*BORRAR*/
nodoArbol * borrarNodo(nodoArbol * arbol,stDatos dato);
nodoArbol * NMD(nodoArbol * arbol);
nodoArbol * NMI(nodoArbol * arbol);

/*PASAJES*/
nodoArbol * arr2treeXApellido(nodoArbol * arbol,stDatos arr[],int base,int tope);

#endif // ARBOL_H_INCLUDED
