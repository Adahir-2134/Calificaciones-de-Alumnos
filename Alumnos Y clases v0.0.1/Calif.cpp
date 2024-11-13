#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // para formatear el promedio

using namespace std;

struct Alumno {
    string nombre;
    float ecuaciones_diferenciales;
    float programacion;
    float administracion_personal;
    float estructuras_datos;
    float promedio;
};

vector<Alumno> listaAlumnos;

float calcularPromedio(float ecuaciones, float programacion, float administracion, float estructuras) {
    return (ecuaciones + programacion + administracion + estructuras) / 4;
}

void agregarAlumno() {
    Alumno nuevoAlumno;
    cout << "Ingrese el nombre del alumno: ";
    cin.ignore();
    getline(cin, nuevoAlumno.nombre);

    cout << "Ingrese la calificación en Ecuaciones Diferenciales: ";
    cin >> nuevoAlumno.ecuaciones_diferenciales;

    cout << "Ingrese la calificación en Programación: ";
    cin >> nuevoAlumno.programacion;

    cout << "Ingrese la calificación en Administración de Personal: ";
    cin >> nuevoAlumno.administracion_personal;

    cout << "Ingrese la calificación en Estructuras de Datos: ";
    cin >> nuevoAlumno.estructuras_datos;

    nuevoAlumno.promedio = calcularPromedio(
        nuevoAlumno.ecuaciones_diferenciales, 
        nuevoAlumno.programacion, 
        nuevoAlumno.administracion_personal, 
        nuevoAlumno.estructuras_datos
    );

    listaAlumnos.push_back(nuevoAlumno);
    cout << "Alumno agregado exitosamente." << endl;
}

void consultarAlumno() {
    if (listaAlumnos.empty()) {
        cout << "No hay alumnos en la lista." << endl;
        return;
    }

    cout << "Ingrese el nombre del alumno que desea consultar: ";
    string nombre;
    cin.ignore();
    getline(cin, nombre);

    bool encontrado = false;
    for (const auto& alumno : listaAlumnos) {
        if (alumno.nombre == nombre) {
            encontrado = true;
            cout << "\nNombre: " << alumno.nombre << endl;
            cout << "Ecuaciones Diferenciales: " << alumno.ecuaciones_diferenciales << endl;
            cout << "Programación: " << alumno.programacion << endl;
            cout << "Administración de Personal: " << alumno.administracion_personal << endl;
            cout << "Estructuras de Datos: " << alumno.estructuras_datos << endl;
            cout << fixed << setprecision(2);
            cout << "Promedio General: " << alumno.promedio << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Alumno no encontrado." << endl;
    }
}

void mostrarMenu() {
    cout << "\n--- Sistema de Gestión de Calificaciones ---" << endl;
    cout << "1. Agregar Alumno" << endl;
    cout << "2. Consultar Alumno" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarAlumno();
                break;
            case 2:
                consultarAlumno();
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 3);

    return 0;
}
