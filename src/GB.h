/*
   hhugboy Game Boy emulator
   copyright 2013 taizou

   Based on GEST
   Copyright (C) 2003-2010 TM

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#ifndef _GB_H
#define _GB_H

#include "types.h"
#include "rom.h"
#include "cheats.h"
#include "memory/GB_MBC.h"
#include "options.h"

class gb_system
{
public:
   gb_system();
   ~gb_system();
   
   bool init();
   void reset(bool change_mode = true, bool preserveMulticartState = false);
   void mem_reset(bool preserveMulticartState = false);
   void cpu_reset();

    gb_mbc* mbc;

   wchar_t rom_filename[ROM_FILENAME_SIZE];
   bool load_rom(const wchar_t* filename, int offset=0);
   bool romloaded;

   //CPU-----------------------------------------
   byte A;
   byte F; 
   word BC;
   word DE;
   word HL;
   word SP;   
   word PC;
   
   // flags in x86 order
   // size word because lahf loads flags to ah
   //unsigned short flags;

   int CFLAG;
   int HFLAG;
   int ZFLAG;
   int NFLAG;

   int system_type;
   
   //#include "opcodes.h"
   
  /* void gbz80_inc(byte* reg);
   void gbz80_dec(byte* reg);
   void gbz80_rlca();
   void gbz80_rrca();
   void gbz80_rla();
   void gbz80_rra();
   void gbz80_rlc(byte* reg);
   void gbz80_rrc(byte* reg);
   void gbz80_rl(byte* reg);
   void gbz80_rr(byte* reg);
   void gbz80_sla(byte* reg);
   void gbz80_sra(byte* reg);
   void gbz80_srl(byte* reg);
   void gbz80_bit(byte reg,int num);
   void gbz80_swap(byte* reg);
   void gbz80_scf();
   void gbz80_ccf();
   void gbz80_cpl();
   void gbz80_and(byte reg);
   void gbz80_xor(byte reg);
   void gbz80_or(byte reg);
   void gbz80_cp(byte reg);
   void gbz80_add(byte reg);
   void gbz80_add16(unsigned short* reg, unsigned short reg2);
   void gbz80_addSP(unsigned short* reg, signed char reg2);
   void gbz80_adc(byte reg);
   void gbz80_sub(byte reg);
   void gbz80_sbc(byte reg);
   void gbz80_daa();
   void gbz80_das();*/
   
   void handle_interrupt();
   
   bool load_state();
   bool save_state();

   bool write_save();
   bool load_save(bool loading_GB1_save_to_GB2 = false);

   //--------------------------------------------
   int frames;

   int button_pressed[8];
   int last_button_pressed[8];

   int wram_bank; 
   int vram_bank;

   bool LCD_clear_needed;
   int skip_frame;
   int off_counter;
   int serialbits;
   int IWait;

   int STAT_wait; 
   int draw_wait;   
   int frameskip_counter;
   int mode3_cyc;
   int wy_set;
   int IME;
   int CPUHalt;
   int gb_speed;
   int int_line;
   int timer_freq;

   int gbc_mode;

   int cycles_DIV;
   int cycles_timer;
   int cycles_LCD;
   int CYCLES_SERIAL;
   int cycles_serial;  
   int cycles_sound;
   int EI_count; 
   
   int timeron;
   int LCDon;
   
   int hdma_source;
   int hdma_destination;
   int hdma_bytes;
   int hdma_on;
   int gdma_rest;

   int tile_map;
   int win_tile_map;
   int tile_pattern;
   byte BGP[4];
   byte OBP0[4];
   byte OBP1[4];
   int sprite_number;
   unsigned short GBC_BGP[32];
   unsigned short GBC_OBP[32];
   int windowline;

   byte io_reg_read(register unsigned short address);

   int io_reg_write(register unsigned short address,register byte data);

   byte readmemory(unsigned short address);

   void writememory(unsigned short address,byte data);

   byte* memory;
   byte *cartRAM;
   byte *VRAM;
   byte *WRAM;
   byte* mem_map[0x10];
   byte* cartROM;
   Cartridge* cartridge;

   byte *memory_another;

    // things that are somewhat MBC related but would be mildly annoying to move
   int rumble_counter; // this can stay in GB for now because, uh, let's say because the cartridge makes the whole GB rumble

   //Sound ---------------------------------------
   byte sound_buffer[4][735];
   signed short final_wave[1470];

   signed short sound_left[5];
   signed short sound_right[5];

   int sound_on;
   int sound_index;
   int sound_buffer_index;
   int sound_balance;
   int sound_level1;
   int sound_level2;
   int sound_digital;

   int channel1_on;
   int channel1_ATL;
   int channel1_skip;
   int channel1_continue;
   int channel1_sweepATL;
   int channel1_sweepATLreload;
   int channel1_sweepdir;
   int channel1_sweepsteps;
   int channel1_envelopevolume;
   int channel1_envelopeATL;
   int channel1_envelopeATLreload;
   int channel1_envelopedir;
   int channel1_index;
   byte* channel1_wave;

   int channel2_on;
   int channel2_ATL;
   int channel2_skip;
   int channel2_continue;
   int channel2_envelopevolume;
   int channel2_envelopeATL;
   int channel2_envelopeATLreload;
   int channel2_envelopedir;
   int channel2_index;
   byte* channel2_wave;

   int channel3_on;
   int channel3_continue;
   int channel3_ATL;
   int channel3_skip;
   int channel3_index;
   int channel3_last;
   int channel3_outputlevel;

   int channel4_on;
   int channel4_clock;
   int channel4_ATL;
   int channel4_skip;
   int channel4_index;
   int channel4_shiftright;
   int channel4_shiftskip;
   int channel4_shiftindex;
   int channel4_Nsteps;
   int channel4_countdown;
   int channel4_continue;
   int channel4_envelopevolume;
   int channel4_envelopeATL;
   int channel4_envelopedir;
   int channel4_envelopeATLreload;

   void sound_register(register unsigned short address,register byte data);
   void channel1();
   void channel2();
   void channel3();
   void channel4();
   void sound_mix();
   void sound_event();
   void sound_reset();

   //Graphics ----------------------------------------------------------------
   void* gfx_buffer1;
   void* gfx_buffer2;
   void* gfx_buffer3;
   void* gfx_buffer4;

   void* gfx_buffer;
   void* gfx_buffer_old;
   void* gfx_buffer_older;
   void* gfx_buffer_oldest;

   bool init_gfx();
   static int gfx_bit_count;   

   void draw_line_tile_DMG();
   void draw_line_tile_GBC();

   void draw_sprites();
   void draw_sprite_tile(int tile, int x,int y,int t, int flags,int size,int spriteNumber);

   void set_LCD_mode(int mode) { memory[0xFF41] = (0x80|(memory[0xFF41]&0xFC)|mode); }
   void do_hdma();

   void set_int(int number) // sets interrupt 
   {
      if(number == 2) // allow only once per line
      {
         if(int_line == memory[0xFF44])
            return;
         else
            int_line = memory[0xFF44];
      }
   
      memory[0xFF0F] |= number;   
   }
   
   void compareLYCtoLY()
   {
      if(memory[0xFF45] == memory[0xFF44])
         memory[0xFF41] |= 0x04;
      else
         memory[0xFF41] &= 0xFB; 
   }

   inline byte readopcode(register unsigned short address) //for fast memory access
   {
   	
      if(number_of_cheats)
         for(int i=0;i<number_of_cheats;++i)
            if(address == cheat[i].address && (!(cheat[i].long_code) || (cheat[i].old_value == mem_map[address>>12][address&0x0fff])))
               return cheat[i].new_value;
              
      if ((address >= 0x0000 && address < 0x8000)|| (address >= 0xa000 && address < 0xc000) ) {
      	return mbc->readmemory_cart(address);
      }

      return mem_map[address>>12][address&0x0FFF];
   }

   unsigned short readword(register unsigned short address) //for fast memory access
   {
      if ((address >= 0x0000 && address < 0x8000) || (address >= 0xa000 && address < 0xc000) ) {
      	return  (unsigned short) ( mbc->readmemory_cart(address) | mbc->readmemory_cart(address+1) << 8  );
      }

      return (unsigned short)(mem_map[address>>12][address&0x0FFF]|(mem_map[(address+1)>>12][(address+1)&0x0FFF]<<8));
   }

   void writeword(register unsigned short address, register unsigned short data) //for fast memory access
   {
      mem_map[address>>12][address&0x0FFF] = data;
      mem_map[((address+1)&0xFFFF)>>12][(address+1)&0x0FFF] = (data>>8);
   }

   void copy_memory(unsigned short to,unsigned short from,int count)
   {
		if ( (from >= 0x0000 && from < 0x8000)  || (from >= 0xa000 && from < 0xc000) ) {
			
			while(count)
		      {
		         mem_map[to>>12][to&0x0FFF] = mbc->readmemory_cart(from);
		         ++to;
		         ++from;
		         --count;
		      }

		} else {
			
			while(count)
		      {
		         mem_map[to>>12][to&0x0FFF] = mem_map[from>>12][from&0x0FFF];
		         ++to;
		         ++from;
		         --count;
		      }
      
		}
   	

   }
   
   void mainloop();

private:
    int romFileSize;
    bool loadrom_zip(const wchar_t* filename);
    bool loadrom_file(const wchar_t* filename, int offset);
};

extern gb_system *GB;
extern gb_system *GB1;
extern gb_system *GB2;


#endif
