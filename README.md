# Convertidor de Infijo a Ensamblador

Proyecto de ingeniería enfocado en la lógica de compiladores que traduce expresiones aritméticas de notación infija a lenguaje ensamblador funcional.

## 🧠 Lógica del Proyecto
El programa realiza un proceso de traducción en tres etapas principales:
1. **Análisis:** Recibe una expresión aritmética (ej. `(A+B)*C`).
2. **Transformación:** Convierte la expresión a notación postfija (RPN) para facilitar su procesamiento lógico.
3. **Generación de Código:** Traduce la expresión resultante a instrucciones de bajo nivel (Assembly), gestionando el uso de registros y la pila (stack).

## 💻 Especificaciones Técnicas
* **Lenguaje:** C puro para un manejo eficiente de memoria y estructuras.
* **Salida:** Genera un archivo con las instrucciones equivalentes en ensamblador listas para ser analizadas.

**english**

# Infix to Assembler Converter

An engineering project focused on compiler logic that translates arithmetic expressions from infix notation to functional assembly language.

## 🧠 Project Logic
The program performs a translation process in three main stages:
1. **Analysis:** Receives an arithmetic expression (e.g., `(A+B)*C`).

2. **Transformation:** Converts the expression to postfix notation (RPN) to facilitate its logical processing.

3. **Code Generation:** Translates the resulting expression into low-level instructions (Assembly), managing the use of registers and the stack.

## 💻 Technical Specifications
* **Language:** Pure C for efficient memory and structure management.

* **Output:** Generates a file with the equivalent assembly instructions ready for analysis.
