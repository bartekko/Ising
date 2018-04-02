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




class Lattice
{
public:
	Lattice(int L)
	{	l=L;
		stor.resize(L*L); 
		boost::random::uniform_int_distribution<> boolean(0,1);
		for(auto& it:stor)
		{
			it=boolean(rng);
		}
	};
	
	char& at(Point p) 
	{	while(p.x<0) p.x+=l;
		while(p.x>=l) p.x-=l;
		while(p.y<0) p.y+=l;
		while(p.y>=l) p.y-=l;
		auto n=p.x*l+p.y;
		return stor[n];
	};
	int sum_of_nn_spins(Point p)
	{

		int c=at(p.shift(0))+at(p.shift(1))+at(p.shift(2))+at(p.shift(3));
		c*=2;
		return c-4;
	}
	std::vector<std::vector<int>> print()
	{
		std::vector<std::vector<int> > img;
		for(int i=0;i<l;i++)
		{
			std::vector<int> row;
			for(int j=0; j<l; j++)
				row.push_back(at(Point(i,j)));
			img.push_back(row);
		}
		
		return img;
	}
	
	 
	double switch_probability(Point p,double Temp)
	{

		auto ans=exp(-2*at(p)*(sum_of_nn_spins(p))/Temp);
		return ans>1?1:ans;
	}
private:
	std::vector<char> stor;
	int l;
};

