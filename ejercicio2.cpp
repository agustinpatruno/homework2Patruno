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

        //funciones de ingreso y visualisacion de datos//

        void agregar_nota(float numero_nota, string materia)
        {
            if (corroborar_nota(numero_nota))
            {
                notas.push_back({materia,numero_nota});
            }
            return;
        }

        void imprimir_nombre()
        {
            cout <<"nombre completo: " << nombre_completo << endl ;
        }

        int imprimir_retornar_legajo()
        {   
            cout << "numero de legajo: " << legajo << endl ;
            return legajo;
        }

        int imprimir_retornar_promedio()
        {
            int promedio = 0;

            for (int i = 0; i < notas.size(); i++)
            {
                promedio += notas.at(i).second; 
            }

            cout << "promedio general :" << promedio/notas.size() << endl;

            return promedio/notas.size();
        }

        void imprimir_todo()
        {
            imprimir_nombre();

            imprimir_retornar_legajo();

            imprimir_retornar_promedio();

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
                if ( estudiantes[i]->imprimir_retornar_legajo() == legajo)
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
                if ( estudiantes[i]->imprimir_retornar_legajo() == legajo)
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
            vector<string> nombres;

            for (int i = 0; i < estudiantes.size(); i++)
            {
                nombres.push_back(estudiantes.at(i));
            }
            
        }
       

};
