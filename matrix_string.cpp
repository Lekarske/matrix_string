#include <iostream>
#include <iomanip>//estetico
#include <cctype>
using namespace std;

void ordenar(int (mat[3][3]),int m,int n){//ordena toda la matriz de menor a mayor -->O(n^2) siempre
     for(int i=0; i<m; i++){//los 2 primeros for para recorrer la matriz
        for(int j=0; j<n; j++){// y  obtener el elemento [i][j]
            for(int x=0; x<m;x++){//recorrer toda la matriz pero por cada elemento que tenga (si tiene 9 elementos recorrera 9*9=81 veces)
                for(int y=0; y<n; y++){//es para comparar el elemento [i][j] con todos los elemento de la matriz [x][y]
                    if(mat[i][j]<mat[x][y]){//si es mejor se intercambia
                        int aux=mat[i][j];//aux guarda el elemento[i][j] para el intercambio de valores
                        mat[i][j]=mat[x][y];
                        mat[x][y]=aux;
            		}}}
	}}return;
}

void calculos(int (mat[3][3]), int resultado[4],int m,int n){
	resultado[0] = mat[0][0];//siempre el minimo esta al principio
	resultado[1] = mat[2][2];//siempre el maximo esta al final
	resultado[2] = 0;//[2] por defecto tenia un valor...
	int aux = 0;//para contar las iteraciones
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			resultado[2]= resultado[2]+mat[i][j];
			aux++;
			if (aux ==(m*n)/2)//cuando llega a la mitad de elementos significa que es la mediana
				resultado[3] = mat[i][j];
		}
	}resultado[2]/=m*n;
	return;
}

void imprimir(int (mat[3][3]), int resultado[4],int m,int n){
//void imprimir(int resultado[4],int m,int n){
	cout << "Su matriz es:\n";
	for (int i=0;i<m;i++){//es solo imprimir la matriz
		for (int j=0;j<n;j++){//es solo imprimir la matriz
			cout << setw(4) << mat[i][j] << "  ";//es solo imprimir la matriz
		}cout << endl;
	}
	ordenar(mat,m,n);//llama la funcion
	calculos(mat, resultado,m,n);
	cout << "La matriz ordenada es:\n";
	for (int i=0;i<m;i++){//es solo imprimir la matriz
		for (int j=0;j<n;j++){//es solo imprimir la matriz
			cout << setw(4) << mat[i][j] << "  ";//es solo imprimir la matriz
		}cout << endl;
	}
	cout << "La matriz 'resultado' es:\n";//es solo imprimir la matriz
	cout << setw(4) <<"Min"<< "  "<< setw(4) <<"Max"<< "  "<< setw(4) <<"Pro"<< "  "<< setw(4) <<"Med"<< "  \n";
	for (int i=0;i<4;i++) cout << setw(4) << resultado[i] << "  ";//es solo imprimir la matriz
	return;
}

void limpiar(std::string cadena){//imprime la cadena limpia de elementos no-'letra'
	for (int i=0;i<cadena.size();i++){//recorre la cadena
		if (isalpha(cadena[i]))
			cout<<cadena[i];//si es letra lo imprime 
	}return;
}

 int main(){
 	string cadena;
 	int resultado[4];
	int m=3,n=3,x;//por si averiguo como generar una matrix no definida
 	cout << setw(9) <<"Matriz 3x3"<<"  (1)\n"<<setw(9)<<"String"<<"  (2)\n";
 	cout <<"Ingrese el numero de operacion que desea realizar: ";cin >> x;
	switch (x){//Una forma mas corta (codigo) de llamar las funciones segun el numero de operacion que eligio
		case 1:
			int mat[3][3];//no se como generar una matrix aun no definida... si pongo [m][n] genera error aun si m,n ya tienen valor
			for (int i=0;i<m;i++){
				cout << "Ingrese uno a uno los valores de la fila "<<i+1<<": "; 
				for (int j=0;j<n;j++) cin >> mat[i][j];
				}
			imprimir(mat, resultado, m, n); break;
			imprimir(mat, resultado, m, n); break;
		case 2: 
			cout << "Ingrese la cadena de caracteres "; cin >> cadena;
			cout << "La cadena con solo letras es: "; 
			limpiar(cadena);break;
		default: cout << "Numero invalido" ;
	}return 0;//segun sea el caso la funcion elegida sera llamada
}

