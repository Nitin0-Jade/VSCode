#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage ./recover FILE\n");
        return 1;
    }
    FILE *card = fopen(argv[1],"r");
    if (card == NULL)
    {
        return 1;
    }

   uint8_t buffer[512];

   int count =0;
   char filename[8];
   FILE *img = NULL;

   while(fread(buffer,512,1,card)==1)
   {
        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]  & 0xf0)==0xe0)
        //((buffer[3]  & 0xf0)==0xe0) what it does is just look at the 1st 4 bits of this 8 bit byte
        //and set the remaining 4 bits to 0 (see lec 4 problem set walkthrough)

        //making a jpeg file
        {
            if (img!=NULL)
            {
                fclose(img);
            }
            sprintf(filename,"%03i.jpg",count);
            count++;
            img = fopen(filename,"w");
            if(img == NULL)
            {
               return 1;
            }

            fwrite(buffer,512,1,img);
        }

        else if (img!=NULL)
        {
            fwrite(buffer,512,1,img);
        }
    }
    if (img!=NULL)
    {
        fclose(img);
    }
    fclose(card);
    return 0;
}
