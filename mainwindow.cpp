#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QIntValidator>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    matrizX = 1;
    matrizY = 1;
    matrizZ = 1;

    ui->lineEditX->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditY->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditZ->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditXBox->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditYBox->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditZBox->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditSphere->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditXEllipsoid->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditYEllipsoid->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditZEllipsoid->QLineEdit::setValidator( new QIntValidator(0, 300, this) );
    ui->lineEditRCor->QLineEdit::setValidator( new QIntValidator(0, 255, this) );
    ui->lineEditGCor->QLineEdit::setValidator( new QIntValidator(0, 255, this) );
    ui->lineEditBCor->QLineEdit::setValidator( new QIntValidator(0, 255, this) );
    ui->lineEditACor->QLineEdit::setValidator( new QIntValidator(0, 100, this) );
    ui->horizontalSliderZTela->QSlider::setMaximum(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSliderZTela_valueChanged()
{
    ui->telaMatriz->setZAtual(ui->horizontalSliderZTela->value());
}

void MainWindow::on_pushButtonMatriz_clicked()
{
    matrizX = ui->lineEditX->text().toInt();
    matrizY = ui->lineEditY->text().toInt();
    matrizZ = ui->lineEditZ->text().toInt();

    ui->horizontalSliderZTela->QSlider::setMaximum(matrizZ-1);

    ui->telaMatriz->setSizeMatriz(matrizX,matrizY,matrizZ);
}

void MainWindow::on_pushButtonMudarCor_clicked()
{
    int r,g,b,a=100;

    r = ui->lineEditRCor->text().toInt();
    g = ui->lineEditGCor->text().toInt();
    b = ui->lineEditBCor->text().toInt();
    a = ui->lineEditACor->text().toInt();

    ui->telaMatriz->setRGBA(r,g,b,a);
}

void MainWindow::on_pushButtonPutBox_clicked()
{
    int x1,y1,z1;

    x1 = ui->lineEditXBox->text().toInt();
    y1 = ui->lineEditYBox->text().toInt();
    z1 = ui->lineEditZBox->text().toInt();

    ui->telaMatriz->putBox(x1,y1,z1);
}

void MainWindow::on_pushButtonCutBox_clicked()
{
    int x1,y1,z1;

    x1 = ui->lineEditXBox->text().toInt();
    y1 = ui->lineEditYBox->text().toInt();
    z1 = ui->lineEditZBox->text().toInt();

    ui->telaMatriz->cutBox(x1,y1,z1);
}

void MainWindow::on_pushButtonPutSphere_clicked()
{
    int r;

    r = ui->lineEditSphere->text().toInt();

    ui->telaMatriz->putSphere(r);
}

void MainWindow::on_pushButtonCutSphere_clicked()
{
    int r;

    r = ui->lineEditSphere->text().toInt();

    ui->telaMatriz->cutSphere(r);
}

void MainWindow::on_pushButtonPutEllipsoid_clicked()
{
    int rx,ry,rz;

    rx = ui->lineEditXEllipsoid->text().toInt();
    ry = ui->lineEditYEllipsoid->text().toInt();
    rz = ui->lineEditZEllipsoid->text().toInt();

    ui->telaMatriz->putEllipsoid(rx,ry,rz);
}

void MainWindow::on_pushButtonCutEllipsoid_clicked()
{
    int rx,ry,rz;

    rx = ui->lineEditXEllipsoid->text().toInt();
    ry = ui->lineEditYEllipsoid->text().toInt();
    rz = ui->lineEditZEllipsoid->text().toInt();

    ui->telaMatriz->cutEllipsoid(rx,ry,rz);
}

void MainWindow::on_pushButtonExportarOFF_clicked()
{
    string nome = ui->lineEditOFF->text().toStdString();
    nome = nome + ".OFF";
    ui->telaMatriz->exportarOFF(nome);
}

void MainWindow::on_radioButtonPut_clicked()
{
    ui->telaMatriz->setRadioButton(1);
}

void MainWindow::on_radioButtonBox_clicked()
{
    ui->telaMatriz->setRadioButton(2);
}

void MainWindow::on_radioButtonSphere_clicked()
{
    ui->telaMatriz->setRadioButton(3);
}

