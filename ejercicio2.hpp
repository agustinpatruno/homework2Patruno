#ifndef EJERCICIO2_HPP
#define EJERCICIO2_HPP

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <limits>
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

        // sobrecarga de operadores //

        bool operator<(const estudiante& otro) const;

        friend ostream& operator<<(ostream& os, const estudiante& est);

        //funciones de ingreso y visualisacion de datos//

        void agregar_nota(float numero_nota, string materia);

        string retornar_nombre();

        int retornar_legajo();

        float retornar_promedio();

        void imprimir_todo();
        
        bool corroborar_materia_existente(string materia);
};


class curso
{
    private:

        vector<shared_ptr<estudiante>> estudiantes;

    public:

        //constructores //

        curso();
        /*
            incializa un objeto curso sin hacerle nada. imprime por consola un mensaje de que se creo el objeto curso
        */

        curso(const curso& otro);
        /*
            constructor que realiza un shallow copy del objeto curso que se le pasa por parametro
        */

        //inscribir estudiante al curso//

        void inscribir_estudiante(const shared_ptr<estudiante>& nuevo);
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

        void imprimir_info(int legajo, bool nombre, bool legaj, bool promedio);

};

#endif // EJERCICIO2_HPP