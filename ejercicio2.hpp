#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <utility>
using namespace std;

const static int capacidad_alumnos = 20;

class  estudiante
{
    private:

        string nombre_completo;

        int legajo;

       vector<pair<string,float>> notas;

    public:
        // constructor//

        estudiante(string nombre, int numero_legajo);

        //funciones de ingreso y visualisacion de datos//


        void agregar_nota(float numero_nota, string materia);

        void imprimir_nombre();

        int imprimir_retornar_legajo();

        int imprimir_retornar_promedio();

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

        void inscribir_estudiante(string nombre, int legajo);
        /*
            crea un objeto de la clase estudiante, le asigna el nombre y el legajo pasado por parametro.
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
        /*
            retorna true si el curso esta completo. caso contrario retorna false.
        */

        // imprimir lista de nombres por orden alfabetico

        void imprimir_nombres();
        /*
            imprime por consola los nombres de los estudiantes pertenecientes al curso en orden alfabetico
        */

};
