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

    public:
        
        cuenta_de_banco(double balance, string nombretitular);
        /*
            constructor que incializa el objeto de la cuenta de banco con el balance y el nombre del titular de
            la cuenta.
        */
        
        double obtenerbalance() const;
        /*
            retorna el balance de la cuenta del titular. no modifica nada.
        */

        void depositar(double monto_depositar);
        /*
            deposita el monto ingresado por parametro en la cuenta el titular
        */

        void virtual retirar(double monto_retirar) = 0;
        /*
            retira el monto ingresado por parametro del balance del titular de la cuenta
        */

        void virtual mostrarinfo() = 0;
        /*
            muestra por consola la informacion de la cuenta. (tipo de cuenta, balance y nombre del titular)
        */
};

class caja_de_ahorro : public cuenta_de_banco
{
    private:

        int cant_veces_info;

        // funcion que realiza el descuento

        void descuento();
        /*
            en caso de que el usuario haya visto ina informacion de la cuenta mas de 2 veces, se le hace un descuento a la cuenta de
            20$. caso de que no tenga dicho monto, se arroja un throw y se lo captura con catch
        */

    public:

        // constructor de la caja de ahorro //

        caja_de_ahorro(double balance, string nombretitular);
        /*
            constructor de la caja de ahorro, donde se incializa con el balance y el nombre del titular de la cuenta.
            en caso de que el monto sea negativo o que sea mayor al disponible en la caja, se arroja un throw y se lo captura con catch.
            sino se retira normalmente
        */

        // definicion de las funciones 

        void virtual retirar(double monto_retirar) override;
        /*
            retira el monto pasado por parametro de la caja de ahorro. caso de que sea mayor al disponible, se arroja un throw y
            se captura con catch
        */

        void virtual mostrarinfo() override;
        /*
            muesta la informacion de la cuenta. con el tipo de cuenta = caja de ahorro
        */
};

class cuentacorriente : public cuenta_de_banco
{
    private:
        
        unique_ptr<caja_de_ahorro> caja_ahorro;

    public:
        
        friend class caja_de_ahorro;

        // constructor de la cuenta corriente // 

        cuentacorriente(double balance_cuenta_corriente, double balance_cuenta_ahorro, string nombretitular);
        /*
            constructor de la cuenta corriente, donde se incializa con el balance de la cuenta corriente, el balance de la caja e ahorro 
            y el nombre del titular. se crea tambien un objeto de la caja de ahorro. 
        */
        
        // definicion de las funciones

        void virtual retirar(double monto_retirar)override;
        /*
            retira el monto que se le pase por parametro. en caso de que sea negativo, se arroja un error. en caso de que sea mayor al 
            disponible en el balance de le cuenta corriente, se va a retirar de la caja de ahorro. En caso de que el excedente sea mayor
            al disponible en la caja de ahorro, se arroja un throw y se captura con catch.
        */

        void virtual mostrarinfo()override;
        /*
            muesta la informacion de la cuenta. con el tipo de cuenta = caja de banco, balance de la cuenta corriente, el balance
            de la caja de ahorro y el nombre del titular
        */
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
        
        -  double obtenerbalance() const;
            retorna el valor del balance. el const impide modificar cualquier atributo.

        - void depositar(double monto_depositar);
            le suma al balance el monto a depositar que se pasa por parametro.

        - void virtual retirar(double monto_retirar) = 0;
            metodo virtual puro. retira el monto ingresado por parametro. caso de ser negativo o de ser mayor que el balance, retorna un
            mensaje.

        - void virtual mostrarinfo() = 0;
            metodo virtual puto. muestra la informacion del titular de la cuenta(nombre, tipo de cuenta, balance). 

        todos estos metodos y atributos estan en public para permitir que las clases derivadas hereden los mismo y puedan acceder
        a sus funcionalidades desde, ya que cuando se deriva una clase de forma publica, los metodos que estan en public van a
        estar disponibles en la parte public de la clase derivada.
        
    protected:
        - string titularcuenta;
            nombre del titular de la cuenta.

        - double balance;
            balance del titular de la cuenta.

       
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
        la funcion retirar al igual que la funcion de mostrarinfo, debe estar en public para que el titular de la cuenta pueda 
        retirar de su cuenta el dinero que desee. 

clase cuentacorriente: 

    private:
        - unique_ptr<caja_de_ahorro> caja_ahorro;
            puntero unique_ptr a una caja de ahorro.
        
        el puntero a caja_de_ahorro esta en la parte private por que no quiero que pueda ser accedido y modificado desde afuera del 
        objeto. ya que si estuviera en la parte public, el usuario podria alterar la informacion de la caja de ahorro, modificando su
        balance, de modo que valor que tenga asociado sea no correspondido.    
    
    public:
         
        - friend class caja_de_ahorro;
            asigno a la clase cuentacorriente, que pueda acceder a todas los metodos/atributos de las areas de la clase caja_de_ahorro

        - cuentacorriente(double balance_cuenta_corriente, double balance_cuenta_ahorro, string nombretitular);
            constructor que incializa el objeto de la cuentacorriente con el balance de la cuenta corriente y el nombre del titular. 
            ademas crea un objeto de la clase cuenta_de_ahorro y la inicializa con el balance de la cuenta de ahorro y el nombre del
            titular.

        - void virtual retirar(double monto_retirar)override;
            funcion virtual derivada de la clase cuenta_de_banco. caso de que el monto a retirar sea negativo o mayor al monto 
            guardado en el balance, intenta sacar dinero de la cuenta de ahorro, pasandole como parametro la diferencia entre el monto
            incial y el balance en la cuenta corriente. 

        - void virtual mostrarinfo()override;
            funcion virtual derivada de la clase cuenta_de_banco. muestra la informacion del titular de la cuenta. 
        
        el constructor neceriamente tiene que estar en la parte public debido a que se requiere para incializar el objeto.
        la funcion de retirar, debe estar en la parte public para que el usuario pueda retirar dinero de su cuenta corriente. 
        la funcion de mostrarinfo, para que el usuario pueda ver sus datos, tiene que estar habilitado al publico. 
*/