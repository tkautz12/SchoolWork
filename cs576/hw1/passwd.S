# ----------------------------------------------------------------------------------------
# Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
# To assemble and run:
#
#     gcc -c hello.s && ld hello.o && ./a.out
#
# 
#
#     gcc -nostdlib hello.s && ./a.out
# ----------------------------------------------------------------------------------------

        .global _start

        .text
_start:


buffer:
#		push	%rbp
#		mov		%rsp, %rbp
		sub		$0x50, %rsp		
open:
		mov		$2, %rax				#system call 2 is open
		mov		$filename, %rdi			#chooses which file to open
		mov		$0, %rsi				#Read only flag
		xor 	%rdx,%rdx					#
		syscall
		mov     %rax, -0x8(%rsp)
read:
#		push	%rax
		mov		%rax, %rdi					#FD for the text is rax when open is successful
		mov		$0, %rax					#system call 0 is read
		mov		%rsp, %rsi				#buffer
		mov		$ 50, %rdx					#bytes to read
		syscall

write:
        # write(1, message, 13)
        mov     $1, %rax                # system call 1 is write
        mov     $1, %rdi                # file handle 1 is stdout
		mov		%rsp, %rsi			#NEEDS TO BE CHANGED TO BUFFER
        mov     $50, %rdx               # number of bytes CHANGE NUM BYTES
        syscall                         # invoke operating system to do the write
        #close
        mov		$3, %rax				#system call 3 is close
        mov		-0x8(%rsp), %rdi
        syscall
        # exit(0)
		mov	$60, %rax					#system call 60 is exit
        xor     %rdi, %rdi              # we want return code 0
        syscall                         # invoke operating system to exit
filename:
		.ascii "/etc/passwd\0"				#filename

