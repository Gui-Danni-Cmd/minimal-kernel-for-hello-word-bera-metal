#include "./kernel.h"

uint16 vga_entry(unsigned char ch, uint8 fore_color, uint8 back_color) {
    return ((uint16)back_color << 12) | ((uint16)fore_color << 8) | ch;
}

void clear_vga_buffer(uint16 **buffer, uint8 tex_color, uint8 fundo_color)
{
    uint32 i;
  for( i = 0; i < BUFSIZE; i++){
    (*buffer)[i] = vga_entry(NULL, tex_color, fundo_color);
  }
}

void init_vga(uint8 tex_color, uint8 fundo_color) {
  vga_buff = (uint16*)VGA_Adrr;  
  clear_vga_buffer(&vga_buff, tex_color, fundo_color);  
}

void Main(void)
{
    const char *string = "Ola mundo!\0";
    init_vga(WHITE, BLUE);
   
    uint16 cont = 0;

    while( string[cont] != '\0' ) {
        vga_buff[cont] = vga_entry((char)string[cont], GREEN, BLUE);
        cont++;
    }

    return;
}