#include "lvgl.h"
#include <stdio.h>

void lv_demo_stress(void)
{
    uint32_t read_num = 0;
    uint8_t buf[30] = {0};
    lv_fs_file_t f;
    lv_fs_res_t res;
    
    res = lv_fs_open(&f, "0:/SYSTEM/LV_FATFS/Fatfs_test.txt", LV_FS_MODE_RD);
    
    if(res != LV_FS_RES_OK)    printf("Open failed");
    
    res = lv_fs_read(&f, buf, 30, &read_num);
    
    if(res != LV_FS_RES_OK)    printf("Read failed");
    
    printf("实际读取长度：%d字节， %s",read_num , buf);
    
    lv_fs_close(&f);
}
