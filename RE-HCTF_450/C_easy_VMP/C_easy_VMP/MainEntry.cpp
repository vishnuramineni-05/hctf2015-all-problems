#include <cstdio>
#include <Windows.h>
#include "Stack.h"
#include "VM.h"
/*
enum myVm
{
	VM_PUSH_EAX = 0,
	VM_PUSH_NUM,
	VM_POP_EAX,
	VM_ADD,
	VM_SUB,
	VM_XOR,
	VM_JMP,
	VM_JZ,
	VM_EXIT,
	VM_CMP,

	VM_STRLEN_CALL

	};
	*/
int main()
{
	char stringIn[10] = {0};
	scanf_s("%s", stringIn, 10);
#ifdef _DEBUG
	printf("addr = %x \n", stringIn);
#endif
	BYTE CODE[] =
	{ 
	VM_X00_START,
	VM_PUSH_NUM,	//NUM1  push addr of input Str

	VM_POP_EBX,
	VM_PUSH_EBX,	//EBX = ADDR STR

	VM_STRLEN_CALL, //pop addr, call strlen, push result

	VM_PUSH_NUM,	//NUNM2 push 0x0 i = 0
	VM_CMP,			//cmp <-----
	VM_PUSH_NUM,	//push NUM3 is jum to exit
	VM_JZ,			//pop NUM3 JZ  (18)
	 
	VM_POP_EAX,		//pop eax  ;eax = i

	
	VM_PUSH_EBX,	//EBX: push addr of input Str
	VM_PUSH_EAX,	//PUSH i
	
	VM_ADD,			//Pop i ,add i str
	VM_BYTE_MEM_GET, //POP STR, FIND BYTE STR, PUSH result
	VM_PUSH_NUM,    //num push 6 (6)
	VM_XOR,			//pop 6,top xor 6

	VM_PUSH_EBX,	//EBX: push addr of input Str
	VM_PUSH_EAX,	//PUSH i
	VM_ADD,			//Pop i ,add i str
	VM_BYTE_MEM_SET,//pop addr,pop result, Set That addr

	VM_PUSH_EAX,	//EAX = i
	VM_PUSH_NUM,	//NUM = 1
	VM_ADD,			//I = I+1
	VM_POP_EAX,		//eax = i
	VM_PUSH_EAX,	//push to jmp

	VM_PUSH_NUM,	//NUM5  jmp code
	VM_JMP,			//circle jmp
	VM_EXIT };
	DWORD CODE_DATA[] =
	{ 
	(DWORD)stringIn,
	0x000,
	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,

	0x012,
	0x006,
	0x001,
	-0x15,
	};

	StartVM(CODE, CODE_DATA);
	if (!strcmp(stringIn, "745230"))
	{
		printf("YOU GOT IT\n");
	}
	else
	{
		printf("SORRY FAIL\n");
	}
#ifdef _DEBUG
	printf("%s", stringIn);
#endif
	return 0;
}