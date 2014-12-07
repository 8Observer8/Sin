#include <cmath>
#include <QDebug>
#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui( new Ui::Dialog )
{
    ui->setupUi( this );

    QVector<double> x( 101 ), y( 101 ); // Initialize with entries 0..100

    for ( int i = 0; i < 101; ++i )
    {
        x[i] = ( i/50.0 - 1 ) * M_PI; // x goes from -Pi to Pi
        y[i] = std::sin( x[i] );
    }

    // Create graph and assign data to it:
    ui->plotWidget->addGraph();
    ui->plotWidget->graph( 0 )->setData( x, y );

    // Give the axes some labels:
    ui->plotWidget->xAxis->setLabel( "x" );
    ui->plotWidget->yAxis->setLabel( "y" );

    // Set axes ranges, so we see all data:
    ui->plotWidget->xAxis->setRange( -M_PI, M_PI );
    ui->plotWidget->yAxis->setRange( -1, 1 );
}

Dialog::~Dialog()
{
    delete ui;
}
