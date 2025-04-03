#include "ejercicio2.hpp"

///////////////////////// definicion de las funciones de la clase estudiante ////////////////////////////////

bool estudiante::corroborar_nota(float numero)
{
    return numero >= 0 && numero <= 10 ? true : false;
}

estudiante::estudiante(string nombre, int numero_legajo)
{
    if (numero_legajo > 0)
    {
        legajo = numero_legajo;
    }
    else
    {
        throw("error, numero de legajo no valido. Corroborar que sea un numero entero positivo ");
    }

    nombre_completo = nombre;
}

//sobrecarga del operador //

bool estudiante::operator<(const estudiante& otro) const {
    return nombre_completo < otro.nombre_completo; // Comparar nombres alfabéticamente
}

// sobrecarga del operador para imprimir el nombre del estudiante

ostream& operator<<(std::ostream& os, const estudiante& est) {
    os << est.nombre_completo; // Imprimir solo el nombre
    return os;
}

/////////////////funciones de ingreso y visualisacion de datos//////////////////

void estudiante::agregar_nota(float numero_nota, string materia)
{
    if (corroborar_nota(numero_nota) && !corroborar_materia_existente(materia))
    {
        notas.push_back({materia,numero_nota});
    }
    else
    {
        throw("error, corroborar que la nota ingresada sea un numero natural menor o igual a 10. y ademas que la materia no este ya ingresada");
    }
}

string estudiante::retornar_nombre()
{
    return nombre_completo;
}

int estudiante::retornar_legajo()
{  
    return legajo;
}

float estudiante::retornar_promedio()
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

void estudiante::imprimir_todo()
{
    cout << "nombre :" << retornar_nombre() << endl;

    cout << "numero de legajo: " << retornar_legajo() << endl;

    cout << "promedio general: " << retornar_promedio() << endl;

    return;
}

bool estudiante::corroborar_materia_existente(string materia)
{
    for (int i = 0; i < notas.size(); i++)
    {
        if (notas[i].first == materia)
        {
            cout << "materia ya ingresada " << endl;
            return true;
        }
    }
    return false;
}

void estudiante::imprimir_info(int legajo, bool nombre, bool legaj, bool promedio)
{
    if (nombre)
    {
        cout << "nombre completo: " << retornar_nombre() << endl;
    }
    if (legaj)
    {
        cout << "numero de legajo: " << retornar_legajo() << endl;
    }
    if (promedio)
    {
        cout << "promedio general: " << retornar_promedio() << endl;
    }
    return;
}

//definicion de las funciones de la clase curso//

curso::curso()
{
    cout << " se creo el objeto curso" << endl;
}

curso::curso(const curso& otro) {

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

/////////////////// definicion de las funciones de la clase curso //////////////////

//inscribir estudiante al curso///
void curso::inscribir_estudiante(const shared_ptr<estudiante>& nuevo)
{
    if (!curso_completo() && !corroborar_inscripcion(nuevo->retornar_legajo()))
    {
        estudiantes.push_back(nuevo);
    }
    else
    {
        throw(" error, verificar que el curso no este lleno y que el estudiante no este ya inscripto");
    }
}

//desinscribir alumno//

void curso::desinscribir_estudiante(int legajo)
{
    for (int i = 0; i < estudiantes.size(); i++)
    {
        if ( estudiantes[i] -> retornar_legajo() == legajo)
        {
            estudiantes.erase(estudiantes.begin()+i);
            return;
        }
    }
    throw("no se pudo desincribir debido a que no hay un estudiante con dicho legajo en el curso");
}

//corroborar que un estudiante este inscripto//

bool curso::corroborar_inscripcion(int legajo)
{   
    if (legajo < 0)
    {
        return false;
    }
    else
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
}

//imformar curso completo

bool curso::curso_completo()
{
    return estudiantes.size() == capacidad_alumnos;
}

// imprimir lista de nombres por orden alfabetico

void curso::imprimir_nombres()
{

    sort(estudiantes.begin(), estudiantes.end(), [](const auto& a, const auto& b) {return *a < *b;});

    cout << "Nombres de los estudiantes ordenados alfabéticamente:\n";

    for (const auto& est : estudiantes) {
        std::cout << "-" << *est << std::endl; // Usar el operador '<<' sobrecargado
    }
    return;
}

/*
d) en mi implementacion del ejercicio 2, la relacion que hay entre la clase estudiante y la clase curso son las siguientes:
-la relacion de asociacion (unidirrecional) donde la clase curso conoce a la clase de estudiante pero no la inversa.
*/

////////////////////////////////////////////////////////////////////////////////////////////////////


void opciones()
{
    cout << " que quieres hacer:" << endl;
    cout << "1) inscribir estudiante a un curso" << endl;
    cout << "2) desinscribir estudiante " << endl;
    cout << "3) corroborar inscripcion de estudiante " << endl;
    cout << "4) indicar si un curso esta lleno" << endl;
    cout << "5) imprimir lista de estudiantes en orden alfabetico de un curso" << endl;
    cout << "6) ver informacion de un estudiante" << endl;
    cout << "7) crear un estudiante " << endl;
    cout << "-1) para terminar el programa " << endl;
    return;
}

void opciones_estudiante()
{
    cout << "1) ver el nombre completo " << endl;
    cout << "2) ver en numero de legajo " << endl;
    cout << "3) ver el promedio " << endl;
    cout << "4) ver todo junto " << endl;
}

void cursos()
{
    cout << "elije el curso: " << endl;
    cout << "1) curso de fisica" << endl;
    cout << "2) curso de proba" << endl;
    cout << "3) curso de paradigmas" << endl;
    cout << "4) curso de economia" << endl;

}

int pedir_numero_correcto(int numero, int rango)
{
    int num = numero;

    while (num > rango || num < 1)
    {
        cout << " error, ingrese un numero dentro de las opciones: " << endl;
        cin >> num;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    return num;
}

bool corroborar_estudiante_lista_totales(vector<shared_ptr<estudiante>> lista_estudiantes, int legajo)
{
    for (int i = 0; i < lista_estudiantes.size(); i++)
    {
        if (lista_estudiantes[i]->retornar_legajo() == legajo)
        {
            return true;
        }
        
    }
    return false;
}

shared_ptr<estudiante> devolver_estudiante(vector<shared_ptr<estudiante>> lista_estudiantes, int legajo)
{
    for (int i = 0; i < lista_estudiantes.size(); i++)
    {
        if (lista_estudiantes[i]->retornar_legajo() == legajo)
        {
            return lista_estudiantes[i];
        }
    }
    return nullptr;
}

void interfaz_curso()
{
    shared_ptr<curso> mi_curso_fisica = make_unique<curso>();
    shared_ptr<curso> mi_curso_proba = make_unique<curso>();
    shared_ptr<curso> mi_curso_paradigmas = make_unique<curso>();
    shared_ptr<curso> mi_curso_economia = make_unique<curso>();

    vector<shared_ptr<curso>> cursos_totales = {mi_curso_fisica,mi_curso_proba,mi_curso_paradigmas,mi_curso_economia};
    vector<shared_ptr<estudiante>> estudiantes_totales = {};

    vector<string> nombre_cursos = {"fisica","probabilidad y estadistica","paradigmas de la programacion","economia 1"};

    while (true)
    {
        int opcion;
        opciones();
        cin>> opcion;

        if (opcion == -1)
        {
            return;
        }
        
        opcion = pedir_numero_correcto(opcion,7);
        
        int legajo;

        if (opcion == 1)
        {
            cout << "ingrese numero de legajo" << endl;
            cin >> legajo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

          if (corroborar_estudiante_lista_totales(estudiantes_totales,legajo))
           {
                int curso;
                cursos();
                cin >> curso;
                curso = pedir_numero_correcto(curso,4);

                cursos_totales[curso-1]->inscribir_estudiante(devolver_estudiante(estudiantes_totales,legajo));

                //pido el nombre de la materia

                string nueva_materia;
                cout << "agregar nota de materia :" << endl;
                cout << "ingrese el nombre de la materia(poner -1 en caso de querer dejar de agregar materias): " << endl;
                getline(cin, nueva_materia);

                // pido la nota de la materia
                float nota;
                cout << "ingrese la nota asociada a la materia: " << endl;
                cin >> nota;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                devolver_estudiante(estudiantes_totales,legajo)->agregar_nota(nota, nueva_materia);
            }
          else
            {
                throw("error, legajo ingresado del estudiante no se encuentra en la lista de estudiantes totales");
            }
        }
        else if (opcion == 2)
        {
            cout << " ingrese el legajo de la persona que quieras borrar: " << endl;
            cin >> legajo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "ingrese el numero del curso al que lo quieres borrar" << endl;
            int curso;
            cursos();
            cin >> curso;
            curso = pedir_numero_correcto(curso,4);
            
            cursos_totales[curso-1]->desinscribir_estudiante(legajo);
            
        }
        else if (opcion == 3)
        {
            cout << "-----" << endl;
            cout << " ingrese el legajo de la persona que quieras saber si esta inscripto: " << endl;
            cin >> legajo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "ingrese el numero del curso al que lo quieres ver si esta inscripto" << endl;
            int curso;
            cursos();
            cin >> curso;
            curso = pedir_numero_correcto(curso,4);

            bool rta = cursos_totales[curso-1]->corroborar_inscripcion(legajo);

            if (rta)
            {
                cout << " - el alumno con legajo: " << legajo << " esta en el curso"<< endl;
            }
            else
            {
                cout << " - el alumno con legajo: " << legajo << " no esta en el curso" << endl;
            }   
        }
        else if (opcion == 4)
        {
            cout << " elija que curso quiere ver si esta completo" << endl;

            int curso;
            cursos();
            cin >> curso;
            curso = pedir_numero_correcto(curso,4);

            if (cursos_totales[curso-1]->curso_completo())
            {
                cout << " - el curso de " << nombre_cursos[curso-1] << " esta lleno" << endl;
            }
            else
            {
                cout << " - el curso de " << nombre_cursos[curso-1] << " no esta lleno " << endl;
            }
        }
        else if (opcion == 5)
        {
            int curso;
            cursos();
            cin >> curso;
            curso = pedir_numero_correcto(curso,4);
            
            cout << "alumnos del curso de "<< nombre_cursos[curso-1]<< endl;
            cursos_totales[curso-1]->imprimir_nombres();
        }
        else if (opcion == 6)
        {
            cout << " - ingrese el legajo de la persona que quieras ver su informacion: " << endl;
            cin >> legajo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(legajo < 0)
            {
                cout << "-- error, ingrese un numero de legajo positivo de una persona que este en el curso: " << endl;
                cin >> legajo;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {

                int opcioninfo = 0;
                opciones_estudiante();
                cin >> opcioninfo;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                opcioninfo = pedir_numero_correcto(opcioninfo,4);

                cout << "-----" << endl;

                shared_ptr<estudiante> est_temp =  devolver_estudiante(estudiantes_totales,legajo);

                if (opcioninfo == 1)
                {
                    est_temp->imprimir_info(legajo,true,false,false);
                }
                else if (opcioninfo == 2)
                {
                    est_temp->imprimir_info(legajo,false,true,false);
                }
                else if (opcioninfo == 3)
                {
                    est_temp->imprimir_info(legajo,false,false,true);
                }
                else
                {
                    est_temp->imprimir_info(legajo,true,true,true);
                }
            }
        } 
        else if (opcion == 7)
        {
            cout << "ingrese numero de legajo" << endl;
            cin >> legajo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "ingrese el nombre del estudiante " << endl;
            string nombre;
            getline(cin, nombre);

            shared_ptr<estudiante> nuevo_estudiante = make_shared<estudiante>(nombre,legajo);

            estudiantes_totales.push_back(nuevo_estudiante);
        }
        
        cout << "-----------------------------------------" << endl;
    }
}

int main()
{

    interfaz_curso();

    curso nuevo_curso;

    shared_ptr<estudiante>  nuevo_estudiante1 = make_shared<estudiante>("agustin patruno",1234);
    shared_ptr<estudiante>  nuevo_estudiante2 = make_shared<estudiante>("marcelo alvarez",1233);
    shared_ptr<estudiante>  nuevo_estudiante3 = make_shared<estudiante>("sofia quilmes",1232);
    shared_ptr<estudiante>  nuevo_estudiante4 = make_shared<estudiante>("pedro rodriguez",1231);
    shared_ptr<estudiante>  nuevo_estudiante5 = make_shared<estudiante>("lucas galar",1230);
    
    nuevo_curso.inscribir_estudiante(nuevo_estudiante1);
    nuevo_curso.inscribir_estudiante(nuevo_estudiante2);
    nuevo_curso.inscribir_estudiante(nuevo_estudiante3);
    nuevo_curso.inscribir_estudiante(nuevo_estudiante4);
    nuevo_curso.inscribir_estudiante(nuevo_estudiante5);

    cout << "-imprimo la lista de los nombres de los estudiantes del nuevo curso" << endl;

    nuevo_curso.imprimir_nombres();

    curso curso_copia(nuevo_curso);// realizo un shallow copy del nuevo curso.
    
    cout << "-imprimo la lista de los nombres de los estudiantes de la copia del curso" << endl;

    curso_copia.imprimir_nombres();

    return 0;

}