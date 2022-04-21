#include "foo.h"

void b_write(Adress adr, byte b);
byte b_read(Adress adr);
void w_write(Adress adr, word w);
word w_read(Adress adr);
void load_file(const char * filename);
void test_mem();
void test_load();


int main(int argc, char* argv[]){
    test_mem();
    load_file(argv[1]);
    test_load();
    return 0;
}

void load_file(const char * filename)
{
    FILE * fin  = fopen(filename, "r");

    unsigned int adr_start_block, now_byte, number_byte, i;

    while (fscanf (fin, "%x %x", &adr_start_block, &number_byte) == 2)
    {
        //printf("%x\n", number_byte);
        for (i = 0; i < number_byte; i++)
            {
                fscanf (fin, "%x", &now_byte);
                b_write (adr_start_block, now_byte);
                adr_start_block++;
                //printf("%d\n", i);
                //printf("Yes\n");
            }
    }
    fclose(fin);
}
