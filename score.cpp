#include "score.h"

Score::Score()
{
	setEnabled(false);
	setReadOnly(true);
	setGeometry(50,50,200,350);
}

Score::~Score()
{

}

void Score::add(string n, int s)
{
	read();

	for(map<string,int>::iterator it=hscores_.begin();it != hscores_.end(); ++it)
	{
		int t = it->second;
		if(s > t)
			cout << "Test!" << endl;
	}
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
		cout << "Good!" << endl;
	}
	else
		cout << "Empty." << endl;
}
