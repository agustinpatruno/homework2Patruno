#ifndef EJERCICIO4_HPP
#define EJERCICIO4_HPP
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class cuenta_de_banco
{     
    protected:

        string titularcuenta;

        double balance;

        double obtenerbalance() const;

        void depositar(double monto_depositar);

        void virtual retirar(double monto_retirar) = 0;

        void virtual mostrarinfo() = 0;
    
    public:
        
        cuenta_de_banco(double balance, string nombretitular);
};

class caja_de_ahorro : public cuenta_de_banco
{
    private:

        int cant_veces_info;

        // funcion que realiza el descuento

        void descuento();

    public:

        // constructor de la caja de ahorro //

        caja_de_ahorro(double balance, string nombretitular);

        // definicion de las funciones 

        void virtual retirar(double monto_retirar) override;

        void virtual mostrarinfo() override;
};

class cuentacorriente : public cuenta_de_banco
{
    private:
        
        unique_ptr<caja_de_ahorro> caja_ahorro;

    public:
        
        friend class caja_de_ahorro;

        // constructor de la cuenta corriente // 

        cuentacorriente(double balance_cuenta_corriente, double balance_cuenta_ahorro, string nombretitular);
        
        // definicion de las funciones

        void virtual retirar(double monto_retirar)override;

        void virtual mostrarinfo()override;
};

#endif

/*
a)

clase cuenta_de_banco:

    private:
        - vacio. esto es debido a que si defino los metodos virtuales puros aca, cuando aplico el polimorfismo en las otras 2 subclases,
            estas no van a poder definir esas funciones debido a que van a tener un error. Esto es debido a que la parte private 
            no permite el acceso a derivadas.
    
    public: 
        - cuenta_de_banco(double balance, string nombretitular);
            debido a que el constructor del objeto tiene que estar necesariamente en la parte pubblica para poder crear el objeto.
        
    protected:
        - string titularcuenta;
            nombre del titular de la cuenta.

        - double balance;
            balance del titular de la cuenta.

        -  double obtenerbalance() const;
            retorna el valor del balance. el const impide modificar cualquier atributo.

        - void depositar(double monto_depositar);
            le suma al balance el monto a depositar que se pasa por parametro.

        - void virtual retirar(double monto_retirar) = 0;
            metodo virtual puro. retira el monto ingresado por parametro. caso de ser negativo o de ser mayor que el balance, retorna un
            mensaje.

        - void virtual mostrarinfo() = 0;
            metodo virtual puto. muestra la informacion del titular de la cuenta(nombre, tipo de cuenta, balance). 

        todos estos metodos y atributos estan en protected para permitir que las clases derivadas hereden los mismo y puedan acceder
        a sus funcionalidades.


clase caja_de_ahorro: 
    
    private:
        - int cant_veces_info;
            contador de la cantidad de veces que se solicita ver la informacion de un titular. 

        - void descuento();
            realiza el incremento de la variable cant_veces_info. ademas despues de mostrar mas de 2 veces la informacion del titular,
            se decuenta 20$ del balanca. caso de que no haya 20$ en el balance, retorna un mensaje.
        
        el atributo, al igual que el metodo esta en private para que no pueda ser modificado desde fuera de un objeto. solo puede ser 
        modificado con un metodo. por que por ejemplo, si estaria en public, el usuario podria modificar el metodo, logrando que luego
        al usar el atributo, le realize un descuento que no se deberia
    
    public: 

        - caja_de_ahorro(double balance, string nombretitular);
            constructor que inicializa en objeto con el balance y el nombre del titual que se le pase por parametro.

        - void virtual retirar(double monto_retirar) override;
            funcion virtual derivada de la clase cuenta_de_banco. caso de que el monto a retirar sea negativo o mayor al balance,
            devuelve un mensaje. caso de que sea menor que el balance, se lo resta al balance.

        - void virtual mostrarinfo() override;
            funcion virtual derivada de la clase cuenta_de_banco. muestra la informacion del titular de la cuenta.
            (tipo de cuenta = caja de ahorro)
        
        el constructor necesariamente tiene que estar en public para que se pueda crear el objeto.
        la funcion retirar, debe estar en public para que el titular de la cuenta pueda retirar de su cuenta el dinero que desee. 
        
*/