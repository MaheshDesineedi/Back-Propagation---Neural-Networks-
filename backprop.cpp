#include<iostream>
#include<math.h>
using namespace std;
double activate(double x)
{
	return (1/(1+exp(-x)));
}

int main()
{
	double x[4][2]={{0,0},{0,1},{1,0},{1,1}};
	double target[4]={0,1,1,0};
	double v[2][2],w[2];
	v[0][0]=0.6;
	v[1][0]=-0.1;
	v[0][1]=-0.3;
	v[1][1]=0.4;
	w[0]=0.4;
	w[1]=0.1;
	double w0=-0.2;
	double v0[2]={0.3,0.5};
	//b[0]=0.3;b[1]=0.5;b[2]=-0.2;
	double zin[2];
	double yin,y;
	int count=0;
	double delta;
	double alpha=0.25;
	double z[2],dw[2],dw0,dv[2][2],dv0[2],deltain[2],deltahid[2];
	int epoch;
	cout<<"enter the number of epochs"<<endl;
	cin>>epoch;
	int counttarget=0;
	int epochno=0;

	cout<<"INPUT"<<endl;
	while(epoch>0){
		epochno++;
	count=0;
	counttarget=0;
	cout<<"EPOCH"<<epochno<<endl<<endl;
	while(count<4){

	cout<<"\tx1 = "<<x[count][0]<<"  "<<"x2 ="<<x[count][1]<<"\t";
	cout<<"Target = "<<target[count];
	for(int i=0;i<2;i++)
	{
		zin[i]=v0[i];
		for(int k=0;k<2;k++)
			zin[i]+=v[k][i]*x[count][k];
		cout<<"\tzin"<<i+1<<" = "<<zin[i];
	}
	for(int i=0;i<2;i++)
	{
		z[i]=activate(zin[i]);
		cout<<"\tz"<<i+1<<" = "<<z[i];
	}
	yin=w0;
	for(int i=0;i<2;i++)
	{
		yin+=w[i]*z[i];
	}

	y=activate(yin);
	cout<<"\tyin = "<<yin<<"\ty = "<<y;
	delta=(target[count]-y)*(y)*(1-y);

	for(int i=0;i<2;i++)
	{
		dw[i]=alpha*delta*z[i];
		w[i]+=dw[i];
		cout<<"\tw"<<i+1<<" = "<<w[i];
	}
	cout<<endl<<endl;;
	dw0=alpha*delta;
	w0+=dw0;
	for(int i=0;i<2;i++)
	{
		deltain[i]=w[i]*delta;
	}
	for(int i=0;i<2;i++)
	{
		deltahid[i]=deltain[i]*z[i]*(1-z[i]);
	}
	for(int i=0;i<2;i++)
	{
		dv0[i]=alpha*deltahid[i];
		v0[i]+=dv0[i];
	}
	for(int i=0;i<2;i++)
	{
		for(int k=0;k<2;k++){
		dv[i][k]=alpha*deltahid[k]*x[count][i];
		v[i][k]+=dv[i][k];
		cout<<"\tv"<<i+1<<k+1<<" = "<<v[i][k];
		}
	}
	for(int i=0;i<2;i++)
		cout<<"\tv0"<<i+1<<v0[i];
	cout<<"\tw0"<<w0;
	count++;
	cout<<endl<<endl<<endl;
		if(target[count]==y)
			counttarget++;
	}
	epoch--;
	if(counttarget==4)
		break;

	}
	return 0;
}
