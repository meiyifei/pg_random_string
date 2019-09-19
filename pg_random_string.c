#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "postgres.h"
#include "fmgr.h"

PG_MODULE_MAGIC;
PG_FUNCTION_INFO_V1(random_string);

Datum
random_string(PG_FUNCTION_ARGS)
{
	int i,ch,tmp;
	short int arg1=PG_GETARG_INT32(0);
	char arry[arg1];
	srand(time(NULL));
	for(i=0;i<arg1;i++)
	{
		tmp=rand()%3;
		switch(tmp)
		{
			case 0:
				ch=rand()%26;
				ch+='A';
				arry[i]=ch;
				break;
			case 1:
				ch=rand()%26;
				ch+='a';
				arry[i]=ch;
				break;
			case 2:
				ch=rand()%10+'0';
				arry[i]=ch;
				break;
		}
	}	
	PG_RETURN_CSTRING(pstrdup(arry));
}
