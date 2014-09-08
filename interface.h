#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <time.h>

using namespace std;
void run_prog(string c)
{
	system(c.c_str());	
	system("./temp.out  "); 
}
int main(int argc, char *argv[]){
	
	int i=0;string c;
	string file[100];
	float arrival_time[100],burst_time[100];
	int priority[100];
	clock_t start_time,end_time;
	system("clear");
	cout<<"Ensure that files are in the same folder(sample files are p1.c & p2.c) \nPress 0 in file name to stop entering files!"<<endl;
	while(1){
		cout<<"Enter name of file #"<<i+1<<": ";	cin>>file[i];

		if( file[i][0]=='0')
			break;
		
		cout<<"Enter it's arrival time: ";		cin>>arrival_time[i];
		cout<<"Enter it's Priority(unique int): ";		cin>>priority[i];
		//Execute the given program according to it's type(C++/C)
		if(file[i][sizeof(file[i])]=='c')
			c="gcc -o temp.out -pthread "+file[i];
		else
			c="g++ -o temp.out -pthread "+file[i]; 
		start_time = clock();
		  			//compile program to temp.out
    	run_prog(c); //run the temp.out file
		end_time = clock();
		system("rm temp.out");
		cout<<"Calculating Burst time: ";
		burst_time[i] = (((float)end_time - (float)start_time) / 1000000.0F ) * 1000; //4900/1000
		cout<<burst_time[i]<<endl;
		cout<<"******************************************************"<<endl;
		i++;
	}
	if(i>0){  //If there are non-zero number of applications
		
		//Write to file
		std::ofstream outfile;
		outfile.open("process.txt");
		outfile << "#file_name\tarrival_time\tburst_time\tpriority"<<endl;
		for(int j=0;j<i;j++)
		outfile << file[j] << "\t" << arrival_time[j]<<"\t"<<burst_time[j]<<"\t"<<priority[j]<<endl;
		//Writing Ends

		/*int t;
		cout<<"Which algorithm do you want to implement among these processes? (1).SJF (2).FCFS (3).SRTF :";
		cin>>t;
		while(t!=1 && t!=2 && t!=3){
			cout<<"Enter options properly: (1).SJF (2).FCFS (3).SRTF :";
			cin>>t;
		}
		switch ( t ) {
			case 1:
			  cout<<"Implementing SJF... "<<endl;
			  //call SJF();
			  break;
			case 2:
			  cout<<"Implementing FCFS... "<<endl;
			  //call FCFS();
			  break;
			case 3:
			  cout<<"Implementing SRTF... "<<endl;
			  //call SRTF();
			  break;
			default:
			  break;
		}*/
	}
	else cout<<"No files"<<endl;
}