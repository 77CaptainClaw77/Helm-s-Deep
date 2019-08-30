#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#define ERR_DISPLAY_NOT_FOUND 1
int main()
{
  XEvent ev;
  int screen;
  Display *disp;
  Window win;
  disp=XOpenDisplay(NULL);
  if(disp==NULL)
    {
      fprintf(stderr,"Display Not Found Error\n");
      exit(ERR_DISPLAY_NOT_FOUND);
    }
  screen=DefaultScreen(disp);
  win=XCreateSimpleWindow(disp,RootWindow(disp,screen),350,400,200,200,1,WhitePixel(disp,screen),BlackPixel(disp,screen));
  XSelectInput(disp,win,ExposureMask | KeyPressMask);
  XMapWindow(disp,win);
  while(1)
    {
      XNextEvent(disp,&ev);
    }
  return 0;
}
