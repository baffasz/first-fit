#include<iostream>
 
using namespace std;
 
int main()
{
	int memc;
	int part_no = 4, pno;
	int flags[4], allocation[4], i, j;
 
	for(i = 0; i < part_no; i++)
	{
		flags[i] = 0;
		allocation[i] = -1;
	}
	cout<<"Enter memory capacity: ";
	cin>>memc;
	cout<<"\nEnter no. of processes: ";
	cin>>pno;
	
	int psize[pno];
	int part_size[part_no] =  { memc * 0.3, memc * 0.4, memc * 0.15, memc * 0.15 };
	
	cout<<"\nEnter size of each process: \n";
	for(i = 0; i < pno; i++)
	{
		cout<<"size of process "<<i+1<<": ";
		cin>>psize[i];
	}
	
	for(i = 0; i < pno; i++)
		for(j = 0; j < part_no; j++)
			if(flags[i] == 0 && part_size[j] >= psize[i])
			{
				allocation[j] = i;
				flags[i] = 1;
				break;
			}
	
	cout<<"\npartition\tpartition size\tprocess no.\tprocess size\tinternal fragmentation";
	for(i = 0; i <part_no; i++)
	{
		cout<<"\n"<< i+1<<"\t\t"<<part_size[i]<<"\t\t";
		if(flags[i] == 1)
			cout<<allocation[i]+1<<"\t\t\t"<<psize[allocation[i]]<<"\t\t\t"<<part_size[i]-psize[allocation[i]];
		else
			cout<<"Not allocated";
	}
	
	return 0;
}
