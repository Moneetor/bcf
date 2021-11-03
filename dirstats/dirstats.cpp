//
// Created by lineprog on 03.11.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DirStats.h" resolved

#include "dirstats.h"
#include "ui_DirStats.h"


DirStats::DirStats(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::DirStats) {
    ui->setupUi(this);
}

DirStats::~DirStats() {
    delete ui;
}

