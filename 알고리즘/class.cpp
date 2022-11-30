#include<bits/stdc++.h>

using namespace std;


class Box
{
public:

    Box(){l=0,b=0,h=0;}

    Box(int tl, int tb, int th)
        :l(tl), b(tb), h(th)
    {

    }

    Box(const Box& rhs)
    {
        l = rhs.l;
        b = rhs.b;
        h = rhs.h;
    }




    bool operator<(const Box& c)
    {
        if (this->getLength() < c.getLength())
            return true;
        else if (this->getBreadth() < c.getBreadth() && this->getLength() == c.getLength())
         return true;
        else if(this->getHeight() < c.getHeight()&& this->getBreadth() == c.getBreadth() && this->getLength() == c.getLength())
            return true;
            
        return false;
     }



    int getLength() const
    {
        return l;
    }
    int getBreadth() const 
    {
        return b;
    }
    int getHeight() const
    {
        return h;
    }
    long long CalculateVolume()
    {
        long long vol=1;
        vol*=l;
        vol*=h;
        vol*=b;
        return vol;
    }

    
private:
    int l, b, h;


};


ostream& operator<< (ostream& out, Box& c)
{
    out << c.getLength() << " " << c.getBreadth() << " " << c.getHeight();
    return out;
}






void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
