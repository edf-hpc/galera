/*
 * Copyright (C) 2009-2013 Codership Oy <info@codership.com>
 *
 * $Id: gu_mmap.hpp 3190 2013-08-07 21:49:17Z alex $
 */

#ifndef __GCACHE_MMAP__
#define __GCACHE_MMAP__

#include "gu_fdesc.hpp"

namespace gu
{

class MMap
{

public:

    size_t const size;
    void*  const ptr;

    MMap (const FileDescriptor& fd, bool sequential = false);

    ~MMap ();

    void dont_need() const;
    void sync() const;
    void unmap();

private:

    bool mapped;

    // This class is definitely non-copyable
    MMap (const MMap&);
    MMap& operator = (const MMap);
};

} /* namespace gu */

#endif /* __GCACHE_MMAP__ */
