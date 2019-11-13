#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_horizontalSliderZTela_valueChanged();
    void on_pushButtonMatriz_clicked();
    void on_pushButtonMudarCor_clicked();
    void on_pushButtonPutBox_clicked();
    void on_pushButtonCutBox_clicked();
    void on_pushButtonPutSphere_clicked();
    void on_pushButtonCutSphere_clicked();
    void on_pushButtonPutEllipsoid_clicked();
    void on_pushButtonCutEllipsoid_clicked();
    void on_pushButtonExportarOFF_clicked();
    void on_radioButtonSphere_clicked();
    void on_radioButtonBox_clicked();
    void on_radioButtonPut_clicked();
private:
    int matrizX,matrizY,matrizZ;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

