#include <windows.h>
#include <mmsystem.h>
#include <mciavi.h>
#include <string>
#include <iostream>

int main(){
    mciSendString("open \"a.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString("play mp3", NULL, 0, NULL);
    mciSendString("play mp3 wait", NULL, 0, NULL);


    return 0;
}
