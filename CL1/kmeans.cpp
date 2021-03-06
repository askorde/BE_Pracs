#define MAXK 10

#include<iostream>

using namespace std;

int abs(int n)
{
	if(n<0)
		return -n;
	return n;
}
class kmean
{
	int k,n;
	int cluster[50];
	int seed[MAXK];
	int data[50];
public:
	kmean()
	{
		k=0;
		n=0;
	}

	void getData()
	{
		cout<<"Size of input:";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>data[i];
			cluster[i]=-1;
		}

		cout<<"Enter k (no. of clusters):";
		cin>>k;

		cout<<"Enter seed points:\n";
		for(int i=0;i<k;i++)
			cin>>seed[i];
	}

	void formClusters()
	{
		bool flag = false;
		int th=1;
		do{
			int sum[k],c[k];
			for(int i=0;i<k;i++)
			{
				sum[i]=c[i]=0;
			}
			for(int i=0;i<n;i++)
			{
				int min = 99999;
				for(int j=0;j<k;j++)
					if(abs(data[i]-seed[j]) < min)
					{
						min = abs(data[i]-seed[j]);
						cluster[i] = j;
					}
				c[cluster[i]]++;
				sum[cluster[i]]+=data[i];
			}

			for(int i=0;i<k;i++)
			{
				if(abs(seed[i]-sum[i]/c[i]) <= th)
					flag = false;
				else flag = true;
				seed[i]=sum[i]/c[i];
				cout<<"Cluster "<<i<<":";
				for(int j=0;j<n;j++)
					if(cluster[j]==i)
						cout<<data[j]<<" ";
				cout<<" Seed:"<<seed[i];
				cout<<endl;
			}
			cout<<endl<<endl;
		}while(flag);
	}
};

int main()
{
	kmean x = kmean();
	x.getData();
	x.formClusters();
}
