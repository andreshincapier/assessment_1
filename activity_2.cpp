#include <iostream>
#include <queue>

int main() {
    // Declaración de la cola: usamos std::queue como contenedor FIFO
    std::queue<int> cola;
    int opcion;

    // Bucle principal que muestra el menú hasta que el usuario elige salir
    do {
        // Imprimir el menú de opciones
        std::cout << "\n=== Menú de Gestión de Cola ===\n";
        std::cout << "1. Insertar en cola\n";
        std::cout << "2. Borrar en cola\n";
        std::cout << "3. Listar cola\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese opción: ";
        std::cin >> opcion;

        // Evaluar la opción seleccionada
        switch (opcion) {
        case 1: {
            // Opción 1: insertar un nuevo elemento al fondo de la cola
            int valor;
            std::cout << "Ingrese un número entero a insertar: ";
            std::cin >> valor;
            cola.push(valor); // push añade al final de la cola
            std::cout << "Número " << valor << " insertado en la cola.\n";
            break;
        }
        case 2: {
            // Opción 2: eliminar el elemento del frente de la cola
            if (!cola.empty()) {
                int eliminado = cola.front(); // obtener el elemento del frente
                cola.pop();                   // pop elimina el frente
                std::cout << "Elemento " << eliminado << " eliminado de la cola.\n";
            }
            else {
                std::cout << "La cola está vacía, nada que borrar.\n";
            }
            break;
        }
        case 3: {
            // Opción 3: listar todos los elementos de la cola de frente a fondo
            if (cola.empty()) {
                std::cout << "La cola está vacía.\n";
            }
            else {
                std::cout << "Contenido de la cola (de frente a fondo): ";
                // Usar copia para no modificar la cola original
                std::queue<int> copia = cola;
                while (!copia.empty()) {
                    std::cout << copia.front() << " ";
                    copia.pop();
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
