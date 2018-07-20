#ifndef FSENSOR_H
#define FSENSOR_H

#include "planner.h"

//#define FSENSOR_CHUNK_LEN      280  //filament sensor chunk length in steps - 1mm
#define FSENSOR_CHUNK_LEN      180  //filament sensor chunk length in steps - 0.64mm

//save restore printing
extern void fsensor_stop_and_save_print(void);
extern void fsensor_restore_print_and_continue(void);

extern void fsensor_init(void);

//enable/disable
extern bool fsensor_enable(void);
extern void fsensor_disable(void);

extern bool fsensor_autoload_enabled;
extern void fsensor_autoload_set(bool State);

//update (perform M600 on filament runout)
extern void fsensor_update(void);

//setup pin-change interrupt
extern void fsensor_setup_interrupt(void);

//
extern void fsensor_autoload_check_start(void);

//
extern void fsensor_autoload_check_stop(void);

//
extern bool fsensor_check_autoload(void);

//callbacks from stepper
extern void fsensor_st_block_begin(block_t* bl);
extern void fsensor_st_block_chunk(block_t* bl, int cnt);

//minimum meassured chunk length in steps
extern int16_t fsensor_chunk_len;
//enable/disable flag
extern bool fsensor_enabled;
//watch runout flag
extern bool fsensor_watch_runout;
//not responding flag
extern bool fsensor_not_responding;

extern uint8_t fsensor_err_cnt;

//autoload enable/disable flag
extern bool fsensor_watch_autoload;


extern uint32_t fsensor_st_sum;
extern uint32_t fsensor_yd_sum;
extern uint32_t fsensor_er_sum;
extern uint16_t fsensor_yd_min;
extern uint16_t fsensor_yd_max;

#endif //FSENSOR_H
