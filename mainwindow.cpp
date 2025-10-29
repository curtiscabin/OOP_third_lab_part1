#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *m_event) {
    QPoint p = m_event->pos();
    bool isSelect = false;

    for(store->first();!store->eol();store->next()){
        if (store->getObject()->isCordBelongCircle(p)){
            isSelect = true;
            if (!store->getObject()->isSelect()){
                select_circles->add(store->getObject());
                store->getObject()->setSelection();
            }
        }
    }
    ui->counter_2->setText(QString::number(select_circles->get_size()));

    if (!isSelect){
        CCircle *c = new CCircle(p, this);
        c->paint_circle();
        store->add(c);
        ui->counter->setText(QString::number(store->get_size()));
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    int key=event->key();

    if (key == Qt::Key_Delete){
         qDebug()<<"key is Delete";
        store->deleteSelect(select_circles);
        ui->counter_2->setText(QString::number(select_circles->get_size()));
        ui->counter->setText(QString::number(store->get_size()));
    }
}




