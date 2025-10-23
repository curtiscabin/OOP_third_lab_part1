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
    CCircle *c = new CCircle(p, this);
    store->add(c);
    ui->counter->setText(QString::number(store->get_size()));
}



void MainWindow::on_PaintAllCircle_clicked()
{
    for(store->first();!store->eol();store->next()){
        store->getObject()->paint_circle();
    }
}

