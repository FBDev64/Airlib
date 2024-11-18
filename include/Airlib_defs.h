#ifdef __linux
#include <X11/Xlib.h>

static Display *d;
static Window w;
static XEvent e;
static int s;

#endif

#define KCLS  "\e[2J"
#define KNRM  "\e[0m"
#define KRED  "\e[31m"
#define KGRN  "\e[32m"
#define KYEL  "\e[33m"
#define KBLU  "\e[34m"
#define KMAG  "\e[35m"
#define KCYN  "\e[36m"
#define KWHT  "\e[37m"
#define KHOL "\033[90m%s\033[0m" // placeholder