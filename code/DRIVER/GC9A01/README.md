# GC9A01解耦驱动

实现hal文件夹下的源文件即可完成移植
本例实现了cubeMX环境下stm32f103的4线spi驱动

> 在gc9a01_macro.h中打开GC9A01_TEST宏就能验证移植是否成功

```c
//测试代码
//需要在gc9a01_macro.h中定义GC9A01_TEST宏为1，并且编译test_240x180.c文件
//测试注意 : 测试图片已经完成像素点倒置，而且定义为const，所以gc9a01_macro.h中的INTERNAL_COLOR_SWAP宏必须为0

#include "gc9a01.h"

void test(){
    GC9A01_init();
    GC9A01_test(); 
}
```

有部分代码todo，已经能实现基本功能
还未完成lvgl的对接