section .rodata 
formatPrintf: 
.asciz "res1 = %ld, res2 = %d, res3 = %ld\n" 
.section .text 
.globl main 
.type main, @function 
main: 
pushq %rbp 
movq %rsp, %rbp 
# get memory from stack 
subq $32, %rsp 
# res1 with garbage value is now in 24(%rsp) 
# res2 with garbage value is now in 16(%rsp) 
# set paramteters 
# put params 8 on stack 
movq $1000, 8(%rsp) 
# put params 7 on stack 
leaq 16(%rsp), %rax # address &res2 
movq %rax, (%rsp) # address 16(%rsp) in 8(%rsp) 
# put paramteters 6 to 1 in registers 
movq $0x1A, %r9 
leaq 24(%rsp), %r8 
movb $'A', %cl 
movw $3, %dx 
movl $012, %esi 
movq $1, %rdi 
call calc 
# print results 
leaq formatPrintf, %rdi 
movq 24(%rsp), %rsi 
movl 16(%rsp), %edx 
movq %rax, %rcx 
movq $0, %rax 
call printf 
# clean up stack 
addq $32, %rsp 
# exit main 
movq $0, %rax 
popq %rbp 
ret 