CS-1-08-08


.section .bss
    .lcomm new_ary, 32        # 8 * 4 Byte = 32 Byte

.section .data
ary:
    .int 0, 10, 20, 30, 40, 50, 60, 70

.section .rodata
printF:
    .asciz "%4d"
printNL:
    .asciz "\n"

.section .text
    .globl main
    .type main, @function
main:
    pushq %rbp
    movq %rsp, %rbp

    ############################
    # a) #
    ############################

    movq $0, %r12       # odd index
    movq $1, %r13       # even index

.for:
    # Adresse von ary holen
    leaq ary(%rip), %rax

    # odd-element laden
    movl (%rax, %r12, 4), %r14d

    # even-element laden
    movl (%rax, %r13, 4), %r15d

    # Adresse von new_ary holen
    leaq new_ary(%rip), %rbx

    # vertauscht speichern
    movl %r15d, (%rbx, %r12, 4)
    movl %r14d, (%rbx, %r13, 4)

    # inkrementiere odd/even
    addq $2, %r12
    addq $2, %r13

.for_test:
    cmpq $7, %r12
    jle .for

    ##########################################
    # b) + c) #
    ##########################################

    movq $0, %r12        # row = 0

.outer_for:
    cmpq $2, %r12
    jge .end_program     # wenn row >= 2, beenden

    movq $0, %r13        # col = 0

.inner_for:
    cmpq $4, %r13
    jge .print_newline


    leaq new_ary(%rip), %rax
    movq %r12, %r14
    imulq $4, %r14       
    addq %r13, %r14      
    imulq $4, %r14       
    addq %r14, %rax     

    movl (%rax), %esi    
    leaq printF(%rip), %rdi
    xor %rax, %rax      
    call printf

    incq %r13
    jmp .inner_for

.print_newline:
    leaq printNL(%rip), %rdi
    call puts

    incq %r12
    jmp .outer_for

.end_program:
    movq $0, %rax
    popq %rbp
    ret
