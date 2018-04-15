#ifndef _MAINWINDOW_h
#define _MAINWINDOW_h

#include <math.h>
#include <cstdlib>
#include <QMainWindow>
#include "ui_MainWindow.h"
#include "vtkGenericOpenGLRenderWindow.h"
#include "vtkOpenGLRenderer.h"
#include "vtkPolyDataReader.h"
#include "vtkPolyData.h"
#include "vtkPolyDataMapper.h"
#include "vtkOpenGLActor.h"
#include "vtkOpenGLProperty.h"
#include <QVTKOpenGLWidget.h>
#include "vtkRendererCollection.h"
#include "vtkSmartPointer.h"
#include <Eigen/Dense>
#include <qwt_scale_engine.h>

class MainWindow : public QMainWindow, public Ui::GUI
{
    Q_OBJECT
public:
    typedef Eigen::VectorXd VectorXd;
    typedef Eigen::Vector3d Vector3d;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow(){}
signals:
    void updateScene1();
    void updateScene2();
private slots:
    double_t calculateAsphericity(vtkSmartPointer<vtkPolyData> p);
    double_t calculateRMSAd(vtkSmartPointer<vtkPolyData> p);
    void on_slider1_valueChanged(double position);
    void on_slider2_valueChanged(double position);
private:
    vtkSmartPointer<vtkPolyData> poly1;
    vtkSmartPointer<vtkPolyData> poly2;
    vtkSmartPointer<vtkPolyData> poly1_0;
    vtkSmartPointer<vtkPolyData> poly2_0;
};

#endif // _MAINWINDOW_h

