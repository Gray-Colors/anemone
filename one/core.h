// Anemone Core file for managing modules. This file should also be used to
// export engine functions and data types for any users.

#include "app.h"

#ifdef ANEMONE_PLATFORM_WINDOWS
#include "app.h"
#endif

#ifdef ANEMONE_PLATFORM_LINUX
#include "app.h"
#endif

// Consider moving to separate file, as core.h is meant to export definitions
// and manage conditional compilation, not included in all internal modules that
// need such macros
/*
#define ANEMO_ASSERT(x, y, err_msg)                                            \
  if (x != y) {                                                                \
    printf(err_msg);                                                           \
    exit(-1);                                                                  \
  }*/
