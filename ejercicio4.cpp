#include "ejercicio4.hpp"

////// implementacion de los metodos de la clase cuenta_de_banco //////

double cuenta_de_banco::obtenerbalance() const
{
    return balance;
}

void cuenta_de_banco::depositar(double monto_depositar)
{
    balance += monto_depositar;
    return;
}

// constructor de la cuenta de banco //

cuenta_de_banco::cuenta_de_banco(double balance, string nombretitular) 
{
    try
    {
        if (balance > 0)
        {
            balance = balance;

            titularcuenta = nombretitular;
        }
        else
        {
            throw logic_error("error, ingrese un balance positivo");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

////////////////////////////////// implementacion de los metodos de caja_de_ahorro //////////////////////////////////////

void caja_de_ahorro::descuento()
{
    if (cant_veces_info > 2)
    {
        try
        {
            if (obtenerbalance() >= 20)
            {
                cout << "se descontara 20$ por solicitar ver la informacion " << endl;

                balance -= 20;

                return;
            }
        throw logic_error("no hay suficiente dinero para aplicar el descuento");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

////// constructor de la caja de ahorro //////

caja_de_ahorro::caja_de_ahorro(double balance, string nombretitular) : cuenta_de_banco(balance,nombretitular), cant_veces_info(0){}

// definicion de las funciones 

void caja_de_ahorro::retirar(double monto_retirar)
{
    try
    {
        if (monto_retirar < 0)
        { 
            throw logic_error("error, no se puede retirar un monto negativo");
        }
        if (monto_retirar > obtenerbalance())
        {
            throw logic_error("error, no se puede retirar un monto mayor al que hay en la cuenta de ahorro.");
        }
    
        balance -= monto_retirar;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void caja_de_ahorro::mostrarinfo()
{
    cout << "tipo de cuenta: cuenta de ahorro" << endl;
    cout << "balance: " << balance << endl;
    cout << "nombre del titular: " << titularcuenta << endl;
    cout << "------------------" << endl;
    
    cant_veces_info += 1;

    descuento();
}

//////////////////////////// implementacion metodos de la clase cuentacorriente ///////////////////////////////////

// constructor de la cuenta corriente // 

cuentacorriente::cuentacorriente(double balance_cuenta_corriente, double balance_cuenta_ahorro, string nombretitular) :cuenta_de_banco(balance_cuenta_corriente,nombretitular)
{
    caja_ahorro = make_unique<caja_de_ahorro>(balance_cuenta_ahorro,nombretitular);
}

// definicion de las funciones

void cuentacorriente::retirar(double monto_retirar)
{
    try
    {
        if (monto_retirar < 0)
        {
            throw logic_error("error, no se puede retirar un monto negativo");
        }
        else if (monto_retirar <= obtenerbalance())
        {
            balance -= monto_retirar;
        }
        else
        {
            double excedente = monto_retirar - obtenerbalance();
    
            balance = 0;
    
            cout << " se intentara retirar: " << excedente << " de la caja de ahorro" << endl;
    
            caja_ahorro->retirar(excedente);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void cuentacorriente::mostrarinfo()
{
 
    cout << "tipo de cuenta: cuenta corriente" << endl;
    cout << "balance de cuenta corriente: " << balance << endl;
    cout << " balanace de la cuenta de ahorro: " << caja_ahorro->obtenerbalance() << endl;
    cout << "nombre del titular: " << titularcuenta << endl;
    cout << "------------------" << endl;
}

/*
    comando para ejecutar:
        make ej4
*/
int main()
{
    caja_de_ahorro miCajaDeAhorro(1000.0, "Juan Pérez");

    cuentacorriente miCuentaCorriente(2000.0, 500.0, "María López");

    // operaciones en la caja de ahorro

    cout << "------------operaciones de la caja de ahorro ---------------" << endl;

    miCajaDeAhorro.mostrarinfo();

    miCajaDeAhorro.retirar(200.0);

    miCajaDeAhorro.mostrarinfo();

    miCajaDeAhorro.depositar(150.43);

    miCajaDeAhorro.mostrarinfo();

    cout <<" - balance de la cuenta de ahorro: "<< miCajaDeAhorro.obtenerbalance() << endl;

    miCajaDeAhorro.retirar(1500.54);

    // operaciones en la cuenta corriente

    cout << "------------operaciones de la cuenta corriente --------------" << endl;

    miCuentaCorriente.retirar(750.65);

    miCuentaCorriente.mostrarinfo();

    miCuentaCorriente.depositar(120.22);

    miCuentaCorriente.mostrarinfo();

    cout << " balance de la cuenta corriente: " << miCuentaCorriente.obtenerbalance() << endl;

    miCuentaCorriente.retirar(2300.43);

    miCuentaCorriente.retirar(-230);

    // casos limite de creacion de cuentas con balance negativo

    caja_de_ahorro miCajaDeAhorro1(-455, "Juan Rodriguez");

    cuentacorriente miCuentaCorriente1(-2000.0, 500.0, "María Perez");

}