#include "led-switch.h"
#include "QDebug"
// --------------------------------------------------
/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 *                   Class Led                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * */
// --------------------------------------------------
Led::Led(QString path) : _led_accessible(0)
{
    on = new char('1');
    off = new char('0');

    _led_file = new QFile(path);

    if(_led_file->open(stdin,  QIODevice::WriteOnly))
    {
        _led_accessible = 1;
        qDebug() << "led file is opend \n";
    }

    else
    {
        _led_accessible = 0;
        qDebug() << "led file not opend  !!\n";
    }
}
// --------------------------------------------------
Led::~Led()
{
    delete _led_file;
}
// --------------------------------------------------
void Led::turn_led_on()
{
    _led_file->write(on);
    qDebug() << "led on \n";
}
// --------------------------------------------------
void Led::turn_led_off()
{
    _led_file->write(off);
    qDebug() << "led off \n";
}
// --------------------------------------------
bool Led::is_led_accessible()
{
    return _led_accessible;
}
