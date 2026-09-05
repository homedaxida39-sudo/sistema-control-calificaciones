#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// ============================================================================
// DECLARACIÓN ANTICIPADA (Forward Declaration) - Función recursiva
// ============================================================================
int sumaHasta(int n);

// ============================================================================
// FUNCIÓN 1: Leer y validar una nota
// Propósito: Solicitar una nota al usuario y validar que esté en rango 0-100
// Parámetros: ninguno
// Retorna: int (la nota válida)
// ============================================================================
int leerNotaValida() {
    int nota;
    bool valida = false;
    
    while (!valida) {
        cout << "Ingrese una nota (0-100): ";
        cin >> nota;
        
        // Validación: verificar que esté en el rango correcto
        if (nota >= 0 && nota <= 100) {
            valida = true;
        } else {
            cout << "ERROR: La nota debe estar entre 0 y 100. Intente de nuevo.\n";
        }
    }
    
    return nota;
}

// ============================================================================
// FUNCIÓN 2: Calcular el promedio
// Propósito: Recibir tres notas y calcular su promedio
// Parámetros: nota1, nota2, nota3 (valores enteros)
// Retorna: double (el promedio)
// ============================================================================
double calcularPromedio(int nota1, int nota2, int nota3) {
    double promedio = (nota1 + nota2 + nota3) / 3.0;
    return promedio;
}

// ============================================================================
// FUNCIÓN 3: Determinar si está aprobado o reprobado
// Propósito: Evaluar si el promedio cumple con la condición de aprobación
// Parámetros: promedio (valor double)
// Retorna: bool (true = aprobado, false = reprobado)
// ============================================================================
bool estaAprobado(double promedio) {
    return promedio >= 61;
}

// ============================================================================
// PROCEDIMIENTO (void): Mostrar reporte completo
// Propósito: Mostrar de forma formateada toda la información del estudiante
// Parámetros: nombre, nota1, nota2, nota3, promedio, aprobado
// Retorna: nada (void)
// ============================================================================
void mostrarReporte(string nombre, int nota1, int nota2, int nota3, 
                     double promedio, bool aprobado) {
    cout << "\n";
    cout << "========================================\n";
    cout << "       REPORTE DE CALIFICACIONES\n";
    cout << "========================================\n";
    cout << "Nombre del estudiante: " << nombre << "\n";
    cout << "----------------------------------------\n";
    cout << "Nota 1: " << nota1 << "\n";
    cout << "Nota 2: " << nota2 << "\n";
    cout << "Nota 3: " << nota3 << "\n";
    cout << "----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Promedio: " << promedio << "\n";
    cout << "----------------------------------------\n";
    
    if (aprobado) {
        cout << "RESULTADO: APROBADO ✓\n";
    } else {
        cout << "RESULTADO: REPROBADO ✗\n";
    }
    
    cout << "========================================\n\n";
}

// ============================================================================
// FUNCIÓN RECURSIVA: Suma de números hasta n
// Propósito: Calcular la suma 1 + 2 + 3 + ... + n usando recursividad
// Parámetros: n (int)
// Retorna: int (la suma total)
// 
// EXPLICACIÓN DE LA RECURSIVIDAD:
// - CASO BASE: cuando n == 1, retorna 1 (termina la recursión)
// - CASO RECURSIVO: n + sumaHasta(n-1) (se acerca progresivamente al caso base)
// 
// Ejemplo: sumaHasta(5)
//   = 5 + sumaHasta(4)
//   = 5 + (4 + sumaHasta(3))
//   = 5 + (4 + (3 + sumaHasta(2)))
//   = 5 + (4 + (3 + (2 + sumaHasta(1))))
//   = 5 + (4 + (3 + (2 + 1)))
//   = 15
// ============================================================================
int sumaHasta(int n) {
    // CASO BASE: cuando n llega a 1, detener la recursión
    if (n == 1) {
        return 1;
    }
    
    // CASO RECURSIVO: n más la suma de todos los números anteriores
    return n + sumaHasta(n - 1);
}

// ============================================================================
// FUNCIÓN PRINCIPAL: main() como coordinador
// Propósito: Coordinar el flujo del programa llamando a las funciones
// ============================================================================
int main() {
    cout << "╔════════════════════════════════════════╗\n";
    cout << "║ SISTEMA DE CONTROL DE CALIFICACIONES  ║\n";
    cout << "║         Desarrollo Modular en C++      ║\n";
    cout << "╚════════════════════════════════════════╝\n\n";
    
    // Variables locales
    string nombre;
    int nota1, nota2, nota3;
    double promedio;
    bool aprobado;
    int opcion;
    
    // MENÚ PRINCIPAL
    do {
        cout << "\n--- MENÚ PRINCIPAL ---\n";
        cout << "1. Procesar calificaciones de un estudiante\n";
        cout << "2. Probar función recursiva sumaHasta(n)\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar buffer después de leer número
        
        if (opcion == 1) {
            // ========== SECCIÓN 1: PROCESAMIENTO DE CALIFICACIONES ==========
            
            // Paso 1: Solicitar nombre
            cout << "\n--- INGRESO DE DATOS ---\n";
            cout << "Ingrese el nombre del estudiante: ";
            getline(cin, nombre);
            
            // Paso 2: Solicitar tres notas (con validación)
            cout << "\nIngrese las tres notas del estudiante:\n";
            nota1 = leerNotaValida();
            nota2 = leerNotaValida();
            nota3 = leerNotaValida();
            
            // Paso 3: Calcular promedio (usando función)
            promedio = calcularPromedio(nota1, nota2, nota3);
            
            // Paso 4: Determinar si aprobó (usando función)
            aprobado = estaAprobado(promedio);
            
            // Paso 5: Mostrar reporte (usando procedimiento void)
            mostrarReporte(nombre, nota1, nota2, nota3, promedio, aprobado);
            
        } else if (opcion == 2) {
            // ========== SECCIÓN 2: PRUEBA DE RECURSIVIDAD ==========
            
            int n;
            cout << "\n--- FUNCIÓN RECURSIVA: sumaHasta(n) ---\n";
            cout << "Ingrese un número entero positivo (n): ";
            cin >> n;
            
            if (n > 0) {
                int resultado = sumaHasta(n);
                cout << "\nCálculo: 1 + 2 + 3 + ... + " << n << " = " << resultado << "\n";
                cout << "\nVerificación con fórmula n(n+1)/2 = " << (n * (n + 1)) / 2 << "\n";
            } else {
                cout << "ERROR: El número debe ser positivo.\n";
            }
            
        } else if (opcion == 3) {
            cout << "\n¡Gracias por usar el Sistema de Control de Calificaciones!\n";
            break;
        } else {
            cout << "Opción inválida. Intente de nuevo.\n";
        }
        
    } while (true);
    
    return 0;
}
