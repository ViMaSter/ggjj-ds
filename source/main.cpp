#include <nds.h>

#include <stdio.h>

// git adds a nice header we can include to access the data
// this has the same name as the image
#include "dan.h"
#include "lobby.h"

int main(void)
{
    videoSetMode   ( MODE_5_2D );

    vramSetBankA( VRAM_A_MAIN_BG );
    vramSetBankB( VRAM_B_MAIN_BG  );

    int bg3 = bgInit( 3, BgType_Bmp16, BgSize_B16_256x256, 5, 0 );
    int bg2 = bgInit( 2, BgType_Bmp16, BgSize_B8_256x256, 0, 0 );

	bgSetPriority(bg3,0);
	bgSetPriority(bg2,1);

	dmaCopy(lobbyBitmap, bgGetGfxPtr(bg2), lobbyBitmapLen);
	dmaCopy(lobbyPal, BG_PALETTE, 256*2);
	dmaCopy(danBitmap, bgGetGfxPtr(bg3), danBitmapLen);


    videoSetModeSub( MODE_5_2D );
	consoleDemoInit();

	iprintf("No, this is not");
	iprintf("\na confirmed DS port.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n...unless?");

	while(1) {
		swiWaitForVBlank();
		scanKeys();
		if (keysDown()&KEY_START) break;
	}

	return 0;
}
