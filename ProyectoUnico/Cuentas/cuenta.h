#ifndef CUENTA_H
#define CUENTA_H
#include <QString>
#include <QStringList>

class Cuenta
{
public:
    Cuenta();
    Cuenta(QString nombe,QString expresionRegular);

    QString nombreArchivo;
    QString expresionRegular;

    bool cadenaValida;

    double dineroTotal;

    void Sumar(QString monto);
    bool Restar(QString monto);//si total es 0 se cancela la transaccion

    QString movimientos;

    QString RetonarMovimiento();

    double ConsultarSaldo();




};

#endif // CUENTA_H
