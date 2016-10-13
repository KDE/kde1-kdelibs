/* config.h.  Generated automatically by configure.  */
/* config.h.in.  Generated automatically from configure.in by autoheader.  */

/* Define if on AIX 3.
   System headers sometimes define this.
   We just want to avoid a redefinition error message.  */
#ifndef _ALL_SOURCE
/* #undef _ALL_SOURCE */
#endif

/* Define if using alloca.c.  */
/* #undef C_ALLOCA */

/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.
   This function is required for alloca.c support on those systems.  */
/* #undef CRAY_STACKSEG_END */

/* Define if you have alloca, as a function or macro.  */
#define HAVE_ALLOCA 1

/* Define if you have <alloca.h> and it should be used (not on Ultrix).  */
#define HAVE_ALLOCA_H 1

/* Define if you have a working `mmap' system call.  */
/* #undef HAVE_MMAP */

/* Define as __inline if that's what the C compiler calls it.  */
/* #undef inline */

/* Define if on MINIX.  */
/* #undef _MINIX */

/* Define to `long' if <sys/types.h> doesn't define.  */
/* #undef off_t */

/* Define if the system does not provide POSIX.1 features except
   with this defined.  */
/* #undef _POSIX_1_SOURCE */

/* Define if you need to in order for stat and other things to work.  */
/* #undef _POSIX_SOURCE */

/* Define to `unsigned' if <sys/types.h> doesn't define.  */
/* #undef size_t */

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at run-time.
 STACK_DIRECTION > 0 => grows toward higher addresses
 STACK_DIRECTION < 0 => grows toward lower addresses
 STACK_DIRECTION = 0 => direction of growth unknown
 */
/* #undef STACK_DIRECTION */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#define TIME_WITH_SYS_TIME 1

/* Define if the C++ compiler supports BOOL */
#define HAVE_BOOL 1

/* defines if having libjpeg (always 1) */
#define HAVE_LIBJPEG 1

/* defines if having libtiff */
#define HAVE_LIBTIFF 1

/* defines if having libpng */
#define HAVE_LIBPNG 1

/* defines which to take for ksize_t */
#define ksize_t socklen_t

/* define if you have setenv */
#define HAVE_FUNC_SETENV 1

/* Define to 1 if NLS is requested.  */
#define ENABLE_NLS 1

/* Define if your locale.h file contains LC_MESSAGES.  */
#define HAVE_LC_MESSAGES 1    

/* Define if you have getdomainname */
#define HAVE_GETDOMAINNAME 1

/* Define if you have gethostname */
#define HAVE_GETHOSTNAME 1

/* Define if you have usleep */
#define HAVE_USLEEP 1

/* Define if you have random */
#define HAVE_RANDOM 1

/* Define if you have S_ISSOCK */
#define HAVE_S_ISSOCK 1

/* This is the prefix of the below paths. This may change in the future */
#define KDEDIR "/opt/kde1"

/* Where your docs should go to. */
#define KDE_HTMLDIR "/opt/kde1/share/doc/HTML"

/* Where your application file (.kdelnk) should go to. */
#define KDE_APPSDIR "/opt/kde1/share/applnk"

/* Where your icon should go to. */
#define KDE_ICONDIR "/opt/kde1/share/icons"

 /* Where your sound data should go to. */
#define KDE_SOUNDDIR "/opt/kde1/share/sounds"

/* Where you install application data. */
#define KDE_DATADIR "/opt/kde1/share/apps"

/* Where translation files should go to. */
#define KDE_LOCALE "/opt/kde1/share/locale"

/* Where cgi-bin executables should go to. */
#define KDE_CGIDIR "/opt/kde1/cgi-bin"

/* Where mimetypes should go to. */
#define KDE_MIMEDIR "/opt/kde1/share/mimelnk"

/* Where mimetypes should go to. */
#define KDE_TOOLBARDIR "/opt/kde1/share/toolbar"

/* Where general wallpapers should go to. */
#define KDE_WALLPAPERDIR "/opt/kde1/share/wallpapers"

/* Where binaries should be installed. */
#define KDE_BINDIR "/opt/kde1/bin"

/* Where KDE parts should be installed. */
#define KDE_PARTSDIR "/opt/kde1/parts"

/* Where KDE config files should be installed */
#define KDE_CONFIGDIR "/opt/kde1/share/config"

/* If the platform supports strdup */
#define HAVE_STRDUP 1

/* Define if you have an SGI like STL implementation */
#define HAVE_SGI_STL 1

/* Define if you have an HP like STL implementation */
/* #undef HAVE_HP_STL */

#ifndef HAVE_BOOL
#define HAVE_BOOL
typedef int bool;
#ifdef __cplusplus
const bool false = 0;
const bool true = 1;
#else
#define false (bool)0;
#define true (bool)1;
#endif
#endif

/* this is needed for Solaris and others */
#ifndef HAVE_USLEEP
#ifndef HAVE_USLEEP_DEFINED
#define HAVE_USLEEP_DEFINED
#ifdef __cplusplus
extern "C"
#endif
void usleep(unsigned int usec);
#endif  
#endif  

#ifndef HAVE_GETDOMAINNAME
#ifndef HAVE_GETDOMAINNAME_DEFINED
#define HAVE_GETDOMAINNAME_DEFINED
#ifdef __cplusplus
extern "C"
#endif
int getdomainname (char *Name, int Namelen);
#endif  
#endif  

#ifndef HAVE_GETHOSTNAME
#ifndef HAVE_GETHOSTNAME_DEFINED
#define HAVE_GETHOSTNAME_DEFINED
#ifdef __cplusplus  
extern "C" 
#endif
int gethostname (char *Name, int Namelen);
#endif  
#endif  

/*
 * This is needed for systems with broken headers that won't work with
 *  gcc -ansi
 */
#ifndef HAVE_STRDUP
#define kstrdup qstrdup
#else
#define kstrdup strdup
#endif

/*
 * This is an ugly little hack incase someone uses the inline keyword,
 * in a straight C file with AIX's xlc.
 */
#ifndef __AIX32
#ifndef __cplusplus
#define inline __inline
#endif
#endif

/*
 * jpeg.h needs HAVE_BOOLEAN, when the system uses boolean in system
 * headers and I'm too lazy to write a configure test as long as only
 * unixware is related
 */
#ifdef _UNIXWARE
#define HAVE_BOOLEAN
#endif

#ifndef HAVE_RANDOM
#ifndef HAVE_RANDOM_DEFINED
#define HAVE_RANDOM_DEFINED
long int random(void); // defined in fakes.cpp
void srandom(unsigned int seed);
#endif 
#endif 

#ifndef HAVE_S_ISSOCK
#define HAVE_S_ISSOCK
#define S_ISSOCK(mode) (1==0)
#endif

/* Define if you have the __argz_count function.  */
#define HAVE___ARGZ_COUNT 1

/* Define if you have the __argz_next function.  */
#define HAVE___ARGZ_NEXT 1

/* Define if you have the __argz_stringify function.  */
#define HAVE___ARGZ_STRINGIFY 1

/* Define if you have the getcwd function.  */
#define HAVE_GETCWD 1

/* Define if you have the getpagesize function.  */
#define HAVE_GETPAGESIZE 1

/* Define if you have the munmap function.  */
#define HAVE_MUNMAP 1

/* Define if you have the putenv function.  */
#define HAVE_PUTENV 1

/* Define if you have the setegid function.  */
#define HAVE_SETEGID 1

/* Define if you have the setenv function.  */
#define HAVE_SETENV 1

/* Define if you have the seteuid function.  */
#define HAVE_SETEUID 1

/* Define if you have the setlocale function.  */
#define HAVE_SETLOCALE 1

/* Define if you have the socket function.  */
#define HAVE_SOCKET 1

/* Define if you have the stpcpy function.  */
#define HAVE_STPCPY 1

/* Define if you have the strcasecmp function.  */
#define HAVE_STRCASECMP 1

/* Define if you have the strchr function.  */
#define HAVE_STRCHR 1

/* Define if you have the vsnprintf function.  */
#define HAVE_VSNPRINTF 1

/* Define if you have the <X11/extensions/shape.h> header file.  */
#define HAVE_X11_EXTENSIONS_SHAPE_H 1

/* Define if you have the <alloca.h> header file.  */
#define HAVE_ALLOCA_H 1

/* Define if you have the <argz.h> header file.  */
#define HAVE_ARGZ_H 1

/* Define if you have the <dirent.h> header file.  */
#define HAVE_DIRENT_H 1

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <fnmatch.h> header file.  */
#define HAVE_FNMATCH_H 1

/* Define if you have the <limits.h> header file.  */
#define HAVE_LIMITS_H 1

/* Define if you have the <linux/socket.h> header file.  */
#define HAVE_LINUX_SOCKET_H 1

/* Define if you have the <locale.h> header file.  */
#define HAVE_LOCALE_H 1

/* Define if you have the <malloc.h> header file.  */
#define HAVE_MALLOC_H 1

/* Define if you have the <ndir.h> header file.  */
/* #undef HAVE_NDIR_H */

/* Define if you have the <nl_types.h> header file.  */
#define HAVE_NL_TYPES_H 1

/* Define if you have the <paths.h> header file.  */
#define HAVE_PATHS_H 1

/* Define if you have the <sigaction.h> header file.  */
/* #undef HAVE_SIGACTION_H */

/* Define if you have the <socketbits.h> header file.  */
/* #undef HAVE_SOCKETBITS_H */

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Define if you have the <strings.h> header file.  */
#define HAVE_STRINGS_H 1

/* Define if you have the <sys/cdefs.h> header file.  */
#define HAVE_SYS_CDEFS_H 1

/* Define if you have the <sys/dir.h> header file.  */
/* #undef HAVE_SYS_DIR_H */

/* Define if you have the <sys/ndir.h> header file.  */
/* #undef HAVE_SYS_NDIR_H */

/* Define if you have the <sys/select.h> header file.  */
#define HAVE_SYS_SELECT_H 1

/* Define if you have the <sys/socket.h> header file.  */
#define HAVE_SYS_SOCKET_H 1

/* Define if you have the <sys/stat.h> header file.  */
#define HAVE_SYS_STAT_H 1

/* Define if you have the <sys/time.h> header file.  */
#define HAVE_SYS_TIME_H 1

/* Define if you have the <sysent.h> header file.  */
/* #undef HAVE_SYSENT_H */

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the <values.h> header file.  */
#define HAVE_VALUES_H 1

/* Name of package */
#define PACKAGE "kdelibs"

/* Version number of package */
#define VERSION "1.1.2.1"

