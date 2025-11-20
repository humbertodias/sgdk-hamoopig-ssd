#include "collision.h"

bool FUNCAO_COLISAO(s16 R1x1, s16 R1y1, s16 R1x2, s16 R1y2, s16 R2x1, s16 R2y1, s16 R2x2, s16 R2y2)
{
	
	s16 temp=0;
	if(R1x1>R1x2){ temp=R1x1; R1x1=R1x2; R1x2=temp; }
	if(R2x1>R2x2){ temp=R2x1; R2x1=R2x2; R2x2=temp; }
	
	if ( (R1x1+(R1x2-R1x1)>R2x1) && (R1x1<R2x1+(R2x2-R2x1)) && 
		 (R1y1+(R1y2-R1y1)>R2y1) && (R1y1<R2y1+(R2y2-R2y1)) )
	{ 
		
		if(R1x1==R1x2 && R1y1==R1y2){
			return 0;
			}else if(R2x1==R2x2 && R2y1==R2y2){
				return 0;
			}else{
				/*houve colisao*/
				return 1;
			}
	}else{ 
		/*nao houve colisao*/
		return 0;
	}
}
