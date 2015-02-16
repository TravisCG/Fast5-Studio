#ifndef MAINWINDOW
#define MAINWINDOW
#include <QMainWindow>
#include "fast5files.h"

class QMenu;

class MainWindow : public QMainWindow{
Q_OBJECT // what the heck is this?
public:
	MainWindow();
private slots:
	void openFast5();
	void saveFasta();
	void exit();
	void about();
private:
	QMenu *fileMenu;
	QAction *openAction;
	QAction *exitAction;
	QAction *saveFastaAction;

	QMenu *statMenu;

	QMenu *helpMenu;
	QAction *aboutAction;

	Fast5Files *fast5files;

	void createMenu();
	void createActions();
//	void openFast5();
//	void exit();
//	void about();
};

#endif
