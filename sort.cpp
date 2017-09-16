#include "sort.h"
#include <cstdlib>

Sort::Sort(QWidget *parent) : QWidget(parent)
{
    QDesktopWidget* desktop = QApplication::desktop(); // =qApp->desktop();也可以
    move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);
}

void sleep(unsigned int msec){
    QTime reachTime=QTime::currentTime().addMSecs(msec);

    while (QTime::currentTime()<reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}

void Sort ::layoutwindow(){
    layout = new QGridLayout(this);
    for(int i = 0; i < b; ++i)
    {
        label[i]->setMinimumSize(55,0);
        label[i]->setAlignment(Qt::AlignCenter);
        layout->addWidget(label[i], 5, i);
    }
    this->setLayout(layout);
}

//直接插入排序
void Sort ::insertsort(){
    QString tmp;
    for(int i=1; i  < b; i++) {
        int j = i;
        while(j > 0 && (label[j]->text().toInt() < label[j-1]->text().toInt())) {
            QFont ft;
            ft.setPointSize(24);
            label[j]->setFont(ft);
            label[j - 1]->setFont(ft);    //简单的字体放大

            tmp = label[j]->text();
            label[j]->setText(label[j - 1]->text());
            label[j - 1]->setText(tmp);    //交换数值
            sleep(1000);    //自定义的延时函数

            ft.setPointSize(12);    //字体的缩小
            label[j]->setFont(ft);
            label[j - 1]->setFont(ft);
            j--;
        }
    }
}

//折半插入排序
void Sort ::BInsertSort(){
	QFont ft;
	for (int i = 1; i<b; i++)
	{
		if (label[i]->text().toInt() >= label[i - 1]->text().toInt())
            continue;
		int low = 0, high = i - 1;//首先0同1 
		int temp = label[i]->text().toInt();
		while (low <= high)
		{
			int mid = (low + high) / 2;//中点在low 
			if (temp>label[mid]->text().toInt())
				low = mid + 1;
			else if (temp<label[mid]->text().toInt())
				high = mid - 1;
			else
				break;
		}
		int j = i;
		while (j>low)//这时low=high,1 3 5 6 
		{
			ft.setPointSize(24);
			label[j]->setFont(ft);
			label[j - 1]->setFont(ft);    //简单的字体放大
			label[j]->setText(label[j-1]->text());    //交换数值
			sleep(1000);    //自定义的延时函数

			ft.setPointSize(12);    //字体的缩小
			label[j]->setFont(ft);
			label[j - 1]->setFont(ft);
			j--;
		}
		ft.setPointSize(24);
		label[low]->setFont(ft);
		label[low]->setText(QString::number(temp));
		sleep(1000);    //自定义的延时函数

		ft.setPointSize(12);    //字体的缩小
		label[low]->setFont(ft);
	}
}

//希尔排序
void Sort ::shell_sort(){
    QString tmp;
    int gap;
    for(gap = 3; gap >0; gap--){
        for(int i=0; i<gap; i++){
            for(int j = i+gap; j<b; j=j+gap){
                if(label[j]->text().toInt()<label[j-gap]->text().toInt()){
                    tmp = label[j]->text();
                    int k = j-gap;
                    QFont ft;
                    while(k>=0&&label[k]->text().toInt()>tmp.toInt())
                    {
                        ft.setPointSize(24);
                        label[k+gap]->setFont(ft);
                        label[k]->setFont(ft);
                        label[k+gap]->setText(label[k]->text());
                        sleep(1000);    //自定义的延时函数
                        ft.setPointSize(12);
                        label[k+gap]->setFont(ft);
                        label[k]->setFont(ft);
                        k = k-gap;
                    }
                    ft.setPointSize(24);
                    label[k+gap]->setFont(ft);
                    label[k+gap]->setText(tmp);
                    sleep(1000);    //自定义的延时函数
                    ft.setPointSize(12);
                    label[k+gap]->setFont(ft);
                }
            }
        }
    }
}

//冒泡排序
void Sort ::Bubble_Sort(){
    QString tmp;
    for(int i = 0; i < b - 1; ++i)
       for(int j = 0; j < b - i - 1; ++j)
           if (label[j]->text().toInt() > label[j + 1]->text().toInt())
           {
              QFont ft;
              ft.setPointSize(24);
              label[j]->setFont(ft);
              label[j + 1]->setFont(ft);    //简单的字体放大

              tmp = label[j]->text();
              label[j]->setText(label[j + 1]->text());
              label[j + 1]->setText(tmp);    //交换数值
              sleep(1000);    //自定义的延时函数

              ft.setPointSize(12);    //字体的缩小
              label[j]->setFont(ft);
              label[j + 1]->setFont(ft);
           }
}
//快速排序
int Sort::partition(QLabel *label[50], int low, int high) {
	int part = label[low]->text().toInt();
	QFont ft;
	while (low<high)
	{
		while (low<high&&label[high]->text().toInt()>part) high--;
		
		ft.setPointSize(24);
		label[low]->setFont(ft);
		label[high]->setFont(ft);    //简单的字体放大
		label[low]->setText(label[high]->text());
		sleep(1000);    //自定义的延时函数

		ft.setPointSize(12);    //字体的缩小
		label[high]->setFont(ft);
		label[low]->setFont(ft);
		while (low<high&&label[low]->text().toInt()<part) low++;
		ft.setPointSize(24);
		label[low]->setFont(ft);
		label[high]->setFont(ft);    //简单的字体放大
		label[high]->setText(label[low]->text());
		sleep(1000);    //自定义的延时函数

		ft.setPointSize(12);    //字体的缩小
		label[high]->setFont(ft);
		label[low]->setFont(ft);
	}
	ft.setPointSize(24);
	label[low]->setFont(ft);
	label[low]->setText(QString::number(part));
	sleep(1000);    //自定义的延时函数

	ft.setPointSize(12);    //字体的缩小
	label[low]->setFont(ft);
	return low;
}
void Sort ::quickSort(QLabel *label[50],int low,int high){
	QStack<int> st;
	int k;
	if (low<high)
	{
		st.push(low);
		st.push(high);
		while (!st.empty())
		{
			int j = st.top(); st.pop();
			int i = st.top(); st.pop();

			k = partition(label, i, j);

			if (i<k - 1)
			{
				st.push(i);
				st.push(k - 1);
			}
			if (k + 1<j)
			{
				st.push(k + 1);
				st.push(j);
			}
		}
	}
}

//简单选择排序
void Sort ::selectSort(){
    int i,index,j;
    QString tmp;
    for(i=0; i<b; i++)//执行第i遍扫描操作
    {
        index = i;
        for(j=i+1; j<b; j++)//比较无序序列中的记录
        {
            if(label[index]->text().toInt() > label[j]->text().toInt())//记录序列中最小值的位置
            {
                index = j;
            }
        }
        if(index != i)//如果无序序列中第一个记录不是最小值，则进行交换
        {
            QFont ft;
            ft.setPointSize(24);
            label[index]->setFont(ft);
            label[i]->setFont(ft);
            tmp = label[index]->text();
            label[index]->setText(label[i]->text());
            label[i]->setText(tmp);
            sleep(1000);    //自定义的延时函数
            ft.setPointSize(12);
            label[index]->setFont(ft);
            label[i]->setFont(ft);
        }
    }
}
