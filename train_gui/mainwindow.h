#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "RSTrainCar.h"
#include "RSTrainLocomotive.h"
#include "RSTrainCoupling.h"
#include "RSTrainParser.h"
#include "RSTrainLocomotiveParser.h"
#include "RSTrainCarParser.h"
#include "RSTrainRailwayElementParser.h"
#include "RSTrainDynamicModel.h"
#include "RSTrainSimulator.h"
#include "RSTrainRoadWatcher.h"
#include "RSTrainVehicle.h"
#include "RSTrainGetter.h"

#include <QPlainTextEdit>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
#include <qcustomplot.h>

#include <QMainWindow>
#include <QTimer>
#include <QStringList>


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


    void on_init_road_clicked();

    void on_browse_road_clicked();

    void on_add_loco_clicked();

    void on_add_car_clicked();

    void on_set_poisition_clicked();

    void on_actionAdd_Plot_triggered();

    void on_start_clicked();

    void updatePlots();


private:
    Ui::MainWindow *ui;
    RSTrainSimulator * simulator;
    RSTrainGetter* getter;

    int number_of_vehicles;
    double train_pos;

    QTimer *timer;

    void print_log_out(QString str);

    QStringList* plotList;

};

#endif // MAINWINDOW_H
