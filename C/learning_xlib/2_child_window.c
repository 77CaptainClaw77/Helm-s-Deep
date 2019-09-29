#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#define ERR_DISPLAY_NOT_FOUND 1
int main()
{
  Display *dpy;//display pointer
  int scr;//screen
  XEvent xe;
  Window win;
  Window embedded_win;
  dpy=XOpenDisplay(NULL);
  if(dpy==NULL)
    {
      fprintf(stderr,"Error finding display\n");
      exit(ERR_DISPLAY_NOT_FOUND);
    }
  scr=DefaultScreen(dpy);
  win=XCreateSimpleWindow(dpy, RootWindow(dpy,scr),200,400,1280,768,2,BlackPixel(dpy,scr),WhitePixel(dpy,scr));
  XSelectInput(dpy,win,ExposureMask | KeyPressMask);
  XMapWindow(dpy,win);
  embedded_win=XCreateSimpleWindow(dpy, RootWindow(dpy,scr),300,500,768,336,1,BlackPixel(dpy,scr),WhitePixel(dpy,scr));
  XSelectInput(dpy,embedded_win,ExposureMask | KeyPressMask);
  XMapWindow(dpy,embedded_win);
  while(1)
    {
      XNextEvent(dpy,&xe);
      if(xe.xany.window==embedded_win)
	{
	  if(xe.type==Expose)
	    {
	      XDrawLine(dpy,embedded_win,DefaultGC(dpy,scr),20,30,90,100);
	    }
	}
    }
  return 0;
}
