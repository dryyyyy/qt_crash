#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QScreen>
#include <QScrollArea>
#include <QStandardPaths>
#include <QLayout>
#include <QScrollArea>
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
signals:



private:
	Ui::ImageViewer ui;
};

#endif // IMAGEVIEWER_H
