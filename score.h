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
	void add(string n, int s);
	void write();
	void read();
private:
	map<string,int> hscores_;
	int n;
} ;

#endif
