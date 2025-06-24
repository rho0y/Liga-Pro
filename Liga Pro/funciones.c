#include "funciones.h"
#include <stdio.h>
#include <string.h>

// Función para guardar jugadores en archivo binario
void guardarJugadores(Jugador jugadores[], int cantidad)
{
    FILE *f;
    f = fopen("jugadores.bin", "wb");
    if (f == NULL)
    {
        printf("Error al abrir el archivo de jugadores.\n");
        return;
    }
    fwrite(jugadores, sizeof(Jugador), cantidad, f);
    fclose(f);
    printf("Datos de jugadores guardados correctamente.\n");
}

// Función para guardar partidos en archivo binario
void guardarPartidos(Partido partidos[], int cantidad)
{
    FILE *f;
    f = fopen("partidos.bin", "wb");
    if (f == NULL)
    {
        printf("Error al abrir el archivo de partidos.\n");
        return;
    }
    fwrite(partidos, sizeof(Partido), cantidad, f);
    fclose(f);
    printf("Datos de partidos guardados correctamente.\n");
}

// Función para guardar tabla de posiciones en archivo binario
void guardarTabla(EquipoTabla equipos[], int cantidad)
{
    FILE *f;
    f = fopen("tabla.bin", "wb");
    if (f == NULL)
    {
        printf("Error al abrir el archivo de tabla de posiciones.\n");
        return;
    }
    fwrite(equipos, sizeof(EquipoTabla), cantidad, f);
    fclose(f);
    printf("Datos de tabla de posiciones guardados correctamente.\n");
}

// Función para guardar jugadores clave en archivo binario
void guardarJugadoresClave(EquipoJugadores equipos[], int cantidad)
{
    FILE *f;
    f = fopen("jugadoresClave.bin", "wb");
    if (f == NULL)
    {
        printf("Error al abrir el archivo de jugadores clave.\n");
        return;
    }
    fwrite(equipos, sizeof(EquipoJugadores), cantidad, f);
    fclose(f);
    printf("Datos de jugadores clave guardados correctamente.\n");
}

// Función para leer y mostrar jugadores desde archivo binario
void mostrarJugadores()
{
    FILE *f;
    Jugador jugador;

    f = fopen("jugadores.bin", "rb");
    if (f == NULL)
    {
        printf("Error al abrir el archivo de jugadores.\n");
        return;
    }

    printf("\n--- LISTA DE GOLEADORES ---\n");
    printf("%-30s %-20s %s\n", "Jugador", "Equipo", "Goles");
    printf("-------------------------------------------------------\n");

    while (fread(&jugador, sizeof(Jugador), 1, f) == 1)
    {
        printf("%-30s %-20s %d\n", jugador.nombre, jugador.equipo, jugador.goles);
    }

    fclose(f);
}

// Función para leer y mostrar partidos desde archivo binario
void mostrarPartidos()
{
    FILE *f;
    Partido partido;

    f = fopen("partidos.bin", "rb");
    if (f == NULL)
    {
        printf("Error al abrir el archivo de partidos.\n");
        return;
    }

    printf("\n--- RESULTADOS DE PARTIDOS ---\n");
    printf("%-25s %-12s %-35s %-20s\n", "Partido", "Resultado", "Goleadores", "Estadísticas Clave");
    printf("-------------------------------------------------------------------------------------------------------\n");

    while (fread(&partido, sizeof(Partido), 1, f) == 1)
    {
        printf("%-25s %-12s %-35s %-20s\n",
               partido.nombrePartido,
               partido.resultado,
               partido.goleadores,
               partido.estadisticas);
    }

    fclose(f);
}

// Función para leer y mostrar tabla de posiciones desde archivo binario
void mostrarTabla()
{
    FILE *f;
    EquipoTabla equipo;

    f = fopen("tabla.bin", "rb");
    if (f == NULL)
    {
        printf("Error al abrir el archivo de tabla de posiciones.\n");
        return;
    }

    printf("\n--- TABLA DE POSICIONES ---\n");
    printf("%-3s %-25s %-3s %-3s %-3s %-3s %-3s %-3s %-4s %-3s\n",
           "Pos", "Equipo", "PJ", "G", "E", "P", "GF", "GC", "DG", "Pts");
    printf("------------------------------------------------------------------------\n");

    while (fread(&equipo, sizeof(EquipoTabla), 1, f) == 1)
    {
        printf("%-3d %-25s %-3d %-3d %-3d %-3d %-3d %-3d %-+4d %-3d\n",
               equipo.posicion,
               equipo.nombre,
               equipo.partidosJugados,
               equipo.partidosGanados,
               equipo.partidosEmpatados,
               equipo.partidosPerdidos,
               equipo.golesFavor,
               equipo.golesContra,
               equipo.diferenciaGoles,
               equipo.puntos);
    }

    fclose(f);
}

// Función para leer y mostrar jugadores clave desde archivo binario
void mostrarJugadoresClave()
{
    FILE *f;
    EquipoJugadores equipo;

    f = fopen("jugadoresClave.bin", "rb");
    if (f == NULL)
    {
        printf("Error al abrir el archivo de jugadores clave.\n");
        return;
    }

    printf("\n--- JUGADORES CLAVE POR EQUIPO ---\n");

    while (fread(&equipo, sizeof(EquipoJugadores), 1, f) == 1)
    {
        printf("\n%-25s\n", equipo.nombre);
        printf("--------------------------------------------------\n");
        printf("%s\n", equipo.jugadores);
        printf("--------------------------------------------------\n");
    }

    fclose(f);
}

// Función para inicializar los datos de jugadores
void inicializarJugadores(Jugador jugadores[])
{
    // Jugador 1
    strcpy(jugadores[0].nombre, "Francisco Fydriszewski");
    strcpy(jugadores[0].equipo, "SD Aucas");
    jugadores[0].goles = 3;

    // Jugador 2
    strcpy(jugadores[1].nombre, "Gonzalo Mastriani");
    strcpy(jugadores[1].equipo, "Barcelona SC");
    jugadores[1].goles = 3;

    // Jugador 3
    strcpy(jugadores[2].nombre, "Alejandro Cabeza");
    strcpy(jugadores[2].equipo, "EMELEC");
    jugadores[2].goles = 2;

    // Jugador 4
    strcpy(jugadores[3].nombre, "Victor Figueroa");
    strcpy(jugadores[3].equipo, "SD Aucas");
    jugadores[3].goles = 2;

    // Jugador 5
    strcpy(jugadores[4].nombre, "Damián Lanza");
    strcpy(jugadores[4].equipo, "Barcelona SC");
    jugadores[4].goles = 1;

    // Jugador 6
    strcpy(jugadores[5].nombre, "Adonis Preciado");
    strcpy(jugadores[5].equipo, "Barcelona SC");
    jugadores[5].goles = 1;

    // Jugador 7
    strcpy(jugadores[6].nombre, "Carlos Garcés");
    strcpy(jugadores[6].equipo, "Barcelona SC");
    jugadores[6].goles = 1;

    // Jugador 8
    strcpy(jugadores[7].nombre, "Joao Gómez");
    strcpy(jugadores[7].equipo, "EMELEC");
    jugadores[7].goles = 1;

    // Jugador 9
    strcpy(jugadores[8].nombre, "Ronny Carrillo");
    strcpy(jugadores[8].equipo, "El Nacional");
    jugadores[8].goles = 1;

    // Jugador 10
    strcpy(jugadores[9].nombre, "Manuel Balda");
    strcpy(jugadores[9].equipo, "El Nacional");
    jugadores[9].goles = 1;

    // Jugador 11
    strcpy(jugadores[10].nombre, "Juan Manuel Tévez");
    strcpy(jugadores[10].equipo, "SD Aucas");
    jugadores[10].goles = 1;
}

// Función para inicializar los datos de partidos
void inicializarPartidos(Partido partidos[])
{
    // Partido 1
    strcpy(partidos[0].nombrePartido, "Barcelona SC vs. EMELEC");
    strcpy(partidos[0].resultado, "2 - 1");
    strcpy(partidos[0].goleadores, "BSC: Mastriani, Damián Lanza\nEME: Alejandro Cabeza");
    strcpy(partidos[0].estadisticas, "Posesión: BSC 45% - EME 55%\nTiros a puerta: BSC 6 - EME 4");

    // Partido 2
    strcpy(partidos[1].nombrePartido, "SD Aucas vs. El Nacional");
    strcpy(partidos[1].resultado, "3 - 0");
    strcpy(partidos[1].goleadores, "AUC: Fydriszewski (2), Figueroa");
    strcpy(partidos[1].estadisticas, "Posesión: AUC 60% - NAC 40%\nTiros a puerta: AUC 8 - NAC 2");

    // Partido 3
    strcpy(partidos[2].nombrePartido, "Barcelona SC vs. SD Aucas");
    strcpy(partidos[2].resultado, "1 - 1");
    strcpy(partidos[2].goleadores, "BSC: Adonis Preciado\nAUC: Fydriszewski");
    strcpy(partidos[2].estadisticas, "Posesión: BSC 50% - AUC 50%\nTiros a puerta: BSC 5 - AUC 5");

    // Partido 4
    strcpy(partidos[3].nombrePartido, "EMELEC vs. El Nacional");
    strcpy(partidos[3].resultado, "2 - 0");
    strcpy(partidos[3].goleadores, "EME: Alejandro Cabeza, Joao Gómez");
    strcpy(partidos[3].estadisticas, "Posesión: EME 58% - NAC 42%\nTiros a puerta: EME 7 - NAC 3");

    // Partido 5
    strcpy(partidos[4].nombrePartido, "Barcelona SC vs. El Nacional");
    strcpy(partidos[4].resultado, "3 - 2");
    strcpy(partidos[4].goleadores, "BSC: Mastriani (2), Carlos Garcés\nNAC: Ronny Carrillo, Manuel Balda");
    strcpy(partidos[4].estadisticas, "Posesión: BSC 48% - NAC 52%\nTiros a puerta: BSC 9 - NAC 6");

    // Partido 6
    strcpy(partidos[5].nombrePartido, "EMELEC vs. SD Aucas");
    strcpy(partidos[5].resultado, "0 - 2");
    strcpy(partidos[5].goleadores, "AUC: Figueroa, Juan Manuel Tévez");
    strcpy(partidos[5].estadisticas, "Posesión: EME 52% - AUC 48%\nTiros a puerta: EME 3 - AUC 7");
}

// Función para inicializar los datos de tabla de posiciones
void inicializarTabla(EquipoTabla equipos[])
{
    // Equipo 1
    equipos[0].posicion = 1;
    strcpy(equipos[0].nombre, "Sociedad Deportiva Aucas");
    equipos[0].partidosJugados = 3;
    equipos[0].partidosGanados = 2;
    equipos[0].partidosEmpatados = 1;
    equipos[0].partidosPerdidos = 0;
    equipos[0].golesFavor = 6;
    equipos[0].golesContra = 1;
    equipos[0].diferenciaGoles = 5;
    equipos[0].puntos = 7;

    // Equipo 2
    equipos[1].posicion = 2;
    strcpy(equipos[1].nombre, "Barcelona Sporting Club");
    equipos[1].partidosJugados = 3;
    equipos[1].partidosGanados = 2;
    equipos[1].partidosEmpatados = 1;
    equipos[1].partidosPerdidos = 0;
    equipos[1].golesFavor = 6;
    equipos[1].golesContra = 4;
    equipos[1].diferenciaGoles = 2;
    equipos[1].puntos = 7;

    // Equipo 3
    equipos[2].posicion = 3;
    strcpy(equipos[2].nombre, "EMELEC");
    equipos[2].partidosJugados = 3;
    equipos[2].partidosGanados = 1;
    equipos[2].partidosEmpatados = 0;
    equipos[2].partidosPerdidos = 2;
    equipos[2].golesFavor = 3;
    equipos[2].golesContra = 4;
    equipos[2].diferenciaGoles = -1;
    equipos[2].puntos = 3;

    // Equipo 4
    equipos[3].posicion = 4;
    strcpy(equipos[3].nombre, "Club Deportivo El Nacional");
    equipos[3].partidosJugados = 3;
    equipos[3].partidosGanados = 0;
    equipos[3].partidosEmpatados = 0;
    equipos[3].partidosPerdidos = 3;
    equipos[3].golesFavor = 2;
    equipos[3].golesContra = 8;
    equipos[3].diferenciaGoles = -6;
    equipos[3].puntos = 0;
}

// Función para inicializar los datos de jugadores clave
void inicializarJugadoresClave(EquipoJugadores equipos[])
{
    // Equipo 1
    strcpy(equipos[0].nombre, "Barcelona Sporting Club");
    strcpy(equipos[0].jugadores, "Javier Rojas, Mario Vega, Paco Rodríguez, Darío Cifuentes, Bruno Piñatares, Gabriel Cortez, Damián Lanza, Adonis Preciado, Gonzalo Mastriani, Carlos Garcés");

    // Equipo 2
    strcpy(equipos[1].nombre, "EMELEC");
    strcpy(equipos[1].jugadores, "Pedro Ramírez, Romario Caicedo, Aníbal Leguizamón, Luca Sosa, Bryan Carabalí, Sebastián Méndez, Dixon Arroyo, Alexis Zapata, Joao Gómez, Alejandro Cabeza, Mauro Quiroga");

    // Equipo 3
    strcpy(equipos[2].nombre, "Sociedad Deportiva Aucas");
    strcpy(equipos[2].jugadores, "Hernán Galíndez, Pedro Perlaza, Ricardo Adé, Luis Cangá, Carlos Cuero, Jhonny Quiñónez, Edison Caicedo, Víctor Figueroa, Francisco Fydriszewski, Juan Manuel Tévez, Luis Cano");

    // Equipo 4
    strcpy(equipos[3].nombre, "Club Deportivo El Nacional");
    strcpy(equipos[3].jugadores, "Leodán Chalá, Jerry Parrales, Jhonnier Chalá, Walter Ayoví, Kevin Peralta, Madison Julio, Jorge Ordóñez, Ronny Carrillo, Byron Palacios, Gustavo Asprilla, Manuel Balda");
}

// Función para inicializar todos los datos y guardarlos en archivos binarios
void inicializarDatos()
{
    Jugador jugadores[11];
    Partido partidos[6];
    EquipoTabla equipos[4];
    EquipoJugadores equiposJugadores[4];

    inicializarJugadores(jugadores);
    inicializarPartidos(partidos);
    inicializarTabla(equipos);
    inicializarJugadoresClave(equiposJugadores);

    guardarJugadores(jugadores, 11);
    guardarPartidos(partidos, 6);
    guardarTabla(equipos, 4);
    guardarJugadoresClave(equiposJugadores, 4);
}