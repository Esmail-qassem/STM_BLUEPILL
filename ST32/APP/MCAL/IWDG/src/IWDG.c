#include "IWDG.h"

void IWDG_VoidInit(void)
{
    /*to write in PR OR RLR write 0x5555*/
    IWDG_KR|=0x5555;
      IWDG_PR=0; /*Prescaler by 8 */
      while(GET_BIT(IWDG_SR,0)==0);
     IWDG_KR|=0xCCCC;

}
void IWDG_VoidReload(void)
{
    /*to reload write 0xaaaa */
    IWDG_KR|=0xAAAA;
}