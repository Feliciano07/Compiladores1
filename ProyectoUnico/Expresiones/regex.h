#ifndef REGEX_H
#define REGEX_H
#include <QString>

class Regex
{
public:
    Regex();
    Regex(QString ide, QString re);
    QString nombre;
    QString rege;
};

#endif // REGEX_H
