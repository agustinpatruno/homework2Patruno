#include "ejercicio2.hpp"

///////////////////////// definicion de los metodos de la clase estudiante ////////////////////////////////

bool estudiante::corroborar_nota(float numero)
{
    return numero >= 0 && numero <= 10 ? true : false;
}

estudiante::estudiante(string nombre, int numero_legajo)
{
    try 
    {
        establecerLegajo(numero_legajo);
    } 
    catch (const invalid_argument& e) 
    {
        cerr << "Excepción en la creacion del objeto estudiante: " << e.what() << endl;
    }
    nombre_completo = nombre;
}

void estudiante::establecerLegajo(int numero_legajo) {
    if (numero_legajo > 0) 
    {
        legajo = numero_legajo;
    } 
    else 
    {
        throw logic_error("Número de legajo no válido.");
    }
}

// sobrecarga del operador para imprimir

bool estudiante::operator<(const estudiante& otro) const {
    return nombre_completo < otro.nombre_completo; // Compara nombres alfabéticamente
}

// sobrecarga del operador para imprimir el nombre del estudiante

ostream& operator<<(ostream& os, const estudiante& est) {
    os << est.nombre_completo; // Imprimir solo el nombre
    return os;
}

/////////////////funciones de ingreso y visualisacion de datos//////////////////

void estudiante::agregar_nota(float numero_nota, string materia)
{
    try
    {
        if (corroborar_nota(numero_nota) && !corroborar_materia_existente(materia))
        {
            notas.push_back({materia,numero_nota});
        }
        else
        {
            throw logic_error("error, corroborar que la nota ingresada sea un numero natural menor o igual a 10. y ademas que la materia no este ya ingresada");
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
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

    for (int i = 0; i < static_cast<int>(notas.size()); i++)
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
    for (int i = 0; i < static_cast<int>(notas.size()); i++)
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
        duplica los punteros que apuntan a los datos y permite una mayor simplicidad en el codigo. de este modo puede modificar 
        los valores tambien sin necesitar memoria.
        este shallow copy se hace creando un constructor, donde toma por parametro el curso que se desea copiar, luego en el objeto
        nuevo (estudiantes) se lo iguala a "otro.estudiantes" para realizar una copia superficial, donde ".estudiantes" accede al 
        vector con los estudiantes del antiguo curso.
    */
    estudiantes = otro.estudiantes;
}

/////////////////// definicion de los metodos de la clase curso //////////////////

//inscribir estudiante al curso///

bool curso::inscribir_estudiante(const shared_ptr<estudiante>& nuevo)
{
    try
    {
        if (nuevo && !curso_completo() && !corroborar_inscripcion(nuevo->retornar_legajo()))
        {
            estudiantes.push_back(nuevo);
            return true;
        }
        else
        {
            throw logic_error(" error, verificar que el curso no este lleno, que el estudiante no este ya inscripto o que el estudiante exista");
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    return false;
}

//desinscribir alumno//

void curso::desinscribir_estudiante(int legajo)
{

    for (int i = 0; i < static_cast<int>(estudiantes.size()); i++)
    {
        if ( estudiantes[i] -> retornar_legajo() == legajo)
        {
            estudiantes.erase(estudiantes.begin()+i);
            return;
        }
    }
    cout << "no se pudo desincribir debido a que no hay un estudiante con dicho legajo en el curso" << endl;
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
        for (int i = 0; i < static_cast<int>(estudiantes.size()); i++)
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
d) en mi implementacion del ejercicio 2, la relacion que hay entre la clase estudiante y la clase curso es las siguiente:
-Relacion de asociacion (unidirrecional) 
por definicion: La relación de asociación ocurre cuando una clase "conoce" a otra y puede interactuar con ella.
la clase curso conoce a la clase de estudiante pero no a la inversa. Esto es debido que adentro de la classe de 
curso, en su parte private, contiene como uno de los atributos, un vector de punteros shared_ptr hacia objetos 
de la clase curso.
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
    for (int i = 0; i < static_cast<int>(lista_estudiantes.size()); i++)
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
    for (int i = 0; i < static_cast<int>(lista_estudiantes.size()); i++)
    {
        if (lista_estudiantes[i]->retornar_legajo() == legajo)
        {
            return lista_estudiantes[i];
        }
    }
    return nullptr;
}

int return_curso()
{
    int curso;
    cursos();
    cin >> curso;
    curso = pedir_numero_correcto(curso,4);
    return curso;
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

        int curso;

        cout << "-------" << endl;

        if (opcion == 1)
        {
            cout << "ingrese numero de legajo" << endl;
            cin >> legajo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            curso = return_curso();

            if (cursos_totales[curso-1]->inscribir_estudiante(devolver_estudiante(estudiantes_totales,legajo)))
            {
                // pido la nota de la materia
                float nota;
                cout << "ingrese la nota asociada a la materia: " << endl;
                cin >> nota;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
                devolver_estudiante(estudiantes_totales,legajo)->agregar_nota(nota,nombre_cursos[curso-1]);
            }
        }
        else if (opcion == 2)
        {
            cout << " ingrese el legajo de la persona que quieras borrar: " << endl;
            cin >> legajo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "ingrese el numero del curso al que lo quieres borrar" << endl;
            curso = return_curso();
            
            cursos_totales[curso-1]->desinscribir_estudiante(legajo);
        }
        else if (opcion == 3)
        {
            cout << " ingrese el legajo de la persona que quieras saber si esta inscripto: " << endl;
            cin >> legajo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "ingrese el numero del curso al que lo quieres ver si esta inscripto" << endl;
            curso = return_curso();

            if ( cursos_totales[curso-1]->corroborar_inscripcion(legajo))
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
            curso = return_curso();

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
           curso = return_curso();
            
            cout << "alumnos del curso de "<< nombre_cursos[curso-1]<< endl;
            cursos_totales[curso-1]->imprimir_nombres();
        }
        else if (opcion == 6)
        {
            cout << " - ingrese el legajo de la persona que quieras ver su informacion: " << endl;
            cin >> legajo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (!corroborar_estudiante_lista_totales(estudiantes_totales,legajo))
            {
                cout << "error, ingrese un numero de legajo de un estudiante que exista " << endl;
            }

            int opcioninfo = 0;
            opciones_estudiante();
            cin >> opcioninfo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            opcioninfo = pedir_numero_correcto(opcioninfo,4);

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

    cout << "-----------------desinscribo al estudiante con legajo 1234 del curso_copia" << endl;

    curso_copia.desinscribir_estudiante(1234);

    cout << "----------------imprimo los estudiantes del curso_copia" << endl;
    
    curso_copia.imprimir_nombres();

    cout << "----------------imprimo los estudiantes del nuevo_curso" << endl;
    
    nuevo_curso.imprimir_nombres();

    /*
        en este caso, cuando desinscribo un estudiante del curso_copia, no se ve reflejado el cambio en el curso original por que
        son 2 instancias independientes. Cuando hago el shallow, el contenedor si se copia pero no se duplican los elementos del vector,
        se copian las referencias. Esto genera que al modificar los elementos apuntados por los shared_ptr, los cambios se ven en los 
        2 vectores. Pero si modifico el vector, este cambio no se vera reflejado en ambos por que son 2 vectore independientes
        Una forma de solucionar esto, es que el vector de estudiantes se pueda compartir entre instancias, 
        usando un shared_ptr que apunta al dicho vector. Esto realiza una copia del puntero compartido. De esta forma al modificar
        el curso_copia, tambien se modificara el curso original
        vector.
    */
    
    return 0;
}