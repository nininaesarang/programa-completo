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
