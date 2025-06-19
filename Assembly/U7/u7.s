CS - Übung 07								Gruppe 08


.equ COUNT, 5
.section .bss
 .lcomm choice, 1
 .lcomm again, 1
.section .data
pattern: .byte 'o'

.section .rodata
putsChoose: .asciz "Choose an option:"
puts1: .asciz "1 - Count up using for loop"
puts2: .asciz "2 - Print triangle pattern with '|'"
puts3: .asciz "3 - Print triangle pattern with 'o'"
printfChoice: .asciz "Your choice: "
putsReturn: .asciz ""
printfD: .asciz "%d "
printfC: .asciz "%c"
printfPlus: .asciz "+"
putsInvalid: .asciz "Invalid selection."
printfQuestion: .asciz "Do you want to try again? (y/n): "
scanfC: .asciz " %c"
# jumptable
.align 8
.jTable:
 .quad .case1
 .quad .case2
 .quad .case3
 .quad .default
.section .text
.globl main
.type main, @function
main:
 pushq %rbp
 movq %rsp, %rbp
.do_while:
 leaq putsChoose, %rdi
 call puts
 leaq puts1, %rdi
 call puts
 leaq puts2, %rdi
 call puts
 leaq puts3, %rdi
 call puts
 leaq printfChoice, %rdi
 movq $0, %rax
 call printf
 # read choice
 leaq scanfC, %rdi
 leaq choice, %rsi
 movq $0, %rax
 call scanf


################

# Lücke 1
    movzbl  choice(%rip), %edi
    sub     $'0', %edi
    cmp     $3, %edi
    ja      .default
    jmp     *.jTable(,%rdi,8)

################

.case1:
 movl $1, %r12d
 jmp .for_test
.for:
 leaq printfD, %rdi
 movl %r12d, %esi
 movq $0, %rax
 call printf
 incl %r12d
.for_test:
 cmpl $COUNT, %r12d
 jle .for
 leaq putsReturn, %rdi
 call puts
 jmp .test_do_while
.case2:
 movb $'|', pattern

###########

# 2. Lücke

.case3:
    cmp $2, %rsi
    jne .loc1
    movb $'o', pattern

    .loc1:
    movl $1, %r12d

    .for2:
        cmpl $COUNT, %r12d
        jg .for2_end

        movl $1, %r13d

    .while:
        cmpl %r13d, %r12d
        jg .while_end

        movl %r13d, %eax
        andl $1, %eax
        cmpl $0, %eax
        jne .loc2

        leaq pattern, %rsi
        movzbl (%rsi), %esi
        leaq printfC, %rdi
        movq $0, %rax
        call printf
        jmp .loc3

    .loc2:
        leaq printfPlus, %rdi
        movq $0, %rax
        call printf

    .loc3:
        incl %r13d
        jmp .while

    .while_end:
        leaq putsReturn, %rdi
        call puts

        incl %r12d
        jmp .for2

    .for2_end:

############

.default:
 leaq putsInvalid, %rdi
 call puts
.test_do_while:
 leaq printfQuestion, %rdi
 movq $0, %rax
 call printf
 # read again
 leaq scanfC, %rdi
 leaq again, %rsi
 movq $0, %rax
 call scanf
 movb again, %r12b
 cmpb $'Y', %r12b
 jz .do_while
 cmpb $'y', %r12b
 jz .do_while

 # end
 movq $0, %rax
 popq %rbp
 ret
