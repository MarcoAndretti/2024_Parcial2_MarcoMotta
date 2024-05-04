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
                archivo << "" << endl;
            }
            archivo.close();
            cout << "Archivo creado: " << ruta_archivo << endl;
        } else {
            cout << "No se pudo crear el archivo " << ruta_archivo << endl;
        }
    }
}

void agregar_texto_archivos(int cantidad, const string& texto) {
    string directorio = "C:\\Users\\Usuario\\Desktop\\";

    if (cantidad % 2 == 0) {
        directorio += "par";
    } else {
        directorio += "impar";
    }

    for (int i = 1; i <= cantidad; ++i) {
        string ruta_archivo = directorio + "\\archivo" + to_string(i) + ".txt";

        ofstream archivo(ruta_archivo, ios::app); // Abrir en modo append
        if (archivo.is_open()) {
            for (int j = 0; j < i; ++j) {
                archivo << texto << endl;
            }
            archivo.close();
            cout << "Texto agregado al archivo: " << ruta_archivo << endl;
        } else {
            cout << "No se pudo abrir el archivo " << ruta_archivo << endl;
        }
    }
}

int main() {
    int cantidad_archivos;
    cout << "¿Cuantos archivos desea crear? " << endl;
    cout << "Ingrese cantidad: ";
    cin >> cantidad_archivos;

    crear_archivos(cantidad_archivos);

    string texto_a_escribir;
    cout << "Ingrese el texto que desea escribir en los archivos: ";
    getline(cin >> ws, texto_a_escribir); // Leer línea completa incluyendo espacios

    agregar_texto_archivos(cantidad_archivos, texto_a_escribir);

    return 0;
}