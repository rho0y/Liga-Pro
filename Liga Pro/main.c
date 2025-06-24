#include <stdio.h>
#include <string.h>
#include "funciones.h"

void mostrarMenu()
{
    printf("\n=================================================\n");
    printf("              ESTADISTICAS LIGA PRO               \n");
    printf("=================================================\n");
    printf("1. Inicializar datos del campeonato\n");
    printf("2. Mostrar tabla de goleadores\n");
    printf("3. Mostrar resultados de partidos\n");
    printf("4. Mostrar tabla de posiciones\n");
    printf("5. Mostrar jugadores clave por equipo\n");
    printf("0. Salir\n");
    printf("=================================================\n");
    printf("Ingrese una opcion: ");
}

void pausar()
{
    printf("\nPresione Enter para continuar...");
    while (getchar() != '\n')
        ;      // Limpiar el buffer
    getchar(); // Esperar por Enter
}

int main()
{
    int opcion = -1;
    int datosInicializados = 0;

    while (opcion != 0)
    {
        printf("\n\n"); // Separador visual en lugar de clear screen
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 0:
            printf("\nGracias por usar el sistema de estadisticas de Liga Pro!\n");
            break;

        case 1:
            inicializarDatos();
            datosInicializados = 1;
            printf("\nTodos los datos han sido inicializados correctamente!\n");
            pausar();
            break;

        case 2:
            if (!datosInicializados)
            {
                printf("\nPrimero debe inicializar los datos (opcion 1).\n");
            }
            else
            {
                mostrarJugadores();
            }
            pausar();
            break;

        case 3:
            if (!datosInicializados)
            {
                printf("\nPrimero debe inicializar los datos (opcion 1).\n");
            }
            else
            {
                mostrarPartidos();
            }
            pausar();
            break;

        case 4:
            if (!datosInicializados)
            {
                printf("\nPrimero debe inicializar los datos (opcion 1).\n");
            }
            else
            {
                mostrarTabla();
            }
            pausar();
            break;

        case 5:
            if (!datosInicializados)
            {
                printf("\nPrimero debe inicializar los datos (opcion 1).\n");
            }
            else
            {
                mostrarJugadoresClave();
            }
            pausar();
            break;

        default:
            printf("\nOpcion invalida. Por favor seleccione una opcion valida.\n");
            pausar();
            break;
        }
    }

    return 0;
}