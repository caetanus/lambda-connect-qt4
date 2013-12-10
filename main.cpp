#include <QApplication>
#include <QPoint>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QPushButton>

#include "mainwindow.h"
#include "lambdaconnect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPushButton b(&w);
    connect(&b, SIGNAL(clicked()),
            []() {
                auto autoVarTest = QString("button was clicked");
                QMessageBox::information(NULL, "button was clicked!", autoVarTest);
            });

    w.show();

    return a.exec();
}
