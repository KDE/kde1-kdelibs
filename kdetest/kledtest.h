#ifndef kledtest_h
#define kledtest_h

#include <ktopwidget.h>
#include <qwidget.h>
#include <qtimer.h>
#include <stdlib.h>
#include <kled.h>

class ktmp : public QObject
{
Q_OBJECT
public:
ktmp(KLed *l) : led(l), ledcolor(l->getColor()), ledlook(l->getLook()) {};
~ktmp() {};

 public slots:
 void nextColor() {
   int tmp = (static_cast<int>(ledcolor) + 1) % 5;
   ledcolor=static_cast<KLed::Color>(tmp);
   led->setColor(ledcolor);
   led->repaint(); }
  void nextLook() { 
    int tmp = (static_cast<int>(ledcolor) + 1) % 3;
    ledlook = static_cast<KLed::Look>(tmp);
    led->setLook(ledlook);
    led->repaint(); }

private:
  KLed        *led;
  KLed::Color ledcolor;
  KLed::Look  ledlook;
};
#endif

