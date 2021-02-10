#include <stdio.h>

typedef struct
{
	char name[15];
	unsigned height;
	unsigned weight;
} sr_t;


typedef struct
{
	double d1;
	double d2;
//	unsigned height;
//	unsigned weight;
} num_t;

void print_num_record(const num_t* sr)
{
	printf("%e : %e \n",sr->d1,sr->d2);
	//printf("%e : %e : %u : %u\n",sr->d1,sr->d2,sr->height,sr->weight);
}
void print_student_record(const sr_t* sr)
{
	printf("%s : %u : %u\n",sr->name,sr->height,sr->weight);
}

int main(int argc, char** argv)
{


#if 0
  for(unsigned i=0;i<argc;i++)
  {
	  printf("Argument %d is %s\n",i+1,argv[i]);
  }
 #endif

	if(argc!=2) 
	{ fprintf(stderr,"Illegal usage of command\n"); 
	  return 1;
	}


	sr_t sr[5] = {{"alice wonder", 170,80},{"bob",165,90},{"charlie",150,50}, {"derick",180,60},{"elon",165,65}};

	FILE* fp=fopen(argv[1],"wb");
	if(fp==NULL)
	{
		fprintf(stderr,"Error opening file\n");
		
		return 1;
	}

	
	fwrite(sr,sizeof(sr[0]),1,fp);
	 fpos_t save_pos;

	fgetpos(fp,&save_pos);
	fwrite(&sr[1],sizeof(sr[0]),4,fp);
	fsetpos(fp,&save_pos);
	//fseek(fp,-2*sizeof(sr[0]),SEEK_CUR);
	//fseek(fp,-sizeof(sr[0]),SEEK_CUR); //SEEK_CUR, SEEK_SET, SEEK_END
	fwrite(&sr[4],sizeof(sr[0]),1,fp);
	fclose(fp);


	fp = fopen(argv[1],"rb");
	if(fp==NULL)
	{
		fprintf(stderr,"Error opening file\n");
		return 1;
	}

	sr_t read_sr[5];
	sr_t *sr_ptr=read_sr;
	unsigned count=0;

	do
	{
		int fs = fread(sr_ptr,sizeof(read_sr[0]),1,fp);
		if(fs>0)
		{
			sr_ptr++;
		count++;
		}
	}while(!feof(fp) && !ferror(fp));

	for(unsigned i=0;i<count;i++)
	{
		print_student_record(&read_sr[i]);
	}




	return 0;
}
