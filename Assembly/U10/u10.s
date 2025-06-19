.section .rodata 
Formatprintf: 
.asciz "%c" 
Format: 
.asciz "" 
.section .text 
.globl pRev 
.type pRev, @function 
pRev: 
pushq %rbp 
movq %rsp, %rbp 
# Save caller-saved registers and align stack 
pushq %rbx 
pushq %r12 
subq $8, %rsp              
# Align stack to 16 bytes 
# Base case: if (length == 0) return 
cmpl $0, %esi 
je .end_function 
# Save length and pointer 
movq %rsi, %rbx            
movq %rdi, %r12            
decq %rbx                  
# rbx = length 
# r12 = word 
# rbx = length - 1 
# Print character: printf("%c", word[length - 1]); 
movzbl (%r12, %rbx, 1), %esi 
leaq Formatprintf(%rip), %rdi 
movq $0, %rax              
call printf 
# Clear rax for varargs 
# Recursive call: pRev(word, length - 1) 
movq %rbx, %rsi 
movq %r12, %rdi 
call pRev 
.end_function: 
addq $8, %rsp              
popq %r12 
popq %rbx 
popq %rbp 
ret 
.section .text 
.globl main 
.type main, @function 
main: 
pushq %rbp 
movq %rsp, %rbp 
# Restore stack alignment 
# Align stack before function calls 
subq $16, %rsp 
# Local variables 
movl $3, -4(%rbp)          
# int length = 3 
movb $'A', -8(%rbp) 
movb $'B', -7(%rbp) 
movb $'C', -6(%rbp) 
movb $0,  -5(%rbp)         
# Null terminator for word[] 
# Function call: pRev(word, length) 
movl -4(%rbp), %esi 
leaq -8(%rbp), %rdi 
call pRev 
# Print newline 
leaq Format(%rip), %rdi 
call puts 
addq $16, %rsp             
movq $0, %rax              
popq %rbp 
ret