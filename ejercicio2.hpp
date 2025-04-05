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

       bool corroborar_nota(float numero);

    public:
        // constructor//

        estudiante(string nombre, int numero_legajo);
        /*
            crea un objeto de clase estudiante, asignando el nombre completo y el numero de legajo con los parametros pasados.
        */

        void establecerLegajo(int numero_legajo);
        /*
            asigna el numero_legajo al atributo legajo en caso de que sea positivo. Caso contrario, arroja un throw.
        */

        // sobrecarga de operadores //

        bool operator<(const estudiante& otro) const;
        /*
            sobrecarga el operador para poder comparar dos objetos de la clase estudiante por su nombre.
        */

        friend ostream& operator<<(ostream& os, const estudiante& est);
        /*
            sobrecarga el operador para poder imprimir solo el nombre completo del objeto estudiante
        */

        //funciones de ingreso y visualisacion de datos//

        void agregar_nota(float numero_nota, string materia);
        /*
            agrega una nota al objeto estudiante con su calificacion y el nombre de la materia asociada. en caso de que la nota se pase
            del rango o que la materia ya sea ingresada, no lo guarda
        */

        string retornar_nombre();
        /*
            retornar el nombre completo del objeto estudiante
        */

        int retornar_legajo();
        /*
            retorna el numero de legajo del objeto estudiante
        */

        float retornar_promedio();
        /*
            retorna el promedio de las notas de todas las materias del objeto estudiante
        */

        void imprimir_todo();
        /*
            imprime por consola el nombre completo, el numero de legajo y el promedio general del objeto estudiante
        */
        
        bool corroborar_materia_existente(string materia);
        /*
            corrobora que una la nota de una materia haya sido guardada anteriormente. caso de que ya este guardada devuelve false,
            si no esta guardada devuelve true.
        */

        void imprimir_info(int legajo, bool nombre, bool legaj, bool promedio);
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

        bool inscribir_estudiante(const shared_ptr<estudiante>& nuevo);
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
#endif // EJERCICIO2_HPP

void opciones();
/*
    imprime por consola todas las opciones que tiene el usuario para realizar. inscribir alumno, desincribir alumno, imprimir nombres, etc
*/

void opciones_estudiante();
/*
    imprimer por consola todas las opciones que tiene para ver la informarcion de un estudiante, nombre completo, legajo, etc.
*/

void cursos();
/*
    imprime por consola las opciones de los cursos existentes
*/

int pedir_numero_correcto(int numero, int rango);
/*
    se le pasa el numero ingresado por el usuario, y el rango de opciones que se tiene
    si el numero no esta dentro del rango, se le pide nuevamente el numero hasta que este dentro. luego retorna ese numero
*/

bool corroborar_estudiante_lista_totales(vector<shared_ptr<estudiante>> lista_estudiantes, int legajo);
/*
    devuelve un bool que determina si un legajo se encuentra asignado a un estudiante. return true en caso de que este el legajo,
    return false en el caso de que no se encuentre.
*/

shared_ptr<estudiante> devolver_estudiante(vector<shared_ptr<estudiante>> lista_estudiantes, int legajo);
/*
    retorna un puntero shared al objeto estudiante que tiene asignado como numero de legajo el que se le pasa por parametro.
    caso de que no haya un estudiante con dicho legajo, se devuelve nullptr
*/

int return_curso();
/*
    retorna el numero del curso que elijio el usuario
*/

void interfaz_curso(); 
/*
 funcion de interfaz con el usuario, donde le muestra todas las opciones en las que puede crear un estudiante, inscribir/desinscribir
 un estudiante de un curso. ver informacion de un estudiante. ver si un curso esta lleno. imprimir la lista de estudiantes de un curso
 o corroborar que un estudiante este inscripto en un curso.
*/