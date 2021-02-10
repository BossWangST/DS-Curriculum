#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_qttest.h"
#include "graph.h"
#include "graph.cpp"
class qttest : public QMainWindow
{
    Q_OBJECT

public:
    friend class graph<int>;
    qttest(QWidget *parent = Q_NULLPTR);
    void readfile(ifstream&);
    void update();
public slots:
    void resetbtn();
    void quitbtn();
    void on_action_triggered();
    void on_action_2_triggered();
    void solution();
protected:
    void keyPressEvent(QKeyEvent* event);
private:
    Ui::qttestClass ui;
    graph<int> *Graph;
    path* Path;
    int housenum = 0;
};
