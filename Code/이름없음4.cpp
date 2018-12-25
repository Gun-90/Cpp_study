#include <iostream>
using namespace std;

class Point{
	private:
		int xpos, ypos;
	public:
		Point(int x=0, int y=0) : xpos(x), ypos(y){	}
		
		void ShowPostion() const{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
		}
};
