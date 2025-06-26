// Estructuras para almacenar los datos
typedef struct
{
    char nombre[50];
    char equipo[50];
    int goles;
} Jugador;

typedef struct
{
    char nombrePartido[50];
    char resultado[15];
    char goleadores[200];
    char estadisticas[200];
} Partido;

typedef struct
{
    int posicion;
    char nombre[50];
    int partidosJugados;
    int partidosGanados;
    int partidosEmpatados;
    int partidosPerdidos;
    int golesFavor;
    int golesContra;
    int diferenciaGoles;
    int puntos;
} EquipoTabla;

typedef struct
{
    char nombre[50];
    char jugadores[500];
} EquipoJugadores;

// Estructura para jugadores por equipo
typedef struct
{
    char nombre[50];
    char equipo[50];
    int goles;
    int indice;
} JugadorEquipo;

// Declaraciones de funciones para guardar datos
void guardarJugadores(Jugador jugadores[], int cantidad);
void guardarPartidos(Partido partidos[], int cantidad);
void guardarTabla(EquipoTabla equipos[], int cantidad);
void guardarJugadoresClave(EquipoJugadores equipos[], int cantidad);

// Declaraciones de funciones para mostrar datos
void mostrarJugadores();
void mostrarPartidos();
void mostrarTabla();
void mostrarJugadoresClave();

// Declaraciones de funciones para inicializar datos
void inicializarJugadores(Jugador jugadores[]);
void inicializarPartidos(Partido partidos[]);
void inicializarTabla(EquipoTabla equipos[]);
void inicializarJugadoresClave(EquipoJugadores equipos[]);
void inicializarDatos();

// Nuevas funciones para entrada interactiva de datos
void inicializarJugadoresEquipos();
void ingresarResultadoPartido();
void mostrarJugadoresEquipo(char *nombreEquipo);
void actualizarTablaEquipos(char *equipoGanador, char *equipoPerdedor, int golesGanador, int golesPerdedor);
void actualizarTablaEmpate(char *equipo1, char *equipo2, int goles1, int goles2);
void cargarJugadoresEquipo(JugadorEquipo jugadores[], char *equipo, int *cantidad);
void guardarJugadoresEquipo();
void calcularPosicionesTabla(EquipoTabla equipos[], int cantidad);
