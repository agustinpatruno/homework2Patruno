#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;


const static int capacidad_alumnos = 20;

class  estudiante
{
    private:

        string nombre_completo;

        int legajo;

       vector<int> notas;

    public:
        // constructores //

        estudiante()
        {
            nombre_completo = "sin nombre asignado";
            legajo = 0;
            notas.push_back(0);
        }
        estudiante(string nombre)
        {
            nombre_completo = nombre;
            legajo = 0;
            notas.push_back(0);
        }
        estudiante(string nombre, int numero_legajo)
        {
            nombre_completo = nombre;
            legajo = numero_legajo;
        }
        estudiante(string nombre, int numero_legajo, int nota_incial)
        {
            nombre_completo = nombre;
            legajo = numero_legajo;
            notas.push_back(nota_incial);
        }

        //funciones de ingreso y visualisacion de datos//

        void agregar_nota(int numero_nota)
        {
            notas.push_back(numero_nota);
        }
        void cambiar_nombre(string nombre)
        {
            nombre_completo = nombre;
        }
        void cambiar_legajo(int numero_legajo)
        {
            legajo = numero_legajo;
        }

        void imprimir_nombre()
        {
            cout <<"nombre completo: " << nombre_completo << endl ;
        }
        int imprimir_legajo()
        {   
            cout << "numero de legajo: " << legajo << endl ;
            return legajo;
        }
        int imprimir_promedio()
        {
            int promedio = 0;

            for (int i = 0; i < notas.size(); i++)
            {
                promedio += notas[i]; 
            }
            cout << "promedio general :" << promedio/notas.size() << endl;

            return promedio;
        }
        void imprimir_todo()
        {
            imprimir_nombre();
            imprimir_legajo();
            imprimir_promedio();
        }
};


class curso
{
    private:

        vector<shared_ptr<estudiante>> estudiantes;

    public:
        void inicializacion_curso() {
            cout << "Curso creado!" << endl;
        }

        //inscribir estudiante al curso//

        void inscribir_estudiante(string nombre)
        {
            if (estudiantes.size()<20)
            {
                shared_ptr<estudiante> nuevo_estudiante = make_shared<estudiante>(nombre);
                estudiantes.push_back(nuevo_estudiante);
                return;
            }
            cout << "error, no entran mas estudiantes" << endl;
            
        }
        void inscribir_estudiante(string nombre, int legajo)
        {
            if (estudiantes.size()<20)
            {
                shared_ptr<estudiante> nuevo_estudiante = make_shared<estudiante>(nombre,legajo);
                estudiantes.push_back(nuevo_estudiante);
                return;
            }
            cout << "error, no entran mas estudiantes" << endl;
        }
        void inscribir_estudiante(string nombre, int legajo, int nota_inicial)
        {
            if (estudiantes.size()<20)
            {
                shared_ptr<estudiante> nuevo_estudiante = make_shared<estudiante>(nombre, legajo, nota_inicial);
                estudiantes.push_back(nuevo_estudiante);
                return;
            }
            cout << "error, no entran mas estudiantes" << endl;
        }

        //desinscribir alumno//

        void desinscribir_estudiante(int legajo)
        {

            for (int i = 0; i < estudiantes.size(); i++)
            {
                if ( estudiantes[i]->imprimir_legajo() == legajo)
                {
                    estudiantes.erase(estudiantes.begin()+i);
                    return;
                }
            }
            return;
        }

        //corroborar que un estudiante este inscripto//

        bool corroborar_inscripcion(int legajo)
        {
            for (int i = 0; i < estudiantes.size(); i++)
            {
                if ( estudiantes[i]->imprimir_legajo() == legajo)
                {
                    return true;
                }
            }
            return false;
        }
        
        //imformar curso completo

        bool curso_completo()
        {
            return estudiantes.size() < 20;
        }

        // imprimir lista de nombres por orden alfabetico

        void imprimir_nombres()
        {

            
        }

};
curso::~curso(){}


