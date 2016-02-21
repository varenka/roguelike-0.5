/*
 * X86 compilation: gcc -o -L/usr/X11/lib   main main.c -lGL -lX11
 * X64 compilation: gcc -o -L/usr/X11/lib64 main main.c -lGL -lX11
 */

#include <iostream>
#include <string>
#include <fstream>
#include "map.h"
#include "player.h"
#include "game.h"
#include "ray.h"
/*#include <X11/X.h>
#include <X11/keysym.h>*/
#include "colors.h"

using namespace std;

int main()
{
    srand(time(NULL));
    map test = map();
    vector3 mapSize;
    mapSize.set(51, 51, 51);
    test.setSize(mapSize);
    test.randomizeTiles();
    game g;
    player p;
    p.position.set(1, 1, 1);
    g.currentMap = test;
    g.currentPlayer = p;
    g.spawnPlayer(p.position);
    g.printMap(p.position.y);
    while(!g.shouldClose) {
        g.gameLoop();
    }
    ray testr;
    vector3f e, r;
    e.set(0, 1, 0);
    r.set(5, 1, 3);
    testr.set(e, r);
    cout << testr.gets() << " has a slope of " << testr.slope() << endl;
    return 0;
}

/*
  while (1)
  {
    do
    {
      XNextEvent(dpy, &event);
      switch (event.type)
      {
        case KeyPress:
        {
          KeySym     keysym;
          XKeyEvent *kevent;
          char       buffer[1];
           It is necessary to convert the keycode to a
            keysym before checking if it is an escape
          kevent = (XKeyEvent *) &event;
          if (   (XLookupString((XKeyEvent *)&event,buffer,1,&keysym,NULL) == 1)
              && (keysym == (KeySym)XK_Escape) )
            exit(0);
          break;
        }
        case ButtonPress:
          recalcModelView = GL_TRUE;
          switch (event.xbutton.button)
          {
            case 1: xAngle += 10.0;
              break;
            case 2: yAngle += 10.0;
              break;
            case 3: zAngle += 10.0;
              break;
          }
          break;
        case ConfigureNotify:
          glViewport(0, 0, event.xconfigure.width,
                     event.xconfigure.height);
        //fall through...
        case Expose:
          needRedraw = GL_TRUE;
          break;
      }
    } while(XPending(dpy)); // loop to compress events

    if (recalcModelView)
    {
      glMatrixMode(GL_MODELVIEW);

      // reset modelview matrix to the identity matrix
      glLoadIdentity();

      // move the camera back three units
      glTranslatef(0.0, 0.0, -3.0);

      // rotate by X, Y, and Z angles
      glRotatef(xAngle, 0.1, 0.0, 0.0);
      glRotatef(yAngle, 0.0, 0.1, 0.0);
      glRotatef(zAngle, 0.0, 0.0, 1.0);

      recalcModelView = GL_FALSE;
      needRedraw = GL_TRUE;
    }
    if (needRedraw)
    {
      redraw();
      needRedraw = GL_FALSE;
    }
  }
*/
