/*
 * BIT_MATH.h
 *
 * Created: 10/20/2023 11:07:24 AM
 *  Author: Hp
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NUM)				REG |= (1<<BIT_NUM)
#define CLEAR_BIT(REG,BIT_NUM)				REG &=(~(1<<BIT_NUM))
#define CHECK_BIT(REG,BIT_NUM)				((REG>>BIT_NUM)&1)
#define FLIP_BIT(REG,BIT_NUM) 			REG ^= (1<<(BIT_NUM))



#endif /* BIT_MATH_H_ */