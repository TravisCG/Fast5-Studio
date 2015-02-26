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

void Fast5Files::getFastq(hid_t dataset){
	hid_t dt;
	size_t size;
	char *data;

	dt   = H5Dget_type(dataset);
	size = H5Tget_size(dt);
	data = (char*)malloc(size);
	H5Dread(dataset, H5T_C_S1, H5S_ALL, H5S_ALL, H5P_DEFAULT, data);
	qDebug() << data;
	free(data);
	H5Dclose(dataset);
}

void Fast5Files::convertFasta(QString outfile){
	hid_t fast5id;
	hid_t fastq;

	for(int i = 0; i < filenames.size(); ++i){
		fast5id = H5Fopen(filenames.at(i).toLatin1().data(), H5F_ACC_RDONLY, H5P_DEFAULT);

		fastq   = H5Dopen2(fast5id, "/Analyses/Basecall_2D_000/BaseCalled_template/Fastq", H5P_DEFAULT);
		if(fastq > 0){
			getFastq(fastq);
		}

		fastq = H5Dopen2(fast5id, "/Analyses/Basecall_2D_000/BaseCalled_complement/Fastq", H5P_DEFAULT);
		if(fastq > 0){
			getFastq(fastq);
		}

		fastq    = H5Dopen2(fast5id, "/Analyses/Basecall_2D_000/BaseCalled_2D/Fastq", H5P_DEFAULT);
		if(fastq > 0){
			getFastq(fastq);
		}

		H5Fclose(fast5id);
	}
}

