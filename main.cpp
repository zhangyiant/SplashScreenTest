#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QString>
#include <iostream>

using namespace std;

class MySplashScreen: public QSplashScreen {
public:
  MySplashScreen(const QPixmap &pixmap, Qt::WindowFlags f=Qt::WindowFlags())
    : QSplashScreen(pixmap, f) {
  }
  void mousePressEvent(QMouseEvent *)
  {
    return;
   }
  void keyPressEvent(QKeyEvent *) {
    cout << "key pressed" << endl;
    return;
  }
  bool event(QEvent *e) {
    // cout << "event" << endl;
    // cout << e->type() << endl;
    return QSplashScreen::event(e);
  }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/splash.png");
    MySplashScreen splash(pixmap);
    splash.show();
    splash.setFocusPolicy(Qt::StrongFocus);
    a.processEvents();
    splash.setFocus();
    cout << splash.focusPolicy() << endl;
    cout << splash.hasFocus() << endl;
    cout << splash.isWindow() << endl;
    int t = 0;
    for (int i = 1; i< 100000; i++) {
        t *= i;

        a.processEvents();
	// cout << splash.hasFocus() << endl;
    }
    MainWindow w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
