#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <windows.h>
namespace fs = std::filesystem;
using namespace std;

void crear_archivos(int cantidad) {
    string directorio = "C:\\Users\\Usuario\\Desktop\\";

    if (cantidad % 2 == 0) {
        directorio += "par";
    } else {
        directorio += "impar";
    }

    if (!fs::exists(directorio))
        fs::create_directory(directorio);

    for (int i = 1; i <= cantidad; ++i) {
        string ruta_archivo = directorio + "\\archivo" + to_string(i) + ".txt";

        ofstream archivo(ruta_archivo);
        if (archivo.is_open()) {
            for (int j = 0; j < i; ++j) {
                archivo << "Hola Inge :)" << endl;
            }
            archivo.close();
            cout << "Archivo creado: " << ruta_archivo << endl;
        } else {
            cout << "No se pudo crear el archivo " << ruta_archivo << endl;
        }
    }
}

int main() {
    int cantidad_archivos;
    cout << "¿Cuantos archivos desea crear? " << endl;
    cout << "Ingrese cantidad: ";
    cin >> cantidad_archivos;

    crear_archivos(cantidad_archivos);

    return 0;
}