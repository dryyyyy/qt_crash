#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QScreen>
#include <QScrollArea>
#include <QStandardPaths>
#include <QLayout>
#include <QScrollArea>
#include <QImageReader>
#include <QMessageBox>
#include <QDebug>
#include <QGraphicsView>
#include "ui_imageviewer.h"

class ImageViewer : public QMainWindow
{
	Q_OBJECT

public:
	ImageViewer(QWidget *parent = 0);
	~ImageViewer();

public slots:
	void on_actionOpen_triggered();
	void on_actionClose_triggered();
	void on_actionMirror_triggered();
	void on_actionNegative_triggered();
	void on_actionTurn_clockwise_triggered();
	void on_actionTurn_counter_clockwise_triggered();
	void wheelEvent(QWheelEvent *event);
	void scaleImage(int factor);
	void on_actionSave_triggered();
	void on_actionSave_as_triggered();
signals:



private:
	Ui::ImageViewer ui;	
};

#endif // IMAGEVIEWER_H


