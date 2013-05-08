#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <QWidget>
#include <QTextEdit>

using namespace std;

class Score : public QTextEdit {
	Q_OBJECT
public:
	Score();
	~Score();
	void add(int s, string name);
	void write();
	void read();
	void setBox();
private:
	map<int,string> hscores_;
	int n;
} ;

#endif
