#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    unsigned char header[0x36];
    struct {
        unsigned char b;
        unsigned char g;
        unsigned char r;
        unsigned char a;
    } palette[16];
    unsigned char image[0];
} BMP;

unsigned char getPicel(unsigned char *bmp,int x,int y){
    if(x & 1){
        return bmp[(x>>1) + (223-y)*128] & 0x0f;
    }else{
        return bmp[(x>>1) + (223-y)*128] >> 4;
    }
}

/*
    SFC Image format
    16x16 のイメージは 8x8 を 4セル以下のアドレスに
    +----+----+
    |   0|  10|
    +----+----+
    | 200| 210|
    +----+----+
    各4プレーンのドットの並びは以下、左上から右下にラインに8ピクセルの直線の場合、
    MSB < = > LSB
    10000000
    01000000
    00100000
    00010000
    00001000
    00000100
    00000010
    00000001
    1プレーンと2プレーンが1セットで16Byteで 8x8 次の16 Byteが隣の 8x8
    32バイトで 16x8 の2Bit分の2プレーンその後、
    3プレーンと4プレーンが1セットで16Byteで1プレーンと2プレーンと同じフォーマットで格納
    200H先に後半の16x8が同じように64Byte格納されている。
*/
unsigned char getPlane(unsigned char *bmp,int plane,int x,int y){
    unsigned char result = 0;
    for(int i = 0; i < 8; i++){
        result <<= 1;
        if(getPicel(bmp,(x&0xfff8)+i,y) & (1 << plane)){
            result |= 1;
        }
    }
    return result;
}

unsigned char* getSfcImage8x8(unsigned char *bmp,unsigned char*sfc,int x,int y){
    for(int idx = 0; idx < 8; idx++){
        *sfc++ = getPlane(bmp, 0, x, y + idx);
        *sfc++ = getPlane(bmp, 1, x, y + idx);
    }
    for(int idx = 0; idx < 8; idx++){
        *sfc++ = getPlane(bmp, 2, x, y + idx);
        *sfc++ = getPlane(bmp, 3, x, y + idx);
    }
    return sfc;
}



int main(int argc,char **argv){
    if(argc != 2){
        printf("Usage : bg4bit 256x224.bmp\n");
        exit(1);
    }
    char *src,*out;
    src = argv[1];
    out = argv[2];

    FILE *fp;
    fp = fopen(src,"rb");
    if(fp == (FILE *)0){
        printf("BMP file open error : %s\n",src);
        exit(1);
    }

    fseek(fp, 0 , SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0 , SEEK_SET);
    BMP *bmp = (BMP*)malloc(file_size);
    fread(bmp,file_size,1,fp);
    fclose(fp);

    if(bmp->header[0] != 'B' || bmp->header[1] != 'M'){
        printf("It is not a BMP format file. : %s\n",src);
        exit(1);
    }
    if(bmp->header[0x12] != 0 || bmp->header[0x13] != 1){
        printf("Image width is 256 pixels : %s\n",src);
        exit(1);
    }
    if(bmp->header[0x16] != 224 || bmp->header[0x17] != 0){
        printf("The height of the image is 224 pixels : %s\n",src);
        exit(1);
    }
    if(bmp->header[0x1c] != 4){
        printf("4bit index color BMP only. : %s\n",src);
        exit(1);
    }
    if(bmp->header[0x1e] != 0){
        printf("Uncompressed BMP only. : %s\n",src);
        exit(1);
    }

    unsigned short SfcPalette[16];
    for(int i = 0; i < 16; i++){
//        printf("%d R=%d,G=%d,B=%d\n",i,bmp->palette[i].r,bmp->palette[i].g,bmp->palette[i].b);
        SfcPalette[i] = ((bmp->palette[i].b >> 3) << 10) | ((bmp->palette[i].g >> 3) << 5) | (bmp->palette[i].r >> 3);
    }
    unsigned char *sfcImage = malloc(256*224/2);
    unsigned char *p = sfcImage;
    for(int y = 0; y < 224; y+=16){
        for(int x = 0; x < 128; x+=8){
            p = getSfcImage8x8(bmp->image,p,x,y);
        }
        for(int x = 0; x < 128; x+=8){
            p = getSfcImage8x8(bmp->image,p,x,y+8);
        }
        for(int x = 128; x < 256; x+=8){
            p = getSfcImage8x8(bmp->image,p,x,y);
        }
        for(int x = 128; x < 256; x+=8){
            p = getSfcImage8x8(bmp->image,p,x,y+8);
        }
    }

    printf("017200006FFF\n");
    for(int i = 0;i < 256*224/2; i++){
        printf("%02X",sfcImage[i]);
        if((i & 0xf) == 0xf) printf("\n");
    }

    printf("01700040001F\n");
    for(int i = 0;i < 16; i++){
        printf("%02X%02X",SfcPalette[i] & 0xff,SfcPalette[i] >> 8);
        if((i & 0x7) == 0x7) printf("\n");
    }

    free(sfcImage);
    free(bmp);

   return 0;
}