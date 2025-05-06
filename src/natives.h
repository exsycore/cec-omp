#ifndef NATIVES_H
#define NATIVES_H

#include <string>
#include <string.h>

#include <sdk.hpp>

#include "amx/amx.h"

namespace Natives
{
    cell AMX_NATIVE_CALL CE_Convert(AMX* amx, const cell* params);
    cell AMX_NATIVE_CALL CE_Convert_Dialog(AMX* amx, const cell* params);
    cell AMX_NATIVE_CALL CE_CountTag(AMX* amx, const cell* params);
    cell AMX_NATIVE_CALL CE_CountVowel(AMX* amx, const cell* params);
}

#endif