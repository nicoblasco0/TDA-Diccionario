# Procesador de Texto — TDA Diccionario

Trabajo Práctico de la materia **Algoritmos y Estructuras de Datos**, 1C - 2025 — UNLaM

Este programa implementa un **procesador de textos** que permite analizar un archivo `.txt` para contar:
- La cantidad total de palabras, espacios y signos de puntuación
- La cantidad de apariciones de cada palabra
- Las 5 palabras más frecuentes del texto

Todo esto se realiza utilizando un **TDA Diccionario** implementado desde cero con hashing y listas, de forma totalmente genérica.

---

## 📁 Estructura del Proyecto

- `main.c` – Flujo principal del programa. Contiene la lógica del menú por consola, controla la ejecución general del sistema y coordina las llamadas a las funciones de procesamiento, estadísticas, podio y visualización interna del diccionario. También gestiona el ciclo de vida de la aplicación (inicio, reuso y liberación de estructuras).
- `diccionario.c / diccionario.h` – Implementación del TDA Diccionario (hash table).
- `procesador_texto.c/ procesador_texto.h` – Núcleo funcional del procesamiento textual.
- `lista.c / lista.h` – Lista simplemente enlazada genérica con inserción ordenada y soporte de actualización al encontrar duplicados.
- `podio.c / podio.h` – Implementa una lista simplemente enlazada ordenada limitada a N elementos. Su visualización incluye el formato posicional clásico de un ranking.
---

## 📋 Menú principal y funcionalidades

El programa cuenta con un menú interactivo por consola que guía al usuario a través de las funciones principales:

- 📂 **Procesar archivo de texto**  
  Solicita la ruta del archivo `.txt`, calcula automáticamente la capacidad ideal para el diccionario (según el tamaño del archivo), y analiza el texto para contar palabras, espacios, signos de puntuación, y registrar cada palabra en la tabla hash.

- 📊 **Mostrar estadísticas del texto**  
  Muestra el conteo total de palabras, espacios y signos, además del listado completo de palabras con su número de apariciones.

- 🏆 **Mostrar podio de palabras más frecuentes**  
  Permite al usuario ingresar un número `N` y muestra un podio con las `N` palabras más repetidas del texto, ordenadas por frecuencia.

- 🗂️ **Mostrar contenido del diccionario**  
  Visualiza la distribución interna del diccionario, mostrando los buckets y las palabras almacenadas en cada uno.

- ❌ **Salir**  
  Finaliza la ejecución del programa.
---
## 🧪 Casos de prueba

El repositorio incluye una serie de archivos `.txt` utilizados como **casos de prueba** para validar el funcionamiento completo del sistema, desde el análisis del texto hasta la distribución en la tabla hash y el podio de palabras más frecuentes:

- 📄 **prueba1.txt** – Texto clásico de prueba con palabras comunes, repeticiones y puntuación. Ideal para verificar estadísticas generales y funcionamiento del podio.
- 📄 **prueba2.txt** – Texto casi vacío, contiene únicamente tres espacios. Útil para validar el correcto conteo de espacios y comportamiento ante archivos sin palabras.
- 📄 **prueba3.txt** – Texto compuesto solo por signos de puntuación. Sirve para testear la lógica que diferencia palabras de símbolos.
- 📄 **prueba4.txt** – Otro texto de prueba más extenso, utilizado para validar la escalabilidad y la dispersión de la tabla hash.

> Todos los archivos se encuentran en el repositorio bajo la carpeta raíz, listos para ser utilizados con la opción 1 del menú del programa.

---
Gracias por visitar el repositorio.
