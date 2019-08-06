#include<stdio.h>
#include<stdlib.h>
void main(){
    FILE *myfile=fopen("Longfile.txt","w");
    fprintf(myfile,"Display Type: Digital\nSerial Number: 779TP795DG2B\nDDC2 Protocol: Supported\nGamma: 2.2\nConnector Type: DisplayPort\nDevice Type: Monitor\nMaximum Image Size\nHorizontal Size: 16.14 inches\nVertical Size: 9.06 inches\nSupported Modes\n640 x 480 (60p Hz)\n640 x 480 (75p Hz)\n720 x 400 (70p Hz)\n800 x 600 (60p Hz)");
    fclose(myfile);
    myfile=fopen("Power.txt","r");
    fseek(myfile,4,SEEK_CUR);
    char ch=fgetc(myfile);
    printf("%c",ch);
    rewind(myfile);
    ch=fgetc(myfile);
    printf("%c",ch);
    fclose(myfile);
}

