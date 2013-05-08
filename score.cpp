#include "score.h"

Score::Score()
{
	n = 0;
	setEnabled(false);
	setReadOnly(true);
	setFixedSize(200,350);

	read();
}

Score::~Score()
{
}

void Score::add(int s, string name)
{
	hscores_[s] = name;
	n++;
	
	if(n > 10)
	{
		hscores_.erase(hscores_.begin());
		n--;
	}
	
	setBox();
	write();
}

void Score::write()
{
	ofstream ofile("scores.txt");
	ofile << n << endl;
	for(map<int,string>::iterator it=hscores_.begin();it != hscores_.end(); ++it)
	{
		ofile << it->first << " " << it->second << endl;
	}
}

void Score::read()
{
	ifstream ifile("scores.txt");
	
	if(ifile.good())
	{
		ifile >> n;
	}
	for(int i=0;i<n;i++)
	{
		string tmp;
		int score;
		ifile >> score >> tmp;
		hscores_[score] = tmp;
	}
	
	setBox();
}

void Score::setBox()
{
	QString text = "High Scores!\n\n";
	int ct = 1;
	for(map<int,string>::reverse_iterator it= hscores_.rbegin();it!=hscores_.rend();it++)
	{
		string name = it->second;
		int s = it->first;
		text = text + QString::number(ct) + ".  "  + QString::fromStdString(name) + "\t" + QString::number(s) + '\n';
		ct++;
	}

	setText(text);
}
