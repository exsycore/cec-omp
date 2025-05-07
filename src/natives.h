#ifndef NATIVES_H
#define NATIVES_H

#include <string>
#include <string.h>

#include "sdk.hpp"

#include <amx/amx2.h>

extern void* pAMXFunctions;

namespace Natives
{
    int CE_Convert(AMX* amx, cell* params);
    int CE_Convert_Dialog(AMX* amx, cell* params);
    int CE_CountTag(AMX* amx, cell* params);
    int CE_CountVowel(AMX* amx, cell* params);
}

#endif
