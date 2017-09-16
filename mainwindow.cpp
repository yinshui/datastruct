#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sort.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    linefromedit=arg1;
}

void MainWindow::on_lineEdit_editingFinished()
{
    if(linefromedit.isEmpty())
        QMessageBox::information(this,"tips","Please input data");
    else{
        sss=new Sort;
        QStringList list = linefromedit.split(" ", QString::SkipEmptyParts);
        sss->b = list.count();
        int bb=sss->b;
        for (bb=bb-1; bb >= 0; bb -= 1)
        {
            sss->label[bb]=new QLabel;
            sss->label[bb]->setText(list.at(bb));
            sss->backup[bb]=new QLabel;
            sss->backup[bb]->setText(list.at(bb));
        }
        sss->layoutwindow();
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(linefromedit.isEmpty())
        QMessageBox::information(this,"tips","Please input data");
    else{
        int bb=sss->b;
        for (bb=bb-1; bb >= 0; bb -= 1)
        {
            sss->label[bb]->setText(sss->backup[bb]->text());
        }
        sss->show();
        sss->insertsort();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(linefromedit.isEmpty())
        QMessageBox::information(this,"tips","Please input data");
    else{
        int bb=sss->b;
        for (bb=bb-1; bb >= 0; bb -= 1)
        {
            sss->label[bb]->setText(sss->backup[bb]->text());
        }
        sss->show();
        sss->BInsertSort();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(linefromedit.isEmpty())
        QMessageBox::information(this,"tips","Please input data");
    else{
        int bb=sss->b;
        for (bb=bb-1; bb >= 0; bb -= 1)
        {
            sss->label[bb]->setText(sss->backup[bb]->text());
        }
        sss->show();
        sss->Bubble_Sort();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(linefromedit.isEmpty())
        QMessageBox::information(this,"tips","Please input data");
    else{
        int bb=sss->b;
        for (bb=bb-1; bb >= 0; bb -= 1)
        {
            sss->label[bb]->setText(sss->backup[bb]->text());
        }
        sss->show();
        sss->shell_sort();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(linefromedit.isEmpty())
        QMessageBox::information(this,"tips","Please input data");
    else{
        int bb=sss->b;
        for (bb=bb-1; bb >= 0; bb -= 1)
        {
            sss->label[bb]->setText(sss->backup[bb]->text());
        }
        sss->show();
        sss->quickSort(sss->label,0,sss->b-1);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if(linefromedit.isEmpty())
        QMessageBox::information(this,"tips","Please input data");
    else{
        int bb=sss->b;
        for (bb=bb-1; bb >= 0; bb -= 1)
        {
            sss->label[bb]->setText(sss->backup[bb]->text());
        }
        sss->show();
        sss->selectSort();
    }
}
