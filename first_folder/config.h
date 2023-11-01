/* 
 * File:   config.h
 * Author: RENATO
 *
 * Created on 20 de enero de 2015, 21:59
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

void system_clock();
void configIOMap();
void configT1();
void configT2();
void configT3();

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

