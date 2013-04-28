#ifndef AUDIO_H
#define AUDIO_H

#include <QObject>
#include <QAudioOutput>
#include <QFile>

class Audio : public QObject
{
public:
	Audio();
	~Audio();
	void play();
private:
	QFile* file;
	QAudioFormat* song;
	QAudioOutput* audioOutput;
} ;

#endif
