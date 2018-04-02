#pragma once

typedef int Direction;

class Point
{
public:
	Point(int _x,int _y){x=_x;y=_y;}
	Point shift(Direction dir)
	{
		Point ans=*this;
		switch(dir)
		{
			case 0:
				ans.y++;
				break; 
			case 1:
 				ans.y--;
				break;	
			case 2:
 				ans.x--;
				break;
			case 3:
  				ans.x++;
				break;
		}
		return ans;
	};			
int x,y;
};
