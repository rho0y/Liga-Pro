#include <stdio.h>
#include <string.h>
#include "funciones.h"

void pausar()
{
    printf("\nPresione Enter para continuar...");
    // Limpia el buffer de entrada antes de esperar el Enter
    while (getchar() != '\n')
        ;
    getchar();
}

int main()
{
    int opcion;
    // Flag para saber si los datos ya fueron cargados en los archivos .bin
    int datosInicializados = 0;

    do
    {
        // system("cls"); // Descomentar para limpiar la pantalla en Windows
        printf("\n\n--- Menu Principal Liga Pro ---\n");
        printf("1. Cargar/Reiniciar Datos del Campeonato\n");
        printf("2. Ingresar Resultado de Partido\n");
        printf("3. Ver Tabla de Goleadores\n");
        printf("4. Ver Resultados de Partidos\n");
        printf("5. Ver Tabla de Posiciones\n");
        printf("6. Ver Jugadores Clave por Equipo\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");

        // Validar que la entrada sea un número
        if (scanf("%d", &opcion) != 1)
        {
            printf("Entrada no valida. Por favor, ingrese un número.\n");
            while (getchar() != '\n')
                ;        // Limpiar buffer
            opcion = -1; // Asignar opción inválida para que el switch no haga nada
        }

        switch (opcion)
        {
        case 1:
            inicializarDatos();
            datosInicializados = 1;
            printf("\nDatos del campeonato cargados y guardados con exito\n");
            printf("Ahora puede comenzar a ingresar resultados de partidos.\n");
            pausar();
            break;
        case 2:
            if (datosInicializados)
            {
                ingresarResultadoPartido();
            }
            else
            {
                printf("\nPrimero debe cargar los datos.\n");
            }
            pausar();
            break;
        case 3:
            if (datosInicializados)
            {
                mostrarJugadores();
            }
            else
            {
                printf("\nPrimero debe cargar los datos.\n");
            }
            pausar();
            break;
        case 4:
            if (datosInicializados)
            {
                mostrarPartidos();
            }
            else
            {
                printf("\nPrimero debe cargar los datos.\n");
            }
            pausar();
            break;
        case 5:
            if (datosInicializados)
            {
                mostrarTabla();
            }
            else
            {
                printf("\nPrimero debe cargar los datos.\n");
            }
            pausar();
            break;
        case 6:
            if (datosInicializados)
            {
                mostrarJugadoresClave();
            }
            else
            {
                printf("\nPrimero debe cargar los datos.\n");
            }
            pausar();
            break;
        case 0:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion no valida. Por favor, intente de nuevo.\n");
            pausar();
        }
    } while (opcion != 0);

    return 0;
}
