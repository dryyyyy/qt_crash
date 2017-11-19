#include "imageviewer.h"
#include <QtWidgets>
#include <QWidget>


ImageViewer::ImageViewer(QWidget *parent)
	: QMainWindow(parent)
{
	//set max main window size to the current desktop resolution
	QScreen *screen = QGuiApplication::primaryScreen();
	QRect  screenGeometry = screen->geometry();
	int height = screenGeometry.height();
	int width = screenGeometry.width();

	ui.setupUi(this);
	
	ui.label->setScaledContents(false);
	ui.label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	ui.scrollArea->setMaximumSize(height, width);
	//ui.label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	ui.scrollArea->setBackgroundRole(QPalette::Dark);
	ui.scrollArea->setWidget(ui.label);
	ui.scrollArea->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
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
		int h = image.height();
		int w = image.width();
		if (valid)
		{
			ui.label->setPixmap(QPixmap::fromImage(image.scaled(w, h, Qt::KeepAspectRatio)));
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
		image.invertPixels(QImage::InvertRgb);
		ui.label->setPixmap(QPixmap::fromImage(image));
	}
}

void ImageViewer::on_actionTurn_clockwise_triggered()
{
	QTransform turn_right;
	turn_right.rotate(90);
	const QPixmap *pixmap = ui.label->pixmap();
	if (pixmap)
	{
		QImage image(pixmap->toImage());
		image = image.transformed(turn_right);
		ui.label->setPixmap(QPixmap::fromImage(image));
	}
}

void ImageViewer::on_actionTurn_counter_clockwise_triggered()
{
	QTransform turn_left;
	turn_left.rotate(-90);
	const QPixmap *pixmap = ui.label->pixmap();
	if (pixmap)
	{
		QImage image(pixmap->toImage());
		image = image.transformed(turn_left);
		ui.label->setPixmap(QPixmap::fromImage(image));
	}
}

void ImageViewer::wheelEvent(QWheelEvent *event)
{
	//setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	const QPixmap *pixmap = ui.label->pixmap();
	if (pixmap)
	{
		QPoint numDegrees = event->angleDelta() / 8;

		if (!numDegrees.isNull())
		{
			QPoint numSteps = numDegrees / 15;
			//scaleImage(numSteps);
		}
	}
}

void ImageViewer::scaleImage(int factor) {
	
	//m_scaleLabel.setText(QStringLiteral("%1%").arg(m_scaleFactor * 100, 0, 'f', 1));
	QSize size = ui.label->pixmap()->size() * factor;
	ui.label->resize(size);
}

void ImageViewer::on_actionSave_triggered()
{

}

void ImageViewer::on_actionSave_as_triggered()
{
	QString fileName = QFileDialog::getSaveFileName(this, "Save as");
	QFile file(fileName);
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		QMessageBox::warning(this, "..", "File not opened.");
		return;
	}
	const QPixmap *pixmap = ui.label->pixmap();
	if (pixmap)
	{
		QImage image(pixmap->toImage());
		image.save(&file);
	}
}



ImageViewer::~ImageViewer()
{

}
