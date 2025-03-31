#ifndef EJERCICIO4_HPP
#define EJERCICIO4_HPP
#include <iostream>
#include <string>
#include <memory>
using namespace std;


class cuenta_de_banco
{     
    public:
        
        
        cuenta_de_banco(double balance, string nombretitular)
        {
            balance = balance;
            titularcuenta = nombretitular;
        }

    protected:

        string titularcuenta;

        double balance;

        double obtenerbalance()
        {
            return balance;
        }

        void depositar(double monto_depositar)
        {
            balance += monto_depositar;
            return;
        }

        void virtual retirar(double monto_retirar) const = 0;

        void virtual mostrarinfo() const = 0;
};


class caja_de_ahorro : public cuenta_de_banco
{
    private:

        int cant_veces_info ;

    public:
        
        caja_de_ahorro(double balance, string nombretitular) : cuenta_de_banco(balance,nombretitular), cant_veces_info(0){}
        

        void retirar(double monto_retirar) override
        {
            if (monto_retirar < 0)
            { 
                throw invalid_argument("arror, no se puede retirar un monto negativo");
                return;
            }
            if (monto_retirar > obtenerbalance())
            {
                throw invalid_argument("arror, no se puede retirar un monto mayor al que hay en balance");
                return;
            }
        }
};

#endif