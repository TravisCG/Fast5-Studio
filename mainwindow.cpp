#include <QtWidgets>
#include "mainwindow.h"

MainWindow::MainWindow(){

	createActions();
	createMenu();

	setWindowTitle("Fast5 Studio");
	resize(640, 480);
}

void MainWindow::createMenu(){
	fileMenu = menuBar()->addMenu("File");
	fileMenu->addAction(openAction);
	fileMenu->addAction(exitAction);

	statMenu = menuBar()->addMenu("Statistics");
	helpMenu = menuBar()->addMenu("Help");
	helpMenu->addAction(aboutAction);
}

void MainWindow::createActions(){
	openAction = new QAction("Open", this);
	connect(openAction, SIGNAL(triggered()), this, SLOT(openFast5()));

	exitAction = new QAction("Exit", this);
	connect(exitAction, SIGNAL(triggered()), this, SLOT(exit()));

	aboutAction = new QAction("About", this);
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::openFast5(){
	QString filename = QFileDialog::getOpenFileName(this);
	if(!filename.isEmpty()){
		QMessageBox::about(this, "Message", "Load this:" + filename);
	}
}

void MainWindow::about(){
	QMessageBox::about(this, "About Fast5 Studio", "Fast5 Studio is an easy to use application to extract information from MinION Fast5 files");
}

void MainWindow::exit(){
	QApplication::quit();
}
