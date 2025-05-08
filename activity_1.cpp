#include <iostream>
#include <vector>

int main() {
    // Declaración de la pila: usamos std::vector como contenedor dinámico
    std::vector<int> pila;
    int opcion;

    // Bucle principal que muestra el menú hasta que el usuario elige salir
    do {
        // Imprimir el menú de opciones
        std::cout << "\n=== Menú de Gestión de Pila ===\n";
        std::cout << "1. Insertar en pila\n";
        std::cout << "2. Borrar en pila\n";
        std::cout << "3. Listar pila\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese opción: ";
        std::cin >> opcion;

        // Evaluar la opción seleccionada
        switch (opcion) {
        case 1: {
            // Opción 1: insertar un nuevo elemento al tope de la pila
            int valor;
            std::cout << "Ingrese un número entero a insertar: ";
            std::cin >> valor;
            pila.push_back(valor); // push_back añade al final, simulando el tope
            std::cout << "Número " << valor << " insertado en la pila.\n";
            break;
        }
        case 2: {
            // Opción 2: eliminar el elemento del tope de la pila
            if (!pila.empty()) {
                int eliminado = pila.back(); // obtener el elemento del tope
                pila.pop_back();             // pop_back elimina el tope
                std::cout << "Elemento " << eliminado << " eliminado de la pila.\n";
            }
            else {
                std::cout << "La pila está vacía, nada que borrar.\n";
            }
            break;
        }
        case 3: {
            // Opción 3: listar todos los elementos de la pila de cima a base
            if (pila.empty()) {
                std::cout << "La pila está vacía.\n";
            }
            else {
                std::cout << "Contenido de la pila (de cima a base): ";
                for (int i = static_cast<int>(pila.size()) - 1; i >= 0; --i) {
                    std::cout << pila[i] << " ";
                }
                std::cout << "\n";
            }
            break;
        }
        case 4:
            // Opción 4: salir del programa
            std::cout << "Saliendo del programa. ¡Hasta luego!\n";
            break;
        default:
            // Manejo de opción inválida
            std::cout << "Opción inválida, por favor seleccione entre 1 y 4.\n";
        }
    } while (opcion != 4);

    return 0;
}
