#include <ejercicio4.hpp>

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

cuenta_de_banco::cuenta_de_banco(double balance, string nombretitular) : balance(balance), titularcuenta(nombretitular){}

// implementacion de los metodos de caja_de_ahorro //

void caja_de_ahorro::descuento()
{
    if (cant_veces_info > 2)
    {
        if (obtenerbalance() >= 20)
        {
            balance -= 20;
            return;
        }
        cout << "no hay suficiente dinero para aplicar el descuento" << endl;
    }
}

////// constructor de la caja de ahorro //////

caja_de_ahorro::caja_de_ahorro(double balance, string nombretitular) : cuenta_de_banco(balance,nombretitular), cant_veces_info(0){}

// definicion de las funciones 

void caja_de_ahorro::retirar(double monto_retirar)
{
    if (monto_retirar < 0)
    { 
        throw invalid_argument("arror, no se puede retirar un monto negativo");
        return;
    }
    if (monto_retirar > obtenerbalance())
    {
        cout << "arror, no se puede retirar un monto mayor al que hay en la cuenta de ahorro." << endl;
        return;
    }

    balance -= monto_retirar;

}

void caja_de_ahorro::mostrarinfo()
{
    cout << "tipo de cuenta: cuenta de ahorro" << endl;
    cout << "balance: " << balance << endl;
    cout << "nombre del titular: " << titularcuenta << endl;
    
    cant_veces_info += 1;

    descuento();
}

////// implementacion metodos de la clase cuentacorriente //////

// constructor de la cuenta corriente // 

cuentacorriente::cuentacorriente(double balance_cuenta_corriente, double balance_cuenta_ahorro, string nombretitular) :cuenta_de_banco(balance_cuenta_corriente,nombretitular)
{
    caja_ahorro = make_unique<caja_de_ahorro>(balance_cuenta_ahorro,nombretitular);
}

// definicion de las funciones

void cuentacorriente::retirar(double monto_retirar)
{
    if (monto_retirar < 0)
    {
        throw invalid_argument("arror, no se puede retirar un monto negativo");
        return;
    }
    else if (monto_retirar <= obtenerbalance())
    {
        balance -= monto_retirar;
    }
    else
    {
        double excedente = monto_retirar - obtenerbalance();

        balance = 0;

        caja_ahorro->retirar(excedente);
    }
}

void cuentacorriente::mostrarinfo()
{
    cout << "tipo de cuenta: cuenta corriente" << endl;
    cout << "balance: " << balance << endl;
    cout << "nombre del titular: " << titularcuenta << endl;
}
