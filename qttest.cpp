#include "qttest.h"
#include <QStyleOption>
#include <QPainter>
#include <QKeyEvent>
#include <QFileDialog>
#include <QFont>
#include <QFontDatabase>

void QAbstractButton::paintEvent(QPaintEvent* e)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
	
	//QWidget::paintEvent(e);
}
void qttest::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_R)
	{
		resetbtn();

	}
	if (event->key() == Qt::Key_Escape)
	{
		QApplication* app;
		app->exit(0);
	}
}
void qttest::on_action_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this, u8"打开", " ", u8"文本文件(*.txt);;全部文件(*.*)");
	if (!fileName.isNull())
	{
		ifstream file(fileName.toStdString());
		readfile(file);
		solution();
	}
}
void qttest::on_action_2_triggered()
{
	QString fileName = QFileDialog::getSaveFileName(this, u8"保存", " ", u8"文本文件(*.txt);;全部文件(*.*)");
	QFile file(fileName);
	file.open(QIODevice::WriteOnly);
	ifstream sourcefile("temp.txt");
	string tempstr;
	QTextStream out(&file);//文件输入流
	QString qtempstr;
	while (!sourcefile.eof())
	{
		getline(sourcefile, tempstr);
		tempstr += '\n';
		qtempstr = QString::fromStdString(tempstr);
		out << qtempstr;
	}
}
void qttest::resetbtn()
{
	if (ui.checkBox->checkState() == Qt::Unchecked)
		ui.checkBox->setCheckState(Qt::Checked);
	if (ui.checkBox_2->checkState() == Qt::Unchecked)
		ui.checkBox_2->setCheckState(Qt::Checked);
	if (ui.checkBox_3->checkState() == Qt::Unchecked)
		ui.checkBox_3->setCheckState(Qt::Checked);
	if (ui.checkBox_4->checkState() == Qt::Unchecked)
		ui.checkBox_4->setCheckState(Qt::Checked);
	if (ui.checkBox_5->checkState() == Qt::Unchecked)
		ui.checkBox_5->setCheckState(Qt::Checked);
	if (ui.checkBox_6->checkState() == Qt::Unchecked)
		ui.checkBox_6->setCheckState(Qt::Checked);
	if (ui.checkBox_7->checkState() == Qt::Unchecked)
		ui.checkBox_7->setCheckState(Qt::Checked);
	if (ui.checkBox_8->checkState() == Qt::Unchecked)
		ui.checkBox_8->setCheckState(Qt::Checked);
	if (ui.checkBox_9->checkState() == Qt::Unchecked)
		ui.checkBox_9->setCheckState(Qt::Checked);
	if (ui.checkBox_10->checkState() == Qt::Unchecked)
		ui.checkBox_10->setCheckState(Qt::Checked);
	if (ui.checkBox_11->checkState() == Qt::Unchecked)
		ui.checkBox_11->setCheckState(Qt::Checked);
	if (ui.checkBox_12->checkState() == Qt::Unchecked)
		ui.checkBox_12->setCheckState(Qt::Checked);
	if (ui.checkBox_13->checkState() == Qt::Unchecked)
		ui.checkBox_13->setCheckState(Qt::Checked);
	if (ui.checkBox_14->checkState() == Qt::Unchecked)
		ui.checkBox_14->setCheckState(Qt::Checked);
	ui.frame->setStyleSheet("QFrame#frame{border-image:url(:/qttest/pipe.png)}");
	ui.frame_2->setStyleSheet("QFrame#frame_2{border-image:url(:/qttest/pipe2.png)}");
	ui.frame_3->setStyleSheet("QFrame#frame_3{border-image:url(:/qttest/pipe3.png)}");
	ui.frame_4->setStyleSheet("QFrame#frame_4{border-image:url(:/qttest/pipe4.png)}");
	ui.frame_5->setStyleSheet("QFrame#frame_5{border-image:url(:/qttest/pipe5.png)}");
	ui.frame_6->setStyleSheet("QFrame#frame_6{border-image:url(:/qttest/pipe6.png)}");
	ui.frame_7->setStyleSheet("QFrame#frame_7{border-image:url(:/qttest/pipe7.png)}");
	ui.frame_8->setStyleSheet("QFrame#frame_8{border-image:url(:/qttest/pipe8.png)}");
	ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9.png)}");
	ui.frame_10->setStyleSheet("QFrame#frame_10{border-image:url(:/qttest/pipe10.png)}");
	ui.frame_11->setStyleSheet("QFrame#frame_11{border-image:url(:/qttest/pipe11.png)}");
	ui.frame_12->setStyleSheet("QFrame#frame_12{border-image:url(:/qttest/pipe12.png)}");
	ui.frame_13->setStyleSheet("QFrame#frame_13{border-image:url(:/qttest/pipe13.png)}");


}
void qttest::quitbtn()
{
	QApplication* app;
	app->exit(0);

}
void qttest::readfile(ifstream& file)
{
	Graph = new graph<int>(file);
	int edgenum = Graph->getedgenum();
	for (int i = 0; i < edgenum; ++i)
	{
		int a = Graph->Pathdata[i].first;
		int b = Graph->Pathdata[i].second;
		int w = Graph->Pathdata[i].weight;
		QString weight = QString::number(w);
		if ((a == 0 && b == 1) || (a == 1 && b == 0))
			ui.lineEdit->setText(weight);
		if ((a == 0 && b == 3) || (a == 3 && b == 0))
			ui.lineEdit_19->setText(weight);
		if ((a == 3 && b == 4) || (a == 4 && b == 3))
			ui.lineEdit_18->setText(weight);
		if ((a == 3 && b == 12) || (a == 12 && b == 3))
			ui.lineEdit_4->setText(weight);
		if ((a == 4 && b == 12) || (a == 12 && b == 4))
			ui.lineEdit_5->setText(weight);
		if ((a == 4 && b == 5) || (a == 5 && b == 4))
			ui.lineEdit_16->setText(weight);
		if ((a == 12 && b == 1) || (a == 1 && b == 12))
			ui.lineEdit_3->setText(weight);
		if ((a == 8 && b == 1) || (a == 1 && b == 8))
			ui.lineEdit_2->setText(weight);
		if ((a == 12 && b == 8) || (a == 8 && b == 12))
			ui.lineEdit_6->setText(weight);
		if ((a == 12 && b == 11) || (a == 11 && b == 12))
			ui.lineEdit_7->setText(weight);
		if ((a == 11 && b == 8) || (a == 8 && b == 11))
			ui.lineEdit_9->setText(weight);
		if ((a == 11 && b == 5) || (a == 5 && b == 11))
			ui.lineEdit_8->setText(weight);
		if ((a == 8 && b == 6) || (a == 6 && b == 8))
			ui.lineEdit_10->setText(weight);
		if ((a == 5 && b == 7) || (a == 7 && b == 5))
			ui.lineEdit_17->setText(weight);
		if ((a == 8 && b == 10) || (a == 10 && b == 8))
			ui.lineEdit_11->setText(weight);
		if ((a == 13 && b == 6) || (a == 6 && b == 13))
			ui.lineEdit_12->setText(weight);
		if ((a == 13 && b == 2) || (a == 2 && b == 13))
			ui.lineEdit_13->setText(weight);
		if ((a == 10 && b == 9) || (a == 9 && b == 10))
			ui.lineEdit_20->setText(weight);
		if ((a == 7 && b == 2) || (a == 2 && b == 7))
			ui.lineEdit_15->setText(weight);
		if ((a == 2 && b == 9) || (a == 9 && b == 2))
			ui.lineEdit_14->setText(weight);

	}
	housenum = Graph->getvexnum();
	//Path = Graph->prim(0);
}


void qttest::solution()
{
	ofstream temp("temp.txt");
	int realhousenum = 0;
	if (ui.checkBox->checkState() == Qt::Checked)
	{
		realhousenum++;
		temp << "0 ";
	}
	if (ui.checkBox_2->checkState() == Qt::Checked)
	{
		realhousenum++;
		temp << "1 ";
	}
	if (ui.checkBox_3->checkState() == Qt::Checked)
	{
		realhousenum++;
		temp << "2 ";
	}
	if (ui.checkBox_4->checkState() == Qt::Checked)
	{
		realhousenum++;
		temp << "3 ";
	}
	if (ui.checkBox_5->checkState() == Qt::Checked)
	{
		realhousenum++;
		temp << "4 ";
	}
	if (ui.checkBox_6->checkState() == Qt::Checked)
	{
		realhousenum++;
		temp << "5 ";
	}
	if (ui.checkBox_7->checkState() == Qt::Checked)
	{
		realhousenum++;
		temp << "6 ";
	}
	if (ui.checkBox_8->checkState() == Qt::Checked)
	{
		realhousenum++;
		temp << "7 ";
	}
	if (ui.checkBox_9->checkState() == Qt::Checked)
	{
		realhousenum++;
		temp << "8 ";
	}
	if (ui.checkBox_10->checkState() == Qt::Checked)
	{
		realhousenum++;
		temp << "9 ";
	}
	if (ui.checkBox_11->checkState() == Qt::Checked)
	{
		realhousenum++;
		temp << "10 ";
	}
	if (ui.checkBox_12->checkState() == Qt::Checked)
	{
		realhousenum++;
		temp << "11 ";
	}
	if (ui.checkBox_13->checkState() == Qt::Checked)
	{
		realhousenum++;
		temp << "12 ";
	}
	if (ui.checkBox_14->checkState() == Qt::Checked)
	{
		realhousenum++;
		temp << "13 ";
	}
	temp << endl;
	stringstream ss;
	int pathnum = 0;
	temp << realhousenum << ' ';
	if (ui.checkBox->checkState() == Qt::Checked && ui.checkBox_2->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "0 1 " << weight << endl;
	}
	if (ui.checkBox->checkState() == Qt::Checked && ui.checkBox_4->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_19->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "0 3 " << weight << endl;
	}
	if (ui.checkBox_4->checkState() == Qt::Checked && ui.checkBox_5->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_18->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "3 4 " << weight << endl;
	}
	if (ui.checkBox_4->checkState() == Qt::Checked && ui.checkBox_13->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_4->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "3 12 " << weight << endl;
	}
	if (ui.checkBox_5->checkState() == Qt::Checked && ui.checkBox_6->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_16->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "4 5 " << weight << endl;
	}
	if (ui.checkBox_5->checkState() == Qt::Checked && ui.checkBox_13->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_5->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "4 12 " << weight << endl;
	}
	if (ui.checkBox_2->checkState() == Qt::Checked && ui.checkBox_13->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_3->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "1 12 " << weight << endl;
	}
	if (ui.checkBox_13->checkState() == Qt::Checked && ui.checkBox_12->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_7->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "12 11 " << weight << endl;
	}
	if (ui.checkBox_12->checkState() == Qt::Checked && ui.checkBox_6->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_8->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "11 5 " << weight << endl;
	}
	if (ui.checkBox_2->checkState() == Qt::Checked && ui.checkBox_9->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_2->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "1 8 " << weight << endl;
	}
	if (ui.checkBox_13->checkState() == Qt::Checked && ui.checkBox_9->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_6->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "12 8 " << weight << endl;
	}
	if (ui.checkBox_12->checkState() == Qt::Checked && ui.checkBox_9->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_9->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "11 8 " << weight << endl;
	}
	if (ui.checkBox_9->checkState() == Qt::Checked && ui.checkBox_11->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_11->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "8 10 " << weight << endl;
	}
	if (ui.checkBox_14->checkState() == Qt::Checked && ui.checkBox_7->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_12->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "13 6 " << weight << endl;
	}
	if (ui.checkBox_14->checkState() == Qt::Checked && ui.checkBox_3->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_13->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "13 2 " << weight << endl;
	}
	if (ui.checkBox_3->checkState() == Qt::Checked && ui.checkBox_10->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_14->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "2 9 " << weight << endl;
	}
	if (ui.checkBox_9->checkState() == Qt::Checked && ui.checkBox_7->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_10->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "8 6 " << weight << endl;
	}
	if (ui.checkBox_6->checkState() == Qt::Checked && ui.checkBox_8->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_17->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "5 7 " << weight << endl;
	}
	if (ui.checkBox_11->checkState() == Qt::Checked && ui.checkBox_10->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_20->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "10 9 " << weight << endl;
	}
	if (ui.checkBox_3->checkState() == Qt::Checked && ui.checkBox_8->checkState() == Qt::Checked)
	{
		QString w = ui.lineEdit_15->text();
		if (w == "")
			w = "-1";
		int weight = w.toInt();
		pathnum++;
		ss << "2 7 " << weight << endl;
	}
	temp << pathnum << endl;
	string pathstring=ss.str();
	temp << pathstring;
	temp.close();
	ifstream file("temp.txt");
	readfile(file);
	bool connected = Graph->dfstraverse();
	if (!connected)
	{
		
		QMessageBox::critical(this, u8"错误", u8"此图不连通\n请重新选择",
			QMessageBox::Close, QMessageBox::Close);
		ui.frame->setStyleSheet("QFrame#frame{border-image:url(:/qttest/pipe.png)}");
		ui.frame_2->setStyleSheet("QFrame#frame_2{border-image:url(:/qttest/pipe2.png)}");
		ui.frame_3->setStyleSheet("QFrame#frame_3{border-image:url(:/qttest/pipe3.png)}");
		ui.frame_4->setStyleSheet("QFrame#frame_4{border-image:url(:/qttest/pipe4.png)}");
		ui.frame_5->setStyleSheet("QFrame#frame_5{border-image:url(:/qttest/pipe5.png)}");
		ui.frame_6->setStyleSheet("QFrame#frame_6{border-image:url(:/qttest/pipe6.png)}");
		ui.frame_7->setStyleSheet("QFrame#frame_7{border-image:url(:/qttest/pipe7.png)}");
		ui.frame_8->setStyleSheet("QFrame#frame_8{border-image:url(:/qttest/pipe8.png)}");
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9.png)}");
		ui.frame_10->setStyleSheet("QFrame#frame_10{border-image:url(:/qttest/pipe10.png)}");
		ui.frame_11->setStyleSheet("QFrame#frame_11{border-image:url(:/qttest/pipe11.png)}");
		ui.frame_12->setStyleSheet("QFrame#frame_12{border-image:url(:/qttest/pipe12.png)}");
		ui.frame_13->setStyleSheet("QFrame#frame_13{border-image:url(:/qttest/pipe13.png)}");

	}
	else
	{
		bool houseflag = true;
		if (ui.checkBox->checkState() == Qt::Checked && houseflag)
		{
			Path = Graph->prim(0);
			houseflag = false;
		}
		if (ui.checkBox_2->checkState() == Qt::Checked && houseflag)
		{
			Path = Graph->prim(1);
			houseflag = false;
		}
		if (ui.checkBox_3->checkState() == Qt::Checked && houseflag)
		{
			Path = Graph->prim(2);
			houseflag = false;
		}
		if (ui.checkBox_4->checkState() == Qt::Checked && houseflag)
		{
			Path = Graph->prim(3);
			houseflag = false;
		}
		if (ui.checkBox_5->checkState() == Qt::Checked && houseflag)
		{
			Path = Graph->prim(4);
			houseflag = false;
		}
		if (ui.checkBox_6->checkState() == Qt::Checked && houseflag)
		{
			Path = Graph->prim(5);
			houseflag = false;
		}
		if (ui.checkBox_7->checkState() == Qt::Checked && houseflag)
		{
			Path = Graph->prim(6);
			houseflag = false;
		}
		if (ui.checkBox_8->checkState() == Qt::Checked && houseflag)
		{
			Path = Graph->prim(7);
			houseflag = false;
		}
		if (ui.checkBox_9->checkState() == Qt::Checked && houseflag)
		{
			Path = Graph->prim(8);
			houseflag = false;
		}
		if (ui.checkBox_10->checkState() == Qt::Checked && houseflag)
		{
			Path = Graph->prim(9);
			houseflag = false;
		}
		if (ui.checkBox_11->checkState() == Qt::Checked && houseflag)
		{
			Path = Graph->prim(10);
			houseflag = false;
		}
		if (ui.checkBox_12->checkState() == Qt::Checked && houseflag)
		{
			Path = Graph->prim(11);
			houseflag = false;
		}
		if (ui.checkBox_13->checkState() == Qt::Checked && houseflag)
		{
			Path = Graph->prim(12);
			houseflag = false;
		}
		if (ui.checkBox_14->checkState() == Qt::Checked && houseflag)
		{
			Path = Graph->prim(13);
			houseflag = false;
		}
		if (!houseflag)
		{
			ui.frame->setStyleSheet("QFrame#frame{border-image:url(:/qttest/pipe.png)}");
			ui.frame_2->setStyleSheet("QFrame#frame_2{border-image:url(:/qttest/pipe2.png)}");
			ui.frame_3->setStyleSheet("QFrame#frame_3{border-image:url(:/qttest/pipe3.png)}");
			ui.frame_4->setStyleSheet("QFrame#frame_4{border-image:url(:/qttest/pipe4.png)}");
			ui.frame_5->setStyleSheet("QFrame#frame_5{border-image:url(:/qttest/pipe5.png)}");
			ui.frame_6->setStyleSheet("QFrame#frame_6{border-image:url(:/qttest/pipe6.png)}");
			ui.frame_7->setStyleSheet("QFrame#frame_7{border-image:url(:/qttest/pipe7.png)}");
			ui.frame_8->setStyleSheet("QFrame#frame_8{border-image:url(:/qttest/pipe8.png)}");
			ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9.png)}");
			ui.frame_10->setStyleSheet("QFrame#frame_10{border-image:url(:/qttest/pipe10.png)}");
			ui.frame_11->setStyleSheet("QFrame#frame_11{border-image:url(:/qttest/pipe11.png)}");
			ui.frame_12->setStyleSheet("QFrame#frame_12{border-image:url(:/qttest/pipe12.png)}");
			ui.frame_13->setStyleSheet("QFrame#frame_13{border-image:url(:/qttest/pipe13.png)}");

			update();
		}
	}
}

void qttest::update()
{
	bool pipe6flag1 = false, pipe6flag2 = false, pipe6flag3 = false;
	bool pipe8flag1 = false, pipe8flag2 = false, pipe8flag3 = false;
	bool pipe9flag1 = false, pipe9flag2 = false, pipe9flag3 = false, pipe9flag4 = false;

	for (int i = 0; i < housenum; ++i)
	{
		int a = Path[i].first, b = Path[i].second;
		if ((a == 0 && b == 1) || (a == 1 && b == 0))
		{
			ui.frame->setStyleSheet("QFrame#frame{border-image:url(:/qttest/piper.png)}");
		}
		if ((a == 1 && b == 12) || (a == 12 && b == 1))
		{
			ui.frame_5->setStyleSheet("QFrame#frame_5{border-image:url(:/qttest/pipe5r.png)}");
		}
		if ((a == 0 && b == 3) || (a == 3 && b == 0))
		{
			ui.frame_11->setStyleSheet("QFrame#frame_11{border-image:url(:/qttest/pipe11r.png)}");
		}
		if ((a == 3 && b == 4) || (a == 4 && b == 3))
		{
			ui.frame_12->setStyleSheet("QFrame#frame_12{border-image:url(:/qttest/pipe12r.png)}");
		}
		if ((a == 3 && b == 12) || (a == 12 && b == 3))
		{
			ui.frame_3->setStyleSheet("QFrame#frame_3{border-image:url(:/qttest/pipe3r.png)}");
		}
		if ((a == 1 && b == 8) || (a == 8 && b == 1))
		{
			ui.frame_2->setStyleSheet("QFrame#frame_2{border-image:url(:/qttest/pipe2r.png)}");
		}
		if ((a == 8 && b == 12) || (a == 12 && b == 8))
		{
			ui.frame_4->setStyleSheet("QFrame#frame_4{border-image:url(:/qttest/pipe4r.png)}");
		}
		if ((a == 11 && b == 8) || (a == 8 && b == 11))
		{
			ui.frame_10->setStyleSheet("QFrame#frame_10{border-image:url(:/qttest/pipe10r.png)}");
		}
		if ((a == 13 && b == 2) || (a == 2 && b == 13))
		{
			ui.frame_7->setStyleSheet("QFrame#frame_7{border-image:url(:/qttest/pipe7r.png)}");
		}
		if ((a == 5 && b == 7) || (a == 7 && b == 5))
		{
			ui.frame_13->setStyleSheet("QFrame#frame_13{border-image:url(:/qttest/pipe13r.png)}");
		}
		//分离
		if ((a == 6 && b == 8) || (a == 8 && b == 6))
			pipe6flag1 = true;
		if ((a == 6 && b == 13) || (a == 13 && b == 6))
			pipe6flag2 = true;
		if ((a == 10 && b == 8) || (a == 8 && b == 10))
			pipe6flag3 = true;
		if ((a == 2 && b == 7) || (a == 7 && b == 2))
			pipe8flag1 = true;
		if ((a == 2 && b == 9) || (a == 9 && b == 2))
			pipe8flag3 = true;
		if ((a == 10 && b == 9) || (a == 9 && b == 10))
			pipe8flag2 = true;
		if ((a == 4 && b == 5) || (a == 5 && b == 4))
			pipe9flag1 = true;
		if ((a == 4 && b == 12) || (a == 12 && b == 4))
			pipe9flag2 = true;
		if ((a == 12 && b == 11) || (a == 11 && b == 12))
			pipe9flag3 = true;
		if ((a == 11 && b == 5) || (a == 5 && b == 11))
			pipe9flag4 = true;

		//if (((a == 4 && b == 12) || (a == 12 && b == 4)) || ((a == 11 && b == 12) || (a == 12 && b == 11)) || ((a == 5 && b == 11) || (a == 11 && b == 5)) || ((a == 4 && b == 5) || (a == 5 && b == 4)))
		//{
		//	bool flag = true;
		//	if (flag && ((a == 4 && b == 12) || (a == 12 && b == 4)) && !((a == 11 && b == 12) || (a == 12 && b == 11)) && !((a == 5 && b == 11) || (a == 11 && b == 5)) && !((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r1.png)}");
		//		flag = false;
		//	}
		//	if (flag && !((a == 4 && b == 12) || (a == 12 && b == 4)) && ((a == 11 && b == 12) || (a == 12 && b == 11)) && !((a == 5 && b == 11) || (a == 11 && b == 5)) && !((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r2.png)}");
		//		flag = false;
		//	}
		//	if (flag && !((a == 4 && b == 12) || (a == 12 && b == 4)) && !((a == 11 && b == 12) || (a == 12 && b == 11)) && ((a == 5 && b == 11) || (a == 11 && b == 5)) && !((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r3.png)}");
		//		flag = false;
		//	}
		//	if (flag && !((a == 4 && b == 12) || (a == 12 && b == 4)) && !((a == 11 && b == 12) || (a == 12 && b == 11)) && !((a == 5 && b == 11) || (a == 11 && b == 5)) && ((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r4.png)}");
		//		flag = false;
		//	}
		//	if (flag && ((a == 4 && b == 12) || (a == 12 && b == 4)) && ((a == 11 && b == 12) || (a == 12 && b == 11)) && !((a == 5 && b == 11) || (a == 11 && b == 5)) && !((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r8.png)}");
		//		flag = false;
		//	}
		//	if (flag && ((a == 4 && b == 12) || (a == 12 && b == 4)) && !((a == 11 && b == 12) || (a == 12 && b == 11)) && ((a == 5 && b == 11) || (a == 11 && b == 5)) && !((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r9.png)}");
		//		flag = false;
		//	}
		//	if (flag && ((a == 4 && b == 12) || (a == 12 && b == 4)) && !((a == 11 && b == 12) || (a == 12 && b == 11)) && !((a == 5 && b == 11) || (a == 11 && b == 5)) && ((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r5.png)}");
		//		flag = false;
		//	}
		//	if (flag && !((a == 4 && b == 12) || (a == 12 && b == 4)) && ((a == 11 && b == 12) || (a == 12 && b == 11)) && ((a == 5 && b == 11) || (a == 11 && b == 5)) && !((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r10.png)}");
		//		flag = false;
		//	}
		//	if (flag && !((a == 4 && b == 12) || (a == 12 && b == 4)) && ((a == 11 && b == 12) || (a == 12 && b == 11)) && !((a == 5 && b == 11) || (a == 11 && b == 5)) && ((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{ 
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r6.png)}");
		//		flag = false;
		//	}
		//	if (flag && !((a == 4 && b == 12) || (a == 12 && b == 4)) && !((a == 11 && b == 12) || (a == 12 && b == 11)) && ((a == 5 && b == 11) || (a == 11 && b == 5)) && ((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{ 
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r7.png)}");
		//		flag = false;
		//	}
		//	if (flag && !((a == 4 && b == 12) || (a == 12 && b == 4)) && ((a == 11 && b == 12) || (a == 12 && b == 11)) && ((a == 5 && b == 11) || (a == 11 && b == 5)) && ((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{ 
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r12.png)}");
		//		flag = false;
		//	}
		//	if (flag && ((a == 4 && b == 12) || (a == 12 && b == 4)) && !((a == 11 && b == 12) || (a == 12 && b == 11)) && ((a == 5 && b == 11) || (a == 11 && b == 5)) && ((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{ 
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r13.png)}");
		//		flag = false;
		//	}
		//	if (flag && ((a == 4 && b == 12) || (a == 12 && b == 4)) && ((a == 11 && b == 12) || (a == 12 && b == 11)) && !((a == 5 && b == 11) || (a == 11 && b == 5)) && ((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{ 
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r14.png)}");
		//		flag = false;
		//	}
		//	if (flag && ((a == 4 && b == 12) || (a == 12 && b == 4)) && ((a == 11 && b == 12) || (a == 12 && b == 11)) && ((a == 5 && b == 11) || (a == 11 && b == 5)) && !((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{ 
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r11.png)}");
		//		flag = false;
		//	}
		//	if (flag && ((a == 4 && b == 12) || (a == 12 && b == 4)) && ((a == 11 && b == 12) || (a == 12 && b == 11)) && ((a == 5 && b == 11) || (a == 11 && b == 5)) && ((a == 4 && b == 5) || (a == 5 && b == 4)))
		//	{ 
		//		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r15.png)}");
		//		flag = false;
		//	}

		//}


	}
	//特殊管道
	if (pipe6flag1 && !pipe6flag2 && !pipe6flag3)
		ui.frame_6->setStyleSheet("QFrame#frame_6{border-image:url(:/qttest/pipe6r1.png)}");
	if (!pipe6flag1 && pipe6flag2 && !pipe6flag3)
		ui.frame_6->setStyleSheet("QFrame#frame_6{border-image:url(:/qttest/pipe6r3.png)}");
	if (!pipe6flag1 && !pipe6flag2 && pipe6flag3)
		ui.frame_6->setStyleSheet("QFrame#frame_6{border-image:url(:/qttest/pipe6r2.png)}");
	if (pipe6flag1 && pipe6flag2 && !pipe6flag3)
		ui.frame_6->setStyleSheet("QFrame#frame_6{border-image:url(:/qttest/pipe6r6.png)}");
	if (pipe6flag1 && !pipe6flag2 && pipe6flag3)
		ui.frame_6->setStyleSheet("QFrame#frame_6{border-image:url(:/qttest/pipe6r5.png)}");
	if (!pipe6flag1 && pipe6flag2 && pipe6flag3)
		ui.frame_6->setStyleSheet("QFrame#frame_6{border-image:url(:/qttest/pipe6r4.png)}");
	if (pipe6flag1 && pipe6flag2 && pipe6flag3)
		ui.frame_6->setStyleSheet("QFrame#frame_6{border-image:url(:/qttest/pipe6r7.png)}");


	if (pipe8flag1 && !pipe8flag2 && !pipe8flag3)
		ui.frame_8->setStyleSheet("QFrame#frame_8{border-image:url(:/qttest/pipe8r2.png)}");
	if (!pipe8flag1 && pipe8flag2 && !pipe8flag3)
		ui.frame_8->setStyleSheet("QFrame#frame_8{border-image:url(:/qttest/pipe8r3.png)}");
	if (!pipe8flag1 && !pipe8flag2 && pipe8flag3)
		ui.frame_8->setStyleSheet("QFrame#frame_8{border-image:url(:/qttest/pipe8r1.png)}");
	if (pipe8flag1 && pipe8flag2 && !pipe8flag3)
		ui.frame_8->setStyleSheet("QFrame#frame_8{border-image:url(:/qttest/pipe8r4.png)}");
	if (pipe8flag1 && !pipe8flag2 && pipe8flag3)
		ui.frame_8->setStyleSheet("QFrame#frame_8{border-image:url(:/qttest/pipe8r5.png)}");
	if (!pipe8flag1 && pipe8flag2 && pipe8flag3)
		ui.frame_8->setStyleSheet("QFrame#frame_8{border-image:url(:/qttest/pipe8r6.png)}");
	if (pipe8flag1 && pipe8flag2 && pipe8flag3)
		ui.frame_8->setStyleSheet("QFrame#frame_8{border-image:url(:/qttest/pipe8r7.png)}");

	
	if (pipe9flag1 && !pipe9flag2 && !pipe9flag3 && !pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r4.png)}");
	if (!pipe9flag1 && pipe9flag2 && !pipe9flag3 && !pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r1.png)}");
	if (!pipe9flag1 && !pipe9flag2 && pipe9flag3 && !pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r2.png)}");
	if (!pipe9flag1 && !pipe9flag2 && !pipe9flag3 && pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r3.png)}");
	if (pipe9flag1 && pipe9flag2 && !pipe9flag3 && !pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r5.png)}");
	if (pipe9flag1 && !pipe9flag2 && pipe9flag3 && !pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r6.png)}");
	if (pipe9flag1 && !pipe9flag2 && !pipe9flag3 && pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r7.png)}");
	if (!pipe9flag1 && pipe9flag2 && pipe9flag3 && !pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r8.png)}");
	if (!pipe9flag1 && pipe9flag2 && !pipe9flag3 && pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r9.png)}");
	if (!pipe9flag1 && !pipe9flag2 && pipe9flag3 && pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r10.png)}");
	if (!pipe9flag1 && pipe9flag2 && pipe9flag3 && pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r11.png)}");
	if (pipe9flag1 && !pipe9flag2 && pipe9flag3 && pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r12.png)}");
	if (pipe9flag1 && pipe9flag2 && !pipe9flag3 && pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r13.png)}");
	if (pipe9flag1 && pipe9flag2 && pipe9flag3 && !pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r14.png)}");
	if (pipe9flag1 && pipe9flag2 && pipe9flag3 && pipe9flag4)
		ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9r15.png)}");


}

qttest::qttest(QWidget* parent)
	: QMainWindow(parent)
{
	QWidget* m_pWidget = new QWidget(this);
	m_pWidget->setGeometry(0, 0, 1067, 719);
	QPalette pal(m_pWidget->palette());

	pal.setColor(QPalette::Background, Qt::white); //设置背景白色
	m_pWidget->setAutoFillBackground(true);
	m_pWidget->setPalette(pal);
	m_pWidget->show();

	ui.setupUi(this);
	ui.checkBox->setStyleSheet("QCheckBox::indicator:unchecked {image: url(:/qttest/house.png);}\
			QCheckBox::indicator:checked {image: url(:/qttest/house3.png);}\
			QCheckBox::indicator{width:50px;height:50px;}");
	ui.checkBox_2->setStyleSheet("QCheckBox::indicator:unchecked {image: url(:/qttest/house.png);}\
			QCheckBox::indicator:checked {image: url(:/qttest/house3.png);}\
			QCheckBox::indicator{width:50px;height:50px;}");
	ui.checkBox_3->setStyleSheet("QCheckBox::indicator:unchecked {image: url(:/qttest/house.png);}\
			QCheckBox::indicator:checked {image: url(:/qttest/house3.png);}\
			QCheckBox::indicator{width:50px;height:50px;}");
	ui.checkBox_4->setStyleSheet("QCheckBox::indicator:unchecked {image: url(:/qttest/house.png);}\
			QCheckBox::indicator:checked {image: url(:/qttest/house3.png);}\
			QCheckBox::indicator{width:50px;height:50px;}");
	ui.checkBox_5->setStyleSheet("QCheckBox::indicator:unchecked {image: url(:/qttest/house.png);}\
			QCheckBox::indicator:checked {image: url(:/qttest/house3.png);}\
			QCheckBox::indicator{width:50px;height:50px;}");
	ui.checkBox_6->setStyleSheet("QCheckBox::indicator:unchecked {image: url(:/qttest/house.png);}\
			QCheckBox::indicator:checked {image: url(:/qttest/house3.png);}\
			QCheckBox::indicator{width:50px;height:50px;}");
	ui.checkBox_7->setStyleSheet("QCheckBox::indicator:unchecked {image: url(:/qttest/house.png);}\
			QCheckBox::indicator:checked {image: url(:/qttest/house3.png);}\
			QCheckBox::indicator{width:50px;height:50px;}");
	ui.checkBox_8->setStyleSheet("QCheckBox::indicator:unchecked {image: url(:/qttest/house.png);}\
			QCheckBox::indicator:checked {image: url(:/qttest/house3.png);}\
			QCheckBox::indicator{width:50px;height:50px;}");
	ui.checkBox_9->setStyleSheet("QCheckBox::indicator:unchecked {image: url(:/qttest/house.png);}\
			QCheckBox::indicator:checked {image: url(:/qttest/house3.png);}\
			QCheckBox::indicator{width:50px;height:50px;}");
	ui.checkBox_10->setStyleSheet("QCheckBox::indicator:unchecked {image: url(:/qttest/house.png);}\
			QCheckBox::indicator:checked {image: url(:/qttest/house3.png);}\
			QCheckBox::indicator{width:50px;height:50px;}");
	ui.checkBox_11->setStyleSheet("QCheckBox::indicator:unchecked {image: url(:/qttest/house.png);}\
			QCheckBox::indicator:checked {image: url(:/qttest/house3.png);}\
			QCheckBox::indicator{width:50px;height:50px;}");
	ui.checkBox_12->setStyleSheet("QCheckBox::indicator:unchecked {image: url(:/qttest/house.png);}\
			QCheckBox::indicator:checked {image: url(:/qttest/house3.png);}\
			QCheckBox::indicator{width:50px;height:50px;}");
	ui.checkBox_13->setStyleSheet("QCheckBox::indicator:unchecked {image: url(:/qttest/house.png);}\
			QCheckBox::indicator:checked {image: url(:/qttest/house3.png);}\
			QCheckBox::indicator{width:50px;height:50px;}");
	ui.checkBox_14->setStyleSheet("QCheckBox::indicator:unchecked {image: url(:/qttest/house.png);}\
			QCheckBox::indicator:checked {image: url(:/qttest/house3.png);}\
			QCheckBox::indicator{width:50px;height:50px;}");
	ui.frame->setStyleSheet("QFrame#frame{border-image:url(:/qttest/pipe.png)}");
	ui.frame_2->setStyleSheet("QFrame#frame_2{border-image:url(:/qttest/pipe2.png)}");
	ui.frame_3->setStyleSheet("QFrame#frame_3{border-image:url(:/qttest/pipe3.png)}");
	ui.frame_4->setStyleSheet("QFrame#frame_4{border-image:url(:/qttest/pipe4.png)}");
	ui.frame_5->setStyleSheet("QFrame#frame_5{border-image:url(:/qttest/pipe5.png)}");
	ui.frame_6->setStyleSheet("QFrame#frame_6{border-image:url(:/qttest/pipe6.png)}");
	ui.frame_7->setStyleSheet("QFrame#frame_7{border-image:url(:/qttest/pipe7.png)}");
	ui.frame_8->setStyleSheet("QFrame#frame_8{border-image:url(:/qttest/pipe8.png)}");
	ui.frame_9->setStyleSheet("QFrame#frame_9{border-image:url(:/qttest/pipe9.png)}");
	ui.frame_10->setStyleSheet("QFrame#frame_10{border-image:url(:/qttest/pipe10.png)}");
	ui.frame_11->setStyleSheet("QFrame#frame_11{border-image:url(:/qttest/pipe11.png)}");
	ui.frame_12->setStyleSheet("QFrame#frame_12{border-image:url(:/qttest/pipe12.png)}");
	ui.frame_13->setStyleSheet("QFrame#frame_13{border-image:url(:/qttest/pipe13.png)}");
	setWindowIcon(QIcon(":/qttest/yancongicon.ico"));
	Graph = NULL;
	//int FontId = QFontDatabase::addApplicationFont("jinhei.ttf"); 
	//QString FontFile = QFontDatabase::applicationFontFamilies(FontId).at(0); 
	//QFont Font = QFont(FontFile, 16);
	//ui.pushButton->setFont(Font);
	//ui.pushButton_2->setFont(Font);
	//ui.pushButton_3->setFont(Font);
	//FontId = QFontDatabase::addApplicationFont("xingshu.ttf");
	//FontFile = QFontDatabase::applicationFontFamilies(FontId).at(0);
	//Font = QFont(FontFile, 30);
	//ui.label->setFont(Font);
}
