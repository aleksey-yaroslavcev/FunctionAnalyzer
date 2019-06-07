#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "IFunction.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void registerFunction(IFunction* function);
    void updateFunctionComboboxes();

private slots:
    void on_zoomInBut_clicked();

    void on_zoomOutBut_clicked();

    void on_scrollUpBut_clicked();

    void on_scrollDownBut_clicked();

    void on_scrollLeftBut_clicked();

    void on_scrollRightBut_clicked();

    void on_resetBut_clicked();

    void on_cobF1Type_activated(int index);

    void on_cobF2Type_activated(int index);

private:
    Ui::MainWindow* ui;
    QList<IFunction*> _functions;
};

#endif // MAINWINDOW_H
