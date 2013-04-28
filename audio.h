#ifndef AUDIO_H
#define AUDIO_H

#include <QObject>
#include <QAudioOutput>
#include <QFile>
#include <QBuffer>
#include <QEventLoop>

class Audio : public QObject
{
	Q_OBJECT
public:
	Audio();
	~Audio();
	void play();
	void stop();
public slots:
	void finished(QAudio::State s);
private:
	QFile* file;
	QAudioFormat* song;
	QAudioOutput* audioOutput;
	QBuffer* buffer;
	QEventLoop* loop;
} ;

#endif
