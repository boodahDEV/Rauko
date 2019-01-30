<<<<<<< HEAD
# C_compiler

C_compiler es un compilador básico elaborado en lenguaje C, capas de procesar y simular el comportamiento de un compilador en tiempo real.
Basado en procesar su propio tipo de lenguaje ~(aun sin un nombre en específico)~ el cual está basado en una combinación del propio **C** y algo de **Script** básico. 

### Ejecución y compilación 
Para ejecutar básicamente basta con ir mediante el terminal a la ruta `C_compiler/src` y colocamos el siguiente comando para compilar:
`gcc main.c -o ../Runner/main` y para ejecutar `../Runner/main`. _PD: El archivo fuente debe estar dentro la carpeta donde esta el fuente._ 
=======
# Rauko

Rauko es un compilador básico elaborado en lenguaje C, capas de procesar y simular el comportamiento de un compilador en tiempo real.
Basado en procesar su propio tipo de lenguaje ~(aun sin un nombre en específico)~ el cual está basado en una combinación del propio **C** y algo de **Script** básico.

### Ejecución y compilación
Para ejecutar básicamente basta con ir mediante el terminal a la ruta `Rauko/src` y colocamos el siguiente comando para compilar:
`gcc main.c -o ../Runner/main` y para ejecutar `../Runner/main`. _PD: El archivo fuente debe estar dentro la carpeta donde esta el fuente._
>>>>>>> d47f1d91807c6bfe907817b540c04498f11b3cdd

En futuras versiones incluira de forma nativa un script ejecutable, tanto para _Windows_ como para sistemas _Linux_.
- #### Es importante ejecutar mediante el terminal usando el compilador C en GCC en el cual podemos instalar en cualquier plataforma.
  - [MinGW](http://www.mingw.org/) : Windows 7/8/8.1/10  [_Ver como se instala_](https://www.technodyan.com/instalar-gcc-windows/)  .
  - **`$ sudo apt install gcc`** o **`$ sudo apt install build-essential`** :  Ubuntu 18.04 lts  [_Ver como se instala_](https://linuxconfig.org/how-to-install-gcc-the-c-compiler-on-ubuntu-18-04-bionic-beaver-linux)  .
- ###### Personalmente probé ejecutarlo en **_Dev C++ V5.11_** y generaba una serie de errores. Por este motivo recomiendo el uso mediante terminal.

### Lenguaje
El lenguaje que maneja este simulador de compilador está basado en una combinación del propio **C** y algo de **Script** básico. Este lenguaje esta aun en desarrollo y está adaptándose al compilador, pero hasta la versión v0.0.90 maneja las salidas a través de la función o comando: `lm` el cual significa LineMessage.

Un ejemplo para mostrar una salida correcta es
```lm ‘hola mundo’. ```
###### **En futuras versiones se podra manejar muchos mas atributos importantes que hacen de un lenguaje de programacion sea generalizado.**

### Contribuyendo
Las solicitudes de extracción son bienvenidas. Para cambios importantes, primero abra un problema para discutir qué le gustaría cambiar.

Por favor, asegúrese de actualizar las pruebas según corresponda.

## Licencia
[Apache 2.0](https://choosealicense.com/licenses/apache-2.0/)



###### PROYECTO AUN EN PAÑALES.
