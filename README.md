#  Piedra, Papel o Tijera

**Actividad 7 – Mini juego con persistencia de datos**  
**Materia:** Laboratorio de Programación – 5.º año  
**Institución:** EEST N.º 1 “Eduardo Ader” – Vicente López  
**Año:** 2026

##  Integrantes

- **Estudiante:** [Benjamin Hlynczuk]
- **Grupo:** [GAMY]

##  Descripción del proyecto

Este proyecto consiste en desarrollar un mini juego de **Piedra, Papel o Tijera** en C++, donde el usuario juega contra una inteligencia artificial que selecciona sus jugadas de manera aleatoria.

El programa permite jugar partidas, determinar automáticamente el resultado y guardar los datos de cada enfrentamiento en un archivo de texto. De esta manera, el historial permanece almacenado incluso después de cerrar el programa.

##  Objetivos

- Aplicar el uso de estructuras (`struct`) para organizar los datos de una partida.
- Utilizar archivos para guardar y recuperar información.
- Implementar escritura mediante `ofstream` y lectura mediante `ifstream`.
- Comprender el funcionamiento de `ios::app` para agregar registros sin sobrescribir los anteriores.
- Aplicar conceptos de persistencia de datos en un programa desarrollado en C++.

##  Funcionalidades

1. **Jugar una partida:** permite ingresar un nombre o nickname y elegir entre piedra, papel o tijera.
2. **Inteligencia artificial:** genera una jugada aleatoria.
3. **Determinación del resultado:** compara ambas elecciones y muestra si el jugador ganó, perdió o empató.
4. **Guardado automático:** registra cada partida en un archivo de texto.
5. **Consulta del historial:** permite visualizar las partidas guardadas anteriormente.
6. **Persistencia:** conserva los registros aunque el programa se cierre.

##  Datos almacenados

Cada partida se representa mediante una estructura llamada `Partida`, que contiene los siguientes campos:

| Campo | Descripción |
|---|---|
| `idPartida` | Identificador de la partida |
| `jugador` | Nombre o nickname del usuario |
| `eleccionJugador` | Jugada seleccionada por el usuario |
| `eleccionIA` | Jugada seleccionada por la IA |
| `resultado` | Victoria, derrota o empate |

Los registros se almacenan en `data/historial_partidas.txt`, utilizando un formato de datos separados por comas.

##  Tecnologías utilizadas

- **Lenguaje:** C++
- **Estándar:** C++11
- **Entorno de desarrollo:** Visual Studio Code
- **Compilador:** g++
- **Bibliotecas principales:** `iostream`, `fstream`, `string`, `cstdlib`, `ctime`, `limits` y `sstream`.

##  Instalación, compilación y ejecución

### Requisitos previos

- Tener instalado un compilador compatible con C++11, como g++.
- Contar con Visual Studio Code o una terminal para ejecutar los comandos.

### Compilar

Desde la carpeta principal del proyecto, ejecutar:

```bash
g++ -std=c++11 src/main.cpp -o src/piedrapapelotijera.exe
```

### Ejecutar

En Windows PowerShell:

```powershell
.\src\piedrapapelotijera.exe
```

**Importante:** la carpeta `data/` debe existir antes de ejecutar el programa para que pueda guardarse el historial correctamente.

##  Estructura del proyecto

```text
piedrapapelotijera/
│
├── .gitattributes
├── .gitignore
├── LICENSE
├── README.md
├── CHANGELOG.md
│
├── src/
│   └── main.cpp
│
├── data/
│   └── historial_partidas.txt
│
├── docs/
│   ├── informe.pdf
│   └── manuales/
│       ├── manual_programador_v1.0.0.md
│       ├── manual_programador_v1.0.0.pdf
│       ├── manual_usuario_v1.0.0.md
│       └── manual_usuario_v1.0.0.pdf
│
└── capturas/
    ├── jugada_consola.png
    └── archivo_disco.png
```

##  Evidencias

En la carpeta `capturas/` se incluyen imágenes que muestran:

- La ejecución del programa y una partida realizada desde la consola.
- El archivo de texto con los registros almacenados en el disco.

##  Documentación

Los manuales de usuario y programador se encuentran en `docs/manuales/`. Allí se explica cómo utilizar el sistema y cómo está organizado e implementado el código fuente.

##  Licencia

Este proyecto se desarrolla con fines educativos como parte de la Actividad 7 de Laboratorio de Programación.