#ifndef PBDHAIR_GLOBAL_H
#define PBDHAIR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PBDHAIR_LIBRARY)
#  define PBDHAIRSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PBDHAIRSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PBDHAIR_GLOBAL_H


