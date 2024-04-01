bits 32  
        section .text

         align 4
         dd 0x1BADB002 
         dd 0x00 
         dd - (0x1BADB002) 
         
        global start 
        extern Main 
         
        start:
         cli
         mov esp, stackpilha
         call Main 
         hlt 
         
        section .bss
        resb 8192
        stackpilha:  