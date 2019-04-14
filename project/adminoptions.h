#ifndef ADMINOPTIONS_H
#define ADMINOPTIONS_H

#include <QDialog>

namespace Ui {
class AdminOptions;
}

class AdminOptions : public QDialog
{
    Q_OBJECT

public:
    explicit AdminOptions(QWidget *parent = nullptr);
    ~AdminOptions();

private slots:
    void on_pushButtonExitDialog_clicked();

private:
    Ui::AdminOptions *ui;
};

#endif // ADMINOPTIONS_H
