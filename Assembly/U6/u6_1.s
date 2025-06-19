.section .bss
    a:      .skip 1        # reserviert 1 Byte für a
    b:      .skip 1        # reserviert 1 Byte für b

.section .data
    prompt: .asciz "Zwei Zahlen eingeben: "
    fmt:    .asciz "%hhd %hhd\n"
    fmtout: .asciz "Ergebnis: %d\nFlags: CF=%d OF=%d SF=%d ZF=%d\n"

.section .text
.globl main
.type main, @function

main:
    push %rbp
# a)
    lea prompt(%rip), %rdi   
    call printf

    lea fmt(%rip), %rdi        
    lea a(%rip), %rsi        
    lea b(%rip), %rdx          
    call scanf
# b)
    movb a(%rip), %al
    movb b(%rip), %bl
    addb %bl, %al

# c) 
    movsx %al, %esi    
    movzx %cl, %edx     
    movzx %dl, %ecx    
    movzx %sil, %r8d  
    movzx %r8b, %r9d    

    lea fmtout(%rip), %rdi
    xor %rax, %rax     
    call printf


# d)
    setc %cl    # Carry Flag in CL
    seto %dl    # Overflow Flag in DL
    sets %sil   # Sign Flag in SIL
    setz %r8b   # Zero Flag in R8B
# ------
    pop %rbp
    ret