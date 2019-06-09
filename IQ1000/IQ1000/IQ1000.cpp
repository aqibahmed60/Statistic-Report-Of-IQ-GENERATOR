// IQ1000.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream> 
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime> 


using namespace std; 

string username;  
int qcount=1; 



void Mean (string s1,string s2) 
{  

	int min; 
	int max; 
	float percentage=0.0;

	int file_count; 
	float mean=0.0; 

	_asm 
	{
		mov min,0 
		mov max,0 
		mov file_count,0
	}  

	ifstream infile (s1); 

	string str; 

	while (getline (infile,str)) 
	{ 
		_asm 
		{
			inc file_count
		}
	}

	infile.close ();

	infile.open (s1); 

	int sum; 

	_asm 
	{
		mov esi,0
		mov sum,0
	} 

	int *array1=new int [file_count]; 

	cout<<"Correct Attempt"<<endl; 
	cout<<"---------------"<<endl; 
	int n; 

	for (int i=0;i<file_count;i++) 
	{
		infile>>array1 [i];
		cout<<array1 [i]<<endl;
		n=array1 [i]; 

		_asm 
		{ 
			mov eax,n 
			add sum,eax 
			mov eax,0 
		}
	} 

	min=array1 [0]; 
	max=array1 [0]; 

		
	for (int i=0;i<file_count;i++) 
	{ 
		n=array1[i]; 

		 _asm 
		 {
			 mov eax,n
			 cmp eax,min 
			 
			 JB aa1 
			 JMP aa2 

			 aa2: 
			 cmp eax,max 
			 JG aa3 
			 JMP aa4 

			 aa1: 
			 mov min,eax 
			 JMP nn2 

			 aa3: 
			 mov max,eax 
			 
			 aa4:
		 }

		 percentage+=(float (array1 [i])*100)/(10); 

	} 

	infile.close ();  

	mean=float (sum)/float (file_count);  

	//standard deviation 

	float sd1=0.0; 
	float standard_deviation=0.0; 
	float variance=0.0; 
	float cc_conv=0.0; 

	for (int i=0;i<file_count;i++) 
	{ 
		sd1+=abs (array1[i]-mean); 
	} 

	cc_conv=float (file_count);
	standard_deviation=sqrt ((sd1)*(sd1)/cc_conv);
	variance=((sd1)*(sd1))/(cc_conv); 

	cout<<"\n\n Mean Of Correct Attempt="<<mean;
	cout<<"\n Total Correct Attempt="<<sum; 
	cout<<"\n Minimum Correct Attempt="<<min; 
	cout<<"\n Maximum Correct Attempt="<<max; 
	cout<<"\n Total Percentage="<<percentage; 
	cout<<"\n Standard Deviation Of Correct Attempt="<<standard_deviation; 
	cout<<"\n Variance Of Correct Attempt="<<variance; 
	infile.close ();




 
	mean=0.0; 

	_asm 
	{
		mov file_count,0
	}  

	infile.open (s2); 
 

	while (getline (infile,str)) 
	{ 
		_asm 
		{
			inc file_count
		}
	}

	infile.close ();

	infile.open (s2); 
 

	_asm 
	{
		mov esi,0
		mov sum,0
	} 

	int *array2=new int [file_count]; 

	cout<<"\n\n\nWrong Attempt"<<endl; 
	cout<<"---------------"<<endl;  

	percentage=0.0; 

	for (int i=0;i<file_count;i++) 
	{
		infile>>array2 [i];
		cout<<array2 [i]<<endl;
		n=array2 [i]; 

		_asm 
		{ 
			mov eax,n 
			add sum,eax 
			mov eax,0 
		} 

		percentage+=(float (array2 [i])*100)/(10); 
	} 


	min=array2 [0]; 
	max=array2 [0]; 


	for (int i=1;i<file_count;i++) 
	{ 
		n=array2 [i]; 

		 _asm 
		 {
			 mov eax,n
			 cmp eax,min 
			 
			 JB nn1 
			 JMP nn2 

			 nn2: 
			 cmp eax,max 
			 JG nn3 
			 JMP nn4 

			 nn1: 
			 mov min,eax 
			 JMP nn2 

			 nn3: 
			 mov max,eax 
			 
			 nn4:
		 }

	} 
	infile.close (); 


	mean=float (sum)/float (file_count); 
	sd1=0.0; 

	for (int i=0;i<file_count;i++) 
	{ 
		sd1+=abs (array2[i]-mean); 
	} 

	float conv_file_count=file_count; 
	standard_deviation=sqrt (((sd1)*(sd1))/conv_file_count);
	variance=(sd1*sd1)/(file_count); 

	cout<<"\n\n Mean Of Wrong Attempt="<<mean;
	cout<<"\n Total Wrong Attempt="<<sum; 
	cout<<"\n Minimum Wrong Attempt="<<min; 
	cout<<"\n Maximum Wrong Attempt="<<max; 
	cout<<"\n Total Percentage Of Wrong Attempt="<<percentage; 
	cout<<"\n Standard Deviation Of Wrong Attempt="<<standard_deviation; 
	cout<<"\n Variance Of Wrong Attempt="<<variance; 

	infile.close ();

}

void stats (string s1,string s2) 
{  
	Mean (s1,s2);
}


int func1 () 
{
	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<":| 4 | 6 | 9 | 13 | 18 |?:"; 
	cin>>n; 

	_asm 
	{ 
		cmp n,24 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;

}

int func2 () 
{

	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<"5 |  7 | 14 | 16 | 32 | 34 | ? "; 
	cin>>n; 

	_asm 
	{ 
		cmp n,68 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;
}

int func3 () 
{

	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<"  2 | 4 | 12 | 48 | ? "; 
	cin>>n; 

	_asm 
	{ 
		cmp n,240 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;
}

int func4 () 
{

	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<"    64 | 32 | 16 | 8 | ? "; 
	cin>>n; 

	_asm 
	{ 
		cmp n,4 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;
}

int func5 () 
{

	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<"	4, 8, 12, 20, ?"; 
	cin>>n; 

	_asm 
	{ 
		cmp n,32 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;
}

int func6 () 
{

	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<"	54, 49, ?, 39, 34"; 
	cin>>n; 

	_asm 
	{ 
		cmp n,44 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;
}

int func7 () 
{

	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<"	 ?, 19, 23, 29, 31"; 
	cin>>n; 

	_asm 
	{ 
		cmp n,17 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;
}

int func8 () 
{

	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<"	4, 8, 16, 32, ?"; 
	cin>>n; 

	_asm 
	{ 
		cmp n,64 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;
}

int func9 () 
{

	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<"	1, 4, 9, 16, 25, 36, ?"; 
	cin>>n; 

	_asm 
	{ 
		cmp n,49 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;
}

int func10 () 
{

	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<"	1,8,27,64,?"; 
	cin>>n; 

	_asm 
	{ 
		cmp n,125 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;
}

int func11 () 
{

	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<"	1,2,6,4,?"; 
	cin>>n; 

	_asm 
	{ 
		cmp n,120 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;
}

int func12 () 
{

	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<"	53,53,40,40,27,27,13,?"; 
	cin>>n; 

	_asm 
	{ 
		cmp n,13 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;
}

int func13 () 
{

	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<"	1,3,12,60,?"; 
	cin>>n; 

	_asm 
	{ 
		cmp n,360 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;
}

int func14 () 
{

	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<"	1,3,12,52,?"; 
	cin>>n; 

	_asm 
	{ 
		cmp n,265 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;
}

int func15 () 
{

	int n; 

	cout<<"\n\n\xDB Q#"<<qcount<<"	2,3,5,8,?"; 
	cin>>n; 

	_asm 
	{ 
		cmp n,12 
		JE n1 
		JMP n2 
	} 

	n1:
	cout<<"\nCorrect";
	return 1;

	n2:
	cout<<"\nWrong";
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string username1;
	string username2; 

	cout <<"\xDB Enter UserName:";
	getline (cin>>ws,username); 
	
	username1=username;
	username2=username; 

	username1+="CorrectAttempt.txt";
	ofstream outfile1 (username1); 


	username2+="WrongAttempt.txt";
	ofstream outfile2 (username2);

	username="";

	a1: 

	int correct; 
	int wrong;

	_asm 
	{	
		mov correct,0 
		mov wrong,0 
	} 


	int array1 [15]; 

	_asm 
	{ 
		mov eax,1 
		lea esi,array1 
		mov ecx,Length array1

		L1: 

			mov [esi],eax 
			add esi,TYPE array1 
			inc eax
			LOOP L1


	}

	srand (time (0));
	random_shuffle (array1,array1+14);

	
	
	
	_asm 
	{
		
		mov eax,0
		mov ebx,1  

		lea esi,array1 

		L2:
			cmp ebx,11 
			JE e1 

			cmp [esi],1 
			JE f1  

			cmp [esi],2 
			JE f2  

			cmp [esi],3 
			JE f3  

			cmp [esi],4 
			JE f4 

			cmp [esi],5 
			JE f5 

			cmp [esi],6 
			JE f6 

			cmp [esi],7 
			JE f7 

			cmp [esi],8 
			JE f8 

			cmp [esi],9 
			JE f9 

			cmp [esi],10 
			JE f10 

			cmp [esi],11 
			JE f11 

			cmp [esi],12 
			JE f12 

			cmp [esi],13 
			JE f13 

			cmp [esi],14 
			JE f14 

			cmp [esi],15 
			JE f15 

			JMP n1

			f1: 
			call func1
			cmp eax,1 
			
			JE c1 
			JMP w1 

			c1:
			inc correct 
			JMP n1 

			w1: 
			inc wrong
			JMP n1 


			f2:
			call func2
			cmp eax,1

			JE c2 
			JMP w2 

			c2:
			inc correct 
			JMP n1 

			w2: 
			inc wrong
			JMP n1

			f3:
			call func3 
			cmp eax,1
			JE c3 
			JMP w3 

			c3:
			inc correct 
			JMP n1 

			w3: 
			inc wrong
			JMP n1

			f4:
			call func4
			cmp eax,1

			JE c4 
			JMP w4 

			c4:
			inc correct 
			JMP n1 

			w4: 
			inc wrong
			JMP n1

			f5:
			call func5
			cmp eax,1

			JE c5 
			JMP w5 

			c5:
			inc correct 
			JMP n1 

			w5: 
			inc wrong
			JMP n1


			f6:
			call func6
			cmp eax,1

			JE c6 
			JMP w6 

			c6:
			inc correct 
			JMP n1 

			w6: 
			inc wrong
			JMP n1


			f7:
			call func7
			cmp eax,1

			JE c7 
			JMP w7 

			c7:
			inc correct 
			JMP n1 

			w7: 
			inc wrong
			JMP n1

			f8:
			call func8
			cmp eax,1

			JE c8 
			JMP w8 

			c8:
			inc correct 
			JMP n1 

			w8: 
			inc wrong
			JMP n1

			f9:
			call func9
			cmp eax,1


			JE c9 
			JMP w9 

			c9:
			inc correct 
			JMP n1 

			w9: 
			inc wrong
			JMP n1

			f10:
			call func10

			cmp eax,1

			JE c10 
			JMP w10 

			c10:
			inc correct 
			JMP n1 

			w10: 
			inc wrong
			JMP n1

			f11:
			call func11
			cmp eax,1


			JE c11 
			JMP w11 

			c11:
			inc correct 
			JMP n1 

			w11: 
			inc wrong
			JMP n1


			f12:
			call func12
			cmp eax,1


			JE c12 
			JMP w12 

			c12:
			inc correct 
			JMP n1 

			w12: 
			inc wrong
			JMP n1


			f13:
			call func13
			cmp eax,1

			JE c13 
			JMP w13 

			c13:
			inc correct 
			JMP n1 

			w13: 
			inc wrong
			JMP n1


			f14:
			call func14
			cmp eax,1


			JE c14 
			JMP w14 

			c14:
			inc correct 
			JMP n1 

			w14: 
			inc wrong
			JMP n1


			f15:
			call func15 
			cmp eax,1

			JE c15 
			JMP w15 

			c15:
			inc correct 
			JMP n1 

			w15: 
			inc wrong
			JMP n1 

			n1:
			
			mov eax,0
			add esi,TYPE array1 
			add qcount,1
			inc ebx 

			JMP L2 

		e1:
			mov qcount,1 

	}  

	cout<<"\n\n\n\nTotal Score"<<endl; 
	cout<<"-----------"<<endl;

	cout<<"\n\n\n\xDB Correct:"<<correct<<endl;
	cout<<"\n\n\n\xDB Wrong:"<<wrong<<endl;

	outfile1<<correct<<endl; 
	outfile2<<wrong<<endl; 

	char choice; 

	cout<<"\n\n\n\n\xDB Do you want to re-attempt (y/n):"; 
	cin>>choice;

	_asm 
	{ 
		cmp choice,'y'
		JE a1 

		JMP nn1 
	} 

	nn1:

	outfile1.close(); 
	outfile2.close(); 

	cout<<"\n\n\xDB Do you want to see your stats report (y/n):"; 
	cin>>choice; 

	_asm 
	{
		cmp choice,'y'
		
		JE s1 
		JMP nn2 


	}


	s1: 
	stats (username1,username2);
	
	nn2:
	return 0;
}

