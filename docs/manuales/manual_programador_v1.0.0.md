# Manual del programador

## 1. Información general

**Proyecto:** Mini juego Piedra, Papel o Tijera\
**Materia:** Laboratorio de Programación\
**Lenguaje:** C++\
**Estándar de compilación:** C++11\
**Archivo principal:** `src/main.cpp`\
**Archivo de persistencia:** `data/historial_partidas.txt`

## 2. Objetivo del programa

El programa permite jugar Piedra, Papel o Tijera contra una computadora
que selecciona su jugada de manera aleatoria. Cada partida se registra
en un archivo de texto para conservar el historial aunque el programa se
cierre.

## 3. Organización del proyecto

La estructura utilizada es:

``` text
piedrapapelotijera/
├── src/
│   └── main.cpp
├── data/
│   └── historial_partidas.txt
├── docs/
│   └── manuales/
└── capturas/
```

La carpeta `data` debe existir antes de ejecutar el programa. El archivo
`historial_partidas.txt` se crea automáticamente al guardar la primera
partida.

## 4. Bibliotecas utilizadas

-   `iostream`: permite mostrar información y recibir datos mediante la
    consola.
-   `fstream`: permite leer y escribir archivos.
-   `string`: permite trabajar con cadenas de texto.
-   `cstdlib`: proporciona funciones como `rand()` y `srand()`.
-   `ctime`: permite inicializar la semilla de números aleatorios con la
    hora.
-   `limits`: permite limpiar correctamente el búfer de entrada.
-   `sstream`: permite analizar el identificador de cada registro del
    historial.

## 5. Estructura de datos

Se utiliza la estructura `Partida` para agrupar los datos de una jugada:

``` cpp
struct Partida {
    int idPartida;
    string jugador;
    string eleccionJugador;
    string eleccionIA;
    string resultado;
};
```

Sus campos representan el número de partida, el nombre del jugador, las
elecciones del jugador y de la IA, y el resultado final.

## 6. Funciones principales

### `int obtenerSiguienteID()`

Lee el archivo de historial y determina el próximo identificador
disponible. Si todavía no existen registros, devuelve el valor inicial
`1`.

### `void jugarPartida(int& contadorID)`

Controla una partida completa: solicita el nombre, recibe una elección
válida, genera la jugada aleatoria de la IA, determina el resultado y
solicita guardar los datos.

El parámetro `contadorID` se pasa por referencia para actualizar el
contador utilizado por el programa.

### `void guardarEnDisco(const Partida& p)`

Abre el archivo `data/historial_partidas.txt` con `ofstream` y el modo
`ios::app`. Esto permite agregar el nuevo registro al final del archivo
sin borrar las partidas anteriores.

Los campos se guardan separados por comas, en el siguiente orden:

``` text
ID,Jugador,EleccionJugador,EleccionIA,Resultado
```

### `void leerHistorialDisco()`

Abre el archivo mediante `ifstream`, lee los campos separados por comas
y muestra cada partida en la consola.

## 7. Persistencia de datos

La persistencia se realiza mediante un archivo de texto ubicado en
`data/historial_partidas.txt`.

-   `ofstream`: escribe los datos de una partida.
-   `ios::app`: agrega información al final del archivo.
-   `ifstream`: recupera los registros guardados.

Los datos permanecen almacenados en el disco después de cerrar el
programa. Al iniciar una nueva ejecución, `obtenerSiguienteID()` revisa
el historial para continuar la numeración.

## 8. Compilación y ejecución

Desde la terminal de PowerShell, ubicada en la carpeta principal del
proyecto, ejecutar:

``` powershell
g++ -std=c++11 src/main.cpp -o src/piedrapapelotijera.exe
```

Luego iniciar el programa con:

``` powershell
.\src\piedrapapelotijera.exe
```

## 9. Consideraciones técnicas

-   La carpeta `data` debe existir para que el programa pueda crear el
    archivo de historial.
-   Las opciones de menú y de jugada se validan para evitar entradas
    numéricas fuera del rango permitido.
-   El nombre del jugador se lee con `getline()` para admitir espacios.
-   Se utiliza `cin.ignore()` para descartar el salto de línea pendiente
    antes de leer el nombre.
-   El formato de almacenamiento utiliza comas como separadores. Por ese
    motivo, se recomienda no ingresar comas en el nombre del jugador.
-   El programa espera que cada registro del archivo mantenga el formato
    indicado.

## 10. Posibles mejoras futuras

Como ampliaciones, se podría incorporar una validación más completa de
los datos del archivo, permitir exportar estadísticas o agregar un
resumen de victorias, derrotas y empates.

------------------------------------------------------------------------

**Fin del manual del programador.**
