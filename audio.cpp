#include "audio.h"

Audio::Audio()
{
	file = new QFile("music/hb.wav");
//	file->setFileName("music/hb.wav");
	file->open(QIODevice::ReadOnly);
	
	song = new QAudioFormat();
	song->setFrequency(44100);
	song->setChannels(1);
	song->setSampleSize(32);
	song->setCodec("audio/pcm");
	song->setByteOrder(QAudioFormat::LittleEndian);
	song->setSampleType(QAudioFormat::UnSignedInt);
	audioOutput = new QAudioOutput(*song,0);
	
	file.close();
}

Audio::~Audio()
{
	delete file;
	delete audioOutput;
	delete song;
}

void Audio::play()
{
	audioOutput->start(file);
}
