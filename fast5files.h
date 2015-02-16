#ifndef FAST5FILES
#define FAST5FILES

#include <hdf5.h>
#include <QVector>
#include <QString>

class Fast5Files {
public:
	Fast5Files();
	~Fast5Files();
	void readDir(QString dir);
	void convertFasta(QString outfile);
private:
	QVector<QString> filenames;
};

#endif
