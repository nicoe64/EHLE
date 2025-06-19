.section .data 
.align 16 
.globl S 
.type S, @object 
.size S, 24 
S: 
.byte 'Z'  
.zero 3   
.long 1,2  
.zero 4   
.quad 0  
.section .text 
.globl _start 
; .type main, @function 
_start: 
pushq %rbp 
movq %rsp, %rbp 
leaq S(%rip), %rsi  
leaq 4(%rsi), %rdi 
movq %rdi, 16(%rsi) 
movq $60, %rax          
xor  %rdi, %rdi        
syscall 
; ret 