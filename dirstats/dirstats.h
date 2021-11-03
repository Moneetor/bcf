//
// Created by lineprog on 03.11.2021.
//

#ifndef BCF_DIRSTATS_H
#define BCF_DIRSTATS_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class DirStats; }
QT_END_NAMESPACE

class DirStats : public QMainWindow {
    Q_OBJECT

public:
    explicit DirStats(QWidget *parent = nullptr);

    ~DirStats() override;

private:
    Ui::DirStats *ui;
};


#endif //BCF_DIRSTATS_H
