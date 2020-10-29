#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void leerBytes(ifstream&, long, int);
int fsize(ifstream&);

int main(int argc, char const *argv[])
{
	string fileName;
	long int offset;
	int n;	

	cout << "Ingrese el nombre del archivo, desde donde quiere comenzar"
		 << "\ny la cantidad de caracteres a leer:" << endl;
	cin >> fileName >> offset >> n;

	ifstream File_in(fileName);

	if (!File_in){
		cout << "\nEl archivo no se abrió con éxito."
			 <<"\n Por favor compruebe que el archivo existe en realidad." << endl;
		exit(1);
	}

	leerBytes(File_in, offset, n);

	return 0;
}

void leerBytes(ifstream& File, long offset, int n){
	char c;
	int fileSize = fsize(File); //tamaño del archivo
	int m = fileSize - offset; // cantidad de caracteres desde offset hasta EOF

	if (offset > fileSize){
		cout << "Parametros de entrada invalidos para este archivo" << endl;
		exit(2); 
	}

	else if ( n > m){
		cout << "desde " << offset << " solo habian " << m << " caracteres" << endl;
		n = m;
	}

	File.seekg(offset, ios::beg);
	
	for (int i = 0; i < n; i++){
		c = File.get();
		cout << c;
	}

	cout << endl;
}

int fsize(ifstream& File){
	int size = 0;

	File.seekg(0, ios::end); // Posiciona el marcador al final
	size = File.tellg(); // obtiene el valor del marcador

	return size;
}