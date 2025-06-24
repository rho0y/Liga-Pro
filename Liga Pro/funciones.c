#include "funciones.h"
#include <stdio.h>
#include <string.h>

// --- Funciones para guardar datos en archivos .bin ---
void guardarJugadores(Jugador jugadores[], int cantidad)
{
    FILE *f = fopen("jugadores.bin", "wb");
    if (f == NULL)
    {
        printf("Error al abrir jugadores.bin\n");
        return;
    }
    fwrite(jugadores, sizeof(Jugador), cantidad, f);
    fclose(f);
}

void guardarPartidos(Partido partidos[], int cantidad)
{
    FILE *f = fopen("partidos.bin", "wb");
    if (f == NULL)
    {
        printf("Error al abrir partidos.bin\n");
        return;
    }
    fwrite(partidos, sizeof(Partido), cantidad, f);
    fclose(f);
}

void guardarTabla(EquipoTabla equipos[], int cantidad)
{
    FILE *f = fopen("tabla.bin", "wb");
    if (f == NULL)
    {
        printf("Error al abrir tabla.bin\n");
        return;
    }
    fwrite(equipos, sizeof(EquipoTabla), cantidad, f);
    fclose(f);
}

void guardarJugadoresClave(EquipoJugadores equipos[], int cantidad)
{
    FILE *f = fopen("jugadoresClave.bin", "wb");
    if (f == NULL)
    {
        printf("Error al abrir jugadoresClave.bin\n");
        return;
    }
    fwrite(equipos, sizeof(EquipoJugadores), cantidad, f);
    fclose(f);
}

// --- Funciones para mostrar datos con formato estético ---
void mostrarJugadores()
{
    FILE *f = fopen("jugadores.bin", "rb");
    if (f == NULL)
    {
        printf("No se pudo abrir jugadores.bin. ¿Inicializaste los datos?\n");
        return;
    }
    Jugador j;
    printf("\n+----------------------------------------------------+\n");
    printf("|               TABLA DE GOLEADORES                |\n");
    printf("+------------------------------+--------------------+-------+\n");
    printf("| %-28s | %-18s | %-5s |\n", "Jugador", "Equipo", "Goles");
    printf("+------------------------------+--------------------+-------+\n");
    while (fread(&j, sizeof(Jugador), 1, f) == 1)
    {
        printf("| %-28s | %-18s | %-5d |\n", j.nombre, j.equipo, j.goles);
    }
    printf("+------------------------------+--------------------+-------+\n");
    fclose(f);
}

void mostrarPartidos()
{
    FILE *f = fopen("partidos.bin", "rb");
    if (f == NULL)
    {
        printf("No se pudo abrir partidos.bin. ¿Inicializaste los datos?\n");
        return;
    }
    Partido p;
    printf("\n================================================================================\n");
    printf("                             RESULTADOS DE PARTIDOS                           \n");
    printf("================================================================================\n");
    while (fread(&p, sizeof(Partido), 1, f) == 1)
    {
        printf("\nPartido:     %s\n", p.nombrePartido);
        printf("Resultado:   %s\n", p.resultado);
        printf("--------------------------------------------------------------------------------\n");
        printf("Goleadores:\n%s\n", p.goleadores);
        printf("--------------------------------------------------------------------------------\n");
        printf("Estadisticas Clave:\n%s\n", p.estadisticas);
        printf("================================================================================\n");
    }
    fclose(f);
}

void mostrarTabla()
{
    FILE *f = fopen("tabla.bin", "rb");
    if (f == NULL)
    {
        printf("No se pudo abrir tabla.bin. ¿Inicializaste los datos?\n");
        return;
    }
    EquipoTabla e;
    printf("\n+----------------------------------------------------------------------+\n");
    printf("|                         TABLA DE POSICIONES                        |\n");
    printf("+-----+---------------------------+----+---+---+---+----+----+----+-----+\n");
    printf("| %-3s | %-25s | %-2s | %-1s | %-1s | %-1s | %-2s | %-2s | %-2s | %-3s |\n", "Pos", "Equipo", "PJ", "G", "E", "P", "GF", "GC", "DG", "Pts");
    printf("+-----+---------------------------+----+---+---+---+----+----+----+-----+\n");
    while (fread(&e, sizeof(EquipoTabla), 1, f) == 1)
    {
        printf("| %-3d | %-25s | %-2d | %-1d | %-1d | %-1d | %-2d | %-2d | %-+2d | %-3d |\n",
               e.posicion, e.nombre, e.partidosJugados, e.partidosGanados, e.partidosEmpatados,
               e.partidosPerdidos, e.golesFavor, e.golesContra, e.diferenciaGoles, e.puntos);
    }
    printf("+-----+---------------------------+----+---+---+---+----+----+----+-----+\n");
    fclose(f);
}

void mostrarJugadoresClave()
{
    FILE *f = fopen("jugadoresClave.bin", "rb");
    if (f == NULL)
    {
        printf("No se pudo abrir jugadoresClave.bin. ¿Inicializaste los datos?\n");
        return;
    }
    EquipoJugadores ej;
    printf("\n+==============================================================================+\n");
    printf("|                           JUGADORES CLAVE POR EQUIPO                         |\n");
    printf("+==============================================================================+\n");
    while (fread(&ej, sizeof(EquipoJugadores), 1, f) == 1)
    {
        printf("\n> Equipo: %s\n", ej.nombre);
        printf("--------------------------------------------------------------------------------\n");
        printf("  %s\n", ej.jugadores);
    }
    printf("\n+==============================================================================+\n");
    fclose(f);
}

// --- Funciones para inicializar con datos predefinidos ---
void inicializarJugadores(Jugador jugadores[])
{
    strcpy(jugadores[0].nombre, "Francisco Fydriszewski");
    strcpy(jugadores[0].equipo, "SD Aucas");
    jugadores[0].goles = 3;
    strcpy(jugadores[1].nombre, "Gonzalo Mastriani");
    strcpy(jugadores[1].equipo, "Barcelona SC");
    jugadores[1].goles = 3;
    strcpy(jugadores[2].nombre, "Alejandro Cabeza");
    strcpy(jugadores[2].equipo, "EMELEC");
    jugadores[2].goles = 2;
    strcpy(jugadores[3].nombre, "Victor Figueroa");
    strcpy(jugadores[3].equipo, "SD Aucas");
    jugadores[3].goles = 2;
    strcpy(jugadores[4].nombre, "Damián Lanza");
    strcpy(jugadores[4].equipo, "Barcelona SC");
    jugadores[4].goles = 1;
    strcpy(jugadores[5].nombre, "Adonis Preciado");
    strcpy(jugadores[5].equipo, "Barcelona SC");
    jugadores[5].goles = 1;
    strcpy(jugadores[6].nombre, "Carlos Garcés");
    strcpy(jugadores[6].equipo, "Barcelona SC");
    jugadores[6].goles = 1;
    strcpy(jugadores[7].nombre, "Joao Gómez");
    strcpy(jugadores[7].equipo, "EMELEC");
    jugadores[7].goles = 1;
    strcpy(jugadores[8].nombre, "Ronny Carrillo");
    strcpy(jugadores[8].equipo, "El Nacional");
    jugadores[8].goles = 1;
    strcpy(jugadores[9].nombre, "Manuel Balda");
    strcpy(jugadores[9].equipo, "El Nacional");
    jugadores[9].goles = 1;
    strcpy(jugadores[10].nombre, "Juan Manuel Tévez");
    strcpy(jugadores[10].equipo, "SD Aucas");
    jugadores[10].goles = 1;
}

void inicializarPartidos(Partido partidos[])
{
    strcpy(partidos[0].nombrePartido, "Barcelona SC vs. EMELEC");
    strcpy(partidos[0].resultado, "2 - 1");
    strcpy(partidos[0].goleadores, "  BSC: Mastriani, Damián Lanza\n  EME: Alejandro Cabeza");
    strcpy(partidos[0].estadisticas, "  Posesión: BSC 45% - EME 55%\n  Tiros a puerta: BSC 6 - EME 4");
    strcpy(partidos[1].nombrePartido, "SD Aucas vs. El Nacional");
    strcpy(partidos[1].resultado, "3 - 0");
    strcpy(partidos[1].goleadores, "  AUC: Fydriszewski (2), Figueroa");
    strcpy(partidos[1].estadisticas, "  Posesión: AUC 60% - NAC 40%\n  Tiros a puerta: AUC 8 - NAC 2");
    strcpy(partidos[2].nombrePartido, "Barcelona SC vs. SD Aucas");
    strcpy(partidos[2].resultado, "1 - 1");
    strcpy(partidos[2].goleadores, "  BSC: Adonis Preciado\n  AUC: Fydriszewski");
    strcpy(partidos[2].estadisticas, "  Posesión: BSC 50% - AUC 50%\n  Tiros a puerta: BSC 5 - AUC 5");
    strcpy(partidos[3].nombrePartido, "EMELEC vs. El Nacional");
    strcpy(partidos[3].resultado, "2 - 0");
    strcpy(partidos[3].goleadores, "  EME: Alejandro Cabeza, Joao Gómez");
    strcpy(partidos[3].estadisticas, "  Posesión: EME 58% - NAC 42%\n  Tiros a puerta: EME 7 - NAC 3");
    strcpy(partidos[4].nombrePartido, "Barcelona SC vs. El Nacional");
    strcpy(partidos[4].resultado, "3 - 2");
    strcpy(partidos[4].goleadores, "  BSC: Mastriani (2), Carlos Garcés\n  NAC: Ronny Carrillo, Manuel Balda");
    strcpy(partidos[4].estadisticas, "  Posesión: BSC 48% - NAC 52%\n  Tiros a puerta: BSC 9 - NAC 6");
    strcpy(partidos[5].nombrePartido, "EMELEC vs. SD Aucas");
    strcpy(partidos[5].resultado, "0 - 2");
    strcpy(partidos[5].goleadores, "  AUC: Figueroa, Juan Manuel Tévez");
    strcpy(partidos[5].estadisticas, "  Posesión: EME 52% - AUC 48%\n  Tiros a puerta: EME 3 - AUC 7");
}

void inicializarTabla(EquipoTabla equipos[])
{
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

void inicializarJugadoresClave(EquipoJugadores equipos[])
{
    strcpy(equipos[0].nombre, "Barcelona Sporting Club");
    strcpy(equipos[0].jugadores, "Javier Rojas, Mario Vega, Paco Rodríguez, Darío Cifuentes, Bruno Piñatares, Gabriel Cortez, Damián Lanza, Adonis Preciado, Gonzalo Mastriani, Carlos Garcés");
    strcpy(equipos[1].nombre, "EMELEC");
    strcpy(equipos[1].jugadores, "Pedro Ramírez, Romario Caicedo, Aníbal Leguizamón, Luca Sosa, Bryan Carabalí, Sebastián Méndez, Dixon Arroyo, Alexis Zapata, Joao Gómez, Alejandro Cabeza");
    strcpy(equipos[2].nombre, "Sociedad Deportiva Aucas");
    strcpy(equipos[2].jugadores, "Hernán Galíndez, Pedro Perlaza, Ricardo Adé, Luis Cangá, Carlos Cuero, Jhonny Quiñónez, Edison Caicedo, Víctor Figueroa, Francisco Fydriszewski, Juan Manuel Tévez");
    strcpy(equipos[3].nombre, "Club Deportivo El Nacional");
    strcpy(equipos[3].jugadores, "Leodán Chalá, Jerry Parrales, Jhonnier Chalá, Walter Ayoví, Kevin Peralta, Madison Julio, Jorge Ordóñez, Ronny Carrillo, Byron Palacios, Gustavo Asprilla");
}

// --- Función principal para inicializar y guardar todos los datos ---
void inicializarDatos()
{
    Jugador jugadores[11];
    Partido partidos[6];
    EquipoTabla tabla[4];
    EquipoJugadores jugadoresClave[4];

    inicializarJugadores(jugadores);
    inicializarPartidos(partidos);
    inicializarTabla(tabla);
    inicializarJugadoresClave(jugadoresClave);

    guardarJugadores(jugadores, 11);
    guardarPartidos(partidos, 6);
    guardarTabla(tabla, 4);
    guardarJugadoresClave(jugadoresClave, 4);
}
