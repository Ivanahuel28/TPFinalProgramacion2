#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(stDatos dato);
nodoArbol * insertar(nodoArbol * arbol, stDatos dato);

void preorder(nodoArbol * arbol);
void inorder(nodoArbol * arbol);
void postorder(nodoArbol * arbol);

nodoArbol * buscar(nodoArbol * arbol,stDatos dato);
int contarTerminales(nodoArbol * arbol);
nodoArbol * buscarNodoDiferido(nodoArbol * arbol,stDatos dato);
nodoArbol * arr2treeXApellido(nodoArbol * arbol,stPersona arr[],int base,int tope);
int contarElementos(nodoArbol * arbol);

nodoArbol * borrarNodo(nodoArbol * arbol,stDatos dato);
nodoArbol * NMD(nodoArbol * arbol);
nodoArbol * NMI(nodoArbol * arbol);

#endif // ARBOL_H_INCLUDED
