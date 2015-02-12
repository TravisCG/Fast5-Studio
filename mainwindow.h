#ifndef MAINWINDOW
#define MAINWINDOW
#include <QMainWindow>

class QMenu;

class MainWindow : public QMainWindow{
Q_OBJECT // what the heck is this?
public:
	MainWindow();
private slots:
	void openFast5();
	void exit();
	void about();
private:
	QMenu *fileMenu;
	QAction *openAction;
	QAction *exitAction;

	QMenu *statMenu;

	QMenu *helpMenu;
	QAction *aboutAction;

	void createMenu();
	void createActions();
//	void openFast5();
//	void exit();
//	void about();
};

#endif
