# ColourFix-omp
Author: https://github.com/qqwrv-f10eq
Edit by: https://github.com/exsycore

# Color Embed Converter

[![Build status](https://ci.appveyor.com/api/projects/status/2qswo7s6hk8jiovf?svg=true)](https://ci.appveyor.com/project/Brian-Less/cec/branch/master) [![Build Status](https://app.travis-ci.com/Brian-Less/cec.svg?branch=master)](https://app.travis-ci.com/Brian-Less/cec) ![License: MIT](https://img.shields.io/badge/License-MIT-red.svg)

ปลั๊กอิน CEC ช่วยเลื่อนแท็กสีให้แสดงผลได้อย่างถูกต้อง

## การติดตั้ง (open.mp)
* นำไฟล์ [cec-omp.dll](cec-omp.dll) ใส่ในโฟลเดอร์ components ของคุณ
* `
  GameMode\
    components\
      cec-omp.dll
`

* นำไฟล์ [cec.inc](cec.inc) ใส่ในโฟลเดอร์ Includes ของคุณ
* `
  qawno\
    include\
      cec.inc
`

## การบิ้ว (ใครที่ไม่ได้จะนำไปพัฒนาต่อข้ามไปได้เลย)

## Sources
```bash
git clone https://github.com/exsycore/cec-omp.git
```

## Building on Windows
```bash
mkdir build
cd build
cmake .. -A Win32 -T ClangCL
```
Open Visual Studio and build the solution.
    
