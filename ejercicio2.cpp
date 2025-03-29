#include <ejercicio2.hpp>

class  estudiante
{
    private:

        string nombre_completo;

        int legajo;

       vector<pair<string,float>> notas;

       float corroborar_nota(float numero)
        {
            return numero > 0 ? numero : 0;
        }

    public:

        // constructor //

        estudiante(string nombre, int numero_legajo)
        {
            nombre_completo = nombre;

            legajo = numero_legajo;
        }

        //sobrecarga del operador //

        bool operator<(const estudiante& otro) const {
            return nombre_completo < otro.nombre_completo; // Comparar nombres alfabéticamente
        }

        // sobrecarga del operador para imprimir el nombre del estudiante

        friend std::ostream& operator<<(std::ostream& os, const estudiante& est) {
            os << est.nombre_completo; // Imprimir solo el nombre
            return os;
        }

        //funciones de ingreso y visualisacion de datos//

        void agregar_nota(float numero_nota, string materia)
        {
            if (corroborar_nota(numero_nota) && notas.size()<20)
            {
                notas.push_back({materia,numero_nota});
            }
            return;
        }

        string retornar_nombre()
        {
            return nombre_completo;
        }

        int retornar_legajo()
        {  
            return legajo;
        }

        float retornar_promedio()
        {
            if (notas.empty())
            {
                return 0;
            }
            
            int promedio = 0;

            for (int i = 0; i < notas.size(); i++)
            {
                promedio += notas.at(i).second; 
            }

            return promedio/notas.size();
        
        }

        void imprimir_todo()
        {
            cout << "nombre :" << retornar_nombre() << endl;

            cout << "numero de legajo: " << retornar_legajo() << endl;

            cout << "promedio general: " << retornar_promedio() << endl;

        }
};

class curso
{
    private:

        vector<shared_ptr<estudiante>> estudiantes;

    public:

        curso(const curso& otro) {
            /*Justificación:
             eliji realizar un shallow copy debido a que es mas eficiente en tiempo, no consume espacio en memoria adicional, solo
             duplica los punteros que apuntan a los datos y mayor simplicidad en el codigo. de este modo puede modificar los valores 
             tambien sin necesitar memoria.
             este shallow copy se hace creando un constructor, donde toma por parametro el curso que se desea copiar, luego en el objeto
             nuevo (estudiantes) se lo iguala a "otro.estudiantes" para realizar una copia superficial, donde ".estudiantes" accede al 
             vector con los estudiantes del antiguo curso.
            */
            estudiantes = otro.estudiantes;
        }

        //inscribir estudiante al curso//

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

        //desinscribir alumno//

        void desinscribir_estudiante(int legajo)
        {

            for (int i = 0; i < estudiantes.size(); i++)
            {
                if ( estudiantes[i]->retornar_legajo() == legajo)
                {
                    estudiantes.erase(estudiantes.begin()+i);
                    return;
                }
            }
            cout << "el estudainte con el legajo : "<< legajo << " no se encuentra en el curso" << endl;
            return;
        }

        //corroborar que un estudiante este inscripto//

        bool corroborar_inscripcion(int legajo)
        {
            for (int i = 0; i < estudiantes.size(); i++)
            {
                if ( estudiantes[i]->retornar_legajo() == legajo)
                {
                    return true;
                }
            }
            return false;
        }
        
        //imformar curso completo

        bool curso_completo()
        {
            return estudiantes.size() == 20;
        }

        // imprimir lista de nombres por orden alfabetico

        void imprimir_nombres()
        {

            sort(estudiantes.begin(), estudiantes.end(), [](const auto& a, const auto& b) {return *a < *b;});
    
            cout << "Nombres de los estudiantes ordenados alfabéticamente:\n";

            for (const auto& est : estudiantes) {
                std::cout << *est << std::endl; // Usar el operador '<<' sobrecargado
            }
            
        }
};

/*
d) en mi implementacion del ejercicio 2, la relacion que hay entre la clase estudiante y la clase curso son las siguientes:
-la de composicion, donde en la clase de curso contiene en un vector a objetos de la clase estudiante.
-la relacion de asociacion (unidirrecional) donde la clase curso conoce a la clase de estudiante pero no la inversa.
- la relacion de agregacion ya que puede ser que un objeto de la clase estudiante exista y que un objeto de la clase curso no, donde
una clase no depende de la existencia de la otra clase.
*/