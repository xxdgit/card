#include <vector>
#include <string>
using namespace std;

class Card
{
public:
	Card();
	~Card();
	void initCard();
	void shuffler();
	void deal();
	void print();
protected:
	vector<string> mAllCard;
	vector<string> *toPlayerCard;
};