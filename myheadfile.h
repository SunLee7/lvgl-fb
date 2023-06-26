#ifndef _MYHEADFILE_H_
#define _MYHEADFILE_H_

#include <sys/types.h>

extern volatile u_int32_t bram_data[];

void my_lvgl(void);
void my_lv_chart_update(void);

int uio_init(void);
int uio_proc(void);

#endif
