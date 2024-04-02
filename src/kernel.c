#include "./kernel.h"

uint16 vga_entry(uint8 ch, uint8 fundo_color, uint8 text_color) {
    return ((uint16)fundo_color << 12) | ((uint16)text_color << 8) | ch;
}

void clear_vga_buffer(uint16 **buffer, uint8 fundo_color, uint8 tex_color)
{
  for( uint16 i = 0; i < BUFSIZE; i++){
    (*buffer)[i] = vga_entry(NULL, fundo_color, tex_color);
  }
}

void init_vga(uint8 fundo_color, uint8 tex_color) {
  vga_buff = (uint16*)VGA_Adrr;  
  clear_vga_buffer(&vga_buff, fundo_color, tex_color);
}

void Main(void)
{
    const char *string = "System init";
    init_vga(BLACK, BRIGHT_CYAN);
   
    uint8 cont = 0;

    while( string[cont] != '\0' ) {
        vga_buff[cont] = vga_entry((char)string[cont], BLACK, BRIGHT_CYAN);
        cont++;
    }

    return;
}