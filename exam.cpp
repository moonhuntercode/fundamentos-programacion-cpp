// main.cpp
#include <iostream>  // 📦 Importa la biblioteca iostream para entrada/salida.
#include <algorithm> // 📚 Importa la biblioteca algorithm para usar std::min.
#include <limits>    // 📊 Importa la biblioteca limits para std::numeric_limits, una buena práctica para el valor máximo.

// Ejercicio I: Multiplicación en Cadena de Matrices

// Usamos std::numeric_limits para obtener el valor máximo de un int.
// Es una práctica más moderna y segura que usar un número mágico.
// Esto evita problemas de desbordamiento y hace el código más portable.
const int MAX_INT = std::numeric_limits<int>::max(); // ⬆️ Define un valor máximo para inicializar el 'menor'.

/**
 * @brief Calcula el número mínimo de multiplicaciones escalares para una cadena de matrices.
 * Utiliza un enfoque de programación dinámica.
 * @param arr Array que contiene las dimensiones de las matrices.
 * Si las matrices son A(d1xd2), B(d2xd3), C(d3xd4), el array sería {d1, d2, d3, d4}.
 * @param i Índice de inicio de la subcadena de matrices (basado en 1 para la función).
 * @param j Índice de fin de la subcadena de matrices (basado en 1 para la función).
 * @return El número mínimo de multiplicaciones.
 */
int oMatriz(int arr[], int i, int j) {
    // 🧐 Caso base: Si solo hay una matriz (i y j son iguales), no se necesitan multiplicaciones. [cite: 1]
    if (i == j) { [cite: 1]
        return 0; [cite: 1]
    }

    int menor = MAX_INT; // 📉 Inicializa el mínimo con un valor muy grande. [cite: 1]

    // 🔄 Itera sobre todos los posibles puntos de división (k) de la cadena de matrices. [cite: 1]
    for (int k = i; k < j; k++) { [cite: 1]
        // 🧪 Calcula el costo de multiplicar las subcadenas y luego las dos matrices resultantes. [cite: 1]
        // La fórmula es: costo(i, k) + costo(k+1, j) + costo de multiplicar las dos matrices resultantes. [cite: 1]
        // arr[i-1] * arr[k] * arr[j] representa el costo de la multiplicación de las dos matrices resultantes. [cite: 1]
        int resultado = oMatriz(arr, i, k) + oMatriz(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j]; [cite: 1]

        // 🎯 Actualiza el mínimo si encontramos un resultado menor. [cite: 1]
        menor = std::min(resultado, menor); [cite: 1]
    }

    return menor; // 🏆 Retorna el número mínimo de multiplicaciones. [cite: 1]
}

// Ejercicio II: Función de Suma Simple

/**
 * @brief Implementa la función 's' del pseudocódigo en C++.
 * Simula un algoritmo de suma simple: c + d.
 * @param c Primer número natural.
 * @param d Segundo número natural.
 * @return La suma de c y d.
 */
int s(int c, int d) {
    int contador = 1;   // 🔢 Inicializa el contador.
    int resultado = c;  // 🎯 Inicializa el resultado con el valor de 'c'.

    // 🔄 El bucle se ejecuta 'd' veces.
    // En cada iteración, se incrementa el resultado en 1.
    while (contador <= d) {
        resultado++; // ➕ Incrementa el resultado en 1 (equivalente a resultado = resultado + 1).
        contador++;  // ⬆️ Incrementa el contador.
    }

    return resultado; // ✅ Devuelve el resultado final.
}

int main() {
    // --- Pruebas para el Ejercicio I ---
    std::cout << "--- Ejercicio I: Multiplicacion de Matrices ---" << std::endl;
    // 🔢 Define las dimensiones de las matrices. [cite: 1]
    // Ejemplo: arr[] = {20, 12, 96, 10, 41} representa matrices de (20x12), (12x96), (96x10), (10x41). [cite: 1]
    int arr[] = {20, 12, 96, 10, 41}; [cite: 1]

    // 📏 Calcula el número de elementos en el array (número de dimensiones). [cite: 1]
    // 'n' es la cantidad de dimensiones, el número de matrices es 'n - 1'. [cite: 1]
    int n = sizeof(arr) / sizeof(arr[0]); [cite: 1]

    // ✍️ Imprime el resultado del Ejercicio I. [cite: 1]
    // La llamada a oMatriz(arr, 1, n - 1) es porque el algoritmo de la matriz encadenada
    // usa un índice basado en 1 para las matrices. [cite: 1]
    std::cout << "Cantidad de multiplicaciones minimo: " << oMatriz(arr, 1, n - 1) << std::endl; [cite: 1]
    std::cout << std::endl; // Salto de línea para separar la salida.

    // --- Pruebas para el Ejercicio II ---
    std::cout << "--- Ejercicio II: Funcion de Suma ---" << std::endl;
    // Ejemplos de uso para determinar el reporte.
    // Puedes cambiar estos valores para probar diferentes escenarios.
    int valor_c_1 = 5;
    int valor_d_1 = 3;
    std::cout << "Resultado de s(" << valor_c_1 << ", " << valor_d_1 << "): " << s(valor_c_1, valor_d_1) << std::endl;

    int valor_c_2 = 10;
    int valor_d_2 = 0;
    std::cout << "Resultado de s(" << valor_c_2 << ", " << valor_d_2 << "): " << s(valor_c_2, valor_d_2) << std::endl;

    int valor_c_3 = 1;
    int valor_d_3 = 5;
    std::cout << "Resultado de s(" << valor_c_3 << ", " << valor_d_3 << "): " << s(valor_c_3, valor_d_3) << std::endl;

    return 0; // ✅ Indica que el programa finalizó correctamente.
}