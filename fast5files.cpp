#include "fast5files.h"
#include <QDir>
#include <QStringList>
#include <QDebug>

Fast5Files::Fast5Files(){
}

Fast5Files::~Fast5Files(){
}

void Fast5Files::readDir(QString dir){
	QDir fast5dir(dir);
	QStringList namefilter;

	fast5dir.setFilter(QDir::Files);
	namefilter << "*.fast5";
	fast5dir.setNameFilters(namefilter);

	QStringList filelist = fast5dir.entryList();
	for(int i = 0; i < filelist.size(); ++i){
		filenames.append(dir + "/" + filelist.at(i));
		//qDebug() << filelist.at(i);
	}
}

void Fast5Files::convertFasta(QString outfile){
	hid_t fast5id;

	fast5id = H5Fopen(filenames.at(0).toLatin1().data(), H5F_ACC_RDONLY, H5P_DEFAULT);
	H5Fclose(fast5id);
}

