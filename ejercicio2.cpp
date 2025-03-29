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

        bool corroborar_materia_existente(string materia)
        {
            for (int i = 0; i < notas.size(); i++)
            {
                if (notas[i].first == materia)
                {
                    cout << "materia ya ingresada " << endl;
                    return false;
                }
            }
            return true;
        }
};

class curso
{
    private:

        vector<shared_ptr<estudiante>> estudiantes;

    public:
        //constructores //

        curso()
        {
            cout << " se creo el objeto curso" << endl;
        }

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

        void inscribir_estudiante(const shared_ptr<estudiante>& nuevo)
        {
            estudiantes.push_back(nuevo);
            return;
        }

        //desinscribir alumno//

        void desinscribir_estudiante(int legajo)
        {

            for (int i = 0; i < estudiantes.size(); i++)
            {
                if ( estudiantes[i] -> retornar_legajo() == legajo)
                {
                    estudiantes.erase(estudiantes.begin()+i);
                    return;
                }
            }

            cout << "el estudiante con el legajo : "<< legajo << " no se encuentra en el curso" << endl;
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

void opciones()
{
    cout << " que quieres hacer:" << endl;
    cout << "1) inscribir estudiante " << endl;
    cout << "2) desinscribir estudiante " << endl;
    cout << "3) corroborar inscripcion de estudiante " << endl;
    cout << "4) indicar si el curso esta lleno" << endl;
    cout << "5) imprimir lista de estudiantes en orden alfabetico " << endl;
    cout << "6) hacer una copia del objeto curso " << endl;
    cout << "7) ver imformacion de un estudiante " << endl;
    cout << "-1) para terminar el programa " << endl;
}

int pedir_numero_correcto(int numero)
{
    int num = numero;

    while (num > 7 || num < 1)
    {
        cout << " error, ingrese un numero dentro de las opciones: " << endl;
        cin >> num;
    }
    
    return num;

}

int pedir_legajo(int legajo, curso lista_estudiantes)
{
    int leg = legajo;

    while (leg < 0 || lista_estudiantes.corroborar_inscripcion(legajo))
    {
        cout << "error, ingrese un numero de legajo entero, positivo y que no este en el curso: " << endl;
        cin >> leg;
    }
    return leg;
}

void interfaz_curso()
{
    curso mi_curso;

    int contador_alumnos = 0;

    while (true)
    {
        int opcion;

        opciones();
        cin>> opcion;

        if (opcion == -1)
        {
            return;
        }
        
        opcion = pedir_numero_correcto(opcion);
        
        int legajo;

        if (opcion == 1 && contador_alumnos < 20)
        {
    
            cout << "ingrese numero de legajo" << endl;
            cin >> legajo;
            legajo = pedir_legajo(legajo, mi_curso);


            string nombre;
            cout << "ingrese el nombre completo" << endl;
            cin >> nombre;

            shared_ptr<estudiante>  nuevo_estudiante = make_shared<estudiante>(nombre,legajo);

            cout << "agregar nota de materias :" << endl;
            while (true)
            {
                string nueva_materia;
                float nota;

                //pido el nombre de la materia

                cout << "ingrese el nombre de la materia(poner -1 en caso de querer dejar de agregar materias): " << endl;
                cin >> nueva_materia;

                if (nueva_materia == "-1")
                {
                    break;
                }

                while (! nuevo_estudiante -> corroborar_materia_existente(nueva_materia))
                {
                    cout << "error, ingrese una materia que no este todavia: " << endl;
                    cin >> nueva_materia;
                }
            
                // pido la nota de la materia

                cout << "ingrese la nota asociada a la materia: " << endl;
                cin >> nota;

                while (nota < 0)
                {
                    cout << "ingrese una nota positiva: " << endl;
                    cin >> nota;
                }
                
                nuevo_estudiante -> agregar_nota(nota,nueva_materia);
            }

            mi_curso.inscribir_estudiante(nuevo_estudiante);
            contador_alumnos ++;
        }
        else if (opcion == 2)
        {
            /* code */
        }
        
        
    }
     
}