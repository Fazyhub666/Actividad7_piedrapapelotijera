# Manual del usuario

## 1. Presentación

Este programa es un mini juego de **Piedra, Papel o Tijera**
desarrollado en C++. Permite jugar contra una computadora que elige su
jugada al azar y guarda automáticamente el resultado de cada partida en
un archivo de texto.

## 2. Requisitos para utilizarlo

-   Una computadora con Windows.
-   El ejecutable `piedrapapelotijera.exe`, generado a partir del código
    fuente.
-   La carpeta `data` dentro de la carpeta principal del proyecto.

No es necesario crear manualmente el archivo `historial_partidas.txt`:
el programa lo genera al guardar la primera partida, siempre que la
carpeta `data` ya exista.

## 3. Cómo iniciar el juego

1.  Abrir la carpeta principal del proyecto.
2.  Abrir una terminal en esa ubicación.
3.  Ejecutar el programa con el siguiente comando:

``` powershell
.\src\piedrapapelotijera.exe
```

Si todavía no se compiló el código, primero ejecutar:

``` powershell
g++ -std=c++11 src/main.cpp -o src/piedrapapelotijera.exe
```

## 4. Menú principal

Al iniciar, se muestra un menú con tres opciones:

1.  **Jugar partida:** comienza una nueva partida contra la computadora.
2.  **Ver historial de partidas:** muestra los registros guardados
    anteriormente.
3.  **Salir del sistema:** cierra el programa.

Para elegir una opción, escribir el número correspondiente y presionar
Enter.

## 5. Cómo jugar una partida

1.  Seleccionar la opción `1` en el menú principal.
2.  Escribir el nombre o nickname del jugador y presionar Enter.
3.  Elegir una jugada:
    -   `1` para Piedra.
    -   `2` para Papel.
    -   `3` para Tijera.
4.  Presionar Enter.
5.  El programa mostrará la elección del jugador, la elección aleatoria
    de la computadora y el resultado.

Las reglas son:

-   Piedra vence a Tijera.
-   Tijera vence a Papel.
-   Papel vence a Piedra.
-   Si ambos eligen lo mismo, el resultado es un empate.

El programa guarda la partida automáticamente al finalizarla.

## 6. Consultar el historial

1.  Volver al menú principal.
2.  Seleccionar la opción `2`.
3.  El programa mostrará las partidas registradas, incluyendo el
    identificador, el nombre del jugador, las dos elecciones y el
    resultado.

Si todavía no se jugaron partidas, se mostrará un aviso indicando que no
hay registros guardados.

## 7. Conservación de las partidas

Las partidas se almacenan en el archivo:

``` text
data/historial_partidas.txt
```

El historial no se pierde al cerrar el juego o apagar la computadora,
porque queda guardado en el disco. Cada nueva partida se agrega al final
del archivo sin eliminar las anteriores.

Por eso, se puede cerrar el programa, volver a abrirlo y consultar las
partidas anteriores desde la opción `2`.

## 8. Cómo salir

Seleccionar la opción `3` del menú principal. El programa mostrará un
mensaje de salida y finalizará.

## 9. Recomendaciones

-   Ingresar únicamente las opciones indicadas en pantalla.
-   Escribir el nombre sin comas, ya que el archivo utiliza comas para
    separar los datos.
-   No borrar ni modificar manualmente el archivo de historial si se
    desea conservar los registros.
-   Mantener la carpeta `data` dentro de la carpeta principal del
    proyecto.

------------------------------------------------------------------------

**Fin del manual del usuario.**
