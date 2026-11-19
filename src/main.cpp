/* 
   ====================================================================
   Materia: Laboratorio de Programación (LPR) — 5° Año
   Institución: E.E.S.T. N° 1 "Eduardo Ader" — Vicente López
   Archivo: src/main.cpp
   Actividad 7: Mini Juego Piedra, Papel o Tijera + Persistencia en Disco
   ====================================================================
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <sstream>

using namespace std;

// Archivo donde se guardara el historial de partidas
const string ARCHIVO_HISTORIAL = "data/historial_partidas.txt";

// Estructura para representar una partida
struct Partida {
    int idPartida;
    string jugador;
    string eleccionJugador;
    string eleccionIA;
    string resultado;
};

// Prototipos de funciones
int obtenerSiguienteID();
void jugarPartida(int& contadorID);
void guardarEnDisco(const Partida& p);
void leerHistorialDisco();

int main() {

    // Inicializar numeros aleatorios
    srand(time(0));

    // Recuperar el siguiente ID disponible
    int contadorID = obtenerSiguienteID();

    int opcion = 0;

    cout << "=====================================================" << endl;
    cout << "  LPR 2026 - ACTIVIDAD 7: PIEDRA, PAPEL O TIJERA      " << endl;
    cout << "  Estudiante / Grupo: [Benjamin Hlynczuk]         " << endl;
    cout << "=====================================================" << endl;

    do {

        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1. Jugar partida" << endl;
        cout << "2. Ver historial de partidas" << endl;
        cout << "3. Salir del sistema" << endl;
        cout << "Ingrese una opcion (1-3): ";

        cin >> opcion;

        // Controlar entradas incorrectas
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n[ERROR] Debe ingresar un numero." << endl;
            continue;
        }

        if (opcion == 1) {
            jugarPartida(contadorID);
        }
        else if (opcion == 2) {
            leerHistorialDisco();
        }
        else if (opcion == 3) {
            cout << "\n[SISTEMA] Saliendo del programa..." << endl;
            cout << "[SISTEMA] Los datos permanecen guardados en disco." << endl;
        }
        else {
            cout << "\n[ERROR] Opcion invalida. Reintente." << endl;
        }

    } while (opcion != 3);

    return 0;
}

// Obtener el siguiente ID para evitar repetir numeros
int obtenerSiguienteID() {

    ifstream archivo(ARCHIVO_HISTORIAL);

    int siguienteID = 1;
    string linea;

    while (getline(archivo, linea)) {

        stringstream ss(linea);
        int id;
        char separador;

        if (ss >> id >> separador && separador == ',') {

            if (id >= siguienteID) {
                siguienteID = id + 1;
            }
        }
    }

    archivo.close();

    return siguienteID;
}

// Funcion para jugar contra la inteligencia artificial
void jugarPartida(int& contadorID) {

    Partida p;

    p.idPartida = contadorID++;

    cout << "\n--- NUEVA PARTIDA #" << p.idPartida << " ---" << endl;

    cout << "Ingrese su nombre / nickname: ";

    // Limpiar el buffer del teclado
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, p.jugador);

    int opcJugador = 0;

    // Solicitar una jugada valida
    do {

        cout << "\nElija su jugada:" << endl;
        cout << "1. Piedra" << endl;
        cout << "2. Papel" << endl;
        cout << "3. Tijera" << endl;
        cout << "Opcion (1-3): ";

        cin >> opcJugador;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcJugador = 0;
        }

        if (opcJugador < 1 || opcJugador > 3) {
            cout << "\n[ERROR] Seleccione una opcion entre 1 y 3." << endl;
        }

    } while (opcJugador < 1 || opcJugador > 3);

    // Asignar eleccion del jugador
    if (opcJugador == 1) {
        p.eleccionJugador = "Piedra";
    }
    else if (opcJugador == 2) {
        p.eleccionJugador = "Papel";
    }
    else {
        p.eleccionJugador = "Tijera";
    }

    // Generar eleccion aleatoria de la IA
    int opcIA = (rand() % 3) + 1;

    if (opcIA == 1) {
        p.eleccionIA = "Piedra";
    }
    else if (opcIA == 2) {
        p.eleccionIA = "Papel";
    }
    else {
        p.eleccionIA = "Tijera";
    }

    // Mostrar elecciones
    cout << "\n[JUGADA] " << p.jugador
         << " eligio: " << p.eleccionJugador << endl;

    cout << "[JUGADA] La IA eligio: "
         << p.eleccionIA << endl;

    // Evaluar resultado
    if (p.eleccionJugador == p.eleccionIA) {

        p.resultado = "Empate";

    }
    else if (
        (p.eleccionJugador == "Piedra" && p.eleccionIA == "Tijera") ||
        (p.eleccionJugador == "Papel" && p.eleccionIA == "Piedra") ||
        (p.eleccionJugador == "Tijera" && p.eleccionIA == "Papel")
    ) {

        p.resultado = "Victoria";

    }
    else {

        p.resultado = "Derrota";

    }

    cout << "\n===================================" << endl;
    cout << "       RESULTADO: " << p.resultado << endl;
    cout << "===================================" << endl;

    // Guardar la partida en el disco
    guardarEnDisco(p);
}

// Funcion para guardar partidas en el archivo
void guardarEnDisco(const Partida& p) {

    // ios::app agrega datos sin borrar los anteriores
    ofstream archivo(ARCHIVO_HISTORIAL, ios::app);

    if (!archivo.is_open()) {

        cerr << "[ERROR] No se pudo abrir el archivo para guardar." << endl;
        return;

    }

    // Guardar los datos separados por comas
    archivo << p.idPartida << ","
            << p.jugador << ","
            << p.eleccionJugador << ","
            << p.eleccionIA << ","
            << p.resultado << endl;

    archivo.close();

    cout << "\n[DISCO] Partida guardada correctamente." << endl;
}

// Funcion para recuperar y mostrar el historial
void leerHistorialDisco() {

    ifstream archivo(ARCHIVO_HISTORIAL);

    if (!archivo.is_open()) {

        cout << "\n[AVISO] Todavia no existen partidas guardadas." << endl;
        return;

    }

    cout << "\n=====================================================" << endl;
    cout << "       HISTORIAL DE PARTIDAS GUARDADAS" << endl;
    cout << "=====================================================" << endl;

    string idStr;
    string jugador;
    string elJug;
    string elIA;
    string resultado;

    int total = 0;

    // Leer los datos separados por comas
    while (
        getline(archivo, idStr, ',') &&
        getline(archivo, jugador, ',') &&
        getline(archivo, elJug, ',') &&
        getline(archivo, elIA, ',') &&
        getline(archivo, resultado)
    ) {

        total++;

        cout << "\nPartida #" << idStr << endl;
        cout << "Jugador: " << jugador << endl;
        cout << "Eleccion del jugador: " << elJug << endl;
        cout << "Eleccion de la IA: " << elIA << endl;
        cout << "Resultado: " << resultado << endl;

        cout << "-----------------------------------" << endl;
    }

    archivo.close();

    if (total == 0) {
        cout << "[AVISO] El historial esta vacio." << endl;
    }
    else {
        cout << "\n[SISTEMA] Total de partidas recuperadas: "
             << total << endl;
    }

    cout << "=====================================================" << endl;
}
