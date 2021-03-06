#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    simulator = new RSTrainSimulator();
    number_of_vehicles = 0;
    train_pos = 0;
    ui->plotArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->plotArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    getter = simulator->getGetterAndLogger();
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlots()));
    plotList = new QStringList;
    plotList->clear();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::print_log_out(QString str)
{
    ui->log_out->appendPlainText(str);
}


void MainWindow::on_init_road_clicked()
{
    QString roadFileName = ui->road_name->text();
    simulator->InitRailwayElement(roadFileName.toUtf8().constData());
    QString txt = "";
    txt.append("Road is initialized: ");
    txt.append(roadFileName);
    this->print_log_out(txt);
}


void MainWindow::on_browse_road_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("Xml Files (*.xml)"));
    ui->road_name->setText(fileName);
}


void MainWindow::on_add_loco_clicked()
{
    number_of_vehicles ++;

    QString type = ui->loco_type->text();
    simulator->addLocomotive(type.toInt());
    QString txt = "";
    txt.append("Added locomotive type ");
    txt.append(type);
    this->print_log_out(txt);

    type.prepend(") ");
    type.prepend(QString::number((number_of_vehicles)));
    type.append(" loco");
    ui->train_list->addItem(type);

    train_pos += simulator->getVehicleVector()[number_of_vehicles-1]->getLength() + 0.15;
    ui->pos_value->setText(QString::number(train_pos));
}

void MainWindow::on_add_car_clicked()
{
    number_of_vehicles ++;

    QString type = ui->car_type->text();
    simulator->addCar(type.toInt());
    QString txt = "";
    txt.append("Added car type ");
    txt.append(type);
    this->print_log_out(txt);

    type.prepend(") ");
    type.prepend(QString::number((number_of_vehicles)));
    type.append(" car");
    ui->train_list->addItem(type);

    train_pos += simulator->getVehicleVector()[number_of_vehicles-1]->getLength() + 0.15;
    ui->pos_value->setText(QString::number(train_pos));
}


void MainWindow::on_set_poisition_clicked()
{
    QString road_index = ui->road_index_value->text();
    QString first_position = ui->pos_value->text();
    QString speed = ui->vel_value->text();
    simulator->InitPositions(road_index.toInt(), first_position.toDouble());
    simulator->InitSpeed(speed.toDouble());

    QString text;
    text.append("The train is set to position ");
    text.append(first_position);
    text.append(" at road index ");
    text.append(road_index);
    text.append(" with speed ");
    text.append(speed);
    print_log_out(text);
}


void MainWindow::on_actionAdd_Plot_triggered()
{
    QWidget *widget = new QWidget();
    QCustomPlot *customPlot = new QCustomPlot(widget);
    QString plotName;
    plotName.setNum(plotList->size());
    customPlot->setObjectName(plotName);
    ui->plotArea->addSubWindow(customPlot);
    plotList->append(plotName);
}


void MainWindow::updatePlots()
{
    for(int k=0;k<plotList->size();k++)
    {
        QCustomPlot *customPlot = ui->plotArea->findChild<QCustomPlot*>(plotList->value(k));
        customPlot->addGraph();
       // customPlot->graph(0)->addData(i,i*2);
        customPlot->xAxis->setLabel("x");
        customPlot->yAxis->setLabel("y");
        // set axes ranges, so we see all data:
        customPlot->xAxis->setRange(-100, 100);
        customPlot->yAxis->setRange(-1000, 1000);
        customPlot->replot();
    }
}

void MainWindow::on_start_clicked()
{
    timer->start(1000);
}
