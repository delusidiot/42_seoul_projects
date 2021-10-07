#ifndef KEYS_H

# define KEYS_H

/*
** Data definitions for libX11 copy
** https://refspecs.linuxfoundation.org/LSB_1.3.0/gLSB/gLSB/libx11-ddefs.html
** KeyPressMask : keyboard button press => KEY_PRESS_MASK
** KeyReleaseMask : keyboard button release => KEY_RELEASE_MASK
** ButtonPressMask : mouse button press => BUTTON_PRESS_MASK
** ButtonReleaseMask : mouse button release => BUTTON_RELEASE_MASK
** PointerMotionMask : mouse move => POINTER_MOTION_MASK
*/

# define KEY_PRESS_MASK         (1L<<0)
# define KEY_RELEASE_MASK       (1L<<1)
# define BUTTON_PRESS_MASK      (1L<<2)
# define BUTTON_RELEASE_MASK    (1L<<3)
# define POINTER_MOTION_MASK	(1L<<6)

/*
** ButtonPress : mouse button press => MOUSE_PRESS
** ButtonRelease : mouse button releas => MOUSE_RELEASE
** MotionNotify : mouse move => MOUSE_MOVE
** DestroyNotify : close => EVENT_CLOSE
** Expose : expose => EVENT_EXPOSE
*/

# define MOUSE_PRESS    4
# define MOUSE_RELEASE  5
# define MOUSE_MOVE     6
# define EVENT_EXPOSE   12
# define EVENT_CLOSE    17



/*
** WSL X launch button codes
*/

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_THIRD_BUTTON	2
# define MOUSE_RIGHT_BUTTON	3
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

# define KEY_ANSI_R     114
# define KEY_ANSI_M     109
# define KEY_ANSI_W 119
# define KEY_ANSI_A 97
# define KEY_ANSI_S 115
# define KEY_ANSI_D 100
# define KEY_ANSI_B 98
# define KEY_ANSI_N 110
# define KEY_ANSI_J 106
# define KEY_ANSI_K 107
# define KEY_SPACE 32
# define KEY_ESCAPE 65307

# define KEY_UPARROW 65362
# define KEY_DOWNARROW 65364
# define KEY_RIGHTARROW 65363
# define KEY_LEFTARROW 65361



# define KEY_ENTER 65293
# define KEY_SPACE 32
# define KEY_CTRL 65507
# define KEY_ALT 65513
# define KEY_SHIFT 65505

#endif