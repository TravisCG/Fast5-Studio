#include <QtWidgets>
#include "mainwindow.h"

MainWindow::MainWindow(){

	createActions();
	createMenu();

	setWindowTitle("Fast5 Studio");
	resize(640, 480);

	fast5files = new Fast5Files();
}

void MainWindow::createMenu(){
	fileMenu = menuBar()->addMenu("File");
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveFastaAction);
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

	saveFastaAction = new QAction("Export Fasta", this);
	connect(saveFastaAction, SIGNAL(triggered()), this, SLOT(saveFasta()));

	aboutAction = new QAction("About", this);
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::openFast5(){
	QString dir = QFileDialog::getExistingDirectory(this, "Open directory", "", QFileDialog::ShowDirsOnly);
	if(!dir.isEmpty()){
		//TODO Maybe a nice progress bar?
		fast5files->readDir(dir);
		QMessageBox::about(this, "Message", dir + " loaded");
	}
}

void MainWindow::about(){
	QMessageBox::about(this, "About Fast5 Studio", "Fast5 Studio is an easy to use application to extract information from MinION Fast5 files");
}

void MainWindow::exit(){
	destroy(fast5files);
	QApplication::quit();
}

void MainWindow::saveFasta(){
	QString outfile = QFileDialog::getSaveFileName(this, "Export to Fasta", "untitled.fasta", "Fasta (*.fasta)");
	if(!outfile.isEmpty()){
		fast5files->convertFasta(outfile);
	}
}
