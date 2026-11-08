// ============================================================
// Asignatura: Logica de Programacion
// Actividad : Sistema de control de calificaciones de un centro educativo
// Estudiante: Camilo Salas Jimenez
// Profesor  : Gamalier Reyes del Carmen
// ============================================================
// Programa de consola que registra las calificaciones de un grupo
// de estudiantes, calcula el promedio de cada uno, indica si esta
// Aprobado o Reprobado y muestra un resumen general del grupo.
// ============================================================

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    // Variable que controla si se procesa otro grupo (s / n)
    char procesarOtroGrupo;

    // BUCLE DO-WHILE (principal): repite todo el programa mientras el
    // usuario responda "s". Se usa do-while porque el grupo debe
    // procesarse por lo menos una vez antes de preguntar si se repite.
    do
    {
        // ---------- Variables del grupo ----------
        int cantidadEstudiantes;
        int cantidadAprobados = 0;      // contador de aprobados
        int cantidadReprobados = 0;     // contador de reprobados
        double sumaPromedios = 0;       // acumulador de los promedios de todos
        double mejorPromedio = -1;      // mayor promedio encontrado (-1 = ninguno aun)
        string nombreMejorEstudiante = "";

        cout << "\n=====================================================\n";
        cout << "   SISTEMA DE CONTROL DE CALIFICACIONES\n";
        cout << "   Centro Educativo \"La Nueva Escuela\"\n";
        cout << "=====================================================\n";

        // BUCLE WHILE (validacion de la cantidad de estudiantes): vuelve
        // a pedir el dato mientras sea invalido (no numerico o menor que 1).
        cout << "Cantidad de estudiantes: ";
        cin >> cantidadEstudiantes;
        while (cin.fail() || cantidadEstudiantes <= 0)
        {
            cin.clear();               // limpia el estado de error de cin
            cin.ignore(10000, '\n');   // descarta lo que se escribio mal
            cout << "Valor invalido. Debe ser un numero mayor que 0.\n";
            cout << "Cantidad de estudiantes: ";
            cin >> cantidadEstudiantes;
        }
        cin.ignore(10000, '\n');       // descarta el Enter para poder usar getline

        // BUCLE FOR (estudiantes): se ejecuta una vez por cada estudiante
        // del grupo. Se conoce de antemano cuantas veces se repite.
        for (int numeroEstudiante = 1; numeroEstudiante <= cantidadEstudiantes; numeroEstudiante++)
        {
            string nombreEstudiante;
            double sumaNotas = 0;      // acumulador de las 4 calificaciones
            double calificacion;

            cout << "\n--- Estudiante " << numeroEstudiante << " ---\n";

            // BUCLE WHILE (validacion del nombre): no deja continuar
            // si el nombre se deja vacio.
            cout << "Nombre: ";
            getline(cin, nombreEstudiante);
            while (nombreEstudiante.empty())
            {
                cout << "El nombre no puede estar vacio.\n";
                cout << "Nombre: ";
                getline(cin, nombreEstudiante);
            }

            // BUCLE FOR (calificaciones): recorre las 4 calificaciones de
            // cada estudiante y las va sumando en el acumulador sumaNotas.
            for (int numeroCalificacion = 1; numeroCalificacion <= 4; numeroCalificacion++)
            {
                cout << "Calificacion " << numeroCalificacion << ": ";
                cin >> calificacion;

                // BUCLE WHILE (validacion de la calificacion): repite la
                // solicitud de ESA calificacion mientras este fuera del
                // rango 0 - 100 o no sea un numero.
                while (cin.fail() || calificacion < 0 || calificacion > 100)
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Calificacion invalida. Debe estar entre 0 y 100.\n";
                    cout << "Calificacion " << numeroCalificacion << ": ";
                    cin >> calificacion;
                }

                sumaNotas = sumaNotas + calificacion;   // acumulador
            }
            cin.ignore(10000, '\n');   // descarta el Enter antes del siguiente getline

            // Promedio del estudiante
            double promedioEstudiante = sumaNotas / 4;

            cout << fixed << setprecision(2);
            cout << "Promedio: " << promedioEstudiante << " - ";

            // Contadores de aprobados / reprobados
            if (promedioEstudiante >= 70)
            {
                cout << "Aprobado\n";
                cantidadAprobados++;
            }
            else
            {
                cout << "Reprobado\n";
                cantidadReprobados++;
            }

            // Acumulador para el promedio general del grupo
            sumaPromedios = sumaPromedios + promedioEstudiante;

            // Se guarda el estudiante con el promedio mas alto
            if (promedioEstudiante > mejorPromedio)
            {
                mejorPromedio = promedioEstudiante;
                nombreMejorEstudiante = nombreEstudiante;
            }
        }

        // ---------- Resumen del grupo ----------
        double promedioGrupo = sumaPromedios / cantidadEstudiantes;

        cout << "\n===== RESUMEN =====\n";
        cout << "Aprobados: " << cantidadAprobados << " | Reprobados: " << cantidadReprobados << "\n";
        cout << "Promedio del grupo: " << promedioGrupo << "\n";
        cout << "Mejor promedio: " << nombreMejorEstudiante << " (" << mejorPromedio << ")\n";

        // BUCLE WHILE (validacion de s/n): sigue preguntando hasta que el
        // usuario escriba una respuesta valida (s, S, n o N).
        cout << "\nDesea procesar otro grupo? (s/n): ";
        cin >> procesarOtroGrupo;
        while (procesarOtroGrupo != 's' && procesarOtroGrupo != 'S' &&
               procesarOtroGrupo != 'n' && procesarOtroGrupo != 'N')
        {
            cin.ignore(10000, '\n');
            cout << "Respuesta invalida. Escriba s para si o n para no.\n";
            cout << "Desea procesar otro grupo? (s/n): ";
            cin >> procesarOtroGrupo;
        }
        cin.ignore(10000, '\n');

    } while (procesarOtroGrupo == 's' || procesarOtroGrupo == 'S');

    cout << "\nGracias por usar el sistema. Hasta luego.\n";
    return 0;
}
