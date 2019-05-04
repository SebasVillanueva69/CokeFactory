#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QMainWindow>
#include "doublelinkedlist.h"

namespace Ui {
class firstWindow;
}

class firstWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit firstWindow(QWidget *parent = nullptr);
    ~firstWindow();
    doubleLinkedList *types = new doubleLinkedList();


private slots:
    void start();
    void add();
private:
    Ui::firstWindow *ui;
};

#endif // FIRSTWINDOW_H
