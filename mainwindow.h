#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QList>
#include "MyStorage.h"
#include "CCircle.h"
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

protected:
    void mousePressEvent(QMouseEvent *m_event) override;
    void keyPressEvent(QKeyEvent *event);
    MyStorage *store = new MyStorage;
    MyStorage *select_circles = new MyStorage;

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
