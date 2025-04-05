#include "ejercicio1.hpp"


int tiempo::comprobar_hora(int hora)
{
    return hora <= 24 ? hora : -1;
}
int tiempo::comprobar_minutos_segundos(int numero)
{
    return numero <= 60 ? numero : -1;
}
bool tiempo::comprobar_momento(string momento)
{
    return momento == "a.m" || momento == "p.m" ? true : false;
}

//constructores del objeto//

tiempo::tiempo()
{
    Hora = 0;
    Minutos = 0;
    Segundos = 0;
    Momento = "a.m";
}

tiempo::tiempo(int horas)
{
    try
    {
        if (comprobar_hora(horas) != -1)
        {
            Hora = horas;
            Minutos = 0;
            Segundos = 0;
            Momento = "a.m";
        }
        throw logic_error("error, hora ingresada no valida");
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

tiempo::tiempo(int horas, int minutos)
{
    try
    {
        if (comprobar_hora(horas) != -1 && comprobar_minutos_segundos(minutos) != -1)
        {
            Hora = horas;
            Minutos = minutos;
            Segundos = 0;
            Momento = "a.m";
        }
        else
        {
            throw logic_error("error, verificar que la hora y los minutos esten en los rangos correctos");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

tiempo::tiempo(int horas, int minutos, int segundos)
{
    try
    {
        if (comprobar_hora(horas) != -1 && comprobar_minutos_segundos(minutos) != -1 && comprobar_minutos_segundos(segundos) != -1)
        {
            Hora = horas;
            Minutos = minutos;
            Segundos = segundos;
            Momento = "a.m";
        }
        else
        {
            throw logic_error("error, verificar que la hora, los minutos y los segundos esten en los rangos correctos");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

tiempo::tiempo(int horas, int minutos, int segundos, string momento)
{
    try
    {
        if (comprobar_hora(horas) != -1 && comprobar_minutos_segundos(minutos) != -1 && comprobar_minutos_segundos(segundos) != -1 && comprobar_momento(momento))
        {
            Hora = horas;
            Minutos = minutos;
            Segundos = segundos;
            Momento = momento;
        }
        else
        {
            throw logic_error("error, verificar que la hora, los minutos, los segundos y el momento esten en los rangos correctos");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

//metodos para leer y cambiar los atributos definidos en private//

void tiempo::leer_hora()
{
    cout << setw(10) <<" hora: " << Hora << endl;
}

void tiempo::cambiar_hora(int nueva_hora)
{
    try
    {
        if (comprobar_hora(nueva_hora)!=-1)
        {
            Hora = nueva_hora;
        }
        else
        {
            throw logic_error("error, hora no valida, verifique que este dentro del rango");
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void tiempo::leer_minutos()
{
    cout << setw(10) <<" minutos: " << Minutos << endl;
}

void tiempo::cambiar_minutos(int nuevos_minutos)
{
    try
    {
        if (comprobar_minutos_segundos(nuevos_minutos)!=-1)
        {
            Minutos = nuevos_minutos;
        }
        else
        {
            throw logic_error("error, minutos no valido, verifique que este dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void tiempo::leer_segundos()
{
    cout << setw(10) <<" segundos: " << Segundos << endl;
}

void tiempo::cambiar_segundos(int nuevos_segundos)
{   
    try
    {
        if (comprobar_minutos_segundos(nuevos_segundos)!=-1)
        {
            Segundos = nuevos_segundos;
        }
        else
        {
            throw logic_error("error, segundos no valido, verifique que este dentro del rango");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void tiempo::leer_momento()
{
    cout << setw(10) <<"el tiempo esta en formato: " << Momento << endl;
}

void tiempo::cambiar_momento(string nuevo_momento)
{   
    try
    {
        if (comprobar_momento(nuevo_momento))
        {
            Momento = nuevo_momento;
        }
        else
        {
            throw logic_error("error, momento no valido, verifique que este dentro de las 2 opciones");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void tiempo::leer_todo()
{
    cout << setw(10) << "hora: " << Hora << " minutos: " << Minutos << " segundos: " << Segundos << " momento: " << Momento << endl;
}

//metodo para mostrar el tiempo en formato de 0 a 24//

void tiempo::mostrar_tiempo_formato_24()
{
    int hora_convertida = Momento == "p.m" ? Hora + 12 : Hora ;
    cout << setw(10) <<"hora: " << hora_convertida << " minutos: " << Minutos << " segundos: " << Segundos << endl ;
}

void opciones()
{
    cout << setfill('-') << setw(10) << "1) la hora " << endl;
    cout << setfill('-') << setw(10) << "2) los minutos" << endl;
    cout << setfill('-') << setw(10) << "3) los segundos" << endl;
    cout << setfill('-') << setw(10) << "4) el momento" << endl;
    
    return;
}

void programa_verificacion()
{

    tiempo tiempo_actual;

    while (true)
    {
        int opcion = 0;

        cout << setw(10) << "que quieres hacer :" << endl;
        cout << setfill('-') << setw(5) << "1) cambiar el tiempo" << endl ;
        cout << setfill('-') << setw(5) << "2) leer el tiempo" << endl ;
        cout << setfill('-') << setw(5) << "3) leer el tiempo en formato 24 horas" << endl ;
        cout << "ingrese el numero de la opcion elegida(-1 para terminar el programa): " << endl;
        cin >> opcion ;

        int subopcion = 0;

        int nuevo_tiempo = 0;

        string nuevo_momento;

        if (opcion == -1)
        {
            return;
        }
        else if (opcion == 1)
        {
            cout << setw(10) << "que quieres modificar:" << endl;
            opciones();

            cin >> subopcion ;

            while (subopcion > 4 || subopcion < 0)
            {
                cout << setw(10) << "error, ingrese un numero dentro de las opciones :" << endl;
                cin >> subopcion ;
            }

            if (subopcion == 1)
            {
                cout << setw(10) << "ingrese la nueva hora :" << endl;
                cin >> nuevo_tiempo;

                while (nuevo_tiempo > 12 || nuevo_tiempo < 0)
                {
                    cout << setw(10) << "error, ingrese una hora valida :" << endl;
                    cin >> nuevo_tiempo ;
                }
                
                tiempo_actual.cambiar_hora(nuevo_tiempo);
            }
            else if (subopcion == 2 || subopcion == 3)
            {
                cout << setw(10) << "ingrese los nuevos minutos/segundos :" << endl;
                cin >> nuevo_tiempo;

                while (nuevo_tiempo > 60 || nuevo_tiempo < 0)
                {
                    cout << setw(10) << "error, ingrese unos minutos/segundos validos :" << endl;
                    cin >> nuevo_tiempo ;
                }

                if (subopcion == 2)
                {
                    tiempo_actual.cambiar_minutos(nuevo_tiempo);
                }
                else
                {
                    tiempo_actual.cambiar_segundos(nuevo_tiempo);
                }
            }
            else if (subopcion == 4)
            {
                string nuevo_momento;
                cout << setw(10) << "ingrese a.m o p.m :" << endl;
                cin >> nuevo_momento;

                while (nuevo_momento != "p.m" && nuevo_momento != "a.m")
                {
                    cout << setw(10) << "error, ingrese un momento valido :" << endl;
                    cin >> nuevo_momento ;
                }
                
                tiempo_actual.cambiar_momento(nuevo_momento);
            }
        }
        else if (opcion == 2)
        {
            cout << setw(10) << "que quieres leer:" << endl;
            opciones();
            cout << setfill('-') << setw(10) << "5) todo en conjunto" << endl;
            cout << "ingrese el numero de la opcion elegida(-1 para terminar el programa): " << endl;
            cin >> subopcion ;

            while (subopcion > 5 || subopcion < 0)
            {
                cout << setw(10) << "error, ingrese un numero dentro de las opciones :" << endl;
                cin >> subopcion;
            }

            if (subopcion == 1)
            {
                tiempo_actual.leer_hora();
            }
            else if (subopcion == 2)
            {
                tiempo_actual.leer_minutos();
            }
            else if (subopcion == 3)
            {
                tiempo_actual.leer_segundos();
            }
            else if (subopcion == 4)
            {
                tiempo_actual.leer_momento();
            }
            else
            {
                tiempo_actual.leer_todo();
            }
        }
        else if (opcion == 3)
        {
            tiempo_actual.mostrar_tiempo_formato_24();
        }
        else
        {
            cout << "error, numero ingresado no valido" << endl ;
        }
    }
}

/*
    comando para ejecutar:
        make ej1
*/
int main()
{
    // casos de inicializacion de objetos con los distintos constructores

    tiempo tiempo1(10);
    tiempo1.leer_todo();

    tiempo tiempo2(10,22);
    tiempo2.leer_todo();

    tiempo tiempo3(10,22,53);
    tiempo3.leer_todo();

    tiempo tiempo4(10,22,53,"a.m");
    tiempo4.leer_todo();

    // casos borde con cada constructor

    tiempo tiempo5(13); //  arroja un throw y lo agarra con catch. muestra por consola que se debe verificar el rango de la hora
    tiempo1.leer_todo();

    tiempo tiempo6(10,76); // arroja un throw y lo agarra con catch. muestra por consola que se debe verificar el rango de la hora y los minutos
    tiempo2.leer_todo();

    tiempo tiempo7(10,22,63); // arroja un throw y lo agarra con catch. muestra por consola que se debe verificar el rango de la hora, los minutos y los segundos
    tiempo3.leer_todo();

    tiempo tiempo8(10,22,53,"p.s"); // arroja un throw y lo agarra con catch. muestra por consola que se debe verificar el rango de la hora, los minutos, los segundos y el momento
    tiempo4.leer_todo();

    programa_verificacion();
    
    return 0;
}