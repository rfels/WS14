/*
 * rms.c
 * 
 * Copyright 2014 robert <robert@T420>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
//#include "simclist.h"

#if defined(WIN32)
  #include <windows.h>
#elif defined(__UNIX__)
  #include <unistd.h>
#else
#endif	

#define maxTasks 100
/**
 * 
 * e - execution times
 * p - periods
 * n - number of processes
 * 
 * **/
int printScheduling(int *e,int *p,int n) {
	printf("Time | Process | Deadlines \n");
	//done of each process
	int d[maxTasks];
	//int deadlines[maxTasks][maxTasks];
	int i;
	//time steps
	for (i=0;1;i++) {
		// get deadlines
		char pString[]="";
		//list_t deadlineList; 
		//list_init(&deadlineList);
		int j;
		//all processes
		for (j=0;j<n;j++) {
			//deadlines[i][j]
			if (i+1%p[j]==0) {
				//list_append(&deadlineList,j);
				char numStr[5];
				sprintf(numStr,"P%d",j+1);
				strcat(pString,numStr);
			}
			
		}
		
		printf("%d | Process | %s\n",i,pString);
		#if defined(WIN32)
			//SetLastError(0);
			Sleep(500);
		#elif defined(LINUX)
			return usleep(1000 * ms);
		#else
		#error ("no milli sleep available for platform")
			//return -1;
		#endif
	}
}

int main(int argc, char **argv)
{
  
  int n;
  //execution times and periods (deadlines) of processes
  int e[maxTasks],p[maxTasks];
  int i;
  float ut,u;
  ut=0;

  printf("\n Enter Number of Processes : ");
  scanf("%d",&n);

  //intput
  for(i=0;i<n;i++){
   printf("\n Enter Execution Time for P%d :",(i+1));
   scanf("%d",&e[i]);
   printf("\n Enter Deadline for P%d :",(i+1));
   scanf("%d",&p[i]);
  }
  
  //feasibility check
  for(i=0;i<n;i++){
	ut=ut+(float)e[i]/(float)p[i];
  }

  u=(float)n*((pow(2.0,1/(float)n))-1);
  if(ut<=u){
	printf("\n Since %f < %f ,",ut,u);
	printf("\n all the processes are schedulable! Scheduling is starting now!\n IF YOU WANT TO QUIT THE PROGRAM PRESS CTRL+C AND CONFIRM!!!\n\n");
	
	printScheduling(e,p,n);
  }
  else
	printf("\n The processes are not schedulable with RMS");
  getch();
  
  return 0;
}
