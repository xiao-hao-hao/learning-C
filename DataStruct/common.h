#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define DataType int
//#define DataType BinTreeNode*//用于二叉树调用

void Swap(DataType *p1, DataType *p2)
{
	DataType tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

#endif