#include "audio.h"
#include <QDebug>

Audio::Audio()
{
	file = new QFile("music/hb.wav");
	
	song = new QAudioFormat();
	song->setFrequency(44100);
	song->setChannels(1);
	song->setSampleSize(32);
	song->setCodec("audio/pcm");
	song->setByteOrder(QAudioFormat::LittleEndian);
	song->setSampleType(QAudioFormat::UnSignedInt);
	audioOutput = new QAudioOutput(*song,0);
	/*
	buffer = new QBuffer(file);
	buffer->open(QIODevice::ReadOnly);
*/
	QObject::connect(audioOutput,SIGNAL(stateChanged(QAudio::State)),this,SLOT(finished(QAudio::State)));
}

Audio::~Audio()
{
	file->close();
	delete file;
	delete audioOutput;
	delete song;
}

void Audio::play()
{
	audioOutput->setBufferSize(500000);
	file->open(QIODevice::ReadOnly);
	audioOutput->start(file);
}

void Audio::finished(QAudio::State state)
{
	if(state == QAudio::StoppedState)
	{
		audioOutput->stop();
		audioOutput->reset();
		file->close();
		play();
	}
	if(state == QAudio::IdleState)
	{
		audioOutput->stop();
		audioOutput->reset();
		file->close();
		play();
	}
}
void Audio::stop()
{
	audioOutput->stop();
	audioOutput->stop();
	audioOutput->reset();
	file->close();
}
