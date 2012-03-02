/*
 *=============================================================================================
 *											LJ_RTOS
 *									  The Real-Time Kernel
 *
 * (c) Copyright 2010, 李明浩
 * All Rights Reserved
 *
 * 文件名称：irq.c
 * 文件标识：c语言源文件
 * 摘    要：本文件定义与中断处理有关的函数
 * 
 * 当前版本：0.0
 * 作    者：李明浩
 * 完成日期：2010/11/12
 *
 * 取代版本：
 * 作    者：
 * 完成日期：
 *==============================================================================================
 */
 
 #include <lj_rtos.h>
 #include "irq.h"
 
/*
 *==============================================================================================
 * 函数名称：ClearPending
 * 功能描述：清除指定中断未决位
 * 传    参：bit (int)：所要清除的中断未决位
 * 返 回 值：void
 *==============================================================================================
 */
 void
 ClearPending( int bit )
 {
 	register i;
 	
 	R_SRCPND = bit;
 	R_INTPND = bit;
 	i = R_INTPND;
 }
 
 /*
 *==============================================================================================
 * 函数名称：ClearSubPending
 * 功能描述：清除指定子中断未决位
 * 传    参：bit (int)：所要清除的子中断未决位
 * 返 回 值：void
 *==============================================================================================
 */
 void
 ClearSubPending( int bit )
 {
 	register i;
 	
 	R_SUBSRCPND = bit;
 	i = R_INTPND;
 }
 
/*
 *=================================================================================================
 * 函数名称：ClearExtPending
 * 功能描述：清除4-23外中断未决位
 * 传    参：bit (int)：4-23号外中断未决位
 * 返 回 值：void
 *=================================================================================================
 */
 void
 ClearExtPending( int bit )
 {
 	register i;
 	
 	R_EINTPEND = bit;
 	
 	i = R_EINTPEND;
 }
 
/*
 *=================================================================================================
 * 函数名称：IsrInit
 * 功能描述：初始化中断控制寄存器和安装Timer0中断处理程序
 * 传    参：void
 * 返 回 值：void
 *=================================================================================================
 */
 void
 IsrInit( void )
 {
 	R_PRIORITY = 0x00000000;					/* 使用默认的中断优先级                           */
 	R_INTMOD   = 0x00000000;					/* 设置所有中断都为IRQ中断                        */
 	ISR_TIMER0 = (U32)LJTickIsr;				/* 安装Timer0中断处理函数                         */
 	ENABLE_IRQ( BIT_TIMER0 );
 }