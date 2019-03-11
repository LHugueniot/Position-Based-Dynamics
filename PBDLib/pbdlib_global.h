#ifndef PBDHAIR_GLOBAL_H
#define PBDHAIR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PBDLIB_LIBRARY)
#  define PBDLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PBDLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PBDHAIR_GLOBAL_H


