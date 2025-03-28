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

       vector<double> notas;

    public:
        // constructores //

        estudiante();

        estudiante(string nombre);

        estudiante(string nombre, int numero_legajo);

        estudiante(string nombre, int numero_legajo, int nota_incial);


        //funciones de ingreso y visualisacion de datos//

        void agregar_nota(int numero_nota);

        void cambiar_nombre(string nombre);

        void cambiar_legajo(int numero_legajo);

        void imprimir_nombre();

        int imprimir_legajo();

        int imprimir_promedio();

        void imprimir_todo();
};


class curso
{
    private:

        vector<shared_ptr<estudiante>> estudiantes;

    public:
        void inicializacion_curso();
        /*
            muestra un mensaje por consola de que se creo bien el objeto
        */

        //inscribir estudiante al curso//

        void inscribir_estudiante(string nombre);
        /*
            crea un objeto de la clase estudiante, le asigna el nombre pasado por parametro 
            y lo guarda en el vector de estudiantes en el caso de que haya lugar (size <20).
            caso contrario muestra un mensaje por consola de que no se pudo guardar.
        */

        void inscribir_estudiante(string nombre, int legajo);
        /*
            crea un objeto de la clase estudiante, le asigna el nombre y el legajo pasado por parametro.
            lo guarda en el vector de estudiantes en el caso de que haya lugar (size <20).
            caso contrario muestra un mensaje por consola de que no se pudo guardar.
        */

        void inscribir_estudiante(string nombre, int legajo, int nota_inicial);
        /*
            crea un objeto de la clase estudiante, le asigna el nombre, el legajo y la nota incial pasado por parametro.
            lo guarda en el vector de estudiantes en el caso de que haya lugar (size <20).
            caso contrario muestra un mensaje por consola de que no se pudo guardar.
        */

        //desinscribir alumno//

        void desinscribir_estudiante(int legajo);
        /*
            elimina un estudiante del vector de estudiantes buscandolo por legajo en el caso de que esté. 
            caso contrario imprime un mensaje por consola de que no se encontro.
        */

        //corroborar que un estudiante este inscripto//

        bool corroborar_inscripcion(int legajo);
        /*
            retorna un true en caso de que el alumno con el legajo pasado por parametro este en el curso. caso contrario devuelve false.
        */
        
        //imformar curso completo

        bool curso_completo();
        

        // imprimir lista de nombres por orden alfabetico

        void imprimir_nombres();

};
