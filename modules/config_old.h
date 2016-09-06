/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */


/* double-inclusion protection for config.h */
#ifndef BOINC_CONFIG_H
#define BOINC_CONFIG_H

/* Version defines are now in version.h */
#include "version.h"



/* Directory where BOINC executables will be installed */
#define BOINC_EXECPREFIX "/usr/local/bin"

/* Directory where BOINC libraries will be installed */
#define BOINC_LIBDIR "/usr/local/lib"

/* Directory tree where BOINC will be installed */
#define BOINC_PREFIX "/usr/local"

/* Define to 1 if CYGWIN should use the WIN32 GUI */
/* #undef CYGWIN_USE_WIN32 */

/* Define to 1 if compiling under OS X 10.3 or earlier */
/* #undef DARWIN_10_3 */

/* Define to the platform's shared library extension */
#define DLLEXT ".so"

/* Use the Apple OpenGL framework. */
/* #undef HAVE_APPLE_OPENGL_FRAMEWORK */


/* Define to 1 if you have the declaration of `tzname', and to 0 if you don't.
   */
/* #undef HAVE_DECL_TZNAME */

/* Define to 1 if you don't have `vprintf' but do have `_doprnt.' */
/* #undef HAVE_DOPRNT */

/* Define to 1 if you have xcb-dpms library */
#define HAVE_DPMS 1



/* Define to 1 if you have the c library */
/* #undef HAVE_LIBC */

/* Define to 1 if you have a functional curl library. */
#define HAVE_LIBCURL 1

/* Define to 1 if you have the c_nonshared library */
/* #undef HAVE_LIBC_NONSHARED */

/* Define to 1 if you have the gcc library */
/* #undef HAVE_LIBGCC */

/* Define to 1 if you have the gcc_eh library */
/* #undef HAVE_LIBGCC_EH */

/* Define to 1 if you have the math library */
#define HAVE_LIBM 1

/* Define to 1 if you have the pthread library */
#define HAVE_LIBPTHREAD 1

/* Define to 1 if you have the stdc++ library */
/* #undef HAVE_LIBSTDC__ */

/* Define to 1 if you have the wsock32 library */
/* #undef HAVE_LIBWSOCK32 */

/* Define if your C++ compiler supports namespaces */
#define HAVE_NAMESPACES 1

/* Define if you have POSIX threads libraries and header files. */
#define HAVE_PTHREAD 1

/* Have PTHREAD_PRIO_INHERIT. */
#define HAVE_PTHREAD_PRIO_INHERIT 1

/* Define to 1 if you have sqlite3. */
#define HAVE_SQLITE3 1

/* Define to 1 if you have the resolv library */
/* #undef HAVE_RESOLV */

/* Define to 1 if locale is in namespace std:: */
#define HAVE_STD_LOCALE 1

/* Define to 1 if max is in namespace std:: */
#define HAVE_STD_MAX 1

/* Define to 1 if min is in namespace std:: */
#define HAVE_STD_MIN 1

/* Define to 1 if transform is in namespace std:: */
#define HAVE_STD_TRANSFORM 1

/* Define to 1 if the system has the type `struct ether_addr'. */
#define HAVE_STRUCT_ETHER_ADDR 1

/* Define to 1 if the system has the type `struct ifconf'. */
/* #undef HAVE_STRUCT_IFCONF */

/* Define to 1 if the system has the type `struct ifreq'. */
/* #undef HAVE_STRUCT_IFREQ */

/* Define to 1 if the system has the type `struct lifconf'. */
/* #undef HAVE_STRUCT_LIFCONF */

/* Define to 1 if the system has the type `struct lifreq'. */
/* #undef HAVE_STRUCT_LIFREQ */

/* Define to 1 if `tm_zone' is a member of `struct tm'. */
#define HAVE_STRUCT_TM_TM_ZONE 1

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
/* #define HAVE_SYS_DIR_H */

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if your `struct tm' has `tm_zone'. Deprecated, use
   `HAVE_STRUCT_TM_TM_ZONE' instead. */
#define HAVE_TM_ZONE 1

/* Define to 1 if you don't have `tm_zone' but do have the external array
   `tzname'. */
/* #undef HAVE_TZNAME */

/* Define to 1 if you have X11 library */
#define HAVE_X11 1


/* Define to 1 if you have xss library */
#define HAVE_XSS 1

/* Define to 1 if /proc/meminfo exists */
#define HAVE__PROC_MEMINFO 1

/* Define to 1 if /proc/self/psinfo exists */
/* #undef HAVE__PROC_SELF_PSINFO */

/* Define to 1 if /proc/self/stat exists */
#define HAVE__PROC_SELF_STAT 1

/* Platform identification used to identify applications for this BOINC core
   client */
#define HOSTTYPE "x86_64-pc-linux-gnu"

/* Alternate identification used to identify applications for this BOINC core
   client */
#define HOSTTYPEALT "i686-pc-linux-gnu"

/* "Define to 1 if largefile support causes missing symbols in C++" */
/* #undef LARGEFILE_BREAKS_CXX */

/* Define to the name of libcurl's certification file */
#define LIBCURL_CABUNDLE ""

/* Defined if libcurl supports AsynchDNS */
/* #undef LIBCURL_FEATURE_ASYNCHDNS */

/* Defined if libcurl supports IPv6 */
#define LIBCURL_FEATURE_IPV6 1

/* Defined if libcurl supports KRB4 */
/* #undef LIBCURL_FEATURE_KRB4 */

/* Defined if libcurl supports libz */
#define LIBCURL_FEATURE_LIBZ 1

/* Defined if libcurl supports SSL */
#define LIBCURL_FEATURE_SSL 1

/* Defined if libcurl supports DICT */
#define LIBCURL_PROTOCOL_DICT 1

/* Defined if libcurl supports FILE */
#define LIBCURL_PROTOCOL_FILE 1

/* Defined if libcurl supports FTP */
#define LIBCURL_PROTOCOL_FTP 1

/* Defined if libcurl supports FTPS */
#define LIBCURL_PROTOCOL_FTPS 1

/* Defined if libcurl supports GOPHER */
#define LIBCURL_PROTOCOL_GOPHER 1

/* Defined if libcurl supports HTTP */
#define LIBCURL_PROTOCOL_HTTP 1

/* Defined if libcurl supports HTTPS */
#define LIBCURL_PROTOCOL_HTTPS 1

/* Defined if libcurl supports LDAP */
#define LIBCURL_PROTOCOL_LDAP 1

/* Defined if libcurl supports TELNET */
#define LIBCURL_PROTOCOL_TELNET 1

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Define to 1 if your C compiler doesn't accept -c and -o together. */
/* #undef NO_MINUS_C_MINUS_O */

/* Name of package */
#define PACKAGE "boinc"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "BOINC"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "BOINC 7.2.4"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "boinc"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "7.2.4"

/* Define to necessary symbol if this constant uses a non-standard name on
   your system. */
/* #undef PTHREAD_CREATE_JOINABLE */

/* Define as the return type of signal handlers (`int' or `void'). */
#define RETSIGTYPE void

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Define to 1 if your <sys/time.h> declares `struct tm'. */
/* #undef TM_IN_SYS_TIME */

/* "Define to 1 if you want to use the openssl crypto library" */
#define USE_OPENSSL 1

/* Define to 1 to use windows sockets */
/* #undef USE_WINSOCK */

/* Define to 1 to use the wxWidgets debug libraries */
/* #undef USE_WX_DEBUG */

/* utmp file location */
#define UTMP_LOCATION "/var/run/utmp"

/* Version number of package */
#define VERSION "7.2.4"

/* Define to prevent redefinition of INT32 in jconfig.h */
/* #undef XMD_H */

/* Define to 1 if the X Window System is missing or not being used. */
/* #undef X_DISPLAY_MISSING */

/* Enable large inode numbers on Mac OS X 10.5.  */
#ifndef _DARWIN_USE_64_BIT_INODE
# define _DARWIN_USE_64_BIT_INODE 1
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define curl_free() as free() if our version of curl lacks curl_free. */
/* #undef curl_free */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */



#ifndef HAVE_XLOCALE_H
#define NO_PER_THREAD_LOCALE 1
#endif

#ifndef HAVE_RES_INIT
#define res_init() (0)
#endif

#include "project_specific_defines.h"

/* end double-inclusion protection for config.h */
#endif /* #ifndef BOINC_CONFIG_H */

