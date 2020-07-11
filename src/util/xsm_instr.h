#ifndef _XSM_INSTR_H_
#define _XSM_INSTR_H_

/* MOV A,B */
#define _MOV(A,B)\
	fprintf(target_file,"MOV %s, %s\n",A,B)

/* MOV Rx,BP */
#define _MOV_RBP(x)\
	fprintf(target_file,"MOV R%d, BP\n",x)

/* MOV Rx,N */
#define _MOV_RN(x,N)\
	fprintf(target_file,"MOV R%d, %d\n",x,N)

/* MOV Rx,S */
#define _MOV_RS(x,S)\
	fprintf(target_file,"MOV R%d, \"%s\"\n",x,S)

/* MOV Rx,Ry */
#define _MOV_RR(x,y)\
	fprintf(target_file,"MOV R%d, R%d\n",x,y)

/* MOV Rx,[y] */
#define _MOV_RA(x,y)\
	fprintf(target_file,"MOV R%d, [%d]\n",x,y)

/* MOV [x],Ry */
#define _MOV_AR(x,y)\
	fprintf(target_file,"MOV [%d], R%d\n",x,y)

/* MOV [Rx],Ry */
#define _MOVA_AR(x,y)\
	fprintf(target_file,"MOV [R%d], R%d\n",x,y)

/* MOV Rx,[Ry] */
#define _MOVA_RA(x,y)\
	fprintf(target_file,"MOV R%d, [R%d]\n",x,y)

/* ADD Rx,Ry */
#define _ADD(x,y)\
	fprintf(target_file,"ADD R%d, R%d\n",x,y)

/* ADD Rx,N */
#define _ADD_N(x,N)\
	fprintf(target_file,"ADD R%d, %d\n",x,N);

/* ADD S,N */
#define _ADD_S(S,N)\
	fprintf(target_file,"ADD %s, %d\n",S,N)

/* SUB Rx,Ry */
#define _SUB(x,y)\
	fprintf(target_file,"SUB R%d, R%d\n",x,y)

/* SUB Rx,N */
#define _SUB_N(x,N)\
	fprintf(target_file,"SUB R%d, %d\n",x,N)

/* MUL Rx,Ry */
#define _MUL(x,y)\
	fprintf(target_file,"MUL R%d, R%d\n",x,y)

/* MUL Rx,N */
#define _MUL_N(x,N)\
	fprintf(target_file,"MUL R%d, %d\n",x,N)

/* DIV Rx,Ry */
#define _DIV(x,y)\
	fprintf(target_file,"DIV R%d, R%d\n",x,y)

/* MOD Rx,Ry */
#define _MOD(x,y)\
	fprintf(target_file,"MOD R%d, R%d\n",x,y)

/* MOV [ADDRESS=x],Ry */
#define _ASN(x,y)\
	MOVA_AR(x,y)

/* LT Rx,Ry */
#define _LT(x,y)\
	fprintf(target_file,"LT R%d, R%d\n",x,y)

/* LE Rx,Ry */
#define _LE(x,y)\
	fprintf(target_file,"LE R%d, R%d\n",x,y)

/* GT Rx,Ry */
#define _GT(x,y)\
	fprintf(target_file,"GT R%d, R%d\n",x,y)

/* GE Rx,Ry */
#define _GE(x,y)\
	fprintf(target_file,"GE R%d, R%d\n",x,y)

/* EQ Rx,Ry */
#define _EQ(x,y)\
	fprintf(target_file,"EQ R%d, R%d\n",x,y)

/* NE Rx,Ry */
#define _NE(x,y)\
	fprintf(target_file,"NE R%d, R%d\n",x,y)

/* INR S */
#define _INR(S)\
	fprintf(target_file,"INR %s\n",S)

/* INR Rx */
#define _INR_R(x)\
	fprintf(target_file,"INR R%d\n",x)

/* DCR S */
#define _DCR(S)\
	fprintf(target_file,"DCR %s\n",S)

/* DCR Rx */
#define _DCR_R(x)\
	fprintf(target_file,"DCR R%d\n",x)

/* PUSH Rx */
#define _PUSH(x)\
	fprintf(target_file,"PUSH R%d\n",x)

/* PUSH S */
#define _PUSH_S(S)\
	fprintf(target_file,"PUSH %s\n",S)

/* POP Rx */
#define _POP(x)\
	fprintf(target_file,"POP R%d\n",x)

/* CALL N */
#define _CALL(N)\
	fprintf(target_file,"CALL %s\n",N)

/* RET */
#define _RET fprintf(target_file,"RET\n")

/* BRKP */
#define _BRKP fprintf(target_file,"BRKP\n")

/* L[y]: */
#define _LABEL_DEC(y)\
	fprintf(target_file,"L%d:\n",y)

/* F[y]: */
#define _FUNC_LABEL_DEC(y)\
	fprintf(target_file,"F%d:\n",y)

/* JMP/CALL/JZ/JNZ [Rx,] label */
#define _LABEL_JMP(label)\
	fprintf(target_file,"JMP L%d\n",label)
#define _LABEL_CALL(label)\
	fprintf(target_file,"CALL L%d\n",label)
#define _FUNC_LABEL_CALL(label)\
	fprintf(target_file,"CALL F%d\n",label)
#define _LABEL_JZ(reg,label)\
	fprintf(target_file,"JZ R%d, L%d\n",reg,label);
#define _LABEL_JNZ(reg,label)\
	fprintf(target_file,"JNZ R%d, L%d\n",reg,label)

#endif