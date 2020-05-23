#ifndef __TRACYFILESYSTEM_HPP__
#define __TRACYFILESYSTEM_HPP__

#include <stdint.h>
#include <sys/stat.h>

namespace tracy
{

class View;

static inline bool FileExists( const char* fn )
{
    struct stat buf;
    return stat( fn, &buf ) == 0 && ( buf.st_mode & S_IFREG ) != 0;
}

bool SourceFileValid( const char* fn, uint64_t olderThan, const View& view );
bool SourceFileValid( const char* fn, uint64_t olderThan );

}

#endif
