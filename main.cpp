#include <stdio.h>
#include <stdint.h>     // use to uint32_t
#include <string.h>     // use to memcpy()
#include <cstdlib>	// malloc
#include <netinet/in.h> // byte ordering
#include "add-nbo.h"

int main(int argc, char *argv[])
{
	FILE* fp = NULL;
	uint32_t data;
	fp = fopen(argv[1],"rb"); 
	if(fp == NULL)
	{
		fprintf(stderr, "오류\n");
		return 1;
	}
	fread(&data, 4, 1, fp);
	data = htonl(data);	
	//printf("%x\n",data);
	

	
        uint32_t data2;
        fp = fopen(argv[2],"rb");
        if(fp == NULL)
        {
                fprintf(stderr, "오류\n");
                return 1;
        }
        fread(&data2, 4, 1, fp);
        data2 = htonl(data2);
	//printf("%x\n", data2);
	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", data,data, data2,data2, add_NBO(data, data2),add_NBO(data, data2));

	fclose(fp);
	return 0;
}
