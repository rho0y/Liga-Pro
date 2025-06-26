#include "funciones.h"
#include <stdio.h>
#include <string.h>

// Array global de jugadores por equipo
JugadorEquipo jugadoresEquipos[50];
int totalJugadoresEquipos = 0;

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

void guardarJugadoresEquipo()
{
    FILE *f = fopen("jugadoresEquipos.bin", "wb");
    if (f == NULL)
    {
        printf("Error al abrir jugadoresEquipos.bin\n");
        return;
    }
    fwrite(&totalJugadoresEquipos, sizeof(int), 1, f);
    fwrite(jugadoresEquipos, sizeof(JugadorEquipo), totalJugadoresEquipos, f);
    fclose(f);
}

void cargarJugadoresEquipo(JugadorEquipo jugadores[], char *equipo, int *cantidad)
{
    *cantidad = 0;
    for (int i = 0; i < totalJugadoresEquipos; i++)
    {
        if (strcmp(jugadoresEquipos[i].equipo, equipo) == 0)
        {
            jugadores[*cantidad] = jugadoresEquipos[i];
            (*cantidad)++;
        }
    }
}

// --- Funciones para mostrar datos ---
void mostrarJugadores()
{
    FILE *f = fopen("jugadores.bin", "rb");
    if (f == NULL)
    {
        printf("No se pudo abrir jugadores.bin. Inicializaste los datos?\n");
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
        printf("No se pudo abrir partidos.bin. Inicializaste los datos?\n");
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
        printf("No se pudo abrir tabla.bin. Inicializaste los datos?\n");
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
        printf("No se pudo abrir jugadoresClave.bin. Inicializaste los datos?\n");
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

void mostrarJugadoresEquipo(char *nombreEquipo)
{
    JugadorEquipo jugadores[15];
    int cantidad;
    cargarJugadoresEquipo(jugadores, nombreEquipo, &cantidad);

    printf("\n+---------------------------------------------------------------+\n");
    printf("|                JUGADORES DE %s", nombreEquipo);
    int espacios = 37 - strlen(nombreEquipo);
    for (int i = 0; i < espacios; i++)
        printf(" ");
    printf("|\n");
    printf("+-------+-------------------------------------------------------+\n");
    printf("| %-5s | %-53s |\n", "Indice", "Nombre del Jugador");
    printf("+-------+-------------------------------------------------------+\n");

    for (int i = 0; i < cantidad; i++)
    {
        printf("| %-5d | %-53s |\n", jugadores[i].indice, jugadores[i].nombre);
    }
    printf("+-------+-------------------------------------------------------+\n");
}

// --- Funciones para la logica interactiva ---
void inicializarJugadoresEquipos()
{
    totalJugadoresEquipos = 0;

    // Jugadores de Barcelona SC
    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Javier Rojas");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "Barcelona SC");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 0;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Mario Vega");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "Barcelona SC");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 1;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Paco Rodriguez");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "Barcelona SC");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 2;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Gonzalo Mastriani");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "Barcelona SC");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 3;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Damian Lanza");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "Barcelona SC");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 4;
    totalJugadoresEquipos++;

    // Jugadores de SD Aucas
    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Hernan Galindez");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "SD Aucas");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 0;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Francisco Fydriszewski");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "SD Aucas");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 1;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Victor Figueroa");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "SD Aucas");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 2;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Juan Manuel Tevez");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "SD Aucas");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 3;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Pedro Perlaza");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "SD Aucas");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 4;
    totalJugadoresEquipos++;

    // Jugadores de El Nacional
    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Leodan Chala");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "El Nacional");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 0;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Ronny Carrillo");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "El Nacional");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 1;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Manuel Balda");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "El Nacional");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 2;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Byron Palacios");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "El Nacional");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 3;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Gustavo Asprilla");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "El Nacional");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 4;
    totalJugadoresEquipos++;

    // Jugadores de EMELEC
    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Pedro Ramirez");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "EMELEC");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 0;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Alejandro Cabeza");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "EMELEC");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 1;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Joao Gomez");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "EMELEC");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 2;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Romario Caicedo");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "EMELEC");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 3;
    totalJugadoresEquipos++;

    strcpy(jugadoresEquipos[totalJugadoresEquipos].nombre, "Sebastian Mendez");
    strcpy(jugadoresEquipos[totalJugadoresEquipos].equipo, "EMELEC");
    jugadoresEquipos[totalJugadoresEquipos].goles = 0;
    jugadoresEquipos[totalJugadoresEquipos].indice = 4;
    totalJugadoresEquipos++;

    guardarJugadoresEquipo();
}

void ingresarResultadoPartido()
{
    char enfrentamientos[6][60] = {
        "SD Aucas vs El Nacional",
        "Barcelona SC vs EMELEC",
        "SD Aucas vs Barcelona SC",
        "El Nacional vs EMELEC",
        "SD Aucas vs EMELEC",
        "El Nacional vs Barcelona SC"};

    printf("\n=== INGRESO DE RESULTADOS DE PARTIDOS ===\n");
    printf("Enfrentamientos disponibles:\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d. %s\n", i, enfrentamientos[i]);
    }

    int partido;
    printf("\nSeleccione el partido (0-5): ");
    scanf("%d", &partido);

    if (partido < 0 || partido > 5)
    {
        printf("Partido no valido.\n");
        return;
    }

    printf("\nPartido seleccionado: %s\n", enfrentamientos[partido]);

    char equipo1[30], equipo2[30];
    switch (partido)
    {
    case 0:
        strcpy(equipo1, "SD Aucas");
        strcpy(equipo2, "El Nacional");
        break;
    case 1:
        strcpy(equipo1, "Barcelona SC");
        strcpy(equipo2, "EMELEC");
        break;
    case 2:
        strcpy(equipo1, "SD Aucas");
        strcpy(equipo2, "Barcelona SC");
        break;
    case 3:
        strcpy(equipo1, "El Nacional");
        strcpy(equipo2, "EMELEC");
        break;
    case 4:
        strcpy(equipo1, "SD Aucas");
        strcpy(equipo2, "EMELEC");
        break;
    case 5:
        strcpy(equipo1, "El Nacional");
        strcpy(equipo2, "Barcelona SC");
        break;
    }

    int resultado;
    printf("\nQuien gano? (0 = %s, 1 = %s, 2 = Empate): ", equipo1, equipo2);
    scanf("%d", &resultado);

    int goles1, goles2;
    printf("Goles de %s: ", equipo1);
    scanf("%d", &goles1);
    printf("Goles de %s: ", equipo2);
    scanf("%d", &goles2);

    if ((resultado == 0 && goles1 <= goles2) ||
        (resultado == 1 && goles2 <= goles1) ||
        (resultado == 2 && goles1 != goles2))
    {
        printf("Error: Los goles no coinciden con el resultado indicado.\n");
        return;
    }

    if (goles1 > 0)
    {
        printf("\n=== Registro de goles para %s ===\n", equipo1);
        mostrarJugadoresEquipo(equipo1);
        for (int i = 0; i < goles1; i++)
        {
            int jugador;
            printf("Gol %d - Indice del jugador: ", i + 1);
            scanf("%d", &jugador);

            for (int j = 0; j < totalJugadoresEquipos; j++)
            {
                if (strcmp(jugadoresEquipos[j].equipo, equipo1) == 0 &&
                    jugadoresEquipos[j].indice == jugador)
                {
                    jugadoresEquipos[j].goles++;
                    break;
                }
            }
        }
    }

    if (goles2 > 0)
    {
        printf("\n=== Registro de goles para %s ===\n", equipo2);
        mostrarJugadoresEquipo(equipo2);
        for (int i = 0; i < goles2; i++)
        {
            int jugador;
            printf("Gol %d - Indice del jugador: ", i + 1);
            scanf("%d", &jugador);

            for (int j = 0; j < totalJugadoresEquipos; j++)
            {
                if (strcmp(jugadoresEquipos[j].equipo, equipo2) == 0 &&
                    jugadoresEquipos[j].indice == jugador)
                {
                    jugadoresEquipos[j].goles++;
                    break;
                }
            }
        }
    }

    if (resultado == 0)
    {
        actualizarTablaEquipos(equipo1, equipo2, goles1, goles2);
    }
    else if (resultado == 1)
    {
        actualizarTablaEquipos(equipo2, equipo1, goles2, goles1);
    }
    else
    {
        actualizarTablaEmpate(equipo1, equipo2, goles1, goles2);
    }

    guardarJugadoresEquipo();

    Jugador goleadores[50];
    int totalGoleadores = 0;
    for (int i = 0; i < totalJugadoresEquipos; i++)
    {
        if (jugadoresEquipos[i].goles > 0)
        {
            strcpy(goleadores[totalGoleadores].nombre, jugadoresEquipos[i].nombre);
            strcpy(goleadores[totalGoleadores].equipo, jugadoresEquipos[i].equipo);
            goleadores[totalGoleadores].goles = jugadoresEquipos[i].goles;
            totalGoleadores++;
        }
    }
    guardarJugadores(goleadores, totalGoleadores);

    printf("\nResultado del partido registrado exitosamente!\n");
}

void actualizarTablaEquipos(char *equipoGanador, char *equipoPerdedor, int golesGanador, int golesPerdedor)
{
    FILE *f = fopen("tabla.bin", "rb");
    if (f == NULL)
        return;

    EquipoTabla equipos[4];
    int cantidad = 0;
    while (fread(&equipos[cantidad], sizeof(EquipoTabla), 1, f) == 1)
    {
        cantidad++;
    }
    fclose(f);

    for (int i = 0; i < cantidad; i++)
    {
        if (strstr(equipos[i].nombre, equipoGanador) != NULL)
        {
            equipos[i].partidosJugados++;
            equipos[i].partidosGanados++;
            equipos[i].golesFavor += golesGanador;
            equipos[i].golesContra += golesPerdedor;
            equipos[i].diferenciaGoles = equipos[i].golesFavor - equipos[i].golesContra;
            equipos[i].puntos += 3;
        }
        else if (strstr(equipos[i].nombre, equipoPerdedor) != NULL)
        {
            equipos[i].partidosJugados++;
            equipos[i].partidosPerdidos++;
            equipos[i].golesFavor += golesPerdedor;
            equipos[i].golesContra += golesGanador;
            equipos[i].diferenciaGoles = equipos[i].golesFavor - equipos[i].golesContra;
        }
    }

    calcularPosicionesTabla(equipos, cantidad);
    guardarTabla(equipos, cantidad);
}

void actualizarTablaEmpate(char *equipo1, char *equipo2, int goles1, int goles2)
{
    FILE *f = fopen("tabla.bin", "rb");
    if (f == NULL)
        return;

    EquipoTabla equipos[4];
    int cantidad = 0;
    while (fread(&equipos[cantidad], sizeof(EquipoTabla), 1, f) == 1)
    {
        cantidad++;
    }
    fclose(f);

    for (int i = 0; i < cantidad; i++)
    {
        if (strstr(equipos[i].nombre, equipo1) != NULL)
        {
            equipos[i].partidosJugados++;
            equipos[i].partidosEmpatados++;
            equipos[i].golesFavor += goles1;
            equipos[i].golesContra += goles2;
            equipos[i].diferenciaGoles = equipos[i].golesFavor - equipos[i].golesContra;
            equipos[i].puntos += 1;
        }
        else if (strstr(equipos[i].nombre, equipo2) != NULL)
        {
            equipos[i].partidosJugados++;
            equipos[i].partidosEmpatados++;
            equipos[i].golesFavor += goles2;
            equipos[i].golesContra += goles1;
            equipos[i].diferenciaGoles = equipos[i].golesFavor - equipos[i].golesContra;
            equipos[i].puntos += 1;
        }
    }

    calcularPosicionesTabla(equipos, cantidad);
    guardarTabla(equipos, cantidad);
}

void calcularPosicionesTabla(EquipoTabla equipos[], int cantidad)
{
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = i + 1; j < cantidad; j++)
        {
            if (equipos[j].puntos > equipos[i].puntos ||
                (equipos[j].puntos == equipos[i].puntos && equipos[j].diferenciaGoles > equipos[i].diferenciaGoles))
            {
                EquipoTabla temp = equipos[i];
                equipos[i] = equipos[j];
                equipos[j] = temp;
            }
        }
    }

    for (int i = 0; i < cantidad; i++)
    {
        equipos[i].posicion = i + 1;
    }
}

void inicializarJugadores(Jugador jugadores[])
{
    // Funcion vacia - no se usan datos predefinidos
}

void inicializarPartidos(Partido partidos[])
{
    for (int i = 0; i < 6; i++)
    {
        strcpy(partidos[i].nombrePartido, "");
        strcpy(partidos[i].resultado, "");
        strcpy(partidos[i].goleadores, "");
        strcpy(partidos[i].estadisticas, "");
    }
}

void inicializarTabla(EquipoTabla equipos[])
{
    strcpy(equipos[0].nombre, "Barcelona Sporting Club");
    equipos[0].posicion = 1;
    equipos[0].partidosJugados = 0;
    equipos[0].partidosGanados = 0;
    equipos[0].partidosEmpatados = 0;
    equipos[0].partidosPerdidos = 0;
    equipos[0].golesFavor = 0;
    equipos[0].golesContra = 0;
    equipos[0].diferenciaGoles = 0;
    equipos[0].puntos = 0;

    strcpy(equipos[1].nombre, "Sociedad Deportiva Aucas");
    equipos[1].posicion = 2;
    equipos[1].partidosJugados = 0;
    equipos[1].partidosGanados = 0;
    equipos[1].partidosEmpatados = 0;
    equipos[1].partidosPerdidos = 0;
    equipos[1].golesFavor = 0;
    equipos[1].golesContra = 0;
    equipos[1].diferenciaGoles = 0;
    equipos[1].puntos = 0;

    strcpy(equipos[2].nombre, "EMELEC");
    equipos[2].posicion = 3;
    equipos[2].partidosJugados = 0;
    equipos[2].partidosGanados = 0;
    equipos[2].partidosEmpatados = 0;
    equipos[2].partidosPerdidos = 0;
    equipos[2].golesFavor = 0;
    equipos[2].golesContra = 0;
    equipos[2].diferenciaGoles = 0;
    equipos[2].puntos = 0;

    strcpy(equipos[3].nombre, "Club Deportivo El Nacional");
    equipos[3].posicion = 4;
    equipos[3].partidosJugados = 0;
    equipos[3].partidosGanados = 0;
    equipos[3].partidosEmpatados = 0;
    equipos[3].partidosPerdidos = 0;
    equipos[3].golesFavor = 0;
    equipos[3].golesContra = 0;
    equipos[3].diferenciaGoles = 0;
    equipos[3].puntos = 0;
}

void inicializarJugadoresClave(EquipoJugadores equipos[])
{
    strcpy(equipos[0].nombre, "Barcelona Sporting Club");
    strcpy(equipos[0].jugadores, "Javier Rojas, Mario Vega, Paco Rodriguez, Gonzalo Mastriani, Damian Lanza");
    strcpy(equipos[1].nombre, "EMELEC");
    strcpy(equipos[1].jugadores, "Pedro Ramirez, Alejandro Cabeza, Joao Gomez, Romario Caicedo, Sebastian Mendez");
    strcpy(equipos[2].nombre, "Sociedad Deportiva Aucas");
    strcpy(equipos[2].jugadores, "Hernan Galindez, Francisco Fydriszewski, Victor Figueroa, Juan Manuel Tevez, Pedro Perlaza");
    strcpy(equipos[3].nombre, "Club Deportivo El Nacional");
    strcpy(equipos[3].jugadores, "Leodan Chala, Ronny Carrillo, Manuel Balda, Byron Palacios, Gustavo Asprilla");
}

void inicializarDatos()
{
    Jugador jugadores[50];
    Partido partidos[6];
    EquipoTabla tabla[4];
    EquipoJugadores jugadoresClave[4];

    inicializarJugadores(jugadores);
    inicializarPartidos(partidos);
    inicializarTabla(tabla);
    inicializarJugadoresClave(jugadoresClave);
    inicializarJugadoresEquipos();

    guardarJugadores(jugadores, 0);
    guardarPartidos(partidos, 6);
    guardarTabla(tabla, 4);
    guardarJugadoresClave(jugadoresClave, 4);
}
