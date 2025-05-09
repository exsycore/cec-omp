Author: [Brian-Less](https://github.com/qqwrv-f10eq)

Edit by: [EasyCore](https://github.com/exsycore)

# Color Embed Converter

[![Build status](https://ci.appveyor.com/api/projects/status/2qswo7s6hk8jiovf?svg=true)](https://ci.appveyor.com/project/Brian-Less/cec/branch/master) [![Build Status](https://app.travis-ci.com/Brian-Less/cec.svg?branch=master)](https://app.travis-ci.com/Brian-Less/cec) ![License: MIT](https://img.shields.io/badge/License-MIT-red.svg)

ปลั๊กอิน CEC ช่วยเลื่อนแท็กสีให้แสดงผลได้อย่างถูกต้อง

## การติดตั้ง (open.mp)
* นำไฟล์ [cec-omp.dll](cec-omp.dll), [pawnraknet.dll](https://github.com/katursis/Pawn.RakNet/releases/tag/1.6.0-omp) ใส่ในโฟลเดอร์ components ของคุณ (ไม่ต้องเพิ่มอะไร config.json สามารถใช้งานได้เลย)
* `
  GameMode\
    components\
      cec-omp.dll
      pawnraknet.dll
`

* นำไฟล์ [cec.inc](cec.inc), [Pawn.RakNet.inc](https://github.com/katursis/Pawn.RakNet/releases/tag/1.6.0-omp) ใส่ในโฟลเดอร์ Includes ของคุณ
* `
  qawno\
    include\
      cec.inc
      Pawn.RakNet.inc
`

## ตัวอย่าง
**ปัญหาและการติดตั้ง**

* ปัญหา

ก่อนใช้งาน

![ก่อนใช้งาน](https://i.imgur.com/M14TACI.png)

หลังใช้งาน

![หลังใช้งาน](https://i.imgur.com/UiuOF5B.png)

* การติดตั้ง
```Pawn
#include <open.mp>
#define cec_auto
#include <cec>
```

## การบิ้ว

## Sources
```bash
git clone https://github.com/exsycore/cec-omp.git
```

## Lib
```bash
https://github.com/qqwrv-f10eq (samp-plugin-sdk)
https://github.com/openmultiplayer/open.mp-sdk
https://github.com/openmultiplayer/open.mp-gdk
```

## Building on Windows
```bash
mkdir build
cd build
cmake .. -A Win32 -T ClangCL
```
Open Visual Studio and build the solution.
    
