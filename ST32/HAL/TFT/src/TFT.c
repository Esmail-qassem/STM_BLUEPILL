#include "STD_TYPES.h"
#include "SysTick_interface.h"
#include "GPIO_INTERFACE.h"
#include "SPI_INTERFACE.h"
#include "TFT.h"


u8 s;
static void WriteData   ( u8 Copy_u8Data ) {

	/* DC is 1 for data */
	GPIO_SetPinValue( TFT_DC_PORT , TFT_DC_PIN , 1 );

	/* Send Data */
	Spi_SendRecieveSync( SPI2,Copy_u8Data,&s ) ;
}

static void WriteCommand( u8 Copy_u8Commend ) {

	/* DC is 0 for data */
	GPIO_SetPinValue( TFT_DC_PORT , TFT_DC_PIN , 0 );

	/* Send Command */
	Spi_SendRecieveSync(SPI2, Copy_u8Commend, &s) ;
}
void TFT_VidInit ( void ) {

	/* Reset Puls To Initializing All registers*/
	GPIO_SetPinValue( TFT_RST_PORT , TFT_RST_PIN , 0 );
	SysTick_voidSetBusyWait( 1 );
	GPIO_SetPinValue( TFT_RST_PORT , TFT_RST_PIN , 1 );
	SysTick_voidSetBusyWait( 134);
	WriteCommand( SLPOUT ) ;   // take display out of sleep mode
	SysTick_voidSetBusyWait   ( 134) ;   // wait 150mS for TFT driver circuits

	WriteCommand( COLMOD ) ;   // select color mode:
	WriteData   ( 0x05   ) ;   // mode 5 = 16bit pixels (RGB565)

	WriteCommand( DISPON ) ;   // turn display on!
	SysTick_voidSetBusyWait   ( 1 );

	/* Remap TFT addresses ( x = 0 , y = 0 Start From The Left Top Of The TFT ) */
	WriteCommand( MADCTL );
	WriteData   ( 0xC0 );
}
int count=0;

void TFT_VidFillImage(const u16 *Copy_ptrImage) {
    // Set column and row ranges
    WriteCommand(CASET);
    WriteData(0); WriteData(0); WriteData(0); WriteData(131);
    WriteCommand(RASET);
    WriteData(0); WriteData(0); WriteData(0); WriteData(161);
    WriteCommand(RAMWR);
    
	u8 buffer[256];  // Buffer for 128 pixels
   

    for (u32 i = 0; i < 164; i+=1) {
        // Fill the buffer with pixel data (128 pixels per batch)
        for (int j = 0; j < 128; j++) {
            u16 pixel = *Copy_ptrImage++;
            buffer[j * 2] = pixel >> 8;      // High byte
            buffer[j * 2 + 1] = pixel & 0xFF; // Low byte
        }

        // Clear DMA transfer complete flag
        DMA_IFCR(DMA1_BASE) |= (1 << 17); // Clear TCIF5 flag
		GPIO_SetPinValue(TFT_DC_PORT, TFT_DC_PIN, 1);
        // Send data via DMA
        SPI_SendDataDMA(buffer, 256);

        // Wait for DMA transfer to complete
        while ((DMA_ISR(DMA1_BASE) & (1 << 17)) == 0);
		count++;
    }

	
       
}


void TFT_VidFillColor ( u16 Copy_u16Color ) {
   
        u8 hiByte = Copy_u16Color >> 8;
        u8 loByte = Copy_u16Color & 0xFF;
        
		WriteCommand(CASET);
		WriteData(0); WriteData(0); WriteData(0); WriteData(131);
		WriteCommand(RASET);
		WriteData(0); WriteData(0); WriteData(0); WriteData(161);
		WriteCommand(RAMWR);
    // Use a buffer to speed up transmission
    u8 buffer[256];  // Buffer for 128 pixels
    for (int i = 0; i < 128; i++) {
        buffer[i * 2] = hiByte;
        buffer[i * 2 + 1] = loByte;
    }

    // Send in chunks to improve performance
    for (u16 i = 0; i < (132 * 162) / 128; i++) {
		GPIO_SetPinValue( TFT_DC_PORT , TFT_DC_PIN , 1 );
        SPI_SendDataDMA(buffer, 256);
        while ((DMA_ISR(DMA1_BASE) & (1 << 17)) == 0);  // Wait for DMA complete
    }
    
    

}



void TFT_VidDrawHLine ( u8 Xaxis , u8 Yaxis , u8 Copy_u8Length , u16 Copy_u8Color ) {

	for ( ; Copy_u8Length > 0 ; Copy_u8Length-- ){

		WriteCommand( CASET ); // set column range (x0,x1)

		WriteData   ( Xaxis );
		WriteData   ( Xaxis );

		WriteCommand( RASET ); // set row range (y0,y1)

		WriteData   ( Yaxis );
		WriteData   ( Yaxis );

		WriteCommand( RAMWR ); // memory write

		WriteData ( Copy_u8Color >> 8   ); // write hi byte
		WriteData ( Copy_u8Color & 0xFF ); // write lo byte

		Xaxis++;

	}

}

void TFT_VidDrawVLine ( u8 Xaxis , u8 Yaxis , u8 Copy_u8Length , u16 Copy_u8Color ) {

	for ( ; Copy_u8Length > 0 ; Copy_u8Length-- ){

		WriteCommand( CASET ); // set column range (x0,x1)

		WriteData   ( Xaxis );
		WriteData   ( Xaxis );

		WriteCommand( RASET ); // set row range (y0,y1)

		WriteData   ( Yaxis );
		WriteData   ( Yaxis );

		WriteCommand( RAMWR ); // memory write

		WriteData ( Copy_u8Color >> 8   ); // write hi byte
		WriteData ( Copy_u8Color & 0xFF ); // write lo byte

		Yaxis++;

	}

}

void TFT_VidDrawRectangle ( u8 Copy_u8Height , u8 Copy_u8Width , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color ) {

	TFT_VidDrawHLine ( Xaxis , Yaxis , Copy_u8Width  , Copy_u8Color                 );
	TFT_VidDrawVLine ( Xaxis , Yaxis , Copy_u8Height , Copy_u8Color                 );
	TFT_VidDrawHLine ( Xaxis , Copy_u8Height + Yaxis , Copy_u8Width  , Copy_u8Color );
	TFT_VidDrawVLine ( Copy_u8Width + Xaxis , Yaxis , Copy_u8Height , Copy_u8Color  );

}

void TFT_VidWriteChar( u8 * Cop_u8Char , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color )
{

	u8  LOC_u8Mask = 0x80 ;
	u8  LOC_u8DataMasked  ;
	u16 LOC_u8Pixel       ;

	for( u8 LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 5 ; LOC_u8Iterator1++ ){

		for( u8 LOC_u8Iterator2 = 0 ; LOC_u8Iterator2 < 7 ; LOC_u8Iterator2++ ){

			/* Set The Position Of 5x7 Character */
			WriteCommand( CASET ); // set column range (x0,x1)

			WriteData( Xaxis +  LOC_u8Iterator1 );
			WriteData( Xaxis +  LOC_u8Iterator1 );

			WriteCommand( RASET ); // set row range (y0,y1)

			WriteData( Yaxis +  LOC_u8Iterator2 );
			WriteData( Yaxis +  LOC_u8Iterator2 );

			WriteCommand( RAMWR ); // memory write

			LOC_u8DataMasked = Cop_u8Char[ LOC_u8Iterator1 ] & LOC_u8Mask ;

			if( LOC_u8DataMasked == 0  ) { LOC_u8Pixel = 0x0000       ; }
			else                         { LOC_u8Pixel = Copy_u8Color ; }

			WriteData ( LOC_u8Pixel >> 8   ); // write hi byte
			WriteData ( LOC_u8Pixel & 0xFF ); // write lo byte

			LOC_u8Mask >>= 1 ;

		}

		LOC_u8Mask = 0x80 ;

	}

}
