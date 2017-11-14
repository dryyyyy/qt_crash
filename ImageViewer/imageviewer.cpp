#include "imageviewer.h"
#include <QImageReader>
#include <QMessageBox>


ImageViewer::ImageViewer(QWidget *parent)
	: QMainWindow(parent)
{
	//set max main window size to the current desktop resolution
	QScreen *screen = QGuiApplication::primaryScreen();
	QRect  screenGeometry = screen->geometry();
	int height = screenGeometry.height();
	int width = screenGeometry.width();

	ui.setupUi(this);
	ui.label->setScaledContents(true);
	ui.scrollArea->setMaximumSize(height, width);
	ui.label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	ui.scrollArea->setBackgroundRole(QPalette::Dark);
	ui.scrollArea->setWidget(ui.label);
	this->setCentralWidget(ui.scrollArea);
}

void ImageViewer::on_actionClose_triggered()
{
	close();
}

void ImageViewer::on_actionOpen_triggered() {
	QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),
		QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).first(),
		tr("Images (*.png *.xpm *.jpg);;All ()"));
	if (QString::compare(filename, QString()) != 0)
	{
		QImage image;
		bool valid = image.load(filename);

		if (valid)
		{
			ui.label->setPixmap(QPixmap::fromImage(image));
		}
		else
		{
			QMessageBox::warning(this, QGuiApplication::applicationDisplayName(), tr("cannot open the file"));
		}
		
		
	}
}

void ImageViewer::on_actionMirror_triggered()
{
	const QPixmap *pixmap = ui.label->pixmap();
	if (pixmap)
	{
		QImage image(pixmap->toImage());
		QImage mirrored = image.mirrored();
		ui.label->setPixmap(QPixmap::fromImage(mirrored));
	}
}

void ImageViewer::on_actionNegative_triggered()
{
	const QPixmap *pixmap = ui.label->pixmap();
	if (pixmap)
	{
		QImage image(pixmap->toImage());
		QImage reversed = image.invertPixels(QImage::InvertRgb);
		ui.label->setPixmap(QPixmap::fromImage(reversed));
	}
}


ImageViewer::~ImageViewer()
{

}
