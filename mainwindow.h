// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include "config.h"
#include "gameframe.h"
class Gameframe;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void startGame();

private:
    QPushButton *startButton;
    QPushButton *exitButton;
    Gameframe* m_game;

public:

};

#endif // MAINWINDOW_H
