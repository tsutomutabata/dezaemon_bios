#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int lowAddress;
    unsigned int highAddress;
    unsigned char data[65536];
} Bank;


int main(int argc,char **argv){
    int isOption = 0;
    Bank memory[2];
    memset(&memory,0,sizeof(memory));

    if(argc != 4 && argc != 3){
        printf("Usage : hz2bin [--hex] hzformat.bin rawname (rawname.b7e & rawname.b7f) %d\n",argc);
        exit(1);
    }
    char *src,*out;
    if(!strcmp(argv[1],"--hex")){
        isOption = 1;
        src = argv[2];
        out = argv[3];
    }else{
        src = argv[1];
        out = argv[2];
    }

    FILE *fp;
    fp = fopen(src,"rb");
    if(fp == (FILE *)0){
        printf("hzformat file open error : %s\n",src);
        exit(1);
    }

    char z = fgetc(fp);
    if(z != 'Z'){
        printf("hzformat is invalid\n");
        fclose(fp);
        exit(1);
    }
    for(;;){
        unsigned char addr[3];
        if(3 != fread(addr,1,3,fp)){
            printf("hzformat chank is broken\n");
            break;
        }
        unsigned char len[3];
        if(3 != fread(len,1,3,fp)){
            printf("hzformat chank is broken\n");
            break;
        }
        int address = addr[0] + addr[1] * 0x100;
        int length = len[0] + len[1] * 0x100;
        if(address + length >= 0x10000){
            printf("Data length overflow\n");
            break;
        }
        if(address == 0 && length == 0){
            fclose(fp);
            for(int i=0; i<2; i++){
                if(memory[i].lowAddress == 0 && memory[i].highAddress == 0) continue;
                printf("BANK %02x %04x ~ %04x\n",i+0x7e,memory[i].lowAddress,memory[i].highAddress);
                char fileName[strlen(out)+8];
                char ext[8];
                int column = 6;
                if(isOption){
                    sprintf(ext,".h%02x",i+0x7e);
                    strcpy(fileName,out);
                    strcat(fileName,ext);
                    fp = fopen(fileName,"w");
                    if(fp == (FILE *)0){
                        printf("file create error : %s\n",fileName);
                        exit(1);
                    }
                    fprintf(fp,"01%02X%04X%04X",i+0x7e,memory[i].lowAddress,memory[i].highAddress-memory[i].lowAddress-1);
                    for(int idx = 0; idx < memory[i].highAddress-memory[i].lowAddress; idx++){
                        fprintf(fp,"%02X",memory[i].data[memory[i].lowAddress+idx]);
                        if(++column >= 16){
                            column=0;
                            fputs("\n",fp);
                        }
                    }
                    fprintf(fp,"03%02X%04X",i+0x7e,memory[i].lowAddress);
                    fclose(fp);
                    exit(0);
                }else{
                    sprintf(ext,".b%02x",i+0x7e);
                    strcpy(fileName,out);
                    strcat(fileName,ext);
                    fp = fopen(fileName,"wb");
                    if(fp == (FILE *)0){
                        printf("file create error : %s\n",fileName);
                        exit(1);
                    }
                    fwrite(&memory[i].data[memory[i].lowAddress],1,memory[i].highAddress-memory[i].lowAddress,fp);
                    fclose(fp);
                    exit(0);
                }
            }
        }else{
            if(addr[2] != 0x7e && addr[2] != 0x7f ){
                printf("Banks are 7e and 7f only\n");
                break;
            }
            int bank = addr[2] - 0x7e;
            if(memory[bank].lowAddress == 0){
                memory[bank].lowAddress = address;
            }
            if(memory[bank].highAddress < address + length){
                memory[bank].highAddress = address + length;
            }
            if(length != fread(&memory[bank].data[address],1,length,fp)){
                printf("hzformat chank is broken\n");
                break;
            }
        }
    }
    fclose(fp);
    return 1;
}