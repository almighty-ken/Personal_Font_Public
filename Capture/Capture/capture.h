#ifndef CAPTURE_H
#define CAPTURE_H

#include <QtWidgets/QMainWindow>
#include "ui_capture.h"

class Capture : public QMainWindow
{
	Q_OBJECT

public:
	Capture(QWidget *parent = 0);
	//inline void setWindowPositionAndSize(const QRect& fg) {resize(fg.size()); move(fg.topLeft());}
	//inline QRect windowPositionAndSize() const { return QRect(pos(), size()); }
	~Capture();

private:
	Ui::CaptureClass ui;
	

	private slots:
		void slot1();
		void slot2();
		void result_output();
		void again();
		void back();
		void Full_Scope();
		void Change_Thread();
		void make_one();
};

#endif // CAPTURE_H
