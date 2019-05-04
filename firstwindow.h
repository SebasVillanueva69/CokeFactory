#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QMainWindow>

namespace Ui {
class firstWindow;
}

class firstWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit firstWindow(QWidget *parent = nullptr);
    ~firstWindow();

private slots:
    void start();
    void add();
private:
    Ui::firstWindow *ui;
};

#endif // FIRSTWINDOW_H
