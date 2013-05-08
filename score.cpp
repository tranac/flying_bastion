#include "score.h"

Score::Score()
{
	setEnabled(false);
	setReadOnly(true);
	setGeometry(75,40,400,300);
	
	read();
}

Score::~Score()
{

}

void Score::add(string n, int s)
{
	QString string = toPlainText();
	string = string + QString::fromStdString(n);
	setText(string);
/*
	for(map<string,int>::iterator it=hscores_.begin();it != hscores_.end(); ++it)
	{
		int t = it->second;
		if(s > t)
			cout << "Test!" << endl;
	}
*/
}

void Score::write()
{
	ofstream ofile("scores.txt");
	
	for(map<string,int>::iterator it=hscores_.begin();it != hscores_.end(); ++it)
	{
		ofile << it->first << " " << it->second << endl;
	}
}

void Score::read()
{
	ifstream ifile("scores.txt");
	
	if(ifile.good())
	{
		setText("Test");
	}
	else
		setText("New.");
}
