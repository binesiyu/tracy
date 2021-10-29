#ifdef _WIN32
#  include <windows.h>
#  include <shellapi.h>
#else
#  include <stdio.h>
#  include <stdlib.h>
#endif

#include "TracyWeb.hpp"

namespace tracy
{

void OpenWebpage( const char* url )
{
#ifdef _WIN32
    ShellExecuteA( nullptr, nullptr, url, nullptr, nullptr, 0 );
#elif defined __APPLE__
    char buf[1024];
    sprintf( buf, "open %s", url );
    system( buf );
#else
    char buf[1024];
    sprintf( buf, "xdg-open %s", url );
    system( buf );
#endif
}

void OpenMvim( const char* fileName, int line )
{
#ifdef _WIN32
    ShellExecuteA( nullptr, nullptr, fileName, nullptr, nullptr, 0 );
#elif defined __APPLE__
    char buf[1024];
    // sprintf( buf, "mvim://open?url=file://%s&line=%d",fileName,line );
    sprintf( buf, "mvim +%d %s",line,fileName);
    system( buf );
#else
    char buf[1024];
    sprintf( buf, "xdg-open %s", fileName );
    system( buf );
#endif
}

}
