#ifndef SORT_H
#define SORT_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QTime>
#include <QApplication>
#include <QPainter>
#include <QStack>
#include <QDesktopWidget>

class Sort : public QWidget
{
    Q_OBJECT
public:
    explicit Sort(QWidget *parent = 0);
    int b;
    QLabel *backup[50];
    QLabel *label[50];
    QGridLayout *layout;    //布局用
    void layoutwindow();
    void insertsort(); //直接插入排序
    void BInsertSort();//折半插入排序
    void shell_sort();//希尔排序
    void Bubble_Sort();    //冒泡排序
    void quickSort(QLabel *label[50],int l,int h);
	int partition(QLabel *label[50], int l, int h);//快速排序
    void selectSort();//简单选择排序
};

#endif // SORT_H
